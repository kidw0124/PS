#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int x,y;
int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

int lcm(int a, int b){
    return a*b/gcd(a,b);
}

int main(){
    int i,j;    
    cin>>x>>y;
    
    cout<<gcd(x,y)<<endl<<lcm(x,y);
    
    return 0;
}