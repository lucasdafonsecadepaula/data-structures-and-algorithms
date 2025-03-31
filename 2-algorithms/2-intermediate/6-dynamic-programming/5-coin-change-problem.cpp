#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int coinChange(const vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int coin : coins)
        {
            if (i >= coin)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

int main()
{
    assert(coinChange({1, 2, 5}, 11) == 3);
    assert(coinChange({2}, 3) == -1);
    assert(coinChange({1}, 0) == 0);
    assert(coinChange({1}, 2) == 2);
    assert(coinChange({186, 419, 83, 408}, 6249) == 20);

    cout << "All tests passed!" << endl;
    return 0;
}
