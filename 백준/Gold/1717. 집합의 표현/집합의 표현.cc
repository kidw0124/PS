#include<bits/stdc++.h>
using namespace std;

int par[1'000'001];

int _find(int i){
    if(par[i]==i){
        return i;
    }
    else return par[i]=_find(par[i]);
}

void _union(int x, int y){
    int rx=_find(x);
    int ry=_find(y);
    if(rx!=ry){
        par[rx]=y;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<=n;i++){
        par[i]=i;
    }
    for(i=0;i<m;i++){
        int q,x,y;
        cin>>q>>x>>y;
        if(q==0){
            _union(x,y);
        }
        else{
            int rx=_find(x);
            int ry=_find(y);
            if(rx==ry){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
}
