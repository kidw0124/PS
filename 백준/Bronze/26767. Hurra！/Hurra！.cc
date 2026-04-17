#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%7&&i%11)cout<<i<<'\n';
        else if(i%77==0)cout<<"Wiwat!\n";
        else if(i%11)cout<<"Hurra!\n";
        else cout<<"Super!\n";
    }
}