#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() : head(nullptr) {}
   void insertSorted(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr || head->data >= newNode->data) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;}
            std::cout << std::endl;}
};

int main() {
    SinglyLinkedList list;
    list.insertSorted(5);
    list.insertSorted(3);
    list.insertSorted(8);
    list.insertSorted(1);
    std::cout << "Sorted Singly Linked List: ";
    list.display();

    return 0;
}
