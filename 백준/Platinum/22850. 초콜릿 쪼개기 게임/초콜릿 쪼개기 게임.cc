#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,m;
    cin>>n>>m;
    if(n>m)swap(n,m);
    const ll period=34;
    const ll stperiod=1000;
    vector<ll>grundy1(stperiod+period+1);
    grundy1[1]=0;
    grundy1[2]=0;
    grundy1[3]=1;
    grundy1[4]=1;
    grundy1[5]=2;
    for(i=6;i<=stperiod+period;i++){
        set<ll> st;
        for(j=1;j<=i-2;j++){
            st.insert(grundy1[j]^grundy1[i-j-1]);
        }
        vector<ll>vec;
        for(auto k:st){
            vec.push_back(k);
        }
        for(j=0;j<vec.size();j++){
            if(vec[j]!=j){
                grundy1[i]=j;
                break;
            }
        }
        if(j==vec.size()){
            grundy1[i]=j;
        }
    }
    if(n>stperiod){
        n=(n-stperiod)%period+stperiod;
    }
    if(m>stperiod){
        m=(m-stperiod)%period+stperiod;
    }
    cout<<((grundy1[n]+grundy1[m])?"sh":"hs");
}
