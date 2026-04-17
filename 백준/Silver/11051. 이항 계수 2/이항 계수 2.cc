#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL mod = 1e4+7;
LL fpow(long long a, int n)
{
    if(n==0)return 1;
    if(n&1){
        return fpow(a,n-1)*a%mod;
    }
    LL half=fpow(a,n>>1);
    return half*half%mod;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    k=min(k,n-k);
    LL ans=1;
    LL f=1;
    for(int i=1;i<=k;++i){
        ans=ans*(n-i+1)%mod;
        f=f*i%mod;
    }
    printf("%lld",ans*fpow(f,mod-2)%mod);
}
