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
vector<int> A;
vector<vector<int>> G;

set<int> seen_values;
int duplicate_count = 0;
vector<int> ans;

void dfs(int v, int p)
{
    bool duplicate = false;
    if (seen_values.count(A[v]))
    {
        duplicate = true;
        duplicate_count++;
    }
    else
    {
        seen_values.insert(A[v]);
    }

    if (duplicate_count > 0)
    {
        ans[v] = 1;
    }
    else
    {
        ans[v] = 0;
    }

    for (int next_v : G[v])
    {
        if (next_v == p)
        {
            continue;
        }
        dfs(next_v, v);
    }

    if (duplicate)
    {
        duplicate_count--;
    }
    else
    {
        seen_values.erase(A[v]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    ans.resize(N);
    G.resize(N);
    A.resize(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    rep(i, N - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    dfs(0, -1);

    rep(i, N)
    {
        if (ans[i])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
