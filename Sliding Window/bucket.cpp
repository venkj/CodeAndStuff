#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(const string &s)
{
    int no_of_balls = 0;
    for (char c : s)
    {
        if (c == 'B')
        {
            ++no_of_balls;
        }
    }

    if (no_of_balls == 0)
        return 0;

    const int n = s.length();

    int r = -1;
    for (int d = 0; d < 2; ++d)
    {
        int first = d, last = d + 2 * (no_of_balls - 1);
        if (last >= n)
            break;
        int may = 0;
        for (int i = first; i <= last; i += 2)
        {
            if (s[i] == 'B')
            {
                ++may;
            }
        }
        r = max(r, may);
        for (last += 2; last < n; last += 2)
        {
            may += s[last] == 'B';
            may -= s[first] == 'B';
            first += 2;
            r = max(r, may);
        }
    }
    const int result = r < 0 ? r : (no_of_balls - r);
    return result;
}

int main()
{
    cout << solution("B.BB.B..B") << endl;
    cout << solution("BB.B.BBB...") << endl;
    cout << solution("..B....B.BB") << endl;
    cout << solution(".BBB.B") << endl;

    return 1;
}