#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

auto calc = [](const pii& line, i64 x) {
    return line.first * x + line.second;
};

auto check = [](const pii& a, const pii& b, const pii& c) -> bool {
    i64 x = a.second - c.second;
    i64 y = c.first - a.first;
    return b.first * x + b.second * y <= c.first * x + c.second + y;
};

auto get_upper_hull = [](auto v) {
    vector res(0, pair(0, 0));
    sort(v.begin(), v.end());
    for (int l = 0, r = 0; l < v.size(); l = r) {
        while (r < v.size() && v[l].first == v[r].first) r++;
        while (res.size() > 1 && check(res.end()[-2], res.back(), v[r - 1])) res.pop_back();
        res.push_back(v[r - 1]);
    }
    return res;
};

void solve() {
    int i,j,k;
    int n;
    cin>>n;
    int m=__lg(n-1)+1;
    if(n==1)m=0;
    cout<<m<<'\n';
    vector<set<pii>>arr(m);
    vector<pii>brr;
    for(i=0;i<m;i++){
        for(j=1;j<=100;j++){
            for(k=1;k<=100;k++){
                arr[i].insert({j,k});
            }
        }
    }
    for(i=1;i<=100;i+=2){
        for(j=1;j<=99;j++){
            brr.push_back({i,j});
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if((i>>j)&1){
                arr[j].erase(brr[i]);
            }
        }
    }
    for(i=0;i<m;i++){
        cout<<arr[i].size()<<' ';
        for(auto [a,b]:arr[i]){
            cout<<a<<' '<<b<<' ';
        }
        cout<<'\n';
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}