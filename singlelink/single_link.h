/*
 * linklist.h
 *
 *  Created on: 2022年9月7日
 *      Author: xia
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef struct node {
    int age;
    struct node *next;
} DoubleNode;

int Linklist_length(DoubleNode *head);

DoubleNode* Create_linklist();

void Add_data_from_head(DoubleNode *head);

int Menu_show();

void Linklist_show(DoubleNode *head);

void Add_data_from_tail(DoubleNode *head);

void Add_data_from_position(DoubleNode *head);

void Delete_data_from_position(DoubleNode *head, int position);

void Change_data_from_position(DoubleNode *head, int position, int data);

void Change_data_from_data(DoubleNode *head, int data, int New_data);

int find_data_with_position(DoubleNode *head);

int find_position_by_data(DoubleNode *head, int data);

void Empty_linklist(DoubleNode *head);

void Delete_linklist(DoubleNode *head);
#endif /* LINKLIST_H_ */
