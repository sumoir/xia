/*
 * linklist.c
 *
 *  Created on: 2022年9月7日
 *      Author: xia
 */

#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

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

int Linklist_length(Linklist *head)
{
    int length = 1;
    Linklist *p = head;

    while (p->next != NULL) {
        p = p->next;
        length++;
    }

    return length;
}

Linklist* Create_linklist()
{
    Linklist *head = (Linklist*)malloc(sizeof(Linklist));

    if (head == NULL) {
        printf("created failed(malloc error)");
        return NULL;
    }
    head->age = -1;
    head->next = NULL;
    printf("created success\n");

    return head;
}

void Add_data_from_head(Linklist *head)
{
    int data = 0;

    printf("Please enter the data to be added:");
    scanf("%d", &data);

    Linklist *p = (Linklist*)malloc(sizeof(Linklist));
    if (p == NULL) {
        printf("Add failed(malloc error)");
        return;
    }

    p->age = data;
    p->next = head->next;
    head->next = p;
}

void Linklist_show(Linklist *head)
{
    Linklist *p = head;
    printf("\n");
    while (p->next != NULL) {
        p = p->next;
        printf("%4d", p->age);
    }
}

void Add_data_from_tail(Linklist *head)
{
    int data = 0;

    printf("Please enter the data to be added:");
    scanf("%d", &data);

    Linklist *p = (Linklist*)malloc(sizeof(Linklist));
    if (p == NULL) {
        printf("Add failed(malloc error)");
        return;
    }
    p->age = data;
    p->next = NULL;

    Linklist *end = head;
    while (end->next != NULL) {
        end = end->next;
    }
    end->next = p;
}

void Add_data_from_position(Linklist *head)
{

    int length = 0, position = 0, data = 0;

    printf("Please enter Position and Data to add(Use spaces between two number):");
    scanf("%d %d", &position, &data);

    length = Linklist_length(head);
    if (position < 0 || position > length) {
        printf("Fall outside!\n");
        return;
    }

    Linklist *p = (Linklist*)malloc(sizeof(Linklist));
    if (p == NULL) {
        printf("Add failed(malloc error)");
        return;
    }

    Linklist *pos = head;
    for (int i = 1; i < position; i++) {
        pos = pos->next;
    }
    p->age = data;
    p->next = pos->next;
    pos->next = p;

    return;
}

void Delete_data_from_position(Linklist *head, int position)
{
    int length = 0;

    length = Linklist_length(head);
    if (position < 0 || position > length - 1) {
        printf("Fall outside!\n");
        return;
    }

    Linklist *pos = head;
    for (int i = 0; i < position - 1; i++) {
        pos = pos->next;
    }
    Linklist *p = pos->next;
    pos->next = p->next;
    free(p);
    p = NULL;

    return;
}

void Change_data_from_position(Linklist *head, int position, int data)
{
    int length = 0;

    length = Linklist_length(head);
    if (position <= 0 || position > length - 1) {
        printf("Fall outside!\n");
        return;
    }

    Linklist *pos = head;
    for (int i = 1; i <= position; i++) {
        pos = pos->next;
    }
    pos->age = data;

    return;
}

void Change_data_from_data(Linklist *head, int data, int New_data)
{
    int length = 0, position = 0;

    position = Find_position_from_data(head, data);
    if (position >= 0) {
        Change_data_from_position(head, position - 1, New_data);
        printf(" change success\n");
        return;
    }
    return;
}

int Find_data_from_position(Linklist *head)
{
    int length = 0, position = 0;

    printf("Please enter position to find:");
    scanf("%d", &position);

    length = Linklist_length(head);
    if (position <= 0 || position > length - 1) {
        printf("Fall outside!\n");
        return -1;
    }
    Linklist *pos = head;

    for (int i = 1; i <= position; i++) {
        pos = pos->next;
    }
    printf("[%d] : %d", position, pos->age);

    return position;
}

int Find_position_from_data(Linklist *head, int data)
{
    int length = 0, position = 1;

    length = Linklist_length(head);
    Linklist *pos = head;

    while (pos->age != data && position++ < length) {
        pos = pos->next;
    }
    if (position > length) {
        printf("\nnot find the data \n");
        return -1;
    }
    printf("%d : [%d]\n", pos->age, position - 1);

    return position;
}

void Empty_linklist(Linklist *head)
{
    Linklist *p = head->next;
    while (p->next != NULL) {
        Delete_data_from_position(head, 0);
        p = head->next;
    }
    Delete_data_from_position(head, 0);

    head->next = NULL;
    printf("Empty linklist success!\n");
    return;

}

void Delete_linklist(Linklist *head)
{

    if (head->next != NULL) {
        Empty_linklist(head);
    }

    free(head);
    head = NULL;

    return;
}

