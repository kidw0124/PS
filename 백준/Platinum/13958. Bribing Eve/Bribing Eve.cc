#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;

ll gcd(ll a, ll b){
    if(a==0||b==0)return a+b;
    return gcd(b,a%b);
}

ll sign(ll n){
    return n==0?0:(n/abs(n));
}

ll ccw(const pll& a, const pll& b, const pll& c) {
    auto x1 = b.first - a.first;
    auto y1 = b.second - a.second;
    auto x2 = c.first - b.first;
    auto y2 = c.second - b.second;
    return x1 * y2 - x2 * y1;
}

//bool cmp(const pair<pll,ll>&l, const pair<pll,ll>&r){
//    auto [ax, ay] = l.first;
//    auto [bx, by] = r.first;
//    if (pll(ax, ay) > pll(0, 0) ^ pll(bx, by) > pll(0, 0)) return pll(ax, ay) > pll(bx, by);
//    return ccw(pll(0, 0), pll(ax, ay), pll(bx, by)) > 0;
//}

ll qua(pll a){
    auto [x,y]=a;
    if(x>0 && y>0)return 1;
    else if(x<=0 && y>=0)return 2;
    else if(x<0 && y<0)return 3;
    else return 4;
}

bool cmp2(pll l, pll r){
    return l.second*r.first < l.first*r.second;
}
bool cmp3(pll l, pll r){
    return l.second*r.first == l.first*r.second;
}

bool cmp(const pair<pll,ll>&l, const pair<pll,ll>&r){
    ll lq= qua(l.first),rq=qua(r.first);
    if(lq==rq){
        if(lq<3)return cmp2(l.first,r.first);
        else return cmp2(l.first,r.first);
    }
    else return lq<rq;
}

const ld eps=1e-12;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll i,j;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin>>n;
    vector<pll>arr(n);
    map<pll,ll>_cnt;
    vector<pair<pll,ll>>cnt;
    ll c0=0;
    for(i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        if(i){
            arr[i].first-=arr[0].first;
            arr[i].second-=arr[0].second;
            ll g=abs(gcd(arr[i].first,arr[i].second));
            if(g)arr[i].first/=g;
            if(g)arr[i].second/=g;
            if(arr[i].first==0&&arr[i].second==0)c0++;
            else{
                _cnt[arr[i]]++;
            }
        }
    }
    for(auto[k,v]:_cnt)cnt.push_back({k,v});
    ll ansmin=n-1,ansmax=0;
    ll m=cnt.size();
    sort(cnt.begin(), cnt.end(),cmp);
    vector<vector<pair<pll,ll>>>ccnt(5);
    vector<ll>q(5);
    for(i=0;i<m;i++){
        ccnt[qua(cnt[i].first)].push_back(cnt[i]);
        q[qua(cnt[i].first)]+=cnt[i].second;
    }
    for(ll qx=1;qx<=4;qx++){
        ll cnow=q[qx]+q[qx%4+1];
        ll en=0;
        if(qx<3) {
            for (i = 0; i < ccnt[qx].size(); i++) {
                ll tmp = 0;
                while (en < ccnt[(qx + 1) % 4 + 1].size() &&
                       cmp2(ccnt[qx][i].first, ccnt[(qx + 1) % 4 + 1][en].first)) {
                    cnow += ccnt[(qx + 1) % 4 + 1][en].second;
                    en++;
                }
                if (en < ccnt[(qx + 1) % 4 + 1].size() && cmp3(ccnt[(qx + 1) % 4 + 1][en].first, ccnt[qx][i].first)) {
                    tmp = ccnt[(qx + 1) % 4 + 1][en].second;
                }
                if(ccnt[qx][i].first.first*ccnt[qx][i].first.second<=0) {
                    ansmin = min(ansmin, n-1-c0-cnow-tmp);
                    ansmax = max(ansmax, n-1-c0-cnow +ccnt[qx][i].second);
                    cnow -= ccnt[qx][i].second;
                }
            }
        }
        else{
            for (i = 0; i < ccnt[qx].size(); i++) {
                ll tmp = 0;
                while (en < ccnt[(qx + 1) % 4 + 1].size() &&
                       cmp2(ccnt[qx][i].first, ccnt[(qx + 1) % 4 + 1][en].first)) {
                    cnow += ccnt[(qx + 1) % 4 + 1][en].second;
                    en++;
                }
                if (en < ccnt[(qx + 1) % 4 + 1].size() && cmp3(ccnt[(qx + 1) % 4 + 1][en].first, ccnt[qx][i].first)) {
                    tmp = ccnt[(qx + 1) % 4 + 1][en].second;
                }
                if(ccnt[qx][i].first.first*ccnt[qx][i].first.second<=0) {
                    ansmin = min(ansmin, cnow-ccnt[qx][i].second);
                    ansmax = max(ansmax, cnow +tmp);
                    cnow -= ccnt[qx][i].second;
                }
            }
        }

    }
    cout<<ansmin+1<<' '<<ansmax+c0+1;

}