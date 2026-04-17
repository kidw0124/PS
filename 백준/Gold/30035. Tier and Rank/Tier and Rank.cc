#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll i,j,k;
    ll n,m,r,p=0;
    cin>>n>>m;
    vector<ll>arr(m);
    vector<string>vct(m);
    map<string,ll>mp;
    for(i=0;i<m;i++){
        cin>>vct[i];
        string str;
        cin>>str;
        mp[vct[i]]=i;
        if(str.back()=='%'){
            arr[i]=stoll(str.substr(0,str.size()-1))*n/100;
            n-=arr[i];
        }
        else {
            arr[i]=min(n,stoll(str));
            n-=arr[i];
        }
    }
    if(n){
        cout<<"Invalid System";
        return 0;
    }
    else{
        string str;
        cin>>str;
        ll tier=0;
        if(isdigit(str.back())){
            tier=str.back()-'0';
            str.pop_back();
        }
//        for(auto k:arr)cout<<k<<' ';cout<<'\n';
        ll idx=mp[str];
        ll sum=0;
        for(i=0;i<idx;i++)sum+=arr[i];
        if(tier){
            ll p=(arr[idx]+3)/4;
            for(i=0;i<tier-1;i++){
                arr[idx]-=p;
                sum+=p;
            }
            if(arr[idx]<=0){
                cout<<"Liar";
            }
            else{
                cout<<sum+1<<' '<<min(sum+p,sum+arr[idx]);
            }
        }
        else{
            if(!arr[idx])cout<<"Liar";
            else cout<<sum+1<<' '<<sum+arr[idx];
        }
    }
}
