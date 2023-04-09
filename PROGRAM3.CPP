/*
Given an unsorted array of integers, design an algorithm and implement it using a program to find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
*/

#include <iostream>
#include <queue>
using namespace std;

// largest : minHeap
int kthlargest(int nums[], int k, int num)
{
    priority_queue<int> minHeap;

    for(int i = 0; i < num; i++)
    {
        minHeap.push(nums[i]);
    }
    while(--k)
    {
        minHeap.pop();
    }
    return minHeap.top();
}

// smallest : maxHeap
int kthSmallest(int nums[], int k, int num)
{
    priority_queue<int> maxHeap;

    for(int i = 0; i < num; i++)
    {
        maxHeap.push(nums[i]);
        if(maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    

    return maxHeap.top();
    
}
int main()
{
    int testcase, val, k;
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

        cout << "Enter: kth smallest/kth largest(1/0): " << endl;
        cin >> val;


        if(val == 1)
        {
            cout << "Enter the value of kth: ";
            cin >> k;
            cout << "the kth smallest element is: " << kthSmallest(nums, k, num);
        }
        else
        {
            cout << "Enter the value of kth: ";
            cin >> k;
            cout << "the kth largest element is: " << kthlargest(nums, k, num);
        }
    }

    return 0;
}
