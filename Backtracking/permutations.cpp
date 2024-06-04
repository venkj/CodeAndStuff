#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res{};

    function<void(int)> backtracking = [&](int indx)
    {
        if (indx == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = indx; i < nums.size(); i++)
        {
            swap(nums[i], nums[indx]);
            backtracking(indx + 1);
            swap(nums[i], nums[indx]);
        }
    };
    backtracking(0);
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    const auto op = permute(nums);
    return 1;
}