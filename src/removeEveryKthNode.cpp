/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head == NULL || K <= 1)
	{
		return NULL;
	}
	int count = 2;
	struct node *temp;
	temp = head;
	while (temp->next != NULL)
	{
		if (K == count)
		{
			if ((temp->next)->next!= NULL)
			{

				temp->next = (temp->next)->next;
				temp = temp->next;
				count = 2;
			}
			else
			{
				temp->next = NULL;
			}
		}
		else
		{
			count++;
			temp = temp->next;
		}
	}
	return head;
}