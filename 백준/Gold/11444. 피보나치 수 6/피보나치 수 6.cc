#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD=1e9+7;

struct Matrix2{
    ll a[2][2];
    Matrix2(){
        a[0][0]=1;
        a[0][1]=0;
        a[1][0]=0;
        a[1][1]=1;
    }
    Matrix2 operator*(const Matrix2& b){
        Matrix2 c;
        c.a[0][0]=(a[0][0]*b.a[0][0]+a[0][1]*b.a[1][0])%MOD;
        c.a[0][1]=(a[0][0]*b.a[0][1]+a[0][1]*b.a[1][1])%MOD;
        c.a[1][0]=(a[1][0]*b.a[0][0]+a[1][1]*b.a[1][0])%MOD;
        c.a[1][1]=(a[1][0]*b.a[0][1]+a[1][1]*b.a[1][1])%MOD;
        return c;
    }
    Matrix2 operator^(ll b){
        Matrix2 c;
        Matrix2 d=*this;
        while(b){
            if(b&1)c=c*d;
            d=d*d;
            b>>=1;
        }
        return c;
    }
};

ll fibo(ll n){
    if(n==0)return 1;
    if(n==1)return 1;
    Matrix2 mat;
    mat.a[0][0]=1;
    mat.a[0][1]=1;
    mat.a[1][0]=1;
    mat.a[1][1]=0;
    mat=mat^(n);
    return mat.a[0][0];
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    if(argc > 1){
        string argv1=argv[1];
        if(argv1=="--input"){
            freopen(argv[2],"r",stdin);
            freopen(argv[3],"w",stdout);
        }
    }
    ll t;
    t=1;
    while(t--){
        ll n;
        cin>>n;
        n--;
        cout<<fibo(n)<<' ';
    }
    cout<<'\n';
}