// Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by dividing the array into two subarrays and combining these subarrays after  sorting each one of them. Your program should also find number of comparisons and inversions during sorting the array. */
#include <bits/stdc++.h>
using namespace std;

void merge(int nums[], int start, int end, int compare[])
{
    static int countCompare;
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
            countCompare++;
        }
        else
        {
            nums[maxIndex++] = second[index2++];
            countCompare++;
        }
    }

    while(index1 < len1)
    {
        nums[maxIndex++] = first[index1++];
        countCompare++;
    }

    while(index2 < len2)
    {
        nums[maxIndex++] = second[index2++];
        countCompare++;
    }
    compare[0] = countCompare;
    delete [] first;
    delete [] second;
}

void mergeSort(int nums[], int start, int end, int compare[])
{
    if(start >= end)
    {
        return;
    }
    int mid = (start + end)/2;
    mergeSort(nums, start, mid, compare);
    mergeSort(nums, mid+1, end, compare);

    merge(nums, start, end, compare);
}

int main()
{
    bool flag = false;
    int compare[0];
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
        mergeSort(nums, 0, num, compare);

        cout << "the sorted elements is: " << endl;
        for(int i = 0; i < num; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl << "number of Comparisions: "<< compare[0] << endl;

    }

    return 0;
}