#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
        if(i%6==0){
            cout<<"Go! ";
        }
    }
    if(n%6!=0)cout<<"Go!";
}