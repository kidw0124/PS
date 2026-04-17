#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a;
    cin>>a>>n;
    while(n--){
        if(a&1)a=a<<1^6;
        else a=a>>1^6;
    }
    cout<<a;
}