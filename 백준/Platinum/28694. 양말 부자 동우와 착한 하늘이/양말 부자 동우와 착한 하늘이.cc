#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t, n, m;
    ll r2 = (MOD+1)/2, r4 = (MOD+1)/4;
    cin >> t;
    while(t--){
        cin >> n >> m;
        n%=MOD;
        cout<< n*r2%MOD << ' ' << n*r4%MOD << '\n';
    }
    return 0;
}