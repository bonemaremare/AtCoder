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

    vector<int> A = {10, 50, 20, 40, 30};
    int N = A.size();
    sort(all(A));

    int target = 35;

    auto it = lower_bound(all(A), target);
    int index = it - A.begin();

    if (index < N)
    {
        cout << target << "以上の最初の数字は" << A[index] << "です。\n";
    }
    else
    {
        cout << target << "以上の数字は見つかりませんでした。\n";
    }

    return 0;
}
