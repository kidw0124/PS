#include<bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE

constexpr bool ddebug = true;

#else

constexpr bool ddebug = false;

#endif

#define debug if(ddebug)cout << "[DEBUG] "

#define debugv(x) debug << #x << " : " << x << "\n";

#define debugc(x) if(ddebug){debug << #x << " : ";for(auto k:x)cout<<k<<", ";cout<<"\n";}

using ll = long long;

using ld = long double;

using LL = __int128_t;

using pll = pair<ll, ll>;

using pld = pair<ld, ld>;

void setup() {

    if(ddebug) {

        freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);

    }

    else {

        ios_base::sync_with_stdio(false);

        cin.tie(NULL);

        cout.tie(NULL);

    }

}

void preprocess() {

    ll i, j;

}

struct node{

    ll val;

    unordered_set<ll>inode;

    char c;

    ll dist=INT_MAX;

};

void solve(ll testcase) {

    ll i, j, k;

    ll n,m,r;

    cin>>n>>m>>r;

    vector<node>arr(n);

    vector<vector<ll>>edge(n);

    for(i=0;i<n;i++) {

        cin >> arr[i].val;

    }

    for(i=0;i<m;i++){

        ll x,y;

        cin>>x>>y;

        x--,y--;

        edge[x].push_back(y);

        edge[y].push_back(x);

    }

    priority_queue<pll>pq;

    arr[0].dist=arr[0].val;

    pq.push({-arr[0].val,0});

    while(pq.size()){

        auto [d,v]=pq.top();

        d=-d;

        pq.pop();

        if(d!=arr[v].dist)continue;

        for(auto k:edge[v]){

            if(arr[k].dist>arr[k].val+d){

                arr[k].inode.clear();

                arr[k].dist=arr[k].val+d;

                arr[k].inode.insert(v);

                pq.push({-arr[k].dist,k});

            }

            else if(arr[k].dist==arr[k].val+d){

                arr[k].inode.insert(v);

            }

        }

    }

    vector<vector<ll>>real_edge(n);

    queue<ll>que;

    que.push(n-1);

    set<ll>sst;

    sst.insert(n-1);

    while(que.size()){

        ll f=que.front();

        que.pop();

        for(auto k:arr[f].inode){

            if(sst.find(k)==sst.end()){

                sst.insert(k);

                que.push(k);

            }

            real_edge[k].push_back(f);

        }

    }

    if(n==2&&r==1){

        cout<<"impossible";

    }

    else if(sst.size()==2&&r==1){

        arr[0].c=arr[n-1].c='S';

        for(i=0;i<n;i++){

            if(arr[i].c)cout<<arr[i].c;

            else if(r){

                r--;

                cout<<'N';

            }

            else cout<<'S';

        }

    }

    else{

        queue<ll>ndnd;

        ndnd.push(0);

        while(r&&ndnd.size()){

            ll f=ndnd.front();

            ndnd.pop();

            arr[f].c='N';

            r--;

            for(auto x:real_edge[f]){

                arr[x].inode.erase(f);

                if(arr[x].inode.size()==0)ndnd.push(x);

            }

        }

        for(i=0;i<n;i++){

            if(arr[i].c)cout<<arr[i].c;

            else if(r){

                r--;

                cout<<'N';

            }

            else cout<<'S';

        }

    }

}

int main() {

    setup();

    preprocess();

    ll t = 1;

//    cin >> t;

    for(ll i = 1; i <= t; i++)solve(i);

    return 0;

}