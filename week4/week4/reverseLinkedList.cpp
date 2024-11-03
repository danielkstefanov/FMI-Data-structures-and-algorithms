#include "ListNode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = head->next;

        while (next != nullptr) {
            ListNode* toSave = next->next;

            current->next = prev;
            next->next = current;

            prev = current;
            current = next;
            next = toSave;
        }

        return current;
    }
};