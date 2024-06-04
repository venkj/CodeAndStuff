#include <iostream>
#include <string>
#include <vector>

using namespace std;

void separateNumbers(string s)
{

    if (s.empty() || 1 == s.size() || '0' == s[0])
    {
        cout << "NO" << std::endl;
        return;
    }

    for (int i = 1; i < s.size(); i++)
    {
        auto startingNumber{std::atol(s.substr(0, i).c_str())};

        string newString{s.substr(0, i)};
        while (newString.size() < s.size())
        {
            newString += to_string(++startingNumber);
        }

        if (newString == s)
        {
            cout << "YES " << s.substr(0, i) << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    separateNumbers("99100");
    return 1;
}