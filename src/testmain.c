/**Author: Moiz Naveed
 * 10/7/2017
 * CIS 2520, Assignment 1
 * testmain.c
 */
#include <stdio.h>
#include "linkedlistAPI.h"
#include "traffic.h"

int main(int argc, char **argv)
{

	/*Creating data for testing functions*/
	typedef struct myInt
	{
		int x;

	} MyInt;

	MyInt *a = malloc(sizeof(MyInt));
	Car *c = malloc(sizeof(Car));
	c->direction = 'N';
	c->turn = 'R';
	c->time_to = 10;
	a->x = 5142;
	int y;

	printf("Testing Function 'initializeList'\n");
	List *mylist = initializeList(&printNode, &deleteListNode, &compare);
	printf("Checking if worked properly\n");
	if (mylist->head == NULL && mylist->tail == NULL)
	{
		printf("List head assigned to 'NULL'\nList tail assigned to 'NULL'\nList has been initialized\nTest Passed\n");
	}
	else
	{
		printf("List not initialized\nTest Failed");
	}
	printf("\n");

	printf("Testing Function 'initializeNode'\n");
	printf("Data being used in the node is from the struct Car\nData: ");
	printCar(c);
	Node *myNode = initializeNode(c);
	printf("Checking if worked properly. Comparing data before and after initializing Node\n");
	printf("Printing Data from the initialized Node: ");
	printCar(myNode->data);
	if (myNode->next == NULL && myNode->previous == NULL && myNode->data == c)
	{
		printf("Next pointer assigned to 'NULL'\nPrevious pointer assigned to 'NULL'\nData matches \nNode has been initialized\nTest Passed\n");
	}
	else
	{
		printf("Node not initialized properly\nTest Failed");
	}
	printf("\n");

	printf("Test 1 for Function 'insertFront'\n");
	printf("adding the following data to the head of the list: ");
	printCar(c);
	insertFront(mylist, c);
	printf("Checking if worked properly\n");
	printf("Printing data from the head of the list: ");
	printCar(mylist->head->data);
	if (mylist->head->data == c)
	{
		printf("Node added to the head of the list\nTest Passed\n");
	}
	else
	{
		printf("Node not added properly\nTest Failed");
	}
	printf("\n");

	printf("Test 2 for Function 'insertFront'\n");
	printf("adding the following data to the head of the list: ");
	printf("%d\n", a->x);
	insertFront(mylist, a);
	printf("Checking if worked properly\n");
	printf("Printing data from the head of the list: ");
	printf("%d\n", a->x);
	if (mylist->head->data == a)
	{
		printf("Node added to the head of the list\nTest Passed\n");
	}
	else
	{
		printf("Node not added properly\nTest Failed");
	}
	printf("\n");

	printf("Test 1 for Function 'insertBack'\n");
	printf("adding the following data to the tail of the list: ");
	printCar(c);
	insertBack(mylist, c);
	printf("Checking if worked properly\n");
	printf("Printing data from the tail of the list: ");
	printCar(mylist->tail->data);
	if (mylist->tail->data == c)
	{
		printf("Node added to the tail of the list\nTest Passed\n");
	}
	else
	{
		printf("Node not added properly\nTest Failed");
	}
	printf("\n");

	printf("Test 2 for Function 'insertBack'\n");
	printf("adding the following data to the tail of the list: ");
	printf("%d\n", a->x);
	insertBack(mylist, a);
	printf("Checking if worked properly\n");
	printf("Printing data from the tail of the list: ");
	printf("%d\n", a->x);
	if (mylist->tail->data == a)
	{
		printf("Node added to the tail of the list\nTest Passed\n");
	}
	else
	{
		printf("Node not added properly\nTest Failed");
	}
	printf("\n");

	printf("Test 1 for Function 'getFromFront'\n");
	Node *temp = getFromFront(mylist);
	printf("Checking if worked properly\n");
	if (mylist->head == temp)
	{
		printf("Head node of the list retrieved successfully\nTest Passed\n");
	}
	else
	{
		printf("Node not retrieved properly\nTest Failed");
	}
	printf("\n");

	printf("Test 1 for Function 'getFromBack'\n");
	temp = getFromBack(mylist);
	printf("Checking if worked properly\n");
	if (mylist->tail == temp)
	{
		printf("Tail node of the list retrieved successfully\nTest Passed\n");
	}
	else
	{
		printf("Node not retrieved properly\nTest Failed");
	}
	printf("\n");

	printf("Test 1 for Function 'printForward'\n");
	printForward(mylist);
	printf("List printed forward successfully but the car struct format expected\nTest Failed\n");
	printf("\n");

	printf("Test 1 for Function 'printBackwards'\n");
	printBackwards(mylist);
	printf("List printed backwards successfully but the car struct format expected\nTest Failed\n");
	printf("\n");

	printf("Test 1 for Function 'compare'\n");
	Car *c2 = malloc(sizeof(Car));
	Car *c3 = malloc(sizeof(Car));
	c2->direction = 'W';
	c2->turn = 'L';
	c2->time_to = 9;
	c3->direction = 'W';
	c3->turn = 'L';
	c3->time_to = 9;
	y = compare(c, c2);
	printf("checking to see if worked properly\n");
	if (y > 0)
	{
		printf("Test Passed\n");
	}
	else
	{
		printf("Test Failed\n");
	}
	printf("\n");

	printf("Test 2 for Function 'compare'\n");
	y = compare(c3, c2);
	printf("checking to see if worked properly\n");
	if (y == 0)
	{
		printf("Test Passed\n");
	}
	else
	{
		printf("Test Failed\n");
	}
	printf("\n");

	printf("Test 1 for Function 'printNode'\n");
	printNode(c);
	printf("Node printed as expected\nTest Passed\n");
	printf("\n");

	printf("Test 1 for Function 'printNode'\n");
	printNode(c2);
	printf("Node printed as expected\nTest Passed\n");
	printf("\n");

	printf("Test for function 'deleteListNode'\n");
	temp = mylist->head;
	deleteListNode(mylist->head);
	printf("checking to see if worked properly\n");
	if (mylist->head != temp)
	{
		printf("Test Passed. Node Deleted\n");
	}
	else
	{
		printf("Test Failed\n");
	}

	printf("\n");

	printf("Testing the function 'deleteList'\n");
	deleteList(mylist);
	printf("Trying to print the list\n");
	printForward(mylist);
	printf("Memory Freed\n");
	printf("Test Passed\n");

	free(c);
	free(a);
	free(c2);
	free(c3);
	return 0;
}
