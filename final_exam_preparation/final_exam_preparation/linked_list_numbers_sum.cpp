#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node* next;
    int data;
};


class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

public:
    Node* head, * tail;
};

void solve(LinkedList& num1, LinkedList& num2) {

    Node* first_iter = num1.head;
    Node* second_iter = num2.head;

    int in_mind = 0;
    int output_len = 0;

    LinkedList result;

    while (first_iter && second_iter)
    {
        int current_digit = first_iter->data + second_iter->data + in_mind;
        in_mind = current_digit / 10;
        current_digit %= 10;

        result.add(current_digit);

        first_iter = first_iter->next;
        second_iter = second_iter->next;
        output_len++;
    }

    while (first_iter)
    {
        int current_digit = first_iter->data + in_mind;
        in_mind = current_digit / 10;
        current_digit %= 10;

        result.add(current_digit);

        first_iter = first_iter->next;
        output_len++;
    }

    while (second_iter)
    {
        int current_digit = second_iter->data + in_mind;
        in_mind = current_digit / 10;
        current_digit %= 10;

        result.add(current_digit);

        second_iter = second_iter->next;
        output_len++;
    }

    if (in_mind != 0)
    {
        result.add(in_mind);
        output_len++;
    }


    vector<int> output(output_len, ' ');
    
    Node* result_iter = result.head;

    for (int i = output_len-1; i >= 0; i--)
    {
        output[i] = result_iter->data;
        result_iter = result_iter->next;
    }

    for (size_t i = 0; i < output_len; i++)
    {
        cout << output[i];
    }
}

void linked_list_sum() {
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for (int i = 0; i < size2; i++) {
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}