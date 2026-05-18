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

    string S;
    cin>>S;

    vector<ll> mod(2019);

    mod[0]=1;

    int cur=0;
    int ten=1;

    for(int i=S.size()-1;i>=0;--i){
        int num=S[i]-'0';
        cur=(cur+num*ten)%2019;
        ten=(ten*10)%2019;

        mod[cur]+=1;

    }
    ll result=0;
    rep(i,2019){
        if(mod[i]>=2){
            result+=(mod[i]*(mod[i]-1))/2;
            
        }

    }
    cout<<result<<"\n";

    return 0;
}
