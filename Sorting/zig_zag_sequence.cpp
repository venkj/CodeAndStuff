
#include <iostream>
#include <vector>
using namespace std;

void printOutput(const vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (i > 0)
            cout << ",";
        cout << a[i];
    }
    cout << endl;
}

void findZigZagSequence(vector<int> &a, int n)
{
    sort(a.begin(), a.end());
    int mid = (n - 1) / 2;
    partial_sort(a.begin() + mid - 1, a.end(), a.end(), greater<int>());
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 4};
    int n = a.size();
    findZigZagSequence(a, n);
    printOutput(a);
}