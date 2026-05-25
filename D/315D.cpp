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

    int H,W;
    cin>>H>>W;

    vector<string> field(H);

    rep(i,H){
        cin>>field[i];
    }

    vector<vector<int>> Hcnt(H,vector<int>(26,0));
    vector<vector<int>> Wcnt(W,vector<int>(26,0));
    vector<int> Hall(H,0);
    vector<int> Wall(W,0);

    rep(i,H){
        rep(j,W){
            if (field[i][j]!='.'){
                int idx=field[i][j]-'a';
                Hcnt[i][idx]+=1;
                Wcnt[j][idx]+=1;
                Hall[i]+=1;
                Wall[j]+=1;
                } 
            }
    
        }
    
    vector<int> Hneeddelete(H,-1);
    vector<int> Wneeddelete(W,-1);


    bool complete=false;

    while(!complete){
        complete=true;
        rep(i,H){
            rep(idx,26){
                if(Hcnt[i][idx]>=2 && Hcnt[i][idx]==Hall[i]){
                    Hneeddelete[i]=idx;
                    complete=false;
                }
            }
        }
        rep(j,W){
            rep(idx,26){
                if(Wcnt[j][idx]>=2 && Wcnt[j][idx]==Wall[j]){
                    Wneeddelete[j]=idx;
                    complete=false;
                }
            }
        }

        rep(i,H){
            if(Hneeddelete[i]!=-1 && Hneeddelete[i]!=-2){
                Hall[i]=0;
                Hcnt[i][Hneeddelete[i]]=0;
                rep(j,W){
                    if(Wneeddelete[j]==-1 && Wall[j]>0){
                        Wall[j]-=1;
                        Wcnt[j][Hneeddelete[i]]-=1;
                    }
                }
                Hneeddelete[i]=-2;
                
            }
            

        }
        rep(j,W){
            if(Wneeddelete[j]!=-1 && Wneeddelete[j]!=-2){
                Wall[j]=0;
                Wcnt[j][Wneeddelete[j]]=0;
                rep(i,H){
                    if(Hneeddelete[i]==-1 && Hall[i]>0 ){
                        Hall[i]-=1;
                        Hcnt[i][Wneeddelete[j]]-=1;
                    }
                }
                Wneeddelete[j]=-2;
            }

        }


        }
    
    int result=0;

    rep(i,H){
        result+=Hall[i];
    }
    
    cout<<result<<"\n";



    return 0;
}
