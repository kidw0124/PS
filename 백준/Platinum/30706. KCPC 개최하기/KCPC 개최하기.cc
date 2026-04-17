#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll i,j;
    ll a,b,c;
    cin >> a >> b >> c;
    vector<pll> arr(a),brr(b),crr(c);
    for(i=0;i<a;i++) cin >> arr[i].first >> arr[i].second;
    for(i=0;i<b;i++) cin >> brr[i].first >> brr[i].second;
    for(i=0;i<c;i++) cin >> crr[i].first >> crr[i].second;
    ll saxx=0,sbxx=0,scxx=0,sayy=0,sbyy=0,scyy=0;
    ll sax=0,sbx=0,scx=0,say=0,sby=0,scy=0;
    ll ans=0;
    for(i=0;i<a;i++){
        sax += arr[i].first;
        say += arr[i].second;
        saxx += arr[i].first * arr[i].first % MOD;
        sayy += arr[i].second * arr[i].second % MOD;
        sax %= MOD;
        say %= MOD;
        saxx %= MOD;
        sayy %= MOD;
    }
    for(i=0;i<b;i++){
        sbx += brr[i].first;
        sby += brr[i].second;
        sbxx += brr[i].first * brr[i].first % MOD;
        sbyy += brr[i].second * brr[i].second % MOD;
        sbx %= MOD;
        sby %= MOD;
        sbxx %= MOD;
        sbyy %= MOD;
    }
    for(i=0;i<c;i++){
        scx += crr[i].first;
        scy += crr[i].second;
        scxx += crr[i].first * crr[i].first % MOD;
        scyy += crr[i].second * crr[i].second % MOD;
        scx %= MOD;
        scy %= MOD;
        scxx %= MOD;
        scyy %= MOD;
    }
    ans += 2 * b * c % MOD * saxx % MOD;
    ans %= MOD;
    ans += 2 * a * c % MOD * sbxx % MOD;
    ans %= MOD;
    ans += 2 * a * b % MOD * scxx % MOD;
    ans %= MOD;
    ans += 2 * b * c % MOD * sayy % MOD;
    ans %= MOD;
    ans += 2 * a * c % MOD * sbyy % MOD;
    ans %= MOD;
    ans += 2 * a * b % MOD * scyy % MOD;
    ans %= MOD;
    
    ans -= 2 * c * sax % MOD * sbx % MOD;
    ans %= MOD;
    ans -= 2 * b * scx % MOD * sax % MOD;
    ans %= MOD;
    ans -= 2 * a * scx % MOD * sbx % MOD;
    ans %= MOD;
    ans -= 2 * c * say % MOD * sby % MOD;
    ans %= MOD;
    ans -= 2 * b * scy % MOD * say % MOD;
    ans %= MOD;
    ans -= 2 * a * scy % MOD * sby % MOD;
    ans %= MOD;

    ans += c * sax % MOD * sby % MOD;
    ans %= MOD;
    ans += b * scx % MOD * say % MOD;
    ans %= MOD;
    ans += a * sbx % MOD * scy % MOD;
    ans %= MOD;
    ans -= c * say % MOD * sbx % MOD;
    ans %= MOD;
    ans -= b * scy % MOD * sax % MOD;
    ans %= MOD;
    ans -= a * sby % MOD * scx % MOD;
    ans %= MOD;

    cout << (ans + MOD) % MOD;
}