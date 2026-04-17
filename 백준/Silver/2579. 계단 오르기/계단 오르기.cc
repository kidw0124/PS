#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>arr;
map<pair<int, int>,int>dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }
    dp[make_pair(0,0)]=0;
    dp[make_pair(0,1)]=0;
    dp[make_pair(1,0)]=0;
    dp[make_pair(1,1)]=arr[0];
    dp[make_pair(2,0)]=arr[1];
    dp[make_pair(2,1)]=arr[0]+arr[1];
    for(int i=3;i<=n;i++){
        int m1,m2,m3;
        m1=max(dp[make_pair(i-2,0)],dp[make_pair(i-2,1)]);

        dp[make_pair(i,0)]=m1?m1+arr[i-1]:0;
        dp[make_pair(i,1)]=dp[make_pair(i-1,0)]?dp[make_pair(i-1,0)]+arr[i-1]:0;
        //cout<<dp[make_pair(i,0)]<<' '<<dp[make_pair(i,1)]<<'\n';
    }
    cout<<max(dp[make_pair(n,0)],dp[make_pair(n,1)]);
}
