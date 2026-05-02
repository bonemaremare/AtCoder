#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) (v).begin(), (v).end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const ll mod = 998244353;
    string S;
    cin >> S;
    int n = S.size();
    vector<ll> N(4, 0);
    ll total = 0;
    int ch;
    rep(i, n)
    {
        if (S[i] == 'a')
        {
            ch = 0;
        }
        else if (S[i] == 'b')
        {
            ch = 1;
        }
        else
        {
            ch = 2;
        }
        ll cur = (N[3] - N[ch] + 1) % mod;
        if (cur < 0)
        {
            cur += mod;
        }
        N[3] = (N[3] + cur) % mod;
        N[ch] = (N[ch] + cur) % mod;
    }

    cout << N[3] << "\n";

    return 0;
}
