/*
 * biz_data.h
 *
 *  Created on: 2022年8月31日
 *      Author: xia
 */

#ifndef BIZ_DATA_H_
#define BIZ_DATA_H_

#include <stdint.h>

#include "codec.h"

#define STUDENT_TYPE 0x01
#define TEACHER_TYPE 0x02

typedef struct students {
    char *name;
    int age;
    char *class;
    char *sex;
} Student;

void show_student(int student_num, Student *student);
int encode_student(Student student, char data[]);
int decode_student(Student *student, char data[]);

void init_student_info(Student *student, int age, char *name, char *class, char *sex);
void init_empty_student(Student *student);
void fini_student(Student *student);

typedef struct teachers {
    char *name;
    int age;
    char *class;
    char *sex;
    char *subject;
} Teacher;

void show_teacher(int i, Teacher *teacher);
int encode_teacher(Teacher teacher, char data[]);
int decode_teacher(Teacher *teacher, char data[]);

void init_teacher_info(Teacher *teacher, int age, char *name, char *class, char *sex, char *subject);
void init_empty_teacher(Teacher *teacher);
void fini_teacher(Teacher *teacher);

int try_to_parse_info(uint8_t type, void *teacher, int *total_length, char data[]);

Frame encode_body_to_frame(uint8_t type, void *info);
int decode_body_from_frame(Frame frame, void *info);

#endif /* BIZ_DATA_H_ */
