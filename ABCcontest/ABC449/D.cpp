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

#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define all(v) (v).begin(), (v).end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll L, R, D, U;
    cin >> L >> R >> D >> U;

    int n = max({abs(L), abs(R), abs(D), abs(U)}) + 1;

    ll ans = 0;

    rep(i, n)
    {
        if (i % 2)
            continue;

        if (D <= i && i <= U)
        {
            ans += max(min(R, i) - max(L, -i) + 1, 0LL);
        }

        if (i != 0 && D <= -i && -i <= U)
        {
            ans += max(min(R, i) - max(L, -i) + 1, 0LL);
        }

        if (L <= i && i <= R)
        {
            ans += max(min(U, i - 1) - max(D, -i + 1) + 1, 0LL);
        }

        if (i != 0 && L <= -i && -i <= R)
        {
            ans += max(min(U, i - 1) - max(D, -i + 1) + 1, 0LL);
        }
    }

    cout << ans << "\n";

    return 0;
}
