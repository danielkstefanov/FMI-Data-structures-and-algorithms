#include <vector>

#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;

        if (!list2)
            return list1;

        ListNode* head = nullptr;
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }

        ListNode* toReturn = head;

        while (list1 && list2) {
            ListNode* toSave = nullptr;

            if (list1->val <= list2->val) {
                toSave = list1->next;
                head->next = list1;
                list1 = toSave;
            }
            else {
                toSave = list2->next;
                head->next = list2;
                list2 = toSave;
            }
            head = head->next;
        }

        if (!list1)
            head->next = list2;

        if (!list2)
            head->next = list1;

        return toReturn;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;

        ListNode* answer = lists[0];
        for (int i = 1; i < lists.size(); i++)
            answer = mergeTwoLists(answer, lists[i]);

        return answer;
    }
};