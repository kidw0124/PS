#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,x,n;
    cin>>x>>n;
    while(n--){
        cin>>a>>b;
        x-=a*b;
    }
    cout<<(x?"No":"Yes");
}