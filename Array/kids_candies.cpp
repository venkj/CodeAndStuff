
#include <iostream>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int max = *max_element(candies.begin(), candies.end());

    vector<bool> result(candies.size(), false);
    for (int i = 0; i < candies.size(); i++)
    {
        result[i] = candies[i] + extraCandies >= max;
    }

    return result;
}

int main()
{
    vector<int> candies{2, 3, 5, 1, 3};
    kidsWithCandies(candies, 3);
    return 1;
}