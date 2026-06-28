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

ll count(vector<ll> A){
    ll cnt=0;
    rep(i,A.size()){
        if (A[i]!=0){
            cnt+=1;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N,M;
    cin>>N>>M;

    vector<vector<pair<ll,ll>>>  dif(M);
     vector<ll> color(N,0);
    vector<ll> A(N);
    vector<ll> D(N);
    vector<ll> B(N);

    rep(i,N){
        ll a,b,d;
        cin>>a>>d>>b;
        A[i]=a-1;
        B[i]=b-1;
        D[i]=d-1;
        color[a]+=1;
        dif[d].push_back{(a,b)};
    }

    rep(n,M){
        for(auto [a,b] :dif[n]){
            color[a]-=1;
            color[b]+=1;

        }
        cout<<count(color)<<"\n";

    }

   
    


    return 0;
}
