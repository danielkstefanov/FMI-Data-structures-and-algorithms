#include <string>
#include <fstream>
#include <iostream>
#include "utils.h"

using namespace std;


bool areThereNextKNodes(SinglyLinkedListNode* head, int k)
{
    for (size_t i = 0; i < k; i++)
    {
        if (head == nullptr)
            return false;
        else
            head = head->next;
    }

    return true;
}

pair<SinglyLinkedListNode*, SinglyLinkedListNode*> reverseFirstKNodes(SinglyLinkedListNode*& head, int k) {
    if (head == nullptr || k <= 0)
        return { nullptr, nullptr };

    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* curr = head;
    SinglyLinkedListNode* next = nullptr;
    SinglyLinkedListNode* last_node_of_reversed_sublist = head;

    int i = 0;
    while (curr != nullptr && i < k) {
        next = curr->next;   
        curr->next = prev;       
        prev = curr;         
        curr = next;
        i++;
    }

    last_node_of_reversed_sublist->next = curr;
    head = prev;
    return { head, last_node_of_reversed_sublist };
}

SinglyLinkedListNode* getKPlusOneNode(SinglyLinkedListNode* head, int k) {

    if (k < 0)
        return nullptr;

    SinglyLinkedListNode* current = head;
    int index = 0;

    while (current != nullptr && index < k) {
        current = current->next;
        index++;
    }

    return current;
}

SinglyLinkedListNode* reverseByGroupLen(SinglyLinkedListNode* head, int k) 
{
    SinglyLinkedListNode* toReturn = nullptr;
    bool isFound = false;

    
    SinglyLinkedListNode* saved = nullptr;

    while (areThereNextKNodes(head,k))
    {   
        pair<SinglyLinkedListNode*, SinglyLinkedListNode*> answer = reverseFirstKNodes(head, k);

        if (saved)
            saved->next = answer.first;

        if (!isFound)
            toReturn = answer.first;

        isFound = true;
        saved = answer.second;
        head = answer.second->next;
    }

    if (!isFound)
        return head;

    return toReturn;

}

int main()
{
    int len;
    cin >> len;
    
    SinglyLinkedList* llist = new SinglyLinkedList();
    
    for (int tests_itr = 0; tests_itr < len; tests_itr++) 
    {
        int current;
        cin >> current;

        llist->insert_node(current);
    }
    
    int k;
    cin >> k;
    
    SinglyLinkedListNode* res = reverseByGroupLen(llist->head,k);
    print_singly_linked_list(res, " ");
    free_singly_linked_list(res);
}