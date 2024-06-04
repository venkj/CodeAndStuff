#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    if (p.size() > s.size())
    {
        return {};
    }

    map<int, int> pCount, sCount;
    for (int i = 0; i < p.size(); i++)
    {
        pCount[p[i]]++;
        sCount[s[i]]++;
    }

    vector<int> ans;
    int l = 0, r = p.size();
    while (r < s.size())
    {
        if (pCount == sCount)
        {
            ans.emplace_back(l);
        }

        sCount[s[l]]--;
        sCount[s[r]]++;

        if (sCount[s[l]] == 0)
        {
            sCount.erase(s[l]);
        }
        l++;
        r++;
    }
    if (pCount == sCount)
    {
        ans.emplace_back(l);
    }
    return ans;
}

int main()
{
    findAnagrams("cbaebabacd", "abc");
    return 1;
}