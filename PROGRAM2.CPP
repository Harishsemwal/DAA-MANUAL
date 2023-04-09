// Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vt;
    vector<int> num;
    int x, numr;

    cout << "Enter the number of elements: ";
    cin >> numr;

    cout << "Enter the elements in sorted order: ";
    for (int  i = 0; i < numr; i++)
    {
        cin >> x;
        vt.push_back(x);
    }

    for(int i = 0; i < vt.size(); i++)
    {
        for(int j = i + 1; j < vt.size(); j++)
        {
            for(int k = j + 1; k < vt.size(); k++)
            {
                if(vt[i] + vt[j] == vt[k])
                {
                    num.push_back(i);
                    num.push_back(j);
                    num.push_back(k);
                }
            }
        }
    }

    cout << endl << "answer: " << endl;
    for(int i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }

    return 0;
}