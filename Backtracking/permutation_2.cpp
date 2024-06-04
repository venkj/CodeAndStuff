#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> res{};
    vector<int> perm{};
    unordered_map<int, int> m;
    for (int num : nums)
    {
        m[num]++;
    }

    function<void()> backtracking = [&]()
    {
        if (perm.size() == nums.size())
        {
            res.push_back(perm);
            return;
        }
        for (auto item : m)
        {
            int num = item.first;
            if (item.second == 0)
                continue;

            perm.push_back(num);
            m[num]--;
            backtracking();
            perm.pop_back();
            m[num]++;
        }
    };
    backtracking();
    return res;
}

int main()
{
    vector<int> nums = {1, 1, 2};
    const auto op = permuteUnique(nums);
    return 1;
}