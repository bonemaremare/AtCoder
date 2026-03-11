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

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    rep(j, Q)
    {
        int K;
        cin >> K;
        set<int> B;
        rep(i, K)
        {
            int b;
            cin >> b;
            B.insert(b);
        }

        int result = 1000000000;

        rep(i, N)
        {
            if (A[i] < result && !B.count(i + 1))
            {
                result = A[i];
            }
                }
        cout << result << "\n";
    }
    return 0;
}
