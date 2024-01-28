#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Singly
{
    Node *start;

public:
    Singly()
    {
        start = NULL;
    }
    void insertAtFirst(int);
    void insertAtEnd(int);
    Node *search(int);
    void insertAfter(Node *, int);
    void display();
    void deleteAtFirst();
    void deleteAtLast();
    void deleteNode(int);
    void input();
    ~Singly();
};