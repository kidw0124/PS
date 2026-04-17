#include<bits/stdc++.h>

using namespace std;

using ll = long long;

using ld = long double;

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;

    cin>>n;

    vector<pair<ll, ll>> arr(n);

    ll sx=0, sy=0, sxx=0, sxy=0;

    for(ll i=0;i<n;i++){

        cin>>arr[i].first>>arr[i].second;

        sx+=arr[i].first;

        sy+=arr[i].second;

        sxx+=arr[i].first*arr[i].first;

        sxy+=arr[i].first*arr[i].second;

    }

    if(n*sxx-sx*sx==0){

        cout<<"EZPZ\n";

        return 0;

    }

    else{

        ld a=(ld)(n*sxy-sx*sy)/(n*sxx-sx*sx);

        ld b=(ld)(sy-a*sx)/n;

        cout<<fixed<<setprecision(3)<<a<<' '<<b<<'\n';

    }

}