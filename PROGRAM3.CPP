/* You have been given two sorted integer arrays of size m and n. Design an algorithm and implement it using a program to find list of elements which are common to both. (Time Complexity = O(m+n)) */
#include <iostream> 
using namespace std;

void findCommonElement(int nums1[], int num1, int nums2[], int num2)
{
    int i = 0,j = 0, k = 0;
    int comn[num1 + num2];

    while(i < num1 && j < num2)
    {
        if(nums1[i] == nums2[j])
        {
            comn[k++] = nums1[i];
            i++;
            j++;
        }
        else if(nums1[i] < nums2[i])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << "the common elements is: " << endl;
    for(int i = 0; i < k; i++)
    {
        cout << comn[i] << " ";
    }
}


int main()
{
    int testcase, count = 0;
    int num1, num2, nums1[20], nums2[20];

    cout << "Enter the total number of testcase: ";
    cin >> testcase;

    while(testcase--)
    {
        cout << "Enter the number of element in array1: ";
        cin >> num1;

        cout << "Enter the first array elements: ";
        for(int i = 0; i < num1; i++)
        {
            cin >> nums1[i];
        }

        cout << "Enter the number of element in array2: ";
        cin >> num2;

        cout << "Enter the second array elements: ";
        for(int i = 0; i < num2; i++)
        {
            cin >> nums2[i];
        }

        findCommonElement(nums1, num1, nums2, num2);

        return 0;
    }
}