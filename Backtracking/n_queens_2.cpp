#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int totalNQueens(int n)
{
    int res = 0;

    unordered_set<int> col{};
    unordered_set<int> posDiag{}; // (row + col)
    unordered_set<int> negDiag{}; // (row - col)

    function<void(int)> backtracking = [&](int r)
    {
        if (r == n)
        {
            res++;
            return;
        }
        for (int c = 0; c < n; c++)
        {
            if (col.count(c) or posDiag.count(r + c) or negDiag.count(r - c))
                continue;

            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);

            backtracking(r + 1);

            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
        }
    };

    backtracking(0);
    return res;
}

int main()
{
    cout << totalNQueens(4) << endl;
    return 1;
}