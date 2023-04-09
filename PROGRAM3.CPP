/* Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],. ,arr[2k] and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching):
Jump Search */

#include <iostream>
#include <math.h>
using namespace std;

int JumpSearch(int arr[], int num, int search)
{
    int start = 0;
    int end = sqrt(num);
    int count = 0;

    while(arr[start] < search && start < num)
    {
        start = end;
        end = end + sqrt(num);

        if(end >= num - 1)
        {
            end = num;
        }
        count++;
    }

    for(int i = 0; i < end; i++)
    {
        if(arr[i] == search)
        {
            return count;
        }
        count++;
    }

    return -1;
}

int main()
{
    bool flag = false;
    int search, num, arr[20];
    cout << "Enter the number of element: ";
    cin >> num;

    cout << "Enter the nonnegative integers: ";
    for(int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the search element: ";
    cin >> search;

    int ans = JumpSearch(arr, num, search);

    if(ans == -1)
    {
        cout << "element is not found...";
    }
    else
    {
        cout << "Congratulation..." << endl;
        cout << "element is found after " << ans << " number of comparesions..." << endl;
    }

    return 0;
}
