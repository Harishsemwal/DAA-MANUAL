/* Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts ( shifts - total number of times the array elements are shifted from their place) required for sorting the array. */

#include <iostream>
using namespace std;

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

        //insertion sort
        int i, j;
        for(i = 1; i < num; i++)
        {
            int temp = nums[i];
            for(j = i-1; j>=0 && temp < nums[j]; j--)
            {
                nums[j+1] = nums[j];
                count++;
            }
            nums[j+1] = temp;
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
