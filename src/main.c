/**Author: Moiz Naveed
 * 10/7/2017
 * CIS 2520 Assignment 1
 * main.c
 * "linkedlistAPI.h" created by Micheal Ellis is being used
 * in this program(unedited). Everything else is original.
 * */

#include <stdio.h>
#include "traffic.h"
#include "linkedlistAPI.h"
/** TRAFFIC SIMULATOR. CIS 2520 ASSIGNMENT 1*/

int main(int argc, char **argv)
{
	char dir_travel, dir_turn;
	int time_to_int, x = 1, cycle = 1;
	float light = 13, global_timer = 1;
	Car *a;

	FILE *f = fopen(argv[1], "r");
	if (f == NULL)
	{
		printf("error! file empty or unreadable\n");
		return 1;
	}
	char line[80];
	List *north_list = initializeList(&printNode, &deleteListNode, &compare);
	List *south_list = initializeList(&printNode, &deleteListNode, &compare);
	List *east_list = initializeList(&printNode, &deleteListNode, &compare);
	List *west_list = initializeList(&printNode, &deleteListNode, &compare);

	while (fgets(line, 80, f) != NULL)
	{
		Car *t = malloc(sizeof(Car));

		sscanf(line, "%c %c %d", &dir_travel, &dir_turn, &time_to_int);
		t->direction = dir_travel;
		t->turn = dir_turn;
		t->time_to = time_to_int;
		if (dir_travel == 'N')
			insertSorted(north_list, t);
		if (dir_travel == 'S')
			insertSorted(south_list, t);
		if (dir_travel == 'E')
			insertSorted(east_list, t);
		if (dir_travel == 'W')
			insertSorted(west_list, t);
	}
	printf("Initial Vehicle Information    Intersection Arrival Time    Completed at Time\n");
	while (x != 0)
	{
		if (north_list->head == NULL && north_list->tail == NULL && south_list->head == NULL && south_list->tail == NULL && east_list->head == NULL && east_list->tail == NULL && west_list->head == NULL && west_list->tail == NULL)
		{
			printf("The lists are empty\nProgram Ended\n");
			x = 0;
		}
		light = 13;
		while (x == 1 && light > 0)
		{
			if (north_list->head == NULL || light < 1.49)
			{
				x = 2;
				global_timer += light;
				break;
			}
			a = north_list->head->data;
			if (a->time_to <= (cycle * 14) - light)
			{
				if (a->turn == 'L' && light > 2.00)
				{
					global_timer += 1.5;
					light -= 1.5;
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(north_list, a);
				}
				if (a->turn == 'R' && light > 3.00)
				{
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(north_list, a);
				}
				if (a->turn == 'F' && light > 3.00)
				{
					global_timer += 1;
					light -= 1;
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(north_list, a);
				}
			}
			global_timer++;
			light--;
		}
		global_timer += 1;
		cycle++;
		light = 13;

		while (x == 2 && light > 0)
		{
			if (east_list->head == NULL || light < 1.49)
			{
				x = 3;
				global_timer += light;
				break;
			}
			a = east_list->head->data;
			if (a->time_to <= (cycle * 14) - light)
			{
				if (a->turn == 'L' && light > 2.00)
				{
					global_timer += 1.5;
					light -= 1.5;
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(east_list, a);
				}
				if (a->turn == 'R' && light > 3.00)
				{
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(east_list, a);
				}
				if (a->turn == 'F' && light > 3.00)
				{
					global_timer += 1;
					light -= 1;
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(east_list, a);
				}
			}
			global_timer++;
			light--;
		}
		global_timer += 1;
		cycle++;
		light = 13;

		while (x == 3 && light > 0)
		{
			if (south_list->head == NULL || light < 1.49)
			{
				x = 4;
				global_timer += light;
				break;
			}
			a = south_list->head->data;
			if (a->time_to <= (cycle * 14) - light)
			{
				if (a->turn == 'L' && light > 2.00)
				{
					global_timer += 1.5;
					light -= 1.5;
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(south_list, a);
				}
				if (a->turn == 'R' && light > 3.00)
				{
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(south_list, a);
				}
				if (a->turn == 'F' && light > 3.00)
				{
					global_timer += 1;
					light -= 1;
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(south_list, a);
				}
			}
			global_timer++;
			light--;
		}
		global_timer += 1;
		cycle++;
		light = 13;
		while (x == 4 && light > 0)
		{
			if (west_list->head == NULL || light < 1.490)
			{
				x = 1;
				global_timer += light;
				break;
			}
			a = west_list->head->data;
			if (a->time_to <= (cycle * 14) - light)
			{
				if (a->turn == 'L' && light > 2.00)
				{
					global_timer += 1.5;
					light -= 1.5;
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(west_list, a);
				}
				if (a->turn == 'R' && light > 3.00)
				{
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(west_list, a);
				}
				if (a->turn == 'F' && light > 3.00)
				{
					global_timer += 1;
					light -= 1;
					printf("%c %c %d    %23d    %27.1f\n", a->direction, a->turn, a->time_to, a->time_to, global_timer + 1);
					deleteNodeFromList(west_list, a);
				}
			}
			global_timer++;
			light--;
		}
		global_timer += 1;
		cycle++;
		light = 13;
	}

	free(north_list);
	free(east_list);
	free(west_list);
	free(south_list);
	return 0;
}
