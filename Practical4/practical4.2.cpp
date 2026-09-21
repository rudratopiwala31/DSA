#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

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

void deleteValue(int value)
{
    if (head == NULL)
        return;

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->next->data == value)
        {
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
            return;
        }

        temp = temp->next;
    }
}

void forward()
{
    Node *temp = head;

    cout << "Front to Back: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void reverse(Node *temp)
{
    if (temp == NULL)
        return;

    reverse(temp->next);
    cout << temp->data << " ";
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    cout << "Original Queue: ";
    forward();

    deleteValue(20);

    cout << "After deleting 20: ";
    forward();

    cout << "Back to Front: ";
    reverse(head);

    return 0;
}
