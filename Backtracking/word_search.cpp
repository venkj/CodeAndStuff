#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

bool exist(vector<vector<char>> &board, string word)
{
    const int ROWS = board.size();
    const int COLS = board[0].size();

    set<pair<int, int>> path{};
    function<bool(int, int, int)> backtrack = [&](int row, int col, int indx)
    {
        if (indx == word.size())
            return true;

        if (row < 0 or
            col < 0 or
            row >= ROWS or
            col >= COLS or
            word[indx] != board[row][col] or
            path.contains(make_pair(row, col)))
        {

            return false;
        }

        auto row_col_pair = make_pair(row, col);

        path.insert(row_col_pair);

        bool res = (backtrack(row + 1, col, indx + 1) or
                    backtrack(row - 1, col, indx + 1) or
                    backtrack(row, col + 1, indx + 1) or
                    backtrack(row, col - 1, indx + 1));

        path.erase(row_col_pair);

        return res;
    };

    for (int row = 0; row < ROWS; ++row)
    {
        for (int col = 0; col < COLS; ++col)
        {
            if (backtrack(row, col, 0))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << boolalpha << exist(board, word) << endl;
    return 1;
}