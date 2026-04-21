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

struct Edge {
    int to;
    ll cost;
    ll span;
};

/**
 * ダイクストラ法 (0-indexedベース)
 * 
 * [引数]
 * N: 頂点数
 * s: スタート地点の頂点番号 (※ 0始まりに変換済みの値を入れる)
 * G: 隣接リスト (※ 0始まりで構築済みのグラフを入れる)
 * 
 * [戻り値]
 * 始点sから各頂点への最短距離の配列 (到達不能はINF)
 * 
 * [！入力受け取り時の注意点！]
 * 問題文の頂点が 1〜N の場合、入力を受け取る時に必ず -1 してグラフを構築すること:
 * cin >> u >> v >> c; u--; v--;
 * G[u].push_back({v, c});
 */
vector<ll> dijkstra(int N, int s, const vector<vector<Edge>> &G) {
    vector<ll> dist(N, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (dist[v] < d) continue;

        for (const auto &e : G[v]) {
            ll wait_time=0;
            if(d%e.span!=0){
                wait_time=e.span-d%e.span;
            }
            if (dist[e.to] > dist[v] + e.cost +wait_time) {
                dist[e.to] = dist[v] + e.cost+wait_time;
                pq.push({dist[e.to], e.to});
            }
        }
    }
    
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,X,Y;
    cin>>N>>M>>X>>Y;

    vector<vector<Edge>> field(N);

    rep(i,M){
        int A,B;
        ll T,K;
        cin>>A>>B>>T>>K;

        field[A-1].push_back({B-1,T,K});
        field[B-1].push_back({A-1,T,K});

    }

    vector<ll> ans=dijkstra(N,X-1,field);

    if (ans[Y-1]==INF){
        cout<<-1<<"\n";
    }
    else{
        cout<<ans[Y-1]<<"\n";
    }



    

    return 0;
}
