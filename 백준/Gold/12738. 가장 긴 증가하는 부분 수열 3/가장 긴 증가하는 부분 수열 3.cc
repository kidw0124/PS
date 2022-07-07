#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lds(const vector<ll>&);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]*=-1;
    }
    cout<<lds(a);
}

ll lds(const vector<ll>&arr){
    // lds with lower bound
    vector<ll> lds_seq;
    lds_seq.push_back(arr[0]);
    for(ll i=1;i<arr.size();i++){
        if(arr[i]<lds_seq.back()){
            lds_seq.push_back(arr[i]);
        }
        else{
            ll j=lower_bound(lds_seq.begin(),lds_seq.end(),arr[i],greater<>())-lds_seq.begin();
            lds_seq[j]=arr[i];
        }
    }
    return lds_seq.size();
}