#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,sum=0,t,ss;
    cin>>t;
    while(t--){
        sum=0,ss=500;
        for(i=0;i<7;i++){
            int tx;
            cin>>tx;
            if(tx&1);
            else{
                sum+=tx;
                if(ss>tx)ss=tx;
            }
        }
            cout<<sum<<' '<<ss<<'\n';
    }
}