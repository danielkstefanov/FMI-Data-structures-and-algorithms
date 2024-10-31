#include <string>
#include <fstream>
#include <iostream>
#include "utils.h"


using namespace std;

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) 
{
	SinglyLinkedListNode* toReturn = llist;

	while (llist != nullptr && llist->next != nullptr)
	{
		if (llist->data == llist->next->data)
		{
			SinglyLinkedListNode* toDelete = llist->next;
			llist->next = toDelete->next;
			delete toDelete;
		}
		else 
		{
			llist = llist->next;
		}
	}

	return toReturn;
}

void removeDuplicates(){
	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		SinglyLinkedList* llist = new SinglyLinkedList();

		int llist_count;
		cin >> llist_count;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < llist_count; i++) {
			int llist_item;
			cin >> llist_item;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			llist->insert_node(llist_item);
		}

		SinglyLinkedListNode* llist1 = removeDuplicates(llist->head);

		print_singly_linked_list(llist1, " ");
		cout << "\n";

		free_singly_linked_list(llist1);
	}
}
