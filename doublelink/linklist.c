/*
 * linklist.c
 *
 *  Created on: 2022年9月8日
 *      Author: xia
 */
#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

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

Linklist* Create_linklist()
{
    Linklist *head = (Linklist*)malloc(sizeof(Linklist));
    if (head == NULL) {
        printf("create fail (malloc error)");
        return NULL;
    }
    head->data = 0;
    head->next = NULL;
    head->previous = NULL;
    printf("Create Success !!!\n");

    return head;
}

void Add_data_from_head(Linklist *head, int data)
{
    int length = 0;
    Linklist *list;

    Linklist *p = (Linklist*)malloc(sizeof(Linklist));
    if (p == NULL) {
        printf("Add failed(malloc error)");
        return;
    }

    length = Length_show(head);
    if (length > 1) {
        p->data = data;
        p->next = head->next;
        p->previous = head;
        list = head->next;
        head->next = p;
        list->previous = p;
    }
    else {
        p->data = data;
        p->next = head->next;
        p->previous = head;
        head->next = p;
    }

    return;
}

void Add_data_from_tail(Linklist *head, int data)
{
    int length = 0;
    Linklist *list = head;

    Linklist *p = (Linklist*)malloc(sizeof(Linklist));
    if (p == NULL) {
        printf("Add failed(malloc error)");
        return;
    }

    while (list->next != NULL) {
        list = list->next;
    }
    p->data = data;
    p->next = list->next;
    p->previous = list;
    list->next = p;

    return;
}

void Add_data_from_position(Linklist *head)
{
    int length = 0, pos = 1;
    int data = 0, position = 0;
    Linklist *right;
    Linklist *left = head;

    printf("Please enter position and data to add(use spaces between two numbers):");
    scanf("%d %d", &position, &data);

    length = Length_show(head);
    Linklist *p = (Linklist*)malloc(sizeof(Linklist));

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
        p->previous = left;
        right->previous = p;
        left->next = p;

        return;
    }

    return;
}

int Find_position_from_data(Linklist *head, int data)
{
    int position = 1;
    Linklist *p = head;
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

void Delete_data_from_position(Linklist *head, int position)
{

    int length = 0, pos = 0;
    Linklist *p = head;
    Linklist *left;
    Linklist *right;

    length = Length_show(head);

    if (position <= 0 || position > length - 1) {
        printf("Data access out of bounds\n");
        return;
    }

    while (pos < position) {
        p = p->next;
        pos++;
    }

    if (position == length - 1) {
        left = p->previous;
        left->next = p->next;
        free(p);
        p = NULL;
        return;
    }

    right = p->next;
    left = p->previous;

    left->next = right;
    right->previous = left;

    free(p);
    p = NULL;

}

void Change_data_from_position(Linklist *head, int position, int New_data)
{
    int length = 0, pos = 0;
    Linklist *p = head;

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

void Show_linklist(Linklist *head)
{
    Linklist *p = head;
    printf("\nPositive:");
    while (p->next != NULL) {
        p = p->next;
        printf("%d ", p->data);
    }

    printf("\n");
    printf("Reverse:");
    while (p->previous != NULL) {
        printf("%d ", p->data);
        p = p->previous;
        if (p->previous == NULL) {
            break;
        }
    }
    printf("\n");
}

int Length_show(Linklist *head)
{
    int length = 1;
    Linklist *p = head;
    while (p->next != NULL) {
        length++;
        p = p->next;
    }

    return length;
}

int Find_data_from_position(Linklist *head, int position)
{
    Linklist *p = head;
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

void Empty_linklist(Linklist *head)
{

    while (head->next != NULL) {
        Delete_data_from_position(head, 1);
    }

}

void Delete_linklist(Linklist *head)
{
    int length = 0;
    length = Length_show(head);
    if(length > 1){
        Empty_linklist(head);
    }
    free(head);
    head = NULL;
}

