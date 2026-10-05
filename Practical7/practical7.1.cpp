#include <iostream>
using namespace std;

class Queue {
    int queue[100];
    int front;
    int rear;
    int size;

public:
    Queue(int n) {
        size = n;
        front = -1;
        rear = -1;
    }

    void join(int token) {
        if (rear == size - 1) {
            cout << "Error = Queue is Full!" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        queue[rear] = token;

        cout << "Joined token = " << token << endl;
        cout << "Current front token = " << queue[front] << endl;
    }

    void serve() {
        if (front == -1) {
            cout << "Error = Queue is Empty!" << endl;
            return;
        }

        cout << "Served token = " << queue[front] << endl;

        front++;

        if (front > rear) {
            front = -1;
            rear = -1;

            cout << "Current front = No token" << endl;
        }
        else {
            cout << "Current front token = " << queue[front] << endl;
        }
    }
};

int main() {
    int n;

    cout << "Enter maximum number of tokens = ";
    cin >> n;

    if (cin.fail() || n <= 0 || n > 100) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    Queue q(n);

    int choice;
    int token;

    while (true) {
        cout << "\n Government Token Counter " << endl;
        cout << "1. Join Queue" << endl;
        cout << "2. Serve Visitor" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter choice = ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            cout << "Enter token number = ";
            cin >> token;

            if (cin.fail()) {
                cout << "Invalid token number!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            q.join(token);
        }
        else if (choice == 2) {
            q.serve();
        }
        else if (choice == 3) {
            cout << "Program ended." << endl;
            break;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}