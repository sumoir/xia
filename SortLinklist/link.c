/*
 * link.c
 *
 *  Created on: 2022年9月8日
 *      Author: xia
 */
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void main()
{

    int data = 0;
    int i = 0, j = 0;
    int n = 7;

    Linklist *head = (Linklist*)malloc(sizeof(Linklist));
    head->data = -1;
    head->next = NULL;
    Linklist *list = head;



    for (i = 0; i < n; i++) {
        printf("Please enter %d data:", i + 1);
        scanf("%d", &data);
        Linklist *p = (Linklist*)malloc(sizeof(Linklist));
        p->data = data;
        p->next = head->next;
        head->next = p;
    }

    Show_linklist(head);
    printf("\n");

    for (j = n - 1; j > 0; j--) {
        list = head;
        for (i = 0; i < j; i++) {
            Sort_linklist(list);
            list = list->next;
        }
    }

    Show_linklist(head);
}
