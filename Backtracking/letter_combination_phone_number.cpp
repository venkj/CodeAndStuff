#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> letterCombinations(string digits)
{
    const unordered_map<char, string> mappings{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};

    vector<string> result{};
    function<void(int, string)> backtrack = [&](int index, string path)
    {
        if (index == digits.size())
        {
            result.push_back(path);
            return;
        }

        for (char c : mappings.at(digits[index]))
        {
            backtrack(index + 1, path + c);
        }
    };
    if (!digits.empty())
        backtrack(0, "");

    return result;
}

int main()
{
    const auto op = letterCombinations("23");
    return 1;
}