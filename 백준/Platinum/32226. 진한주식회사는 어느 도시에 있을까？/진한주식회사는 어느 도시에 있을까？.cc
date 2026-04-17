#include<bits/stdc++.h>

#pragma comment(linker, "/STACK:336777216")

#pragma GCC optimize("O3,unroll-loops")

#pragma GCC target("avx,avx2,fma")

using namespace std;

using ll = long long;

using LL = __int128;

using pll = pair<ll, ll>;

using ld = long double;

const ld PI = acos((ld)-1);

void preprocess() {

    ;

}

ld circle(ld r){

    return PI*r*r;

}

ld triangle(ld a, ld b, ld c){

    ld s = (a+b+c)/2;

    return sqrt(s*(s-a)*(s-b)*(s-c));

}

ld get_inter(ld r1, ld r2, ld d){

    ld x = (r1*r1 - r2*r2 + d*d)/(2*d);

    ld y = (r2*r2 - r1*r1 + d*d)/(2*d);

    ld theta_x = acos(x/r1), theta_y = acos(y/r2);

    return r1*r1*theta_x + r2*r2*theta_y - x*sqrt(r1*r1 - x*x) - y*sqrt(r2*r2 - y*y);

}

void solve() {

    ll i,j;

    ll a,b,c;

    cin>>a>>b>>c;

    if(a*a+ b*b > c*c){

        cout<<fixed<<setprecision(10)<<triangle(a,b,c)*4-(circle(a)+circle(b)+circle(c))/2

                    +(get_inter(a,b,c)+get_inter(b,c,a)+get_inter(c,a,b))<<'\n';

    }

    else{

        cout<<fixed<<setprecision(10)<<get_inter(a,b,c)<<'\n';

    }

}

int main() {

#ifdef kidw0124

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

    clock_t beg = clock();

#else

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cout.tie(0);

#endif

    preprocess();

    ll t=1;

//    cin>>t;

    while(t--)solve();

#ifdef kidw0124

    cout<<clock()-beg<<"ms\n";

#endif

}