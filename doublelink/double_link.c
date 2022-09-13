/*
 * linklist.c
 *
 *  Created on: 2022年9月8日
 *      Author: xia
 */
#include "double_link.h"

#include <stdio.h>
#include <stdlib.h>


int Menu_show()
{
    int choose = 0;
    printf("\t1.Create linklist\n");
    printf("\t2.Show linklist\n");
    printf("\t3.Show length\n");
    printf("\t4.Add data from head\n");
    printf("\t5.Add data from tail\n");
    printf("\t6.Add data from position\n");
    printf("\t7.Find data from position\n");
    printf("\t8.Find position from data\n");
    printf("\t9.Delete data from position\n");
    printf("\t10.Change data from position\n");
    printf("\t11.Empty linklist\n");
    printf("\t12.Delete linklist\n");

    printf("\t0.Exit\n");

    printf("Please enter your choose:");
    scanf("%d", &choose);
    printf("\n");

    return choose;
}

DoubleNode* Create_linklist()
{
    DoubleNode *head = (DoubleNode*)malloc(sizeof(DoubleNode));
    if (head == NULL) {
        printf("create fail (malloc error)");
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    printf("Create Success !!!\n");

    return head;
}

void Add_data_from_head(DoubleNode *head, int data)
{
    int length = 0;
    DoubleNode *list;

    DoubleNode *p = (DoubleNode*)malloc(sizeof(DoubleNode));
    if (p == NULL) {
        printf("Add failed(malloc error)");
        return;
    }

    length = Length_show(head);
    if (length > 1) {
        p->data = data;
        p->next = head->next;
        p->prev = head;
        list = head->next;
        head->next = p;
        list->prev = p;
    }
    else {
        p->data = data;
        p->next = head->next;
        p->prev = head;
        head->next = p;
    }

    return;
}

void Add_data_from_tail(DoubleNode *head, int data)
{
    int length = 0;
    DoubleNode *list = head;

    DoubleNode *p = (DoubleNode*)malloc(sizeof(DoubleNode));
    if (p == NULL) {
        printf("Add failed(malloc error)");
        return;
    }

    while (list->next != NULL) {
        list = list->next;
    }
    p->data = data;
    p->next = list->next;
    p->prev = list;
    list->next = p;

    return;
}

void Add_data_from_position(DoubleNode *head)
{
    int length = 0, pos = 1;
    int data = 0, position = 0;
    DoubleNode *right;
    DoubleNode *left = head;

    printf("Please enter position and data to add(use spaces between two numbers):");
    scanf("%d %d", &position, &data);

    length = Length_show(head);
    DoubleNode *p = (DoubleNode*)malloc(sizeof(DoubleNode));

    if (position <= 0 || position > length) {
        printf("Data access out of bounds");
        return;
    }

    if (p == NULL) {
        printf("Add failed(malloc error)\n");
        return;
    }

    if (position == 1) {
        Add_data_from_head(head, data);
        return;
    }
    else if (position == length) {
        Add_data_from_tail(head, data);
        return;
    }
    else {
        while (pos < position) { ///
            left = left->next;
            pos++;
        }
        right = left->next;
        p->data = data;

        p->next = right;
        p->prev = left;
        right->prev = p;
        left->next = p;

        return;
    }

    return;
}

int find_position_by_data(DoubleNode *head, int data)
{
    int position = 1;
    DoubleNode *p = head;
    while (p->next != NULL) {
        if (p->data == data) {
            return position - 1;
        }
        p = p->next;
        position++;
    }
    if (p->data == data) {
        return position - 1;
    }
    else {
        printf("Not found this data\n");
    }

    return -1;
}

void Delete_data_from_position(DoubleNode *head, int position)
{
    int length = 0, pos = 0;
    DoubleNode *e = head;
    DoubleNode *left;
    DoubleNode *right;

    length = Length_show(head);

    if (position <= 0 || position > length - 1) {
        printf("Data access out of bounds\n");
        return;
    }

    while (pos < position) {
        e = e->next;
        pos++;
    }

    if (position == length - 1) {
        left = e->prev;
        left->next = e->next;
        free(e);
        e = NULL;
        return;
    }

    right = e->next;
    left = e->prev;

    left->next = right;
    right->prev = left;

    free(e);
    e = NULL;
}

void Change_data_from_position(DoubleNode *head, int position, int New_data)
{
    int length = 0, pos = 0;
    DoubleNode *p = head;

    length = Length_show(head);

    if (position <= 0 || position > length - 1) {
        printf("Data access out of bounds\n");
        return;
    }

    while (pos < position) {
        p = p->next;
        pos++;
    }
    p->data = New_data;

    return;

}

void show_double_linklist(DoubleNode *head)
{
    DoubleNode *p = head;
    printf("\nPositive:");
    while (p->next != NULL) {
        p = p->next;
        printf("%d ", p->data);
    }

    printf("\n");
    printf("Reverse:");
    while (p->prev != NULL) {
        printf("%d ", p->data);
        p = p->prev;
        if (p->prev == NULL) {
            break;
        }
    }
    printf("\n");
}

int Length_show(DoubleNode *head)
{
    int length = 1;
    DoubleNode *p = head;
    while (p->next != NULL) {
        length++;
        p = p->next;
    }

    return length;
}

int find_data_with_position(DoubleNode *head, int position)
{
    DoubleNode *p = head;
    int length = 0;
    int i = 0;

    length = Length_show(head);

    if (position < 0 || position > length) {
        printf("Data access out of bounds");
        return -1;
    }

    for (i = 0; i < position; i++) {
        p = p->next;
    }

    return p->data;
}

void Empty_linklist(DoubleNode *head)
{

    while (head->next != NULL) {
        Delete_data_from_position(head, 1);
    }

}

void Delete_linklist(DoubleNode *head)
{
    int length = 0;
    length = Length_show(head);
    if(length > 1){
        Empty_linklist(head);
    }
    free(head);
    head = NULL;
}

