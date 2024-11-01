#include "ListNode.h"

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {

		if (!head)
			return nullptr;

		ListNode* toReturn = head;
		ListNode* currentNode = head;
		ListNode* nextNode = head->next;

		while (nextNode) {
			if (nextNode->val == val) {
				ListNode* toDelete = nextNode;
				currentNode->next = nextNode->next;
				nextNode = nextNode->next;
				if (nextNode)
					delete toDelete;
				else
					break;
			}
			else {
				currentNode = currentNode->next;
				nextNode = nextNode->next;
			}
		}

		if (toReturn->val == val)
			return toReturn->next;

		return toReturn;
	}
};