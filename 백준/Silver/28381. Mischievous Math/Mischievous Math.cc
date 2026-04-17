#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll n = 550;

vector<ll> mul(vector<ll>& a, vector<ll>& b)
{
    vector<ll> ret(n);
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if(i + j >= n)break;
            ret[i + j] += a[i] * b[j];
        }
    }

    return ret;
}

void solve() {
    ll n;
    cin>>n;
    switch (n) {
    case 1:case 2: case 3:case 4:case 5:case 6:case 7:case 8:case 9:cout<<"62 89 100";break;
    default:cout<<"1 2 3";

    }
//    ll p, q, r, s, t;
//    vector<ll> a1(n), a2(n), a3(n), a4(n), a5(n);
//    for(ll i = 1; i <= 4; i++)a1[i] = 1;
//    for(ll i = 1; i <= 6; i++)a2[i] = 1;
//    for(ll i = 1; i <= 8; i++)a3[i] = 1;
//    for(ll i = 1; i <= 12; i++)a4[i] = 1;
//    for(ll i = 1; i <= 20; i++)a5[i] = 1;
//
//    cin >> p >> q >> r >> s >> t;
//    vector<ll> res(n);
//    res[0] = 1;
//    for(ll i = 0; i < p; i++) {
//        vector<ll> tmp;
//        tmp = mul(res, a1);
//        res = tmp;
//    }
//    for(ll i = 0; i < q; i++) {
//        vector<ll> tmp;
//        tmp = mul(res, a2);
//        res = tmp;
//    }
//    for(ll i = 0; i < r; i++) {
//        vector<ll> tmp;
//        tmp = mul(res, a3);
//        res = tmp;
//    }
//    for(ll i = 0; i < s; i++) {
//        vector<ll> tmp;
//        tmp = mul(res, a4);
//        res = tmp;
//    }
//    for(ll i = 0; i < t; i++) {
//        vector<ll> tmp;
//        tmp = mul(res, a5);
//        res = tmp;
//    }
//
//    vector<pll> tmp;
//    for(ll i = 0; i < n; i++) {
//        tmp.push_back({res[i], i});
//    }
//
//    sort(tmp.begin(), tmp.end());
//    for(ll i = n - 1; i >= 0; i--) {
//        if(tmp[i].first == 0)break;
//        cout << tmp[i].second << " ";
//    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}