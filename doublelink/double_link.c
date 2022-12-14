/*
 * linklist.c
 *
 *  Created on: 2022年9月8日
 *      Author: xia
 */
#include "double_link.h"

#include <stdio.h>
#include <stdlib.h>


int show_menu()
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

DoubleNode* create_linklist()
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

void add_data_from_head(DoubleNode *head, int data)
{
    DoubleNode *p = (DoubleNode*)malloc(sizeof(DoubleNode));
    if (p == NULL) {
        printf("Add failed(malloc error)");
        return;
    }
    p->data = data;

    //head & p
    p->next = head->next;
    head->next = p;
    p->prev = head;

    //head->next & p
    if (p->next != NULL) {
        p->next->prev = p;
    }

    return;
}

void add_data_from_tail(DoubleNode *head, int data)
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

void add_data_with_position(DoubleNode *head)
{
    int length = 0, pos = 1;
    int data = 0, position = 0;
    DoubleNode *right;
    DoubleNode *left = head;

    printf("Please enter position and data to add(use spaces between two numbers):");
    scanf("%d %d", &position, &data);

    length = get_length(head);
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
        add_data_from_head(head, data);
        return;
    }
    else if (position == length) {
        add_data_from_tail(head, data);
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

void delete_data_by_position(DoubleNode *head, int target)
{
    int pos = 0;
    DoubleNode *e = head;
    DoubleNode *left;
    DoubleNode *right;

    while (e != NULL) {
        if (pos == target) {
            break;
        }

        e = e->next;
        pos++;
    }

    if (e == NULL) {
        return;
    }

    right = e->next;
    left = e->prev;

    left->next = right;
    if (right != NULL) {
        right->prev = left;
    }

    free(e);
    e = NULL;
}

void update_data_from_position(DoubleNode *head, int position, int New_data)
{
    int length = 0, pos = 0;
    DoubleNode *p = head;

    length = get_length(head);

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

int get_length(DoubleNode *head)
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

    length = get_length(head);

    if (position < 0 || position > length) {
        printf("Data access out of bounds");
        return -1;
    }

    for (i = 0; i < position; i++) {
        p = p->next;
    }

    return p->data;
}

void reset_linklist(DoubleNode *head)
{

    while (head->next != NULL) {
        delete_data_by_position(head, 1);
    }

}

void clear_linklist(DoubleNode *head)
{
    int length = 0;
    length = get_length(head);
    if(length > 1){
        reset_linklist(head);
    }
    free(head);
    head = NULL;
}

