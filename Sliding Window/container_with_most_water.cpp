#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxArea(vector<int> &height)
{
    int l = 0, r = height.size() - 1;

    int res = 0;
    while (l < r)
    {
        res = max(res, ((r - l) * min(height[l], height[r])));

        if (height[l] < height[r])
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return res;
}

int main()
{
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    return 1;
}