#include <iostream>
using namespace std;

class Node {
public:
    string patient;
    Node* next;

    Node(string p) {
        patient = p;
        next = NULL;
    }
};

class PatientQueue {
    Node* front;
    Node* rear;

public:
    PatientQueue() {
        front = NULL;
        rear = NULL;
    }

    void arrive(string patient) {
        Node* newNode = new Node(patient);

        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Patient arrived = " << patient << endl;
        cout << "Current front patient = " << front->patient << endl;
    }

    void attend() {
        if (front == NULL) {
            cout << "Error = Queue is Empty!" << endl;
            return;
        }

        Node* temp = front;

        cout << "Attended patient = " << front->patient << endl;

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;

        if (front == NULL) {
            cout << "Current front = No patient" << endl;
        }
        else {
            cout << "Current front patient = " << front->patient << endl;
        }
    }
};

int main() {

    PatientQueue q;

    int choice;
    string patient;

    while (true) {

        cout << endl;
        cout << " Hospital Emergency Queue " << endl;
        cout << "1. Patient Arrive" << endl;
        cout << "2. Attend Patient" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice = ";

        if (!(cin >> choice)) {
            cout << "Input error. Program ended." << endl;
            return 0;
        }

        if (choice == 1) {

            cout << "Enter patient name = ";

            if (!(cin >> patient)) {
                cout << "Input error. Program ended." << endl;
                return 0;
            }

            q.arrive(patient);
        }

        else if (choice == 2) {

            q.attend();
        }

        else if (choice == 3) {

            cout << "Program ended." << endl;
            return 0;
        }

        else {

            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}