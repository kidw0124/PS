#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod=1'000'000;

struct Matrix22{
    ll a,b,c,d;
    void rem(ll mod){
        a%=mod;
        b%=mod;
        c%=mod;
        d%=mod;
    }
    Matrix22 operator*(const Matrix22 & r)const{
        Matrix22 ret;
        ret.a = a*r.a + b*r.c;
        ret.b = a*r.b + b*r.d;
        ret.c = c*r.a + d*r.c;
        ret.d = c*r.b + d*r.d;
        ret.rem(mod);
        return ret;
    }

    Matrix22 operator^(ll r)const{
        Matrix22 ret({1,0,0,1});
        if(r==0){
            return ret;
        }
        else{
            ret=(*this)^(r>>1);
            ret=ret*ret;
            if(r&1){
                return ret*(*this);
            }
            return ret;
        }
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    Matrix22 mat({1,1,1,0}),temp({1,0,0,0});
    mat= mat^(n-1);
    mat=mat*temp;
    cout<<mat.a;
}
