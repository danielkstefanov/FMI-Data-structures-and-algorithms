#include "Node.h"

Node* flatten(Node* head) {
	if (!head)
		return nullptr;

	Node* toReturn = head;

	while (head) {
		if (head->child) {
			Node* toSave = head->next;

			Node* newHead = flatten(head->child);
			head->next = newHead;
			newHead->prev = head;

			while (newHead->next)
				newHead = newHead->next;

			newHead->next = toSave;

			if (toSave)
				toSave->prev = newHead;

			head->child = nullptr;
		}

		head = head->next;
	}

	return toReturn;
}
