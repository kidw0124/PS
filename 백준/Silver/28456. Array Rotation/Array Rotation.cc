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

    vector<vector<ll>>arr(n+1,vector<ll>(n+1));

    for(i=1;i<=n;i++){

        for(j=1;j<=n;j++){

            cin>>arr[i][j];

        }

    }

    ll q;

    cin>>q;

    while(q--){

        ll p;

        cin>>p;

        if(p==1){

            ll l;

            cin>>l;

            ll tmp=arr[l][n];

            for(i=n;i>=1;i--){

                arr[l][i]=arr[l][i-1];

            }

            arr[l][1]=tmp;

        }

        else{

            vector<vector<ll>>tmp=arr;

            for(i=1;i<=n;i++){

                for(j=1;j<=n;j++){

                    tmp[j][n-i+1]=arr[i][j];

                }

            }

            arr=tmp;

        }

    }

    for(i=1;i<=n;i++){

        for(j=1;j<=n;j++){

            cout<<arr[i][j]<<' ';

        }

    }

}

int main(){

    setup();

    preprocess();

    ll t=1;

//    cin>>t;

    for(ll testcase = 1; testcase<=t;testcase++)solve(testcase);

}