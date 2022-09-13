/*
 * linklist.h
 *
 *  Created on: 2022年9月8日
 *      Author: xia
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef struct node {
    struct node *prev;
    int data;
    struct node *next;
} DoubleNode;

int Menu_show();

DoubleNode* Create_linklist();

void show_double_linklist();
int Length_show(DoubleNode *head);
void Add_data_from_head(DoubleNode *head, int data);
void Add_data_from_tail(DoubleNode *head, int data);
void Add_data_from_position(DoubleNode *head);
int find_data_with_position(DoubleNode *head, int position);
int find_position_by_data(DoubleNode *head, int data);
void Delete_data_from_position(DoubleNode *head, int position);
void Change_data_from_position(DoubleNode *head, int position, int New_data);
void Empty_linklist(DoubleNode *head);
void Delete_linklist(DoubleNode *head);

#endif /* LINKLIST_H_ */
