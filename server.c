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

int total_length = 0;

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
    int end = 1, teacher_num = 1;
    char temp[100], str[100];

    Frame frame;

    frame = encode_body_to_frame(STUDENT_TYPE, &student);
    memset(str, 0, sizeof(str));
    index = encode_frame(frame, str);

    write(clnt_sock, "hello", 5);
    write(clnt_sock, str, index - 8);
    write(clnt_sock, str + index - 8, index + 8);
    write(clnt_sock, "hello", 5);
    sleep(1);

    memset(str, 0, sizeof(str));
    while (end) {
        memset(temp, 0, sizeof(temp));
        count = read(clnt_sock, temp, sizeof(temp));

        if (count <= 0) {
            end = 0;
            break;
        }
        else {
            total_length += count;
            memcpy(buffer + offset, temp, count);
        }
/////////////////////////gaidong//////////////////////
        offset = 0;
        while (offset == 0) {
            offset = try_to_parse_info(TEACHER_TYPE, &teacher, &total_length, buffer);

            if (offset == 0) {
                show_teacher(teacher_num++, &teacher);

                memset(buffer, 0, sizeof(buffer));
                frame = encode_body_to_frame(STUDENT_TYPE, &student);
                index = encode_frame(frame, str);

                write(clnt_sock, "hello", 5);
                write(clnt_sock, str, index - 8);
                write(clnt_sock, str + index - 8, index + 8);
                write(clnt_sock, buffer, index);
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
