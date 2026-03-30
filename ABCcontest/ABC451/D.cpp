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

vector<ll> goodnum;
vector<ll> twos;

void dfs(ll cur_num){
    if (cur_num>0){
        goodnum.push_back(cur_num);
    }
    for(ll p : twos){
        ll multi=1;
        ll tmp=cur_num;
        while(tmp>0){
            multi*=10;
            tmp/=10;
        }

        ll next_num=p*(multi)+cur_num;
        if(next_num<=1e9){
            dfs(next_num);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;

    ll num=1;
    while(num<=1e9){
        twos.push_back(num);
        num*=2;
    }

    dfs(0);

    sort(all(goodnum));
    goodnum.erase(unique(all(goodnum)),goodnum.end());


    cout<<goodnum[N-1]<<"\n";







    return 0;
}
