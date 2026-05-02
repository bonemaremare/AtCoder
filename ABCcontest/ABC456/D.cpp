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

    string S;
    cin >> S;
    int n = S.size();
    vector<ll> N(n, 0);
    N[0] = 1;

    if (n == 1)
    {
        cout << 1 << "\n";
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            N[i] += 1;
            rep(j, i)
            {
                if (S[i] != S[j])
                {
                    N[i] = (N[i] + N[j]) % 998244353;
                }
            }
        }
        ll ans = 0;
        rep(i, n)
        {
            ans = (ans + N[i]) % 998244353;
        }
        cout << ans << "\n";
    }

    return 0;
}
