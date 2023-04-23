#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int a=0,y;
        while(n--){
            cin>>y;
            a+=y;
        }
        cout<<a<<'\n';
    }
}