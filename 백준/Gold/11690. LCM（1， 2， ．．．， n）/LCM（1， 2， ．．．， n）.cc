#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL n;
LL cnt_p;

const LL mod=pow(2,32);

int main(){
    long long i,j,lcm=1;
    cin>>n;

    bool*isprime=(bool*)malloc(n+1);
    LL prime[5761456][2];
    if(n>=mod){
        cout<<'0';
        return 0;
    }
    for(i=2;i<=n;i++){
        if(!isprime[i]){
            for(j=i*i;j<=n;j+=i)isprime[j]=1;
            prime[cnt_p++][0]=i;
        }
    }

    for(i=cnt_p-1;i>=0;i--){
        prime[i][1]=floor(log(n)/log(prime[i][0]));
        for(j=0;j<prime[i][1];j++)lcm*=(LL)prime[i][0]%mod;
    }
    cout<<(lcm%mod>=0?lcm%mod:lcm%mod+mod);
    return 0;
}
