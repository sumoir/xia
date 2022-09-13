/*
 * linklist.c
 *
 *  Created on: 2022年9月7日
 *      Author: xia
 */

#include <stdio.h>
#include <stdlib.h>

#include "single_link.h"

int Menu_show()
{
    int choose = 0;

    printf("\n\t1.Create linklist\n");
    printf("\t2.Add data from head\n");
    printf("\t3.Add data from tail\n");
    printf("\t4.Show linklist\n");
    printf("\t5.Add data from position\n");
    printf("\t6.Show linklist length\n");
    printf("\t7.Delete data from position\n");
    printf("\t8.Change data from position\n");
    printf("\t9.Find data from position\n");
    printf("\t10.Find position from data\n");
    printf("\t11.Change data from data\n");
    printf("\t12.Empty linklist\n");
    printf("\t13.Delete linklist\n");
    printf("\t0.Exit\n\n");

    printf("\tPlease enter your choice:");
    scanf("%d", &choose);
    return choose;
}

int Linklist_length(SingleNode *head)
{
    int length = 1;
    SingleNode *p = head;

    while (p->next != NULL) {
        p = p->next;
        length++;
    }

    return length;
}

SingleNode* Create_linklist()
{
    SingleNode *head = (SingleNode*)malloc(sizeof(SingleNode));

    if (head == NULL) {
        printf("created failed(malloc error)");
        return NULL;
    }
    head->next = NULL;
    head->age = 0xFFFFFFFF;
    printf("created success\n");

    return head;
}

void add_data_from_head(SingleNode *head, int data)
{
    SingleNode *p = (SingleNode*)malloc(sizeof(SingleNode));
    if (p == NULL) {
        printf("Add failed(malloc error)");
        return;
    }

    p->age = data;
    p->next = head->next;
    head->next = p;
}

void Linklist_show(SingleNode *head)
{
    SingleNode *p = head;
    printf("\n");
    while (p->next != NULL) {
        p = p->next;
        printf("%4d", p->age);
    }
}

void Add_data_from_tail(SingleNode *head, int data)
{
    SingleNode *p = (SingleNode*)malloc(sizeof(SingleNode));
    if (p == NULL) {
        printf("Add failed(malloc error)");
        return;
    }
    p->age = data;
    p->next = NULL;

    SingleNode *end = head;
    while (end->next != NULL) {
        end = end->next;
    }
    end->next = p;
}

void Add_data_from_position(SingleNode *head, int position, int data)
{
    int length = 0;

    length = Linklist_length(head);
    if (position <= 0 || position > length) {
        printf("Fall outside!\n");
        return;
    }

    SingleNode *p = (SingleNode*)malloc(sizeof(SingleNode));
    if (p == NULL) {
        printf("Add failed(malloc error)");
        return;
    }
    p->age = data;

    SingleNode *pos = head;
    for (int i = 1; i < position; i++) {
        pos = pos->next;
    }
    p->next = pos->next;
    pos->next = p;

    return;
}

void delete_data_by_position(SingleNode *head, int position)
{
    int length = 0;

    length = Linklist_length(head);
    if (position < 0 || position > length - 1) {
        printf("Fall outside!\n");
        return;
    }

    SingleNode *pos = head;
    for (int i = 0; i < position - 1; i++) {
        pos = pos->next;
    }
    SingleNode *p = pos->next;
    pos->next = p->next;
    free(p);
    p = NULL;

    return;
}

void Change_data_from_position(SingleNode *head, int position, int data)
{
    int length = 0;

    length = Linklist_length(head);
    if (position <= 0 || position > length - 1) {
        printf("Fall outside!\n");
        return;
    }

    SingleNode *pos = head;
    for (int i = 1; i <= position; i++) {
        pos = pos->next;
    }
    pos->age = data;

    return;
}

void Change_data_from_data(SingleNode *head, int data, int New_data)
{
    int length = 0, position = 0;

    position = find_position_by_data(head, data);
    if (position >= 0) {
        Change_data_from_position(head, position - 1, New_data);
        printf(" change success\n");
        return;
    }
    return;
}

int find_data_with_position(SingleNode *head)
{
    int length = 0, position = 0;

    printf("Please enter position to find:");
    scanf("%d", &position);

    length = Linklist_length(head);
    if (position <= 0 || position > length - 1) {
        printf("Fall outside!\n");
        return -1;
    }
    SingleNode *pos = head;

    for (int i = 1; i <= position; i++) {
        pos = pos->next;
    }
    printf("[%d] : %d", position, pos->age);

    return position;
}

int find_position_by_data(SingleNode *head, int data)
{
    int position = 0;

    SingleNode *pos = head;

    while (pos != NULL) {
        if (pos->data == data) {
            break;
        }

        pos = pos->next;
        position++;
    }

    if (pos == NULL) {
        printf("\nnot find the data \n");
        return -1;
    }
    printf("%d : [%d]\n", pos->age, position);

    return position;
}

void Empty_linklist(SingleNode *head)
{
    SingleNode *p = head->next;
    while (p->next != NULL) {
        delete_data_by_position(head, 0);
        p = head->next;
    }
    delete_data_by_position(head, 0);

    head->next = NULL;
    printf("Empty linklist success!\n");
    return;

}

void Delete_linklist(SingleNode *head)
{

    if (head->next != NULL) {
        Empty_linklist(head);
    }

    free(head);
    head = NULL;

    return;
}

