#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    if(n<=2)cout<<"-1\n";
    else{
        for(int i=0;i<n;i++){
            cout<<i<<" "<<i*(i+1)/2<<"\n";
        }
    }
}