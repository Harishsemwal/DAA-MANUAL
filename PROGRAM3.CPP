/* Given an array of nonnegative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K. */
#include <iostream>
using namespace std;

int main()
{
    int count = 0, target;
    int num, nums[20];

    cout << "Enter the number of element: ";
    cin >> num;

    cout << "Enter the elements: ";
    for(int i = 0; i < num; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter the target Value: ";
    cin >> target; 

    for(int i = 0; i < num; i++)
    {
        for(int j = i+1; j < num; j++)
        {
            if(nums[i] + nums[j] == target)
            {
                count++;
            }
        }
    }

    cout << "total ("<< count << ") number number of pair exits....";
    return 0;
}