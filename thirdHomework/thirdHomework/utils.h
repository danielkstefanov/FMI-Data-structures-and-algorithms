#pragma once
#include <string>
#include <iostream>

using namespace std;



class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data);
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList();

    void insert_node(int node_data);
};


void print_singly_linked_list(SinglyLinkedListNode* node, string sep);
void free_singly_linked_list(SinglyLinkedListNode* node);