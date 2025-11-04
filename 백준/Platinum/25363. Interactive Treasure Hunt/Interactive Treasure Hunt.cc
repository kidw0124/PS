#include <bits/stdc++.h>
using namespace std;

using ll = int;
using pll = pair<ll,ll>;
using ld = long double;

void solve() {
    srand(time(NULL));
    ll i,j;
    ll n,m;
    cin>>n>>m;
    ll q=0;
    ll a,b;
    cout<<"SCAN 1 1\n";
    cout.flush();
    cin>>a;
    cout<<"SCAN 1 "<<m<<"\n";
    cout.flush();
    cin>>b;
    ll c,d;
    cout<<"SCAN "<<(a+b+6-m-m)/4<<" 1\n";
    cout.flush();
    cin>>c;
    cout<<"SCAN 1 "<<(a-b+2+m+m)/4<<"\n";
    cout.flush();
    cin>>d;
    ll dx=c-(a-b+2+m+m)/2+2,dy=d-(a+b+6-m-m)/2+2;
    pll x={((a+b+6-m-m)/2+dx)/2,((a-b+2+m+m)/2+dy)/2};
    pll y={((a+b+6-m-m)/2-dx)/2,((a-b+2+m+m)/2-dy)/2};
    cout<<"DIG "<<x.first<<" "<<x.second<<"\n";
    cout.flush();
    cin>>a;
    if(a){
        cout<<"DIG "<<y.first<<" "<<y.second<<"\n";
        cout.flush();
        cin>>a;
    }
    else{
        swap(x.second,y.second);
        cout<<"DIG "<<x.first<<" "<<x.second<<"\n";
        cout.flush();
        cin>>a;
        cout<<"DIG "<<y.first<<" "<<y.second<<"\n";
        cout.flush();
        cin>>a;
    }

}

int main() {
//#ifdef ONLINE_JUDGE
//    cin.tie(0)->sync_with_stdio(0);
//#else
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//#endif
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}