/* Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(logn), where n is the size of input). */

#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key)
{
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            result = mid;
            break;
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
    bool flag = false;
    int count = 0, search, num, arr[20];
    cout << "Enter the number of element: ";
    cin >> num;

    cout << "Enter the nonnegative integers: ";
    for(int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the search element: ";
    cin >> search;
    int ans = binarySearch(arr, 0, num-1, search);
    
    if(ans == -1)
    {
        cout << "element is not present...";
    }
    else
    {
        cout << "Congratulation..." << endl;
        cout << "element is found after " << count << " number of comparesions..." << endl;
    }

    return 0;
}
