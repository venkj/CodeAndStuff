#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

double findMaxAverage(vector<int> &nums, int k)
{
    int l = 0, r = k;
    int sum = accumulate(nums.begin(), nums.begin() + k, 0);
    int res = sum;
    while (r < nums.size())
    {
        sum = sum - nums[l] + nums[r];
        res = max(res, sum);
        l++;
        r++;
    }
    return static_cast<double>(res) / k;
}

int main()
{
    vector<int> nums{1, 12, -5, -6, 50, 3};
    cout << findMaxAverage(nums, 4) << endl;
    return 1;
}