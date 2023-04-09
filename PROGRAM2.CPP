// Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by partitioning the array into two subarrays based on a pivot element such that one of the sub array holds values smaller than the pivot element while another subarray holds values greater than the pivot element. Pivot element should be selected randomly from the array. Your program should also find number of comparisons and swaps required for sorting the array */

#include <iostream>
using namespace std;

int partition(int nums[], int start, int end, int swapCount[])
{
    int pivot = nums[start];
    int count = 0;
    static int countSwap;
    for(int i = start + 1; i <=end; i++)
    {
        if(nums[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = count + start;
    swap(nums[start], nums[pivotIndex]);
    countSwap++;

    int i = start;
    int j = end;

    while(i < pivotIndex && j > pivotIndex)
    {
        while(nums[i] < pivotIndex)
        {
            i++;
        }

        while(nums[j] > pivotIndex)
        {
            j--;
        }

        if(i < pivotIndex && j > pivotIndex)
        {
            swap(nums[i++], nums[j--]);
            countSwap++;
        }
    }
    swapCount[0] = countSwap;
    return pivotIndex;
}

void QuickSort(int nums[], int start, int end, int swapCount[])
{
    if(start >= end)
    {
        return;
    }

    int P = partition(nums, start, end, swapCount);
    QuickSort(nums, start, P, swapCount);
    QuickSort(nums, P+1, end, swapCount);
}
int main()
{
    int testcase, count = 0;
    int swapCount[0];
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

        QuickSort(nums, 0, num-1, swapCount);

        cout << "The sorted elements is: " << endl;
        for(int i = 0; i < num; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl << "the element will be sorted after " << swapCount[0] << " number of Swaps..." << endl;

        return 0;
    }
}
