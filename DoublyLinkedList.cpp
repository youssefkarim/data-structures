//
// Created by Dr. Ahmed Said on 07/03/2025.
//
#include <iostream>

typedef int ElementType;

class Node {
public:
    ElementType data;
    Node* next;
    Node* prev;
};

typedef Node* Position;


class DoublyList {
private:
    Position head; //points to the first node
    Position tail;   //points to the last node
    int counter;
public:
    void MakeNull();
    Position First();
    Position Next(Position p);
    Position Previous(Position p);
    Position End();
    void InsertAtEnd(ElementType x);
    void InsertAtStart(ElementType x);
    void InsertAt(ElementType x, Position p);
    void Delete(Position p);
    Position Locate(int x);
    ElementType Retrieve(Position p);
    void PrintList();
};

void DoublyList::MakeNull() {
    head = nullptr;
    tail = nullptr;
    counter = 0;
    // need to add codes to free (delete) nodes memory allocation
}

Position DoublyList::First() {
    return head;
}

Position DoublyList::Next(Position p) {
    if(p == nullptr) {
        return nullptr;
    }
    return p->next;
}

Position DoublyList::Previous(Position p) {
    if(p == nullptr) {
        return nullptr;
    }
    return p->prev;
}

Position DoublyList::End() {
    return tail;
}

void DoublyList::InsertAtStart(ElementType x) {
    Position newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    newNode->prev = nullptr;

    if(head != nullptr) {
        head->prev = newNode;
    }

    head = newNode;

    if(tail == nullptr) {
        tail = head;
    }
    counter++;
}

void DoublyList::InsertAtEnd(ElementType x) {
    Position newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = tail;

    if(tail != nullptr) {
        tail->next = newNode;
    }

    tail = newNode;

    if(head == nullptr) {
        head = tail;
    }
    counter++;
}

void DoublyList::InsertAt(ElementType x, Position p = nullptr) {
    if(p == nullptr) {
        InsertAtEnd(x);
    }
    else if(p == head) {
        InsertAtStart(x);
    }
    else {
        Position newNode = new Node;
        newNode->data = x;
        newNode->next = p->next;
        newNode->prev = p;

        if(p->next != nullptr) {
            p->next->prev = newNode;
        }
        p->next = newNode;

        if(p == tail) {
            tail = newNode;
        }
        counter++;
    }
}

void DoublyList::Delete(Position p) {
  if(p == nullptr) {
    // No Element to Delete
    return;
  }
  if(p == tail) {
    tail = p->prev;
  }
  if(p == head) {
    head = p->next;
  }

  Position temp = p;
  if(p->prev != nullptr) {
    p->prev->next = p->next;
  }
  if(p->next != nullptr) {
    p->next->prev = p->prev;
  }

  delete temp;
  counter--;
}

Position DoublyList::Locate(ElementType x) {
  Position p = head;
  while(p != nullptr) {
    if(p->data == x)
      return p;

    p = p->next;
  }
  return nullptr;
}

ElementType DoublyList::Retrieve(Position p) {
  if(p == nullptr) {
    return nullptr;
  }
  return p->data;
}

void DoublyList::PrintList() {
  Position p = head;
  while(p != nullptr) {
    std::cout << p->data << " -> ";
    p = p->next;
  }
}

int main() {
  DoublyList list;
  list.InsertAtStart(1);
  list.InsertAtStart(2);
  list.InsertAtStart(3);
  list.InsertAtStart(4);
  list.InsertAt(10, list.End());
  list.InsertAt(-30, list.First());
  list.InsertAt(-10, list.First());
  list.InsertAt(20, list.End());
  list.PrintList();
}