#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        while(n--){
            int a;
            cin>>a;
            if(a>=0)k=max(k,m-a);
        }
        cout<<"The scoreboard has been frozen with "<<k<<" minute"<<(k==1?"":"s")<<" remaining.\n";
    }
    
}