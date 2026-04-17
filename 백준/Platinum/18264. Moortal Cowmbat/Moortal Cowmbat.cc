#include<bits/stdc++.h>
using namespace std;
#define MAX_NODE 100001

typedef long long LL;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

int cost[27][27];
LL pre[100005][27];
LL arr[100005][27];
LL n,m,k;
char str[100005];

void floyd_w(){
    int d[27][27];
    LL i,j,k;
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            d[i][j]=cost[i][j];
        }
    }
    for(k=0;k<m;k++){
        for(i=0;i<m;i++){
            for(j=0;j<m;j++){
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            cost[i][j]=d[i][j];
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  //  freopen("cowmbat.in","r",stdin);
  //  freopen("cowmbat.out","w",stdout);
    scanf("%lld %lld %lld",&n,&m,&k);
    scanf(" %s",str);
    LL i, j, f;
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    floyd_w();
    for(j=0;j<m;j++){
        pre[0][j]=cost[(int)(str[0]-'a')][j];
    }
    for(i=1;i<n;i++){
        for(j=0;j<m;j++){
            pre[i][j]=pre[i-1][j]+cost[(int)(str[i]-'a')][j];
        }
    }
    for(i=0;i<m;i++){
        arr[n-k][i]=pre[n-1][i]-((n-k==0)?0:(pre[n-k-1][i]));
    }
    for(i=n-k-1;i>=0;i--){
        for(j=0;j<m;j++){
            arr[i][j]=arr[i+1][j]+cost[(int)(str[i]-'a')][j];
            if(i<=n-2*k){
                for(f=0;f<m;f++){
                    LL tmp=arr[i+k][f]+pre[i+k-1][j]-pre[i-1][j];
                    if(tmp<arr[i][j])arr[i][j]=tmp;
                }
            }
        }
    }
    LL maxi=999999999;
    for(i=0;i<m;i++){
        if(maxi>arr[0][i])maxi=arr[0][i];
    }
    cout<<maxi;

    return 0;
}
