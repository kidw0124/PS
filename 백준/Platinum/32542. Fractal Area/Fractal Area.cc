#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void setup() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}
constexpr ll mod=1e9+7;
pair<long double, long double> a[1010];

void solve(ll tc){
    int i, N; cin>>N;
    long double sq = 0;
    for(i=0; i<N; i++) cin>>a[i].first>>a[i].second;
    for(i=1; i<N; i++) {
        sq += (a[i].first - a[i-1].first) * (a[i].first - a[i-1].first)
                + (a[i].second - a[i-1].second) * (a[i].second - a[i-1].second);
    }
    long double area = 0;
    for(i=0; i<N-1; i++) area += (a[i].first * a[i+1].second);
    for(i=0; i<N-1; i++) area -= (a[i].second * a[i+1].first);
    area *= -1; area /= 2;
    long double triangle = sqrt( (long double) 3.0) / 4;
    if(area == 0) {
        cout.precision(12);
        cout<<fixed;
        cout<<triangle;
        return;
    }
    long double alpha = area / triangle;

    long double ans = triangle * (1 + (3 * alpha) / (1 - sq));

    cout.precision(12);
    cout<<fixed;
    cout<<ans;

}

void preprocess(){
    ll i,j,k;
}

int main(){
    setup();preprocess();
    ll t=1;
//    cin>>t;
    for(ll i=0;i<t;i++){
        solve(t+1);
    }
    return 0;
}