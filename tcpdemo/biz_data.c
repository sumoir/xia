/*
 * biz_data.c
 *
 *  Created on: 2022年8月31日
 *      Author: xia
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include "codec.h"
#include "biz_data.h"

Frame encode_body_to_frame(uint8_t type, void *info)
{
    Frame frame;

    frame.header = 0xFA; ///
    switch (type) {
    case STUDENT_TYPE:
        frame.type = type;
        frame.length = encode_student(*(Student*)info, frame.data);
        break;
    case TEACHER_TYPE:
        frame.type = type;
        frame.length = encode_teacher(*(Teacher*)info, frame.data);
        break;
    default:
        frame.length = 0;
        printf("Unknown info type.");
    }

    return frame;
}

int decode_body_from_frame(Frame frame, void *info)
{
    switch (frame.type) {
    case STUDENT_TYPE:
        decode_student((Student*)info, frame.data);
        break;
    case TEACHER_TYPE:
        decode_teacher((Teacher*)info, frame.data);
        break;
    default:
        printf("Unknown info type.decode body from frame\r\n");
        return -1;
    }

    return 0;
}

int try_to_parse_info(uint8_t type, void *info, int *total_length, char data[])
{

    int offset = -1;
    int length = 0;
    char buffer[1000];

    memcpy(buffer, data, *total_length);

    offset = find_header(*total_length, buffer);
    if (offset < 0) {
        memset((char*)data, 0, *total_length);
        *total_length = 0;
        return offset;
    }

    length = buffer[offset + 2] + 3; //
    if (*total_length < length) {
        memset((char*)data, 0, 1000);
        memcpy((char*)data, buffer + offset, *total_length);
        *total_length -= offset;
        return *total_length;
    }

    Frame frame;
    offset += decode_frame(&frame, buffer + offset);
    memset((char*)data, 0, 1000);
    memcpy((char*)data, buffer + offset, *total_length);
    *total_length -= offset;

    if (type == STUDENT_TYPE) {
        Student *student = (Student*)info;
        memset(student->name, 0, 100);
        memset(student->class, 0, 100);
        memset(student->sex, 0, 100); //
        return decode_body_from_frame(frame, (void*)student);
    }
    else if (type == TEACHER_TYPE) {
        Teacher *teacher = (Teacher*)info;
        memset(teacher->name, 0, 100);
        memset(teacher->class, 0, 100);
        memset(teacher->sex, 0, 100);
        memset(teacher->subject, 0, 100); //
        return decode_body_from_frame(frame, (void*)teacher);

    }
    else {
        printf("Unknown info try type");
        return -1;
    }

    return 0;
}

void show_student(int student_num, Student *student)
{
    printf("Client received %d student from server: name:%s, age:%d, sex:%s, class:%s.\r\n", student_num, student->name, student->age,
           student->sex, student->class);
}

int encode_student(Student student, char data[])
{
    int index = 0;
    data[index] = 0XFA;
    index += 1;

    data[index] = sizeof(student.age) + strlen(student.class) + strlen(student.name) + strlen(student.sex);
    index += 1;

    index += encode_string(data + index, student.name);
    index += encode_int(data + index, student.age);
    index += encode_string(data + index, student.class);
    index += encode_string(data + index, student.sex);

    return index;
}

int decode_student(Student *student, char data[])
{
    int index = 0;
    index += 2;

    index += decode_string(student->name, (uint32_t)data[index], data + index + 1);
    index += decode_int(&student->age, data + index);
    index += decode_string(student->class, (uint32_t)data[index], data + index + 1);
    index += decode_string(student->sex, (uint32_t)data[index], data + index + 1);

    return index;
}

void init_student_info(Student *student, int age, char *name, char *class, char *sex)
{
    student->age = age;
    student->class = (char*)malloc(strlen(class));
    strncpy(student->class, class, strlen(class));

    student->name = (char*)malloc(strlen(name));
    strncpy(student->name, name, strlen(name));

    student->sex = (char*)malloc(strlen(sex));
    strncpy(student->sex, sex, strlen(sex));
}

void init_empty_student(Student *student)
{
    student->class = (char*)malloc(100 * sizeof(char));
    student->name = (char*)malloc(100 * sizeof(char));
    student->sex = (char*)malloc(100 * sizeof(char));
}

void fini_student(Student *student)
{
    free(student->class);
    free(student->name);
    free(student->sex);
}

void show_teacher(int i, Teacher *teacher)
{
    printf("Server received %d message from client:name:%s, age:%d, class:%s, sex:%s, subject:%s.\r\n", i, teacher->name, teacher->age,
           teacher->class, teacher->sex, teacher->subject);
}

int encode_teacher(Teacher teacher, char data[])
{
    int index = 0;

    data[index] = 0XFA;
    index += 1;

    data[index] = sizeof(teacher.age) + strlen(teacher.class) + strlen(teacher.name) + strlen(teacher.sex) + strlen(teacher.subject);
    index += 1;

    index += encode_string(data + index, teacher.name);
    index += encode_int(data + index, teacher.age);
    index += encode_string(data + index, teacher.class);
    index += encode_string(data + index, teacher.sex);
    index += encode_string(data + index, teacher.subject);

    return index;
}

int decode_teacher(Teacher *teacher, char data[])
{
    int index = 0;
    index += 2;

    index += decode_string(teacher->name, (uint32_t)data[index], data + index + 1);
    index += decode_int(&teacher->age, data + index);
    index += decode_string(teacher->class, (uint32_t)data[index], data + index + 1);
    index += decode_string(teacher->sex, (uint32_t)data[index], data + index + 1);
    index += decode_string(teacher->subject, (uint32_t)data[index], data + index + 1);

    return index;
}

void init_teacher_info(Teacher *teacher, int age, char *name, char *class, char *sex, char *subject)
{
    teacher->age = age;
    teacher->class = (char*)malloc(strlen(class));
    strncpy(teacher->class, class, strlen(class));

    teacher->name = (char*)malloc(strlen(name));
    strncpy(teacher->name, name, strlen(name));

    teacher->sex = (char*)malloc(strlen(sex));
    strncpy(teacher->sex, sex, strlen(sex));

    teacher->subject = (char*)malloc(strlen(subject));
    strncpy(teacher->subject, subject, strlen(subject));
}

void init_empty_teacher(Teacher *teacher)
{
    teacher->class = (char*)malloc(100 * sizeof(char));
    teacher->name = (char*)malloc(100 * sizeof(char));
    teacher->sex = (char*)malloc(100 * sizeof(char));
    teacher->subject = (char*)malloc(100 * sizeof(char));
}

void fini_teacher(Teacher *teacher)
{
    free(teacher->class);
    free(teacher->name);
    free(teacher->sex);
    free(teacher->subject);
}
