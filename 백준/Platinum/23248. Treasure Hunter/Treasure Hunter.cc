#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef pair<ll, ll> pll;
vector<pll> a;
vector<ll> b;
ll n, m, k, i, res=1, st, ed, md;
int main(){
    ll i,j;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    a.resize(k);
    b.resize(m);
    for(i=0;i<k;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(), a.end());
    b[0]=a[0].second;
    for(i=1;i<k;i++){
        st=0;
        ed=res-1;
        while(st<ed){
            md=(st+ed)/2;
            if(b[md]>a[i].second)st=md+1;
            else ed=md;
        }
        if(b[st]<=a[i].second)b[st]=a[i].second;
        else{
            b[res]=a[i].second;
            res++;
        }
    }
    cout<<res;
}
