#include<bits/stdc++.h>
using namespace std;
using ll = int;
using pll = pair<ll, ll>;
using ld = double;
using pld = pair<ld, ld>;

void solve() {
    ll n, i;
    ld deg, p, q, res = 0;
    cin >> deg >> n;
    deg = 1/tan(deg / 180 * acos((ld)-1));
    priority_queue<ld>pq1,pq2;
    for(i=0;i<n;i++){
        ll x,h;
        cin>>x>>h;
        pq1.push(x+h*deg),pq2.push(x);
    }
    ll cnt=0;
    ld ans=0;
    ld bef;
    while(pq1.size()){
        bef=pq1.top();
        pq1.pop();
        cnt++;
        while(cnt){
            if(pq1.size()&&pq1.top()>pq2.top()){
                cnt++;
                pq1.pop();
            }
            else{
                cnt--;
                if(!cnt)ans+=bef-pq2.top();
                pq2.pop();
            }
        }
    }
    cout<<setprecision(10)<<fixed<<ans<<'\n';
}

int main(){
#ifdef kidw0124
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    solve();
    return 0;
}