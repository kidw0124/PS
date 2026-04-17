#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c=0,d=1,e=0;
    cin>>a>>b;
    for(int i=1;i<=b;i++){
        if(a<=i)e+=d;
        if(++c>=d)c=0,d++;
    }
    cout<<e;
}