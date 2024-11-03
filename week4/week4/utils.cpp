#include "utils.h"
#include <iostream>

void printList(ListNode* head)
{
	if (!head)
		return;

	while (head)
	{
		std::cout << head->val << "->";
		head = head->next;

	}
}

void printList(Node* head)
{
	if (!head)
		return;

	while (head)
	{
		std::cout << head->val << " <-> ";
		head = head->next;

	}
}
