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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    ll K;
    cin>>N>>K;

    vector<int> P(N);
    rep(i,N){
        cin>>P[i];
        P[i]-=1;
    }
    vector<ll> C(N);
    rep(i,N){
        cin>>C[i];
    }

    ll ans=-2e18;


    rep(i,N){
        int v=i;
        ll cycle_sum=0;
        vector<ll> path_scores;

        while(true){
            v=P[v];
            path_scores.push_back(C[v]);
            cycle_sum+=C[v];
            if(v==i){
                break;
            }
      }

      int l=path_scores.size();
      ll current_path_sum=0;
      rep(j,l){
        ll steps=j+1;
        if (steps>K){
            break;
        }

        current_path_sum+=path_scores[j];
        ll score=current_path_sum;

        if(cycle_sum>0){
            ll loops=(K-steps)/l;
            score+=cycle_sum*loops;
        }

        ans=max(ans,score);

      }
    }

    cout<<ans<<"\n";

    return 0;
}
