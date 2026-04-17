#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){

    ll i,j,k;

    ll n;

    cin>>n;

    vector<ll>arr(n);

    for(i=0;i<n;i++){

        cin>>arr[i];

    }

    for(i=0;i<n;i++){

        cin>>j;

        arr[i]-=j;

    }

    cout<<count_if(arr.begin(),arr.end(),[](ll x){

                   return x<=0;

                   });

}

