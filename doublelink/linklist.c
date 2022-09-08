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
    printf("\t6.\n");
    printf("\t7.\n");
    printf("\t8.\n");
    printf("\t9.\n");
    printf("\t10.\n");
    printf("\t11.\n");
    printf("\t12.\n");

    printf("\t0.Exit\n");

    printf("Please enter your choose:");
    scanf("%d", &choose);

    return choose;
}

Linklist* Create_linklist()
{
    Linklist *head = (Linklist*)malloc(sizeof(Linklist));
    if (head == NULL) {
        printf("create fail (malloc error)");
        return NULL;
    }
    head->data = -1;
    head->next = NULL;
    head->previous = NULL;

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

void Find_data()
{

}

void Delete_data()
{

}

void Change_data()
{

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

