/* Given an unsorted array of integers, design an algorithm and implement it using a program to find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n)) */

#include <bits/stdc++.h>
using namespace std;

bool findPairs(int nums[], int num, int key, int store[])
{
    int left = 0; 
    int right = num - 1;

    while(left < right)
    {
        sort(nums, nums + num);

        if(nums[left] + nums[right] == key)
        {
            store[0] = nums[left];
            store[1] = nums[right];
            return true;
        }
        else if(nums[left]+ nums[right] < key)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
}

int main()
{
    int testcase;
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

        int key, store[2];
        cout << "Enter the key element: ";
        cin >> key;

        bool ans = findPairs(nums, num, key, store);

        if(ans)
        {
        cout << "pair: " << store[0] <<" " << store[1] << endl;
        }
        else
        {
            cout << "Pairs not exits..." << endl;
        }

        return 0;
    }
}