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
vector<bool> broken;
long long max_high;
bool complete;

void judge(int n)
{
    rep(i, N)
    {
        if (complete)
        {
            break;
        }

        if (broken[i])
        {
            continue;
        }
        ll high_now = H[i] + (n - 1) * S[i];
        if (high_now > max_high)
        {
            continue;
        }

        else
        {
            broken[i] = true;
            if (n == 1)
            {
                complete = true;
                break;
            }
            else
            {
                judge(n - 1);
                broken[i] = false;
            }
        }
    }
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

    broken.resize(N);
    rep(i, N)
    {
        broken[i] = false;
    }

    long long limit = -1;
    rep(i, N)
    {
        long long highi = H[i] + S[i] * (N - 1);
        if (highi > limit)
        {
            limit = highi;
        }
    }
    bool success = false;
    ll x = 0;
    ll y = limit;

    while (!success)
    {
        complete = false;
        max_high = (x + y) / 2;
        fill(all(broken), false);
        judge(N);
        if (complete)
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
