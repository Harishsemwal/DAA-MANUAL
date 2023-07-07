// Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or not. If present, then also find the number of copies of given key. (Time Complexity = O(log n)).

#include <iostream>
using namespace std;

int binarySearchFirst(int arr[], int low, int high, int key)
{
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            result = mid;
            high = mid - 1;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

int binarySearchLast(int arr[], int low, int high, int key)
{
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            result = mid;
            low = mid + 1;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}

int main()
{
    int n, key;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the key element: ";
    cin >> key;
    int first = binarySearchFirst(arr, 0, n - 1, key);
    if (first == -1)
    {
        cout << "Key element not found in the array" << endl;
    }
    else
    {
        int last = binarySearchLast(arr, 0, n - 1, key);
        int count = last - first + 1;
        cout << "Key element found " << count << " times in the array" << endl;
    }
    return 0;
}
