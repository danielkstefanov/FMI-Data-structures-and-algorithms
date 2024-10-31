#include <string>
#include <fstream>
#include <iostream>
#include "utils.h"

using namespace std;

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);

    if (llist == nullptr)
        return node;

    SinglyLinkedListNode* toReturn = llist;

    for (int i = 0; i < position-1; i++)
        llist = llist->next;

    SinglyLinkedListNode* toSave = llist->next;
    llist->next = node;
    node->next = toSave;

    return toReturn;
}

void insertNodeOnPositionInput(){
    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }

    int data;
    cin >> data;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int position;
    cin >> position;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    SinglyLinkedListNode* llist_head = insertNodeAtPosition(llist->head, data, position);

    print_singly_linked_list(llist_head, " ");
    cout << "\n";

    free_singly_linked_list(llist_head);
}