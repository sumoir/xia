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
} SingleNode;

int Linklist_length(SingleNode *head);

SingleNode* Create_linklist();

void add_data_from_head(SingleNode *head);

int Menu_show();

void Linklist_show(SingleNode *head);

void Add_data_from_tail(SingleNode *head);

void Add_data_from_position(SingleNode *head);

void delete_data_by_position(SingleNode *head, int position);

void Change_data_from_position(SingleNode *head, int position, int data);

void Change_data_from_data(SingleNode *head, int data, int New_data);

int find_data_with_position(SingleNode *head);

int find_position_by_data(SingleNode *head, int data);

void Empty_linklist(SingleNode *head);

void Delete_linklist(SingleNode *head);
#endif /* LINKLIST_H_ */
