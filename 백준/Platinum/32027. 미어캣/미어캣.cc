#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

void solve(){
    int i,j,k;
    int n,a,b;
    cin>>n;
    vector<pair<int,int>> loc(n);
    vector<int> lef,rig;
    for(i=0;i<n;i++){
        cin>>loc[i].first;
        char dir;
        cin>>dir;
        if(dir=='L')lef.push_back(loc[i].first),loc[i].second=0;
        else rig.push_back(loc[i].first),loc[i].second=1;
    }
    if(lef.empty()||rig.empty()){
        cout<<n<<'\n';
        return;
    }
    sort(lef.begin(), lef.end());
    sort(rig.begin(), rig.end());
    int ans=0;
    for(i=-1;i<n;i++){
        vector<int> tmp(n);
        int nowl=lef.size()-1,nowr=rig.size()-1;
        for(j=i;j>=0;j--){
            if(loc[j].second==0){
                tmp[j]=lef[nowl--];
            }
        }
        for(j=i+1;j<n;j++){
            if(loc[j].second==1){
                tmp[j]=rig[nowr--];
            }
        }
        for(j=i;j>=0;j--){
            if(loc[j].second==1){
                tmp[j]=rig[nowr--];
            }
        }
        for(j=i+1;j<n;j++){
            if(loc[j].second==0){
                tmp[j]=lef[nowl--];
            }
        }
        int now=0;
        vector<int>maxlef(n),maxrig(n);
        maxlef[0]=tmp[0];
        for(j=1;j<n;j++){
            maxlef[j]=max(maxlef[j-1],tmp[j]);
        }
        maxrig[n-1]=tmp[n-1];
        for(j=n-2;j>=0;j--){
            maxrig[j]=max(maxrig[j+1],tmp[j]);
        }
        for(j=0;j<n;j++){
            if(loc[j].second==0){
                if(j==0||tmp[j]>maxlef[j-1]) now++;
            }
            else{
                if(j==n-1||tmp[j]>maxrig[j+1]) now++;
            }
        }
        ans=max(ans,now);
    }
    cout<<ans<<'\n';
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t st=clock();
#else
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
    int t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}