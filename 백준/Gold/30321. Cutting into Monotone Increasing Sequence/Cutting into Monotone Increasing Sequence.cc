#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll INF = 998244353;

struct number{
    string num;
    number(){}
    number(string str):num(str){}
    bool operator<(number&r){
        if(num.size()!=r.num.size()){
            return num.size()<r.num.size();
        }
        else{
           return num<=r.num;
        }
    }
};

void solve() {
    ll i, j, k;
    number a,b;
    cin>>a.num>>b.num;
    string & arr=a.num;
    string & brr=b.num;
    ll maxn=brr.size()+1,n=arr.size();
    vector<vector<ll>>dp(n,vector<ll>(maxn,INT_MAX));
    vector<vector<number>>subs(n,vector<number>(maxn+1));
    for(i=0;i<n;i++){
        subs[i][0].num=arr[i];
        for(j=i+1;j<min(n,i+maxn);j++){
            subs[i][j-i].num=subs[i][j-i-1].num+arr[j];
        }
    }
    for(i=0;i<min(n,maxn);i++){
        number str = subs[0][i];
        if(str<b){
            dp[i][i]=0;
        }
        else break;
    }
    for(i=1;i<n;i++){
        for(j=0;j<min(i,maxn);j++){
            for(k=0;k<min(maxn,i-j);k++){
                if(i==4){
//                    cout<<j;
                }
                if(arr[i-j]!='0'&&subs[i-j-1-k][k]<subs[i-j][j] && subs[i-j][j]<b){
                    dp[i][j]=min(dp[i][j],dp[i-j-1][k]+1);
                }
            }
        }
    }
    ll ans=INT_MAX;
    for(i=0;i<maxn;i++){
        ans=min(ans,dp[n-1][i]);
    }
    if(ans==INT_MAX){
        cout<<"NO WAY";
    }
    else cout<<ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    solve();

    return 0;
}