#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,nx,ny,n;
    cin>>x>>y>>n;
    while(n--){
        cin>>nx>>ny;
        cout<<(nx==x||ny==y?0:1)<<"\n";
    }
}