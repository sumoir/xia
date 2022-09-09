/*
 * list.c
 *
 *  Created on: 2022年9月8日
 *      Author: xia
 */

#include <stdio.h>

#include "list.h"

void Show_linklist(Linklist *head)
{
    Linklist *list = head;

    while (list->next != NULL) {
        list = list->next;
        printf("%d ", list->data);
    }
}

void Sort_linklist(Linklist *head)
{
    Linklist *left = head->next;
    Linklist *right = left->next;

    if (left->data > right->data) {

        left->next = right->next;
        right->next = left;
        head->next = right;

    }
    else {
        left = right;
        right = right->next;
    }

}
