#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() : head(nullptr) {}
    void insertSorted(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr || head->data >= newNode->data) {
            newNode->next = head;
            if (head != nullptr) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;}
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;}
        std::cout << std::endl;
    }
};
int main() {
    DoublyLinkedList list;
    list.insertSorted(15);
    list.insertSorted(5);
    list.insertSorted(9);
    list.insertSorted(7);
    std::cout << "Sorted Doubly Linked List: ";
    list.display();

    return 0;
}
