#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    ll n,a,b,c;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Scenario #"<<i+1<<":\n";
        cin>>a>>b>>c;
        tie(a,b,c)=tuple{min({a,b,c}),a+b+c-min({a,b,c})-max({a,b,c}),max({a,b,c})};
        if(a*a+b*b==c*c)cout<<"yes\n\n";
        else cout<<"no\n\n";
    }
}
            