#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a, int b){return b?gcd(b,a%b):a+b;}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll n,m;
    cin>>n>>m;
    vector<vector<int>>vec(n);
    vector<int>deg(n);
    vector<bool>isapt(n),vis(n);
    vector<int>arr(n),par(n),dep(n),brr(n);
    for(i=0;i<n-1;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        vec[a].push_back(b);
        vec[b].push_back(a);
        deg[a]++,deg[b]++;
    }
    for(i=0;i<m;i++){
        cin>>j;
        isapt[j-1]=1;
    }
    ll x=j-1;
    ll ans=0;
    vis[x]=1;
    stack<int>st;
    st.push(x);
    par[x]=-1;
    while(!st.empty()){
        ll now=st.top();
        st.pop();
        if(isapt[now]){
            arr[now]=2;
        }
        for(i=0;i<vec[now].size();i++){
            ll next=vec[now][i];
            if(vis[next])continue;
            else{
                par[next]=now;
                if(arr[now])arr[next]=1;
                vis[next]=1;
                dep[next]=dep[now]+1;
                st.push(next);
            }
        }
    }
    priority_queue<pair<int,int>>pq;
    for(i=0;i<n;i++){
        pq.push({dep[i],i});
    }
    while(!pq.empty()){
        ll now=pq.top().second;
        pq.pop();
        if((isapt[now]||brr[now])&&par[now]!=-1){
            brr[par[now]]++;
        }
    }
//    for(auto k:dep)cout<<k <<' ';
//    cout<<'\n';
//    for(auto k:brr)cout<<k <<' ';
    for(i=0;i<n;i++){
        if(brr[i]||isapt[i])ans++;//cout<<i<<' ';
    }
    cout<<ans;
}
