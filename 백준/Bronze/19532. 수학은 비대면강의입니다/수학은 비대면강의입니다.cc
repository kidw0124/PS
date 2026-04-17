#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    cout<<(c*e-b*f)/(a*e-b*d)<<' '<<(c*d-a*f)/(b*d-a*e);

}
