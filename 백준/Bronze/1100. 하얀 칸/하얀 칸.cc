#include<bits/stdc++.h>
using namespace std;
int main(){
    int cnt=0,i;
    char x;
    for(i=0;i<32;i++){
        cin>>x;
        if(x!='.'&&i/4%2==0)cnt++;
        cin>>x;
        if(x!='.'&&i/4%2!=0)cnt++;
    }
    cout<<cnt;
}