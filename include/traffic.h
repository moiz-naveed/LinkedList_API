/**Author: Moiz Naveed
 *10/7/2017
 * CIS 2520 Assignment 1
 * traffic.h*/

#ifndef TRAFFIC_H
#define TRAFFIC_H
#include <stdlib.h>

/** THE CAR STRUCT */
typedef struct car
{
	char direction;
	char turn;
	int time_to;
} Car;

/** Function definitions*/

void printCar(Car *c);

int compareCar(const Car *carA, const Car *carB);

#endif
