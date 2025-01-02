#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,s=0;
    cin>>a>>b>>c;
    s=(a-11)*24*60+(b-11)*60+c-11;
    if(s<0)cout<<-1;
    else cout<<s;
}