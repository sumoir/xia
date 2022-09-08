/*
 * link.c
 *
 *  Created on: 2022年9月8日
 *      Author: xia
 */

#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

void main()
{
    Linklist *head;
    int choose = 0;
    int data = 0;

    while (1) {
        printf("\n");
        choose = Menu_show();
        switch (choose) {
        case 1:
            head = Create_linklist();
            break;
        case 2:
            Show_linklist(head);
            break;
        case 3:
            data = Length_show(head);
            printf("\nlinklist length is %d\n", data);
            break;
        case 4:
            printf("Please enter data from head:");
            scanf("%d", &data);
            Add_data_from_head(head, data);
            break;
        case 5:
            printf("Please enter data from tail:");
            scanf("%d",&data);
            Add_data_from_tail(head, data);
            break;
        case 6:
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("not choose \n");
            break;

        }

    }

}
