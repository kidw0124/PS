#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct vct{
    ld x,y,z;
    vct outer(const vct&r)const{
        return {
            y*r.z-z*r.y,
            z*r.x-x*r.z,
            x*r.y-y*r.x
        };
    }
    ld norm2()const{
        return x*x+y*y+z*z;
    }
    ld norm()const{
        return sqrt(norm2());
    }
    vct operator*(const ld&r)const{
        return {
            x*r,y*r,z*r
        };
    }
    vct operator/(const ld&r)const{
        return (*this)*(1/r);
    }
    vct unit()const{
        return (*this)/norm();
    }
    vct operator+(const vct&r)const{
        return{
            x+r.x,
            y+r.y,
            z+r.z
        };
    }
    vct operator-()const{
        return{
            -x,-y,-z
        };
    }
    vct operator-(const vct&r)const{
        return (*this)+(-r);
    }
    ld dist(const vct&r)const{
        return ((*this)-r).norm();
    }
    void input(){
        cin>>x>>y>>z;
    }
};

void solve() {
    vct a,n;
    ld l,h;
    n.input(),a.input(),cin>>l>>h;
    vct nn=n.unit();
    vct b=nn.outer(a)*sqrt((ld)3)/2-a/2,c=-(nn.outer(a)*sqrt((ld)3)/2)-a/2;
    vct pp={0,0,-h};
    cout<<fixed<<setprecision(6)<<pp.dist(a)<<' '<<pp.dist(b)<<' '<<pp.dist(c)<<'\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}