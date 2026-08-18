#include <iostream>
using namespace std;

void binarySearch(int arr[], int low, int high, int target)
{
    if(low > high)
    {
        cout << "Not Found";
        return;
    }

    int mid = (low + high) / 2;

    if(arr[mid] == target)
    {
        cout << "Found at position " << mid + 1;
        return;
    }

    if(target < arr[mid])
    {
        binarySearch(arr, low, mid - 1, target);
    }
    else
    {
        binarySearch(arr, mid + 1, high, target);
    }
}

int main()
{
    int n, target;

    cout << "Enter number of books = ";
    cin >> n;

    int arr[100];

    cout << "Enter book codes in sorted order = ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter book code to search = ";
    cin >> target;

    binarySearch(arr, 0, n - 1, target);

    return 0;
}
