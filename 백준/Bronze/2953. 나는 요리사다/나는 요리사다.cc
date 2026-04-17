#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,sum=0,ans1=0,ans2=-1;
    for(i=1;i<=5;i++){
        sum=0;
        int t;
        cin>>t;
        sum+=t;
        cin>>t;
        sum+=t;
        cin>>t;
        sum+=t;
        cin>>t;
        sum+=t;
        if(sum>ans2)ans1=i,ans2=sum;
    }
    cout<<ans1<<' '<<ans2;
}