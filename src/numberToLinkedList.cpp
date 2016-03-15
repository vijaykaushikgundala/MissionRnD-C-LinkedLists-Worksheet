
/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
int reverse(int n)
{
	int i = n, rem, y = 0;
	while (i > 0)
	{
		rem = i % 10;
		y = y * 10 + rem;
		i = i / 10;
	}
	return y;
}
struct node * numberToLinkedList(int N)
{
	struct node *temp, *start;
	temp = (struct node *)malloc(sizeof(struct node));
	int x = N, rem;
	if (x < 0)
	{
		x = x*-1;
	}
	x = reverse(x);
	rem = x % 10;
	x = x / 10;
	temp->num = rem;
	temp->next = NULL;
	start = temp;
	while (x>0)
	{
		rem = x % 10;
		struct node *newnode = (struct node *)malloc(sizeof(struct node));

		temp->next = newnode;
		newnode->num = rem;
		newnode->next = NULL;
		temp = newnode;
		x = x / 10;
	}
	return start;
}
