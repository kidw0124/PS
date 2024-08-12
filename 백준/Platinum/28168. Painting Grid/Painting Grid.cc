#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll i,j;
    ll n,m;
    bool sw=0;
    cin>>n>>m;
    if(n*m%2==1){
        cout<<"NO\n";
    }
    else if(n==2&&m==3){
        cout<<"YES\n";
        cout<<"001\n"
              "101\n";
    }
    else if(n==2&&m==3){
        cout<<"YES\n";
        cout<<"10\n"
              "00\n"
              "11\n";
    }
    else{
        ll now=1;
        if(n<m)swap(n,m),sw=1;
        for(i=0;i<m;i++){
            if(now*2>=n)break;
            now*=2;
        }
        if(i==m){
            cout<<"NO\n";
            return;
        }
        vector<vector<ll>>arr(n,vector<ll>(m));
        vector<vector<ll>>xrr,yrr;
        ll nex=0;
        if(m==1){
            arr[0][0]=1;
            nex=2;
        }
        else if(m==2){
            arr[0][0]=arr[1][1]=1;
            nex=2;
        }
        else{
            for(i=0;i<m;i++){
                if(i%2==0){
                    arr[i][i]=1;
                    vector<ll>tmp(m);
                    for(j=0;j<m;j++){
                        tmp[j]=1;
                    }
                    tmp[i]=0;
                    if(i!=m-1)xrr.push_back(tmp);
                }
                else{
                    for(j=0;j<m;j++){
                        arr[i][j]=1;
                    }
                    arr[i][i]=0;
                    vector<ll>tmp(m);
                    tmp[i]=1;
                    yrr.push_back(tmp);
                }
            }
            nex=m;
            if(m&1){
                for(j=0;j<m-1;j++){
                    arr[m][j]=1;
                }
                nex++;
            }
        }
        cout<<"YES\n";
        ll tmp=0,now2=0;
        for(i=nex;i<n;i+=2){
            if(i==n-1){
                if(__builtin_popcountll(tmp)==m/2){
                    for(j=0;j<m;j++){
                        if(tmp>>j&1)arr[i][j]=1;
                    }
                }
                else{
                    for(j=m/2-1;j<m-1;j++)arr[i][j]=1;
                    auto it=find(arr.begin(), arr.end(),arr[i]);
                    if(it!=arr.begin()+i){
                        ll idx=it-arr.begin();
                        abc:;
                        while(__builtin_popcountll(tmp)==1)tmp++;
                        for(j=0;j<m;j++){
                            if(tmp>>j&1)arr[idx][j]=1;
                        }
                        for(j=0;j<m;j++){
                            if(arr[idx][j])arr[idx+1][j]=0;
                            else arr[idx+1][j]=1;
                        }
                        if(arr[i]==arr[idx]){tmp++;goto abc;}
                    }
                }
            }
            else{
                if(now2<xrr.size()){
                    arr[i]=xrr[now2];
                    arr[i+1]=yrr[now2++];
                }
                else{
                    while(__builtin_popcountll(tmp)==1)tmp++;
                    for(j=0;j<m;j++){
                        if(tmp>>j&1)arr[i][j]=1;
                    }
                    for(j=0;j<m;j++){
                        if(arr[i][j])arr[i+1][j]=0;
                        else arr[i+1][j]=1;
                    }
                    tmp++;
                }
            }
        }
        vector<vector<ll>>ans;
        if(sw){
            for(j=0;j<m;j++){
                vector<ll>tmp;
                for(i=0;i<n;i++){
                    cout<<arr[i][j];
                    tmp.push_back(arr[i][j]);
                }
                ans.push_back(tmp);
                cout<<'\n';
            }
        }
        else for(i=0;i<n;i++){
                vector<ll>tmp;
                for(j=0;j<m;j++){
                    cout<<arr[i][j];
                    tmp.push_back(arr[i][j]);
                }
                ans.push_back(tmp);
                cout<<'\n';
            }
        auto ans2=ans;
        sort(ans2.begin(), ans2.end());
        ans2.erase(unique(ans2.begin(), ans2.end()),ans2.end());
        assert(ans2.size()==ans.size()||sw);
    }
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}