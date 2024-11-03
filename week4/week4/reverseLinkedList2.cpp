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

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head)
            return nullptr;

        if (head->next == nullptr || left == right)
            return head;

        ListNode* toReturn = left == 1 ? nullptr : head;

        for (int i = 0; i < left - 2; i++)
            head = head->next;

        ListNode* saveStart = left == 1 ? nullptr : head;
        ListNode* reversedEnd = left == 1 ? head : head->next;

        int toRemove = 0;
        if (left == 1)
            toRemove = 1;

        for (int i = 0; i <= right - left - toRemove; i++)
            head = head->next;

        ListNode* saveEnd = head ? head->next : nullptr;

        if (head != nullptr)
            head->next = nullptr;

        ListNode* reversedStart = reverseList(reversedEnd);

        reversedEnd->next = saveEnd;

        if (!saveStart)
            return reversedStart;

        saveStart->next = reversedStart;

        return toReturn == nullptr ? reversedStart : toReturn;
    }
};