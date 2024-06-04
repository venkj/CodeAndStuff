
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
bool closeStrings(string word1, string word2)
{
    if (word1.size() != word2.size())
    {
        return false;
    }

    unordered_map<char, int> m1;
    for (const char c : word1)
    {
        m1[c]++;
    }

    unordered_map<char, int> m2;
    for (const char c : word2)
    {
        if (m1.find(c) == m1.end())
            return false;
        m2[c]++;
    }

    vector<int> freq1;
    for (const auto &i : m1)
    {
        freq1.push_back(i.second);
    }
    sort(freq1.begin(), freq1.end());

    vector<int> freq2;
    for (const auto &i : m2)
    {
        freq2.push_back(i.second);
    }
    sort(freq2.begin(), freq2.end());

    return freq1 == freq2;
}

int main()
{
    string word1 = "aaabbbbccddeeeeefffff";
    string word2 = "aaaaabbcccdddeeeeffff";
    cout << boolalpha << closeStrings(word1, word2);
}