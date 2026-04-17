#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    if(b>=45)cout<<a<<' '<<b-45;
    else{
        b+=15;
        if(a)a--;
        else a=23;
        cout<<a<<' '<<b;
    }
}