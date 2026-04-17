#include<bits/stdc++.h>

using namespace std;

using ll = long long;

using ld = long double;

#ifdef DWOO

constexpr bool ddebug = true;

#else

constexpr bool ddebug = false;

#endif

#define debug if constexpr(ddebug) cout << "[DEBUG] "

#define debugv(x) if constexpr (ddebug) cout << "[DEBUG] " << #x << " == " << x << '\n';

void setup(){

#ifdef DWOO

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

#else

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#endif

}

void preprocess(){

}

void solve(ll testcase){

    ll n,i,j;

    cin>>n;

    for(i=0;i<n;i++){

        cin>>j;

        if(j==300)cout<<"1 ";

        else if(j>=275)cout<<"2 ";

        else if(j>=250)cout<<"3 ";

        else cout<<"4 ";

    }

}

int main(){

    setup();

    preprocess();

    ll t=1;

//    cin>>t;

    for(ll testcase = 1; testcase<=t;testcase++)solve(testcase);

}