#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void display()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void insertFront(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertEnd(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertPosition(int value, int pos)
{
    if (pos == 1)
    {
        insertFront(value);
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    insertFront(10);
    cout << "After front insertion: ";
    display();

    insertEnd(20);
    cout << "After end insertion: ";
    display();

    insertPosition(15, 2);
    cout << "After position insertion: ";
    display();

    return 0;
}
