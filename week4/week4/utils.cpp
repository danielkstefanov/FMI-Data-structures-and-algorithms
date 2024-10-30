#include "utils.h"


SinglyLinkedList::SinglyLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void SinglyLinkedList::insert_node(int node_data) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

    if (!this->head) {
        this->head = node;
    }
    else {
        this->tail->next = node;
    }

    this->tail = node;
}

SinglyLinkedListNode::SinglyLinkedListNode(int node_data) {
    this->data = node_data;
    this->next = nullptr;
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}


void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}