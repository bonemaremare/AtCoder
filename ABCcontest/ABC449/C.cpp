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

    int N, L, R;
    cin >> N >> L >> R;

    string S;
    cin >> S;

    vector<int> result(26, 0);

    ll ans = 0;

    for (int i = L; i <= (min(N - 1, R)); ++i)
    {
        result[S[i] - 'a']++;
    }

    rep(i, N)
    {
        ans += result[S[i] - 'a'];
        if (i + R + 1 < N)
        {
            result[S[i + R + 1] - 'a']++;
        }

        if (i + L < N)
        {
            result[S[i + L] - 'a']--;
        }
        }

    cout << ans << "\n";

    return 0;
}
