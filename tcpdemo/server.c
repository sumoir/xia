/*
 * server.c
 *
 *  Created on: 2022年8月28日
 *      Author: xia
 */
#include <stdio.h>

#include "biz_data.h"
#include "connect.h"
#include "codec.h"

int main()
{
    int clnt_sock = 0;
    clnt_sock = server_connect_from_client("127.0.0.1", 1234);

    Student student;
    init_student_info(&student, 19, "sun", "A", "boy");
    char buffer[100];
    int index = 0;

    Teacher teacher;
    init_empty_teacher(&teacher);
    int offset = 0, count = 0;
    int end = 1, teacher_num = 0;
    char temp[100], str[100];

    Frame frame;
    int total_length = 0;
    frame = encode_body_to_frame(STUDENT_TYPE, &student);
    index = encode_frame(frame, str);

    write(clnt_sock, "hello", 5);
    write(clnt_sock, str, index - 8);
    write(clnt_sock, str + index - 8, index + 8);
    write(clnt_sock, "hello", 5);
    sleep(1);

    while (teacher_num < 10) {
        memset(temp, 0, sizeof(temp));
        count = read(clnt_sock, temp, sizeof(temp));

        if (count <= 0) {
            break;
        }
        else {
            total_length += count;
            memcpy(buffer + offset, temp, count);
        }

        if (total_length < 3 + 1 + 1 + 4 + 1 + 1 + 1) {
            offset = total_length;
            continue;
        }

        offset = 0;
        while (offset == 0) {
            offset = try_to_parse_info(TEACHER_TYPE, &teacher, &total_length, buffer);

            if (offset == 0) {
                teacher_num++;
                show_teacher(teacher_num, &teacher);

                memset(str, 0, sizeof(str));
                frame = encode_body_to_frame(STUDENT_TYPE, &student);
                index = encode_frame(frame, str);

                write(clnt_sock, "hello", 5);
                write(clnt_sock, str, index);
                write(clnt_sock, str + index - 8, index + 8);
                write(clnt_sock, str, index - 8);
                write(clnt_sock, "hello", 5);
            }

            if (offset < 0) {
                offset = 0;
                break;
            }

        }

    }

    fini_student(&student);
    fini_teacher(&teacher);
    close(clnt_sock);
    return 0;
}
