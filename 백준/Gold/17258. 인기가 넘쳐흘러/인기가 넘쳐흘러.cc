#include<bits/stdc++.h>

using namespace std;

int main(){

    int i,j;

    int n,m,k,t;

    cin>>n>>m>>k>>t;

    vector<int>arr(n+1,-t);

    for(i=0;i<m;i++){

        int a,b;

        cin>>a>>b;

        for(j=a;j<b;j++){

            arr[j]++;

        }

    }

    vector<vector<int>>dp(n+1,vector<int>(k+1));

    for(i=1;i<=n;i++){

        int nex=i;

        while(nex<=n&&arr[nex]<0)nex++;

        if(i==nex){

            for(j=0;j<=k;j++){

                dp[i][j]=max(dp[i][j],dp[i-1][j]+(arr[i]>=0));

            }

        }

        else{

            for(j=0;j<=k;j++){

                for(m=0;m<=k-j;m++){

                    dp[i][j+m]=max({dp[i][j+m],dp[i-1][j]+(arr[i]+m>=0)});

                    for(int p=i+1;p<nex;p++){

                        dp[p][j+m]=max({dp[p][j+m],dp[p-1][j+m]+(arr[p]+m>=0)});

                    }

                }

            }

            i=nex-1;

        }

    }

    int ans=0;

    for(i=0;i<=n;i++)for(j=0;j<=k;j++)ans=max(ans,dp[i][j]);

    cout<<ans;

}