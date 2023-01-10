#import<bits/stdc++.h>
using namespace std;
int main(){
    int sum=0,a=INT_MAX,t=7,h;
    while(t--){
        cin>>h;
        if(h&1){
            sum+=h;
            a=min(a,h);
        }
    }
    if(sum==0)cout<<-1;
    else cout<<sum<<' '<<a;
    
}