#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int mod = 998'244'353;

vector<ll> fwht_xor(vector<ll> &x, bool inv) {

    vector<ll> a = x;

    ll n = a.size();

    for(int s = 2, h = 1; s <= n; s <<= 1, h <<= 1) {

        for(int l = 0; l < n; l += s) {

            for(int i = 0; i < h; i++) {

                ll t = a[l + h + i];

                a[l + h + i] = a[l + i] - t;

                a[l + h + i]%=mod;

                a[l + i] += t;

                a[l + i] %= mod;

                if(inv) a[l + h + i]*= 499122177, a[l + i] *=499122177;

                a[l + h + i]%=mod;

                a[l + i] %= mod;

            }

        }

    }

    return a;

}

vector<ll> xor_convol(vector<ll>&x, vector<ll>&y){

    auto xx= fwht_xor(x,0);

    auto yy= fwht_xor(y,0);

    for(int i=0;i<min(xx.size(),yy.size());i++){

        yy[i]*=xx[i];

        yy[i]%=mod;

    }

    return fwht_xor(yy,1);

}

void solve() {

    int i,j;

    ll n;

    cin>>n;

    string str1,str2;

    cin>>str1>>str2;

    vector<ll>pref1(n),pref2(n);

    pref1[0]=str1[0]-'0';

    pref2[0]=str2[0]-'0';

    for(i=1;i<n;i++){

        pref1[i]=pref1[i-1]^(str1[i]-'0');

        pref2[i]=pref2[i-1]^(str2[i]-'0');

    }

    ll cnt1=std::count(pref1.begin(), pref1.end(),1);

    ll cnt2=std::count(pref2.begin(), pref2.end(),1);

    if(cnt1==0&&cnt2==0)cout<<"YES\n";

    else if(cnt1==0)cout<<"NO\n";

    else if(cnt1==cnt2)cout<<"YES\n";

    else if(n+1-cnt1==cnt2)cout<<"YES\n";

    else cout<<"NO\n";

}

int main() {

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#else

    cin.tie(0)->sync_with_stdio(0);

#endif

    ll t=1;

    cin>>t;

    while(t--)solve();

    return 0;

}