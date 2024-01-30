#include "single.h"

void Singly ::insertAtFirst(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->next = start;
    start = temp;
}

void Singly ::insertAtEnd(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
        return;
    }
    else
    {
        Node *tem = start;
        while (tem->next != NULL)
        {
            tem = tem->next;
        }
        tem->next = temp;
    }
}

void Singly::display()
{
    Node *temp = start;
    if (start == NULL)
    {
        cout << "List is empty " << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

Node* Singly ::search(int value)
{
    Node *temp = start;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void Singly::insertAfter(Node *temp, int data)
{
    Node *n;
    if (temp != NULL)
    {
        n = new Node;
        n->data = data;
        n->next = temp->next;
        temp->next = n;
    }
}
void Singly ::deleteAtFirst()
{
    Node *temp = start;
    if (start == NULL)
    {
        cout << "List is empty " << endl;
    }
    else
    {
        start = start->next;
        delete temp;
    }
}

void Singly ::deleteAtLast()
{
    Node *temp = start;
    if (start == NULL)
    {
        cout << "List is empty " << endl;
    }
    else if (start->next == NULL)
    {
        delete start;
        start = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {

            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

// void Singly ::deleteAtMiddle()
// {
//     Node *temp = start;
//     if (start == NULL)
//     {
//         cout << "List is empty " << endl;
//         return;
//     }
//     if (start->next == NULL)
//     {
//         delete start;
//         start = NULL;
//         return;
//     }

//     Node *fast_ptr = start;
//     Node *slow_ptr = start;

//     Node *prev;

//     while (fast_ptr != NULL && fast_ptr->next != NULL)
//     {
//         fast_ptr = fast_ptr->next->next;
//         prev = slow_ptr;
//         slow_ptr = slow_ptr->next;
//     }

//     prev->next = slow_ptr->next;
//     delete slow_ptr;
//     slow_ptr = NULL;
// }

void Singly::deleteNode(int data)
{

    Node *t, *temp;
    if (start)
    {
        t = start;
        if (t->data == data)
        {
            start = start->next;
            delete t;
        }
        else
        {
            while (t->next != NULL)
            {
                if (t->next->data == data)
                {
                    temp = t->next;
                    t->next = temp->next;
                    delete temp;
                    break;
                }
                t = t->next;
            }
        }
    }
}

Singly::~Singly()
{
    while (start)
        deleteAtFirst();
}

void Singly ::input()
{
    while (1)
    {
        cout << "1.Insert at first : "
             << "\n2.Insert at end : "
             << "\n3.Delete at first : " << endl;
        cout << "4.Delete at last : "
             << "\n5.Delete  specific :"
             << "\n6.Display\n7.Insert after\n";
        int choice;
        cout << "Enter your choice : " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int num;
            cout << "Enter data : ";
            cin >> num;
            insertAtFirst(num);
            break;
        case 2:
            int num1;
            cout << "Enter data : ";
            cin >> num1;
            insertAtEnd(num1);
            break;

        case 3:
            deleteAtFirst();
            break;

        case 4:
            deleteAtLast();
            break;

        case 5:
            int num2;
            cout << "Enter data : ";
            cin >> num2;
            deleteNode(num2);
            break;

        case 6:
            display();
            break;

        case 7:
            int num3,num4;
            cout << "Enter after value : ";
            cin >> num3;
            cout << "Enter value : ";
            cin >> num4;
            insertAfter(search(num3),num4);
            break;
        default:
            cout << "Invalid choice ";
            break;
        }
    }
}