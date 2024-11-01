#include "ListNode.h"

class Solution {
public:
	ListNode* middleNode(ListNode* head) {

		if (!head)
			return nullptr;

		ListNode* slowIter = head;
		ListNode* fastIter = head;

		while (fastIter) {
			if (fastIter->next == nullptr)
				return slowIter;

			fastIter = fastIter->next->next;
			slowIter = slowIter->next;
		}

		return slowIter;
	}
};