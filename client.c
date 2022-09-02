/*
 * client.c
 *
 *  Created on: 2022年8月28日
 *      Author: xia
 */

#include <stdio.h>
#include <unistd.h>

#include "connect.h"
#include "biz_data.h"
#include "codec.h"

int total_length = 0;

int main()
{
    int sock = 0;
    sock = client_connection_server("127.0.0.1", 1234);

    Student student;
    init_empty_student(&student);

    char str[50], buffer[1000], temp[100];

    int count = 0, offset = 0;
    int student_num = 0;

    Teacher teacher;
    int index = 0;
    init_teacher_info(&teacher, 25, "mike", "A", "girl", "English");

    Frame frame;

    while (student_num < 10) {
        memset(temp, 0, sizeof(temp));
        count = read(sock, temp, sizeof(temp));

        if (count <= 0) {
            break;
        }
        else {
            total_length += count;
            memcpy(buffer + offset, temp, count);
        }

        if (total_length < 1 + 1 + 4 + 1 + 1 + 1) {
            offset = total_length;
            continue;
        } //

        offset = 0;
        while (offset == 0) {
            offset = try_to_parse_info(STUDENT_TYPE, &student, &total_length, buffer);
            if (offset == 0) {
                student_num++;
                show_student(student_num, &student);

                memset(str, 0, sizeof(str));
                frame = encode_body_to_frame(TEACHER_TYPE, &teacher);
                index = encode_frame(frame, str);

                write(sock, "hello", 5);
                write(sock, str, index);
                write(sock, str, index - 3);
                write(sock, str + index - 3, index + 3);
                write(sock, "hello", 5);
            }
            if (offset < 0) {
                offset = 0;
                break;
            }
        }

    }

    printf("End\r\n");
    fini_student(&student);
    fini_teacher(&teacher);
    close(sock);
    return 0;
}
