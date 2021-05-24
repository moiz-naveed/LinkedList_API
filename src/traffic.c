/**Author: Moiz Naveed
 *10/7/2017
 * CIS 2520 Assignment 1
 * traffic.c*/

#include <stdio.h>
#include "linkedlistAPI.h"
#include "traffic.h"

/**Function to print the car struct
 * Didn't want to change the API definitions so
 * the print function in the API calls this */
void printCar(Car *c)
{
	printf("%c %c %d\n", c->direction, c->turn, c->time_to);
}

/**Function to compare the data. The only thing that needs 
 * to be compared is the time to intersection. This function is called
 * by the compare function in the linkedlistAPI */
int compareCar(const Car *carA, const Car *carB)
{
	if (carA->time_to > carB->time_to)
		return 1;
	if (carA->time_to < carB->time_to)
		return -1;
	if (carA->time_to == carB->time_to)
		return 0;
	return 0;
}
