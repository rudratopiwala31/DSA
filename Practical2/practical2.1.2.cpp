#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int target, int i)
{
    if(i == n)
    {
        cout << "Not Found";
        return;
    }

    if(arr[i] == target)
    {
        cout << "Found at position " << i + 1;
        return;
    }

    linearSearch(arr, n, target, i + 1);
}

int main()
{
    int n, target;

    cout << "Enter number of vehicles = ";
    cin >> n;

    int arr[100];

    cout << "Enter vehicle numbers = ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter vehicle to search = ";
    cin >> target;

    linearSearch(arr, n, target, 0);

    return 0;
}
