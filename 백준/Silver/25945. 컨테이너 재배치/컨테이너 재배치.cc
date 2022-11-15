#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, i, sum = 0, cnt, assist, res=0;
    cin>>n;
    vector<ll> a(n, 0);
    for(i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(), a.end());
    cnt=sum/n;
    assist=n-sum%n;
    for(i=0;i<assist;i++){
        res+=abs(a[i]-cnt);
    }
    cnt++;
    for(i=assist;i<n;i++){
        res+=abs(a[i]-cnt);
    }
    cout<<res/2;
    return 0;
}