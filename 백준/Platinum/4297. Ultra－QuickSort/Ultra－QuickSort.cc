#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
#define debug if constexpr(ddebug) cout << "[DEBUG] "

constexpr ll MOD = 1e9+9;
void mmerge(vector<ll>&arr, ll l, ll mid, ll r, ll&cnt){
    vector<ll>tmp;
    ll x=l,y=mid;
    while(x<mid&&y<r){
        if(arr[x]<=arr[y]){
            tmp.push_back(arr[x++]);
        }
        else{
            cnt+=mid-x;
            tmp.push_back(arr[y++]);
        }
    }
    while(y<r){
        tmp.push_back(arr[y++]);
    }
    while(x<mid){
        tmp.push_back(arr[x++]);
    }
    copy(tmp.begin(),tmp.end(),arr.begin()+l);
}

void msort(vector<ll>&arr, ll l, ll r, ll&cnt){
    if(l+1>=r){
        return;
    }
    else{
        ll mid=(l+r)>>1;
        msort(arr,l,mid,cnt);
        msort(arr,mid,r,cnt);
        mmerge(arr,l,mid,r,cnt);
    }
}

ll merge_sort(vector<ll>arr){
    ll cnt=0;
    msort(arr,0,arr.size(),cnt);
    return cnt;
}
void solve(){
    int i,j,k;
    ll n;
    cin>>n;
    if(n==0)return;
    vector<ll>arr(n);
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<merge_sort(arr)<<'\n';
    solve();

}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t st=clock();
#else
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif
    int t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    debug<<clock()-st<<"ms\n";
#endif
}