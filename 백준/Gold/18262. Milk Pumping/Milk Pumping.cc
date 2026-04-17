
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

int n, m;
vector< pair< LL, LL > > maxi (1005, make_pair(10000,1));
int cost[1005][1005];
int flow[1005][1005];
int flowbin[1005];
vector<pair<LL, LL> > a[1005];

LL eff=0;
LL INF = 10000000000000;
LL mico(LL mf){
    LL d[1005];
    LL i;
    for(i=0;i<1005;i++)d[i]=INF;
    d[1]=0;
    priority_queue< pair<LL,LL> > pq;
    pq.push(make_pair(0,1));
    while(!pq.empty()){
        LL current_cost=-pq.top().first;
        LL current_node=pq.top().second;
        pq.pop();
        LL s=a[current_node].size();
        for (LL i = 0; i < s; i++) {
			LL next_node = a[current_node][i].first;
			LL stopby_cost = a[current_node][i].second;
            if(flow[current_node][next_node]>=mf){
                LL total_cost = current_cost + stopby_cost;
                if (d[next_node] > total_cost) {
                    d[next_node] = total_cost;
                    pq.push(make_pair(-total_cost, next_node));
                }
            }
		}
    }
    return d[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL i,j, t1, t2, t3, t4;
   // freopen("pump.out","w",stdout);
  //  freopen("pump.in","r",stdin);
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%lld %lld %lld %lld",&t1,&t2,&t3,&t4);
        flow[t1][t2]=t4;
        cost[t1][t2]=t3;
        flow[t2][t1]=t4;
        cost[t2][t1]=t3;
        flowbin[i]=t4;
        a[t1].push_back(make_pair(t2,t3));
        a[t2].push_back(make_pair(t1,t3));
    }
    for(i=0;i<m;i++){
        LL mc=mico((LL)flowbin[i]);
        eff=max(eff,((LL)flowbin[i]*1000000)/((LL)mc));
    }
    printf("%lld",eff);



    return 0;
}
