#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compress(vector<char> &chars)
{

    if (chars.size() < 2)
    {
        return 1;
    }

    int n = chars.size();
    int index = 0, i = 0;
    while (i < n)
    {
        char curr_char = chars[i];
        int count = 0;

        while (i < n && chars[i] == curr_char)
        {
            count++;
            i++;
        }

        chars[index] = curr_char;
        index++;

        if (count > 1)
        {
            string count_str = to_string(count);
            for (const char ch : count_str)
            {
                chars[index] = ch;
                index++;
            }
        }
    }
    return index;
}

int main()
{
    vector<char> chars{{'a', 'a', 'b', 'b', 'c', 'c', 'c'}};
    compress(chars);
    return 1;
}