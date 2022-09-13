/*
 * link.c
 *
 *  Created on: 2022年9月6日
 *      Author: xia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "single_link.h"

int main()
{
    int data = 0, New_data = 0; 
    int choose = 0, position = 0;
    SingleNode *head;

    while (1) {
        choose = Menu_show();
        switch (choose) {
        case 1:
            head = Create_linklist();
            break;
        case 2:
            add_data_from_head(head);
            break;
        case 3:
            Add_data_from_tail(head);
            break;
        case 4:
            Linklist_show(head);
            break;
        case 5:
            Add_data_from_position(head);
            break;
        case 6:
            data = Linklist_length(head);
            printf("linklist length:%d", data);
            break;
        case 7:
            printf("Please enter the position to be delete:");
            scanf("%d", &position);
            delete_data_by_position(head, position);
            break;
        case 8:
            printf("Please enter Position and Data to change(Use spaces between two number):");
            scanf("%d %d", &position, &data);
            Change_data_from_position(head, position, data);
            break;
        case 9:
            find_data_with_position(head);
            break;
        case 10:
            printf("Please enter data to find:");
            scanf("%d", &data);
            find_position_by_data(head, data);
            break;
        case 11:
            printf("Please enter Data and New data to change(Use spaces between two number):");
            scanf("%d %d", &data, &New_data);
            Change_data_from_data(head, data, New_data);
            break;
        case 12:
            Empty_linklist(head);
            break;
        case 13:
            Delete_linklist(head);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("No the correct option !\n");
            break;
        }
    }

}
