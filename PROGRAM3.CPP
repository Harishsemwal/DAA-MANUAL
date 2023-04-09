/* I. Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not. (use sorting) (Time Complexity = O(n log n)) */

#include <bits/stdc++.h>
using namespace std;

void merge(int nums[], int start, int end)
{
    int mid = (start + end)/2;

    int len1 = mid - start + 1;
    int len2 = end - start;

    int *first = new int[len1];
    int *second = new int[len2];

    int maxIndex = start;
    for(int i = 0; i < len1; i++)
    {
        first[i] = nums[maxIndex++];
    }

    maxIndex = mid + 1;
    for(int i = 0; i < len2; i++)
    {
        second[i] = nums[maxIndex++];
    }

    int index1 = 0;
    int index2 = 0;
    maxIndex = start;

    while(index1 < len1 && index2 < len2)
    {
        if(first[index1] < second[index2])
        {
            nums[maxIndex++] = first[index1++];
        }
        else
        {
            nums[maxIndex++] = second[index2++];
        }
    }

    while(index1 < len1)
    {
        nums[maxIndex++] = first[index1++];
    }

    while(index2 < len2)
    {
        nums[maxIndex++] = second[index2++];
    }

    delete [] first;
    delete [] second;
}

void mergeSort(int nums[], int start, int end)
{
    if(start >= end)
    {
        return;
    }
    int mid = (start + end)/2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid+1, end);

    merge(nums, start, end);
}

int main()
{
    bool flag = false;
    int testcase, count = 0;
    int num, nums[20], container[20];

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

        mergeSort(nums, 0, num);
        
        for(int i = 0; i < num - 1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                flag = true;
            }
        }

        if(flag == true)
        {
            cout << "Duplicate element is Present...";
        }
        else
        {
            cout << "Duplicate element is not Present...";
        }
    }

    return 0;
}