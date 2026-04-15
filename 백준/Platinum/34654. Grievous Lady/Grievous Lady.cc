#include<bits/stdc++.h>
using namespace std;
//using ll=long long;
using ll=int;
using ull=unsigned long long;
using ld=long double;

constexpr ll mod=1e9+7;
void solve(ll tc){
    ll i,j,k,n,m;
    cin>>n>>m;
    vector arr(n,vector<ll>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<ll>ord({1,2,3,4});
    vector dx({1,-1,0,0}),dy({0,0,1,-1});
    bool ok=false;
    do{
        auto tmp=arr;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(tmp[i][j]==0){
                    set<ll>st;
                    for(k=0;k<4;k++){
                        ll nx=i+dx[k],ny=j+dy[k];
                        if(nx>=0&&ny>=0&&nx<n&&ny<m){
                            st.insert(tmp[nx][ny]);
                        }
                    }
                    for(k=0;k<4;k++){
                        if(!st.count(ord[k])){
                            tmp[i][j]=ord[k];
                            break;
                        }
                    }
                    if(k==4)goto abc;
                }
            }
        }
        abc:;
        if(i==n&&j==m){
            for(auto&x:tmp){
                for(auto&y:x)cout<<y<<" ";
                cout<<"\n";
            }
            ok=true;
            break;
        }
    }while(next_permutation(ord.begin(), ord.end()));
    assert(ok);
}

int main(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    ll t=1;
    cin>>t;
    for(ll tc=1;tc<=t;tc++){
        solve(tc+1);
    }
}