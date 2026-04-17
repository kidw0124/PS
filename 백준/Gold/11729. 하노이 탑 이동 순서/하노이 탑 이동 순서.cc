#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
void ans(ll n, int s, int e){
    if(n){
        ans(n-1,s,6-s-e);
        printf("%d %d\n",s,e);
        ans(n-1,6-s-e,e);
    }
}

int main(){
    scanf("%lld",&n);
    printf("%lld\n",((ll)1<<n)-1);
    ans(n,1,3);
}
