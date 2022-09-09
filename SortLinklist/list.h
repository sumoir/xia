/*
 * list.h
 *
 *  Created on: 2022年9月8日
 *      Author: xia
 */

#ifndef LIST_H_
#define LIST_H_

typedef struct node{

    int data;
    struct node *next;
}Linklist;


void Show_linklist(Linklist *head);
void Sort_linklist(Linklist *head);

#endif /* LIST_H_ */
