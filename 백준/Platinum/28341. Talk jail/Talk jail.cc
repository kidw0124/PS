#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

#ifdef ONLINE_JUDGE
constexpr bool ddebug=false;
#else
constexpr bool ddebug=true;
#endif

constexpr ll mod = 1e9+7;

void preprocess(){
}

void solve(ll tc){
    ll i,j,n,m;
    cout<<"#"<<tc<<'\n';
    cin>>n>>m;
    vector<tuple<ll,ll,ll,ll>>arr(m);
    for(auto&[a,b,c,d]:arr)cin>>a>>b>>c;
    for(i=0;i<m;i++)get<3>(arr[i])=i;
    sort(arr.begin(), arr.end());
    vector<ll>ans(m);
    unordered_set<ll>us;
    for(i=0;i<n;i++)us.insert(i+1);
    for(i=m-1;i>=0;i--){
        auto&[_,b,c,d]=arr[i];
        us.erase(b);
        if(c==us.size())ans[d]=c;
    }
    for(i=1;i<m;i++){
        auto&[_,_1,_2,pd]=arr[i-1];
        auto&[_3,_4,_5,d]=arr[i];
        ans[d]=max(ans[d],ans[pd]);
    }
    for(auto k:ans)cout<<k<<'\n';
}

int main(){
    if(!ddebug){
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    }
    else{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    preprocess();
    ll t=1;
    cin>>t;
    for(ll i=0;i<t;i++)solve(i+1);
}