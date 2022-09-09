/*
 * linklist.h
 *
 *  Created on: 2022年9月8日
 *      Author: xia
 */

#ifndef LINKLIST_H_
#define LINKLIST_H_

typedef struct node {
    struct node *previous;
    int data;
    struct node *next;
} Linklist;

int Menu_show();

Linklist* Create_linklist();
void Show_linklist();
int Length_show(Linklist *head);
void Add_data_from_head(Linklist *head, int data);
void Add_data_from_tail(Linklist *head, int data);
void Add_data_from_position(Linklist *head);
int Find_data_from_position(Linklist *head, int position);
int Find_position_from_data(Linklist *head, int data);
void Delete_data_from_position(Linklist *head, int position);
void Change_data_from_position(Linklist *head, int position, int New_data);
void Empty_linklist(Linklist *head);
void Delete_linklist(Linklist *head);

#endif /* LINKLIST_H_ */
