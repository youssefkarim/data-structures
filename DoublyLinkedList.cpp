//
// Created by Dr. Ahmed Said on 07/03/2025.
//
#include <iostream>

typedef int ElementType;

class Node {
public:
    Node() {
        next = nullptr;
        prev = nullptr;
    };
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
  DoublyList() {
    head = nullptr;
    tail = nullptr;
    counter = 0;
  }
    void MakeNull();
    Position First();
    Position End();

    Position Next(Position p);
    Position Previous(Position p);

    void InsertAtEnd(ElementType x);
    void InsertAtStart(ElementType x);
    void InsertAt(ElementType x, Position p);
    void InsertAfter(ElementType x, Position p);
    void InsertBefore(ElementType x, Position p);

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
    Position newNode = new Node();
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
    Position newNode = new Node();
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

// This method insert node after p
void DoublyList::InsertAt(ElementType x, Position p = nullptr) {
    if(p == nullptr) {
        InsertAtEnd(x);
    }
    else if(p == head) {
        InsertAtStart(x);
    }
    else {
        Position newNode = new Node();
        newNode->data = x;
        newNode->prev = p->prev;
        newNode->next = p;
        if(p->prev != nullptr) {
            p->prev->next = newNode;
        }
        p->prev = newNode;

        counter++;
    }
}

void DoublyList::InsertAfter(ElementType x, Position p) {
    if(p == nullptr) {
        InsertAtEnd(x);
    }
    else if(p == head) {
        InsertAtStart(x);
    }
    else {
        Position newNode = new Node();
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

void DoublyList::InsertBefore(ElementType x, Position p) {
    InsertAt(x, p);
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
    return NULL;
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
  Position n10 = list.Locate(10);
  list.Delete(n10);
  Position n20 = list.Locate(20);
  list.Delete(n20);
  list.PrintList();
  return 0;
}

//calculates the summation of all values in the list.
ElementType Sum(DoublyList L)
{
    Position curr=L.First();
    ElementType s=0;
    while(curr!=NULL)
    {
        ElementType x=L.Retrieve(curr);
        s=s+x;
        curr=L.Next(curr);
    }
    return s;
}

DoublyList Reverse(DoublyList l1)
{
    DoublyList l2;
    Position pos=l1.First();
    while (pos!=NULL)
    {
        int x=l1.Retrieve(pos);
        l2.InsertAt(x,l2.First());
        pos=l1.Next(pos);
    }
    return l2;
}

//splits the linked to two lists, one for odd numbers and one for even numbers
void Split(DoublyList L, DoublyList& lOdd, DoublyList& lEven)
{
    Position curr=L.First();
    //while(curr!=L.END())
    while(curr!=NULL)
    {
        int x=L.Retrieve(curr);
        if (x%2==0)
            lEven.InsertAt(x);
        else
            lOdd.InsertAt(x);

        curr=L.Next(curr);
    }
}

