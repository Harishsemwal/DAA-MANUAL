/* Given an array of nonnegative integers, design a linear algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(n), where n is the size of input). */

#include <iostream>
using namespace std;

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

    for(int i = 0; i < num; i++)
    {
        if(arr[i] == search)
        {
            flag = true;
        }
        count++;
    }

    if(flag == false)
    {
        cout << "element is not found...";
    }
    else
    {
        cout << "Congratulation..." << endl;
        cout << "element is found after " << count << " number of comparesions..." << endl;
    }

    return 0;
}

