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

int N;
vector<ll> H;
vector<ll> S;

bool judge(ll X)
{
    vector<ll> timelimit(N);

    rep(i, N)
    {
        if (X < H[i])
        {
            return false;
        }

        timelimit[i] = (X - H[i]) / S[i];
    }

    sort(all(timelimit));

    rep(i, N)
    {
        if (timelimit[i] < i)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    H.resize(N);
    S.resize(N);

    rep(i, N)
    {
        int h, s;
        cin >> h >> s;
        H[i] = h;
        S[i] = s;
    }

    long long limitb = -1;
    ll limits = 1000000000;
    rep(i, N)
    {
        long long highi = H[i] + S[i] * (N - 1);
        if (highi > limitb)
        {
            limitb = highi;
        }
        if (highi < limits)
        {
            limits = highi;
        }
    }
    bool success = false;
    ll x = limits - 1;
    ll y = limitb;

    while (!success)
    {
        ll max_high = (x + y) / 2;
        if (judge(max_high))
        {
            y = max_high;
        }
        else
        {
            x = max_high + 1;
        }

        if (y - x < 1)
        {
            cout << y << "\n";
            success = true;
        }
    }

    return 0;
}
