#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

LL n,p,q,x,y;

map<LL,LL>a;
LL f(LL s){
    if(s<=0) return 1;
    if(a.find(s)!=a.end()) return a[s];
    return a[s]=f(s/p-x)+f(s/q-y);
}

int main(){
    ios_base::sync_with_stdio(false);
    int i,j;
    cin>>n>>p>>q>>x>>y;

    cout<<f(n);


    return 0;
}
