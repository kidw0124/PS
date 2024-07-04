#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve() {
    ll i,j,k;
    ll n, m;
    cin>>n>>m;
    vector<string>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
        for(j=0;j<m;j++){
            arr[i][j]=([](char x){
                switch (x) {
                    case '-':return '|';
                    case '|':return '-';
                    case '\\':return '/';
                    case '/':return '\\';
                    case '^':return '<';
                    case '<':return 'v';
                    case 'v':return '>';
                    case '>':return '^';
                }
                return x;
            })(arr[i][j]);
        }
    }
    for(i=m-1;i>=0;i--){
        for(j=0;j<n;j++){
            cout<<arr[j][i];
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