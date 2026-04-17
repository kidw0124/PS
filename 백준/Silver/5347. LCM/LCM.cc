#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(max(a,b)==b)swap(a,b);
    if(a%b)return gcd(b,a%b);
    return b;
}

int main(){
    int a,b,t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        int g=gcd(a,b);
        cout<<(long long)a*b/g<<endl;
    }
}
