#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

bool p[1000001];
bool check[1000001];
LL m,M;
LL ans;
int main(){
    cin>>m>>M;
    LL len=M-m;
    for(LL i=2;i*i<=M;i++){
        if(!p[i]){
            for(LL j=i*2;j*j<=M;j+=i){
                p[j]=1;
            }
            LL s=i*i;
            for(LL j=(((m-1)/s)+1)*s;j<=M;j+=s){
                if(j>=m){
                    check[j-m]=1;
                }
            }
        }
    }
    for(int i=0;i<=len;i++){
        if(!check[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
