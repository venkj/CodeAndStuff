#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res{};
    vector<int> comb{};
    function<void(int, int)> backtracking = [&](int i, int total)
    {
        if (total == target)
        {
            res.push_back(comb);
            return;
        }

        if (i < candidates.size() && total <= target)
        {
            comb.push_back(candidates[i]);
            backtracking(i, candidates[i] + total);
            comb.pop_back();
            backtracking(i + 1, total);
        }
    };

    backtracking(0, 0);
    return res;
}

int main()
{
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    const auto op = combinationSum(candidates, target);
    return 1;
}