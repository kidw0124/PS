#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, i, j, k, l, dp[105][105][105][100], sum, maximum;

ll func(ll x,ll y, ll z,ll w){
    if(dp[x][y][z][w])return dp[x][y][z][w];
    ll tx, ty, tz;
    tx=min({x,y,z});
    tz=max({x,y,z});
    ty=x+y+z-tx-tz;
    x=tx,y=ty,z=tz;
    if(x==0){
        if(y==0){
            if(z==0)return 0;
            else if(z<=w)return dp[x][y][z][w]=z;
            else return dp[x][y][z][w]=w-func(x,y,z-w,w+1);
        }
        else{
            if(z<=w){
                ll p=z-func(0,y,0,w+1);
                ll q=y-func(0,0,z,w+1);
                return dp[x][y][z][w]=max(p,q);
            }
            else if(y<=w){
                ll p=w-func(0,y,z-w,w+1);
                ll q=y-func(0,0,z,w+1);
                return dp[x][y][z][w]=max(p,q);
            }
            else{
                ll p=w-func(0,y,z-w,w+1);
                ll q=w-func(0,y-w,z,w+1);
                return dp[x][y][z][w]=max(p,q);
            }
        }
    }
    else{
        if(z<=w){
            ll p=z-func(x,y,0,w+1);
            ll q=y-func(x,0,z,w+1);
            ll r=x-func(0,y,z,w+1);
            return dp[x][y][z][w]=max({p,q,r});
        }
        else if(y<=w){
            ll p=w-func(x,y,z-w,w+1);
            ll q=y-func(x,0,z,w+1);
            ll r=x-func(0,y,z,w+1);
            return dp[x][y][z][w]=max({p,q,r});
        }
        else if(x<=w){
            ll p=w-func(x,y,z-w,w+1);
            ll q=w-func(x,y-w,z,w+1);
            ll r=x-func(0,y,z,w+1);
            return dp[x][y][z][w]=max({p,q,r});
        }
        else{
            ll p=w-func(x,y,z-w,w+1);
            ll q=w-func(x,y-w,z,w+1);
            ll r=w-func(x-w,y,z,w+1);
            return dp[x][y][z][w]=max({p,q,r});

        }
    };
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>c;
    ll t=func(a,b,c,1);
    if(t>0){
        cout<<"F";
    }
    else if (t==0){
        cout<<"D";
    }
    else cout<<"S";

    return 0;
}