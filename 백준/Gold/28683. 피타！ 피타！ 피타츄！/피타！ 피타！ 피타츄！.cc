#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, i, ans=0;
    vector<ll> squares;
    cin >> n;
    for(i=1;i*i<=n;i++){
        squares.push_back(i*i);
    }
    if(binary_search(squares.begin(), squares.end(), n)){
        cout << -1 << "\n";
        return 0;
    }
    for(auto k:squares){
        if(binary_search(squares.begin(), squares.end(), n-k)){
            ans++;
        }
    }
    ans = (ans+1)/2;
    for(i=1;i*i<=n;i++){
        if(n%i==0){
            if(i%2==(n/i)%2){
                ans++;
            }
        }
    }
    cout << ans << "\n";
}
