#include<bits/stdc++.h>
using namespace std;
using ll=long long;

void preprocess(){
    int i,j;
}

void solve(){
    int i,j;
    int n,b;
    cin>>n>>b;
    vector<int> a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    bool flag=false;
    for(i=1;i<n-1;i++){
        if(a[i]!=a[i+1])flag=true;
    }
    if(flag){
        cout<<2*b<<'\n';
        ll cnt=0;
        for(i=0;i<2*b;i++){
            if(a.back()==b-1||cnt==b)cout<<'B';
            else cnt++,cout<<'A';
            a.back()++;
            a.back()%=b;
        }
    }
    else{
        cout<<b<<'\n';
        for(i=0;i<b;i++){
            if(a.back()==b-1)cout<<'A';
            else cout<<'B';
            a.back()++;
            a.back()%=b;
        }
    }
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
    preprocess();
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
}