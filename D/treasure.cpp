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

const ll INF = 1e18;

struct Edge
{
    int to;
    ll cost;
};

vector<ll> dijkstra(int N, int s, const vector<vector<Edge>> &G)
{
    vector<ll> dist(N, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty())
    {
        auto [d, v] = pq.top();
        pq.pop();

        if (dist[v] < d)
            continue;

        for (const auto &e : G[v])
        {
            if (dist[e.to] > dist[v] + e.cost)
            {
                dist[e.to] = dist[v] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    ll T;
    cin >> N >> M >> T;

    vector<ll> A(N);
    rep(i, N)
    {
        cin >> A[i];
    }

    vector<vector<Edge>> G(N), rG(N);
    rep(i, M)
    {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        u--;
        v--;
        G[u].push_back({v, c});
        rG[v].push_back({u, c});
    }
    vector<ll> dist_go = dijkstra(N, 0, G);
    vector<ll> dist_back = dijkstra(N, 0, rG);

    ll max_treasure = 0;
    rep(i, N)
    {
        if (dist_go[i] == INF || dist_back[i] == INF)
        {
            continue;
        }
        ll travel_time = dist_go[i] + dist_back[i];
        ll stay_time = T - travel_time;
        if (stay_time < 0)
        {
            continue;
        }
        ll treasure = A[i] * stay_time;
        if (treasure > max_treasure)
        {
            max_treasure = treasure;
        }
    }

    cout << max_treasure << "\n";

    return 0;
}
