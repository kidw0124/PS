#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n,k;

double lnp=0,lnpp=0,lnppp=0;
double num[10];
double numb;

int main(){
    int i,j;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        lnp+=log(i);
    }
    for(int i=1;i<=k;i++){
        lnpp+=log(i);
    }
    for(int i=1;i<=n-k;i++){
        lnppp+=log(i);
    }

    double lp=lnp-lnpp-lnppp+0.00000001;

    LL ans=floor(exp(lp));

    printf("%lld",ans);

    return 0;
}
