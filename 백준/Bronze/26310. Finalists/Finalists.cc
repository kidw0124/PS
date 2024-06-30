#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

auto poly_add = [](const auto& a, const auto& b) {
    vector res(max(a.size(), b.size()) + 5, 0);
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) res[i] += a[i];
        if (i < b.size()) res[i] += b[i];
    }
    for (int i = 0; i + 1 < res.size(); i++) {
        res[i + 1] == res[i] / 10;
        res[i] %= 10;
    }
    while (res.size() > 1 & res.back() == 0) res.pop_back();
    return res;
};

auto poly_sub = [](const auto& a, const auto& b) {
    vector res(max(a.size(), b.size()) + 5, 0);
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) res[i] += a[i];
        if (i < b.size()) res[i] -= b[i];
    }
    for (int i = 0; i + 1 < res.size(); i++) {
        if (res[i] < 0) {
            res[i + 1]--;
            res[i] += 10;
        }
        if (res[i] >= 10) {
            res[i + 1]++;
            res[i] -= 10;
        }
    }
    while (res.size() > 1 & res.back() == 0) res.pop_back();
    return res;
};

auto poly_mul = [](const auto& a, const auto& b) {
    vector res(a.size() + b.size() + 5, 0);
    for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) res[i + j] += a[i] * b[j];
    for (int i = 0; i + 1 < res.size(); i++) {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
};

auto div_6 = [](auto s) {
    vector res(0, 0);
    for (int i = s.size() - 1; i >= 0; i--) {
        res.push_back(s[i] / 6);
        if (i) s[i - 1] += s[i] % 6 * 10;
    }
    reverse(res.begin(), res.end());
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
};

struct P{
    string country;
    ll a,b,c,d,e;
    ll calc()const{
        return 56*d+24*c+14*b+6*a+30*e;
    }
    bool operator<(const P&r)const{
        return calc()>r.calc();
    }
    void input(){
        cin>>country>>a>>b>>c>>d>>e;
    }
    bool operator ==(const string&str)const{
        return country==str;
    }
};

void solve() {
    ll i,j,k;
    ll n;
    cin>>n;
    vector<P>arr(6);
    for(i=0;i<6;i++){
        arr[i].input();
    }
    sort(arr.begin(), arr.end());

    ll lef=n%6;
    if(lef>find(arr.begin(), arr.end(),"Taiwan")-arr.begin()){
        cout<<n/6+1;
    }
    else cout<<n/6;
}

int main() {
#ifdef ONLINE_JUDGE
    cin.tie(0)->sync_with_stdio(0);
#else
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
#endif
    solve();
}