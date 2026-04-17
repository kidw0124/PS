#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll arr[100000+5];
ll brr[100000+5];
ll crr[100000+5];
ll drr[100000+5];
ll x,y;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;


    long long i,j;


    for(i=0;i<n;i++){
        cin>>arr[i];
        if(i){
            if(arr[i]%2-arr[i-1]%2)crr[i]=crr[i-1]+1;
            else{
                crr[i]=crr[i-1];
            }
        }
        else crr[i]=0;
    }
    for(i=0;i<n;i++){
        cin>>brr[i];
        if(i){
            if(brr[i]%2-brr[i-1]%2)drr[i]=drr[i-1]+1;
            else{
                drr[i]=drr[i-1];
            }
        }
        else drr[i]=0;
    }

    for(i=0;i<q;i++){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--,b--,c--,d--;
        if(crr[c]-crr[a]||drr[b]-drr[d]){
            cout<<"NO\n";
            continue;
        }
        if(arr[a]%2-brr[b]%2){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
}
