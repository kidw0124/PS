// Kruskal : O(ElgE)
// 공간복잡도 : O(V+E) : 16E+8V
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
vector<pair<ll,pll>>edge;
vector<ll>group;
ll ans,v,e;

ll _find(ll a){
    if(a==group[a])return a;
    else return group[a]=_find(group[a]);
}

bool isSameGroup(ll a,ll b){
    a=_find(a);
    b=_find(b);
    if(a==b)return true;
    else return false;
}

void _union(ll a,ll b){
    b=_find(b);
    group[b]=_find(a);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>v>>e;
    group.resize(v+1);
    iota(group.begin(),group.end(),0);
    for(i=0;i<e;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }
    sort(edge.begin(),edge.end());
    ll p=0;
    for(i=0;i<e;i++){
        if(p==v-1)break;
        else if(isSameGroup(edge[i].second.first,edge[i].second.second))continue;
        else{
            ans+=edge[i].first;
            _union(edge[i].second.first,edge[i].second.second);
            p++;
        }
    }
    cout<<ans;
    return 0;
}