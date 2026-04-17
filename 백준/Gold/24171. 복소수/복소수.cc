#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

class realnum{
private:
    void mult(ll x){
        a*=x,b*=x,c*=x;
    }
    void div(ll x){
        a/=x,b/=x,c/=x;
    }
public:
    ll a,b,c,d;
    void stabilize(){
        if(a<0)mult(-1);
        div(max(1ll,abs(gcd(gcd(a,b),c))));
    }
    realnum(){}
    realnum(ll a, ll b, ll c, ll d){
        this->a=a;
        this->b=b;
        this->c=c;
        this->d=d;
    }
    realnum operator+(const realnum&r)const{
        realnum tl=*this,tr=r;
        tl.mult(r.a),tr.mult(this->a);
        tl.b+=tr.b,tl.c+=tr.c;
        tl.stabilize();
        return tl;
    }
    realnum operator-(const realnum&r)const{
        realnum tr=r;
        tr.mult(-1);
        tr.a*=-1;
        return *this+tr;
    }
    realnum operator*(const realnum&r)const{
        realnum t(a*r.a,b*r.b+c*r.c*d,b*r.c+c*r.b,d);
        t.stabilize();
        return t;
    }
    realnum operator/(const realnum&r)const{
        realnum tr(r.b*r.b-r.c*r.c*d,r.a*r.b,r.a*r.c*-1,d);
        return *this*tr;
    }
};
ostream& operator<<(ostream&x,const realnum&r){
    return x<<r.a<<' '<<r.b<<' '<<r.c<<' '<<(r.c?r.d:0)<<' ';
}
istream& operator>>(istream&x,realnum&r){
    return x>>r.a>>r.b>>r.c>>r.d;
}

class complexnum{
public:
    realnum a,b;
    complexnum operator+(const complexnum&r){
        realnum t=a+r.a,tt=b+r.b;
        t.stabilize(),tt.stabilize();
        return {t,tt};
    }
    complexnum operator-(const complexnum&r){
        realnum t=a-r.a,tt=b-r.b;
        t.stabilize(),tt.stabilize();
        return {t,tt};
    }
    complexnum operator*(const complexnum&r){
        realnum t=a*r.a-b*r.b,tt=a*r.b+b*r.a;
        t.stabilize(),tt.stabilize();
        return {t,tt};
    }
    complexnum operator/(const complexnum&r){
        complexnum tr={r.a/(r.a*r.a+r.b*r.b),r.b/(r.b*r.b+r.a*r.a)};
        tr.b.a*=-1;
        return *this*tr;
    }
};
ostream& operator<<(ostream&x,const complexnum&r){
    return x<<r.a<<r.b<<'\n';
}
istream& operator>>(istream&x,complexnum&r){
    return x>>r.a>>r.b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    complexnum a,b;
    cin>>a>>b;
    cout<<a+b<<a-b<<a*b<<a/b;

    return 0;
}
