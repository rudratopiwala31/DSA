#include <iostream>
using namespace std;

class Node {
public:
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = NULL;
    }
};

class BrowserHistory {
    Node* top;

public:
    BrowserHistory() {
        top = NULL;
    }

    void visit(string page) {
        Node* newNode = new Node(page);

        newNode->next = top;
        top = newNode;

        cout << "Visited page = " << page << endl;
        cout << "Current page = " << top->page << endl;
    }

    void back() {
        if (top == NULL) {
            cout << "Error = No page history left!" << endl;
            return;
        }

        Node* temp = top;

        cout << "Going back from = " << top->page << endl;

        top = top->next;

        delete temp;

        if (top == NULL) {
            cout << "Current page = No previous page" << endl;
        }
        else {
            cout << "Current page = " << top->page << endl;
        }
    }
};

int main() {
    BrowserHistory browser;

    int choice;
    string page;

    do {
        cout << "\n Browser History " << endl;
        cout << "1. Visit Page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Exit" << endl;

        cout << "Enter choice = ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page name = ";
            cin >> page;

            browser.visit(page);
        }
        else if (choice == 2) {
            browser.back();
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