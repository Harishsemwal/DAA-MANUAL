/* I. Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and implement it using a program to find which alphabet has maximum number of occurrences and print it. (Time Complexity = O(n)) (Hint: Use counting sort) */
#include <iostream>
using namespace std;

void countingSort(int arr[], int num)
{
    int maxi = -1;
    for(int i = 0; i < num; i++)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }

    cout <<"maxi: " << maxi << endl;

    int count[maxi];
    int postion[num];
    int output[num];

    for(int i = 0; i < maxi; i++)
    {
        count[i] = 0;
    }

    for(int i = 0; i < num; i++)
    {
        count[arr[i]]++;
    }

    for(int i = 1; i < num; i++)
    {
        count[i] = count[i] + count[i-1];
    }
    for(int i = 0; i < num; i++)
    {
        output[--postion[arr[i]]] = arr[i];
    }

    for(int i = 0; i < num ;i++)
    {
        arr[i] = count[i];
    }

}

int main()
{
    int testcase, count = 0;
    int num, nums[20];

    cout << "Enter the total number of testcase: ";
    cin >> testcase;

    while(testcase--)
    {
        cout << "Enter the number of element: ";
        cin >> num;

        cout << "Enter the elements: ";
        for(int i = 0; i < num; i++)
        {
            cin >> nums[i];
        }

        countingSort(nums, num);

        cout << "the sorted elements is: " << endl;
        for(int i = 0; i < num; i++)
        {
            cout << nums[i] << " ";
        }
    }
}