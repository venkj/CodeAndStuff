#include <iostream>
#include <string>

using namespace std;

int beautifulBinaryString(string b)
{
    const string pattern{"010"};

    int counter = 0;
    auto it = b.find(pattern);

    while (it != string::npos)
    {
        b[it + 2] = '1';
        counter++;

        it = b.find(pattern);
    }
    return counter;
}

int main()
{
    cout << beautifulBinaryString("0101010") << endl;
    return 1;
}