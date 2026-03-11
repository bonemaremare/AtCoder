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

void dfs(int n, set<int> &number, vector<bool> &seen, bool pass, vector<bool> &result, const vector<int> &A, const vector<pair<int, int>> &connect)
{
    for (auto v : connect)
    {
        seen[n] = true;
        int m = -1;
        if (v.first == n && !seen[v.second])
        {
            m = v.second;
        }
        else if (v.second == n && !seen[v.first])
        {
            m = v.first;
        }
        else
        {
            continue;
        }

        if (pass)
        {
            result[m] = true;

            dfs(m, number, seen, pass, result, A, connect);
        }
        else
        {
            if (number.count(A[m]))
            {
                pass = true;
                result[m] = true;
                dfs(m, number, seen, pass, result, A, connect);
            }
            else
            {
                number.insert(A[m]);
                result[m] = false;
                dfs(m, number, seen, pass, result, A, connect);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }
    vector<pair<int, int>> connect(N - 1);
    rep(i, N - 1)
    {
        int u, v;
        cin >> u >> v;
        connect[i] = {u - 1, v - 1};
    }

    vector<bool> seen(N, false);

    vector<bool> result(N, false);

    set<int> number;
    number.insert(A[0]);

    bool pass = false;

    dfs(0, number, seen, pass, result, A, connect);

    rep(i, N)
    {
        if (!result[i])
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }

    return 0;
}
