
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> ss;
    int start = 0;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (ss.find(c) != ss.end())
        {
            start = ss[c] + 1;
        }
        else
        {
            ans = max(ans, i - start + 1);
        }

        ss[c] = i;
    }
    return ans;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    return 1;
}