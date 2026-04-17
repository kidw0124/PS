#include<bits/stdc++.h>

#pragma warning(disable:4996)

#pragma comment(linker, "/STACK:336777216")

using namespace std; typedef long long ll; typedef long long LL; typedef pair<int, int> pii; typedef vector<int> vi; typedef pair<ll, ll> pll; typedef vector<ll> vl;

int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    ll i,j;

    ll n,d;

cin>>n>>d;

    vector<ll>arr(d);

    iota(arr.begin(),arr.end(),0);

    arr[0]=1,arr[1]=0;

    do{

        ll x=0;

        for(i=0;i<d;i++){

            x*=d;

            x+=arr[i];

            }

        if(x>n){

            cout<<x;

            return 0;

            }

        }while(next_permutation(arr.begin(),arr.end()));

    cout<<-1;

    return 0;

}
        