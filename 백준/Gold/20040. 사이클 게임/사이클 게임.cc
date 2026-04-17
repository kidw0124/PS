#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
vector<ll>arr(500000+5),anc(500000+5);

ll union_find(ll point){
    if(point==anc[point]){
        return point;
    }
    else{
        return anc[point]=union_find(anc[point]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ll i;
    for(i=0;i<=n;i++){
        arr[i]=anc[i]=i;
    }
    for(i=0;i<m;i++){
        ll t1,t2;
        cin>>t1>>t2;
        ll t1t=union_find(t1);
        ll t2t=union_find(t2);
        if(t1t==t2t){
            cout<<i+1;
            return 0;
        }
        else{
            anc[t2t]=t1;
            union_find(t2);
        }
    }
    cout<<0;
    return 0;
}
