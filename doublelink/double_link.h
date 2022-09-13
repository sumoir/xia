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

int show_menu();

DoubleNode* create_linklist();

void show_double_linklist();

int get_length(DoubleNode *head);

void add_data_from_head(DoubleNode *head, int data);

void add_data_from_tail(DoubleNode *head, int data);
void add_data_with_position(DoubleNode *head);

int find_data_with_position(DoubleNode *head, int position);
int find_position_by_data(DoubleNode *head, int data);

void delete_data_by_position(DoubleNode *head, int position);
void update_data_from_position(DoubleNode *head, int position, int New_data);

void reset_linklist(DoubleNode *head);
void clear_linklist(DoubleNode *head);

#endif /* LINKLIST_H_ */
