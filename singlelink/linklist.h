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
} Linklist;

int Linklist_length(Linklist *head);

Linklist* Create_linklist();

void Add_data_from_head(Linklist *head);

int Menu_show();

void Linklist_show(Linklist *head);

void Add_data_from_tail(Linklist *head);

void Add_data_from_position(Linklist *head);

void Delete_data_from_position(Linklist *head, int position);

void Change_data_from_position(Linklist *head, int position, int data);

void Change_data_from_data(Linklist *head, int data, int New_data);

int Find_data_from_position(Linklist *head);

int Find_position_from_data(Linklist *head, int data);

void Empty_linklist(Linklist *head);

void Delete_linklist(Linklist *head);
#endif /* LINKLIST_H_ */
