#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generateParenthesis(int n)
{
    vector<string> res{};
    string s{};
    function<void(int, int)> backtrack = [&](int openCnt, int closedCnt)
    {
        if (openCnt == n && closedCnt == n)
        {
            res.emplace_back(s);
            return;
        }

        if (openCnt < n)
        {
            s += "(";
            backtrack(openCnt + 1, closedCnt);
            s.pop_back();
        }

        if (closedCnt < openCnt)
        {
            s += ")";
            backtrack(openCnt, closedCnt + 1);
            s.pop_back();
        }
    };

    backtrack(0, 0);
    return res;
}

int main()
{
    const auto op = generateParenthesis(3);
    return 1;
}