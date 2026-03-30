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
    cin>>N;

    vector<vector<int>> G(N,vector<int>(N));

    rep(i,N-1){
        rep(j,N-i-1){
            int num;
            cin >>num;
            G[i][j]=num;
        }

    }

    bool can_make=true;

    rep(i,N-2){
        if (not can_make){
            break;
        }
        vector<int> Gi=G[i];
        rep(j,N-i-1){
            if (not can_make){
                break;
            }
            
            vector<int> Gj=G[j+i+1];
            rep(k,N-i-j-2){
                int t1=Gi[j];
                int t2=Gi[j+k+1];
                int t3=Gj[k];

                if (t1+t2<t3 || t1+t3<t2 || t2+t3<t1){
                    can_make=false;
                    break;
                }
            }
        }
    }

    if (can_make){
        cout<<"Yes\n";
    }   
    else{
        cout<<"No\n";
    }

    return 0;
    
}
