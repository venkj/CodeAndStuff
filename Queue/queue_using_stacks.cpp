#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> in;
    stack<int> out;

    void flip()
    {
        while (not in.empty())
        {
            out.push(in.top());
            in.pop();
        }
    }

public:
    void enqueue(int a)
    {
        in.push(a);
    }

    void dqueue()
    {
        if (out.empty())
        {
            flip();
        }
        out.pop();
    }

    int peek()
    {
        if (out.empty())
        {
            flip();
        }
        return out.top();
    }
};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int queryCount = 0;
    cin >> queryCount;

    Queue q;

    for (int i = 0; i < queryCount; ++i)
    {

        int op = 0;
        cin >> op;

        if (op == 1)
        {
            int x = 0;
            cin >> x;
            q.enqueue(x);
        }
        if (op == 2)
        {
            q.dqueue();
        }
        if (op == 3)
        {
            cout << q.peek() << endl;
        }
    }

    return 0;
}
