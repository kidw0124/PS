#include<bits/stdc++.h>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
#define endl '\n'

#define debug if constexpr (!ndebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

void maketree(ll l, ll r, vector<pll>&points,vector<pll>&tree,vector<bool>&dxbdy){
    if(l>=r)return;
    else{
        ll mid=(l+r)>>1;
        ll mx=points[l].first, Mx=points[l].first;
        ll my=points[l].second, My=points[l].second;
        for(ll i=l;i<r;i++){
            mx=min(mx,points[i].first);
            my=min(my,points[i].second);
            Mx=max(Mx,points[i].first);
            My=max(My,points[i].second);
        }
        dxbdy[mid]=((Mx-mx)>=(My-my));
        nth_element(points.begin()+l,points.begin()+mid,points.begin()+r,[&](pll&a, pll&b){
                        return dxbdy[mid]?(a.first<b.first):(a.second<b.second);
                    });
        tree[mid]=points[mid];
        if(l+1==r)return;
        else{
            maketree(l,mid,points,tree,dxbdy);
            maketree(mid+1,r,points,tree,dxbdy);
        }
    }
}

void ans(ll l, ll r, pll point, ll&answer,vector<pll>&tree,vector<bool>&dxbdy){
    if(l>=r)return;
    else{
        ll mid=(l+r)>>1;
        ll dsq=(point.first-tree[mid].first)*(point.first-tree[mid].first)
                +(point.second-tree[mid].second)*(point.second-tree[mid].second);
        if(0<dsq&&dsq<answer)answer=dsq;
        if(l+1==r)return;
        ll del=dxbdy[mid]?(point.first-tree[mid].first):(point.second-tree[mid].second);
        pll lef={l,mid},rig={mid+1,r};
        if(del>0){
            swap(lef,rig);
        }
        ans(lef.first,lef.second,point,answer,tree,dxbdy);
        if(del*del<answer){
            ans(rig.first,rig.second,point,answer,tree,dxbdy);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j;
    ll tc;
    cin>>tc;
    while(tc--){
        ll n;
        cin>>n;
        vector<pll>arr(n),brr;
        vector<pll>tree(n);
        vector<bool>dxbdy(n);
        each(k,arr){
            cin>>k.first>>k.second;
        }
        brr=arr;
        maketree(0,n,brr,tree,dxbdy);
        for(i=0;i<n;i++){
            ll answer=(ll)3e18;
            ans(0,n,arr[i],answer,tree,dxbdy);
            cout<<answer<<'\n';
        }
    }
    return 0;
}
