#include <iostream>
using namespace std;

int main()
{
    int q[100], n = 0;

    
    q[n++] = 10;

  
    for (int i = n; i > 0; i--)
        q[i] = q[i - 1];

    q[0] = 5;
    n++;

    cout << "After front insertion: ";
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    cout << endl;


    q[n++] = 20;

    cout << "After end insertion: ";
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    cout << endl;


    int pos = 2;

    if (pos >= 0 && pos <= n)
    {
        for (int i = n; i > pos; i--)
            q[i] = q[i - 1];

        q[pos] = 15;
        n++;
    }
    else
    {
        cout << "Invalid position!" << endl;
    }

    cout << "After position insertion: ";
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    cout << endl;


    cout << "Final Queue: ";

    for (int i = 0; i < n; i++)
        cout << q[i] << " ";

    return 0;
}