/*
 * link.c
 *
 *  Created on: 2022年9月8日
 *      Author: xia
 */

#include <stdio.h>
#include <stdlib.h>

#include "double_link.h"


int main(int argc, char **argv)
{
    DoubleNode *head;
    int choose = 0, position;
    int data = 0, New_data = 0;

    while (1) {
        choose = show_menu();
        switch (choose) {
        case 1:
            head = create_linklist();
            break;
        case 2:
            show_double_linklist(head);
            break;
        case 3:
            data = get_length(head);
            printf("\nlinklist length is %d\n", data);
            break;
        case 4:
            printf("Please enter data from head:");
            scanf("%d", &data);
            add_data_from_head(head, data);
            break;
        case 5:
            printf("Please enter data from tail:");
            scanf("%d", &data);
            add_data_from_tail(head, data);
            break;
        case 6:
            add_data_with_position(head);
            break;
        case 7:
            printf("Please enter position to find data:");
            scanf("%d", &position);
            data = find_data_with_position(head, position);
            if (data == -1) {
                break;
            }
            printf("[%d] = %d\n", position, data);
            break;
        case 8:
            printf("Please enter data to find position:");
            scanf("%d", &data);
            position = find_position_by_data(head, data);
            if (position == -1) {
                break;
            }
            printf("%d = [%d]\n", data, position);
            break;
        case 9:
            printf("Please enter position to delete:");
            scanf("%d", &position);
            delete_data_by_position(head, position);
            break;
        case 10:
            printf("Please enter position and New data to change(use spaces between two numbers):");
            scanf("%d %d",&position, &New_data);
            update_data_from_position(head,position,New_data);
            break;
        case 11:
            reset_linklist(head);
            break;
        case 12:
            clear_linklist(head);
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
