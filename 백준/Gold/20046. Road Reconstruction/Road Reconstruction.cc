#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;

const ll mn=1000+5;

ll dijk[mn][mn],arr[mn][mn];
bool vvisit[mn][mn];


ll ddx[4]={0,0,1,-1};
ll ddy[4]={1,-1,0,0};

priority_queue<pair<ll,pair<ll,ll> > > que;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    ll i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            dijk[i][j]=999999;
            cin>>arr[i][j];
        }
    }
    dijk[0][0]=arr[0][0];
    que.push({-arr[0][0],{0,0}});
    if(arr[0][0]==-1){
        cout<<-1;
        return 0;
    }
    while(!que.empty()){
        ll cost=-que.top().first;
        pair<ll,ll> now=que.top().second;
        que.pop();
        if(vvisit[now.first][now.second])continue;
        if(now.first==n-1&&now.second==m-1){
            cout<<cost;
            return 0;
        }
        vvisit[now.first][now.second]=1;
        for(i=0;i<4;i++){
            if(now.first+ddx[i]<0||now.first+ddx[i]>=n||now.second+ddy[i]<0||now.second+ddy[i]>=m)continue;
            if(arr[now.first+ddx[i]][now.second+ddy[i]]==-1)continue;
            if(vvisit[now.first+ddx[i]][now.second+ddy[i]])continue;
            if(cost+arr[now.first+ddx[i]][now.second+ddy[i]]>=dijk[now.first+ddx[i]][now.second+ddy[i]])continue;
            else{
                dijk[now.first+ddx[i]][now.second+ddy[i]]=cost+arr[now.first+ddx[i]][now.second+ddy[i]];
                que.push({-dijk[now.first+ddx[i]][now.second+ddy[i]],{now.first+ddx[i],now.second+ddy[i]}});
            }
        }
    }
    cout<<-1;
    return 0;
}
