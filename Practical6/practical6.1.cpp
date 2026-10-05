#include <iostream>
using namespace std;

class Stack {
    int stack[100];
    int top;
    int size;

public:
    Stack(int n) {
        size = n;
        top = -1;
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Error = Stack is Full!" << endl;
            return;
        }

        top++;
        stack[top] = value;

        cout << "Placed tray = " << value << endl;
        cout << "Current top tray = " << stack[top] << endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Error = Stack is Empty!" << endl;
            return;
        }

        cout << "Taken tray = " << stack[top] << endl;
        top--;

        if (top == -1) {
            cout << "Current top = No tray" << endl;
        }
        else {
            cout << "Current top tray = " << stack[top] << endl;
        }
    }
};

int main() {
    int n;

    cout << "Enter maximum number of trays = ";
    cin >> n;

    Stack s(n);

    int choice;
    int value;

    do {
        cout << "\n Cafeteria Tray Stack " << endl;
        cout << "1. Place Tray" << endl;
        cout << "2. Take Tray" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter choice = ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter tray number = ";
            cin >> value;

            s.push(value);
        }
        else if (choice == 2) {
            s.pop();
        }
        else if (choice == 3) {
            cout << "Program ended." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 3);

    return 0;
}