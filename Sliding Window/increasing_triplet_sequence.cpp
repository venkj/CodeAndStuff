#include <iostream>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return false;

    int l = numeric_limits<int>::max(), r = numeric_limits<int>::max();
    for (int i = 0; i < n; i++)
    {
        int num = nums[i];
        if (num <= l)
        {
            l = num;
        }
        else if (num <= r)
        {
            r = num;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums{{2, 1, 5, 0, 4, 6}};
    cout << boolalpha << increasingTriplet(nums) << endl;
    return 1;
}