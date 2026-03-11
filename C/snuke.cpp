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

    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    vector<int> C(N);

    rep(i, N)
    {
        cin >> A[i];
    }
    rep(i, N)
    {
        cin >> B[i];
    }
    rep(i, N)
    {
        cin >> C[i];
    }
    sort(all(A));
    sort(all(B));
    sort(all(C));

    long long result = 0;
    rep(i, N)
    {
        int b = B[i];
        auto a_it = lower_bound(all(A), b);
        auto c_it = upper_bound(all(C), b);
        long long a_idx = a_it - A.begin();
        long long c_idx = c_it - C.begin();
        result += a_idx * (N - c_idx);
    }
    cout << result << "\n";
    return 0;
}
