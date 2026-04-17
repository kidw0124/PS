#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL dp[54][2500];

LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

int n;

int main(){
    int i,j;
    cin>>n;
    if(n%4==1||n%4==2){
        cout<<"0";
        return 0;
    }
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=2500;j++){
            dp[i][j]=dp[i-1][j];
            if(j>=i)dp[i][j]+=dp[i-1][j-i];
        }
    }
    cout<<(dp[n][(n*(n+1))/4]);


    return 0;
}
