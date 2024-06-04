#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res{};
    vector<int> comb{};
    function<void(int)> backtracking = [&](int indx)
    {
        if (indx >= nums.size())
        {
            res.push_back(comb);
            return;
        }

        comb.push_back(nums[indx]);
        backtracking(indx + 1);
        comb.pop_back();
        backtracking(indx + 1);
    };

    backtracking(0);
    return res;
}

int main()
{
    vector<int> nums{1, 2, 3};
    const auto op = subsets(nums);
    return 1;
}