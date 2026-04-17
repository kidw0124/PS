#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

LL n,t;

LL loc[100005];
LL fin[100005];

int main(){
    LL i,j;

    cin>>n>>t;
    for(i=0;i<n;i++){
        cin>>loc[i];
        LL p;
        cin>>p;
        fin[i]=loc[i]+p*t;
    }
    LL k=loc[0];
    sort(loc,loc+n);
    sort(fin,fin+n);
    for(i=0;i<n;i++){
        if(k==loc[i]){
            cout<<fin[i];
            return 0;
        }
    }

    return 0;
}
