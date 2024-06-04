#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<string>> solveNQueens(int n)
{
    std::vector<std::vector<std::string>> res;

    // Arrays to track column and diagonal conflicts
    std::vector<bool> col(n, false);
    std::vector<bool> posDiag(2 * n - 1, false); // (row + col)
    std::vector<bool> negDiag(2 * n - 1, false); // (row - col + n - 1)

    // Single vector to represent the board state
    std::vector<std::string> board(n, std::string(n, '.'));

    // Helper function to perform backtracking
    std::function<void(int)> backtracking = [&](int r)
    {
        if (r == n)
        {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++)
        {
            if (!col[c] && !posDiag[r + c] && !negDiag[r - c + n - 1])
            {
                col[c] = posDiag[r + c] = negDiag[r - c + n - 1] = true;
                board[r][c] = 'Q';
                backtracking(r + 1);
                board[r][c] = '.';
                col[c] = posDiag[r + c] = negDiag[r - c + n - 1] = false;
            }
        }
    };

    backtracking(0);
    return res;
}

int main()
{
    const auto op = solveNQueens(4);
    return 1;
}