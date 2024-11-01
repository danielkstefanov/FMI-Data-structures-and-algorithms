#include "ListNode.h"

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head)
			return nullptr;

		ListNode* toReturn = head;
		ListNode* insertPosition = head;

		ListNode* lastSortedNode = head;
		ListNode* currentNodeToInsert = head->next;

		while (currentNodeToInsert) {

			lastSortedNode->next = currentNodeToInsert->next;

			if (currentNodeToInsert->val <= toReturn->val) {
				currentNodeToInsert->next = toReturn;
				toReturn = currentNodeToInsert;
			}
			else {
				while (insertPosition->next && insertPosition->next != currentNodeToInsert->next) {

					if (insertPosition->next->val >= currentNodeToInsert->val) {
						currentNodeToInsert->next = insertPosition->next;
						insertPosition->next = currentNodeToInsert;

						break;
					}

					insertPosition = insertPosition->next;
				}
			}

			if (insertPosition->next == currentNodeToInsert->next)
			{
				insertPosition->next = currentNodeToInsert;
				lastSortedNode = lastSortedNode->next;
			}

			if (!insertPosition) {
				currentNodeToInsert->next = nullptr;
				insertPosition->next = currentNodeToInsert;
			}

			insertPosition = toReturn;
			currentNodeToInsert = lastSortedNode->next;
		}

		return toReturn;
	}
};