/* Given an unsorted array of integers, design an algorithm and implement a program to sort this array using selection sort. Your program should also find number of comparisons and number of swaps required. */

#include <iostream>
using namespace std;

int selectionSort(int nums[], int num, int index)
{
    int smallIndex = index;
    int mini = nums[index];

    for(int i = index + 1; i < num ; i++)
    {
        if(mini > nums[i])
        {
            mini = nums[i];
            smallIndex = i;
        }
    }
    return smallIndex;
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

        //Selection sort
        for(int i = 0; i < num; i++)
        {
            int ans = selectionSort(nums, num, i);
            swap(nums[i], nums[ans]);
        }

        cout << "The elements will be sorted after ("<< count <<") number of comparisions..." << endl;
        cout << "Sorted elements is: " << endl;
        for(int i = 0; i < num; i++)
        {
            cout << nums[i] << " ";
        }

        return 0;
    }
}
