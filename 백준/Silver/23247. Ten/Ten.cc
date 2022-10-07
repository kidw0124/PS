#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll m,n;
int main(){
    ll i,j;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>n;
    ll arr[305][305]={0};
    ll prefi[305][305]={0};
    for(int i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>arr[i][j];
            prefi[i+1][j+1]=arr[i][j]+prefi[i][j+1]+prefi[i+1][j]-prefi[i][j];
        }
    }
    ll ans=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            for(ll k=0;k<10;k++){
                for(ll p=0;p<10;p++){
                    if(i+k>=m||j+p>=n)break;
                    if(prefi[i+k+1][j+p+1]-prefi[i][j+p+1]-prefi[i+k+1][j]+prefi[i][j]==10)ans++;
                }
            }
        }
    }
    cout<<ans;
}
