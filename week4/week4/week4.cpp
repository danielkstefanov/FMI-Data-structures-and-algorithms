#include <iostream>
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}

};
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


void printList(ListNode* head)
{
	if (!head)
		return;

	while (head)
	{
		std::cout << head->val;
		head = head->next;

	}
}
int main()
{
	/*ListNode* three = new ListNode(3);
	ListNode* one = new ListNode(1,three);
	ListNode* two = new ListNode(2,one);
	ListNode* forth = new ListNode(4,two);*/

	ListNode* zero = new ListNode(0);
	ListNode* fourht = new ListNode(4, zero);
	ListNode* three = new ListNode(3, fourht);
	ListNode* five = new ListNode(5, three);
	ListNode* negone = new ListNode(-1, five);
	printList(insertionSortList(negone));
}