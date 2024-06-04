#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>

using namespace std;

int openLock(vector<string> &deadends, string target)
{
    unordered_set<string> visited(deadends.begin(), deadends.end());
    if (visited.count("0000"))
        return -1;

    auto children = [](const string &lock) -> vector<string>
    {
        vector<string> children;
        for (int i = 0; i < 4; i++)
        {
            string newLock = lock;
            newLock[i] = (newLock[i] == '9' ? '0' : newLock[i] + 1);
            children.push_back(newLock);

            newLock = lock;
            newLock[i] = (newLock[i] == '0' ? '9' : newLock[i] - 1);
            children.push_back(newLock);
        }
        return children;
    };

    queue<pair<string, int>> q;
    q.push({"0000", 0});

    while (!q.empty())
    {
        auto [lock, turn] = q.front();
        q.pop();
        if (lock == target)
        {
            return turn;
        }
        for (const auto &child : children(lock))
        {
            if (!visited.count(child))
            {
                visited.insert(child);
                q.push({child, turn + 1});
            }
        }
    }
    return -1;
}

int main()
{
    vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    cout << openLock(deadends, target) << endl;
    return 1;
}