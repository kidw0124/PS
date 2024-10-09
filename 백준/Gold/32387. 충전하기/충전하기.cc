#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using ll = long long;
using LL = __int128;
using pll = pair<ll, ll>;

void preprocess() {
    ;
}

void solve() {
    ll i,j;
    ll n,q;
    cin>>n>>q;
    vector<ll>arr(n+1);
    set<ll>st;
    for(i=1;i<=n;i++)st.insert(i);
    for(i=1;i<=q;i++){
        ll t,c;
        cin>>t>>c;
        if(t==1){
            auto it=st.lower_bound(c);
            if(it==st.end()){
                cout<<-1<<'\n';
            }
            else{
                cout<<*it<<'\n';
                arr[*it]=i;
                st.erase(it);
            }
        }
        else{
            if(st.find(c)==st.end()){
                cout<<arr[c]<<'\n';
                st.insert(c);
            }
            else{
                cout<<-1<<'\n';
            }
        }
    }
}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t beg = clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}
