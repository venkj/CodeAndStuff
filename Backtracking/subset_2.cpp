#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res{};
    vector<int> subset{};
    function<void(int)> backtracking = [&](int i)
    {
        if (i >= nums.size())
        {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtracking(i + 1);
        subset.pop_back();
        while (i + 1 < nums.size() and nums[i] == nums[i + 1])
        {
            i++;
        }
        backtracking(i + 1);
    };

    backtracking(0);
    return res;
}

int main()
{
    vector<int> nums{1, 2, 2};
    const auto op = subsetsWithDup(nums);
    return 1;
}