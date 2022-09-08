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
void Add_data_from_head(Linklist *head, int data);
void Find_data();
void Delete_data();
void Change_data();
void Show_linklist();
int Length_show(Linklist *head);
void Add_data_from_tail(Linklist *head, int data);


#endif /* LINKLIST_H_ */
