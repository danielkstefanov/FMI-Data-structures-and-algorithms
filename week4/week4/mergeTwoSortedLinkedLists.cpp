#include <string>
#include <fstream>
#include <iostream>
#include "utils.h"

using namespace std;

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {


    if (!head1)
        return head2;

    if (!head2)
        return head1;

    SinglyLinkedListNode* toReturn = nullptr;
    SinglyLinkedListNode* answer = nullptr;


    if (head1->data <= head2->data)
    {
        toReturn = head1;
        head1 = head1->next;
    }
    else
    {
        toReturn = head2;
        head2 = head2->next;
    }

    answer = toReturn;


    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data <= head2->data)
        {
            answer->next = head1;
            head1 = head1->next;
        }
        else
        {
            answer->next = head2;
            head2 = head2->next;
        }

        answer = answer->next;
    }

    if (!head1)
        answer->next = head2;

    if (!head2)
        answer->next = head1;

    return toReturn;
}

void mergeTwoSortedLinkedLists() 
{
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }

        SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ");
        cout << "\n";

        free_singly_linked_list(llist3);
    }
}