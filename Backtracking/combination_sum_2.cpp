#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> res{};
    vector<int> comb{};

    function<void(int, int)> backtracking = [&](int indx, int total)
    {
        if (total == 0)
        {
            res.push_back(comb);
            return;
        }
        for (int i = indx; i < candidates.size(); i++)
        {
            if (i > indx && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if (candidates[i] <= total)
            {
                comb.push_back(candidates[i]);
                backtracking(i + 1, total - candidates[i]);
                comb.pop_back();
            }
        }
    };

    backtracking(0, target);
    return res;
}

int main()
{
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    const auto op = combinationSum2(candidates, target);
    return 1;
}