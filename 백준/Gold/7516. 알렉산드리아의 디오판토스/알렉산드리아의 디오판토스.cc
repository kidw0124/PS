#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,t;
    cin>>t;
    for(int testcase=0;testcase<t;testcase++){
        ll n;
        cin>>n;
        //n*=n;
        ll sn;
        vector<ll>primes;
        vector<ll>factorize;
        vector<bool>isprime(sn=ceil(sqrt(n)));
        for(i=2;i<=sn;i++){
            if(isprime[i])continue;
            primes.push_back(i);
            for(j=i*2;j<=sn;j+=i){
                isprime[j]=1;
            }
        }
        factorize.resize(primes.size(),0);
        auto k=primes.begin();
        int x=0;
        for(;k!=primes.end();){
            if(n%(*k)==0){
                n/=(*k);
    //            cout<<n<<'\n';
                factorize[x]++;
    //            cout<<factorize[x]<<' '<<x<<'\n';
            }
            else{
                k++;
                x++;
            }
        }
        ll ans=1;
        if(n>1){
            ans=3;
        }
        for(i=0;i<factorize.size();i++){
            factorize[i]*=2;
    //        cout<<i<<' '<<factorize[i]<<'\n';
            ans*=factorize[i]+1;
        }
        cout<<"Scenario #"<<testcase+1<<":\n";
        cout<<(ans+1)/2<<"\n\n";
    }
}
