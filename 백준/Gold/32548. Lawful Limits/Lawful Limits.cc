#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void setup() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

void done(ll y, ll p) {
    std::vector<ll> digrev;
    while(y > 0) {
        digrev.push_back(y % p);
        y /= p;
    }
    std::reverse(digrev.begin(), digrev.end());

    std::cout << p << ' ';
    for(ll dig : digrev) {
        if(dig > 10) {
            char c = 'a' + (dig - 10);
            std::cout << c;
        } else {
            std::cout << dig;
        }
    }
}

struct data_ {
    int x, l, v, w;
};

struct value {
    int x;
    long double y;
    bool operator < (const value &r) const {
        return y > r.y;
    }
};

vector <data_> V[100100];
long double dist[100100];
int check[100100];

void solve(ll tc){
    int i, j, N, M, T; cin>>N>>M>>T;
    for(i=0; i<M; i++) {
        int x, y, l, v, w; cin>>x>>y>>l>>v>>w;
        V[x].push_back( {y, l, v, w} );
        V[y].push_back( {x, l, v, w} );
    }
    const long double inf = 1e18;
    for(i=1; i<=N; i++) dist[i] = inf, check[i] = 0;
    dist[1] = 0;
    priority_queue <value> Q; Q.push( {1, 0} );
    while(!Q.empty()){
        value X = Q.top(); Q.pop();
        if(check[X.x]) continue;
        check[X.x] = 1;
         for(i=0; i<V[X.x].size(); i++) {
            data_ nxt = V[X.x][i];
            long double tt = 0;
            long double nxtT = 0;
            if(X.y >= T) {
                nxtT = X.y + (long double) nxt.l / (long double) nxt.w;
            } else {
                nxtT = X.y + (long double) nxt.l / (long double) nxt.v;
                if(nxtT > T) {
                    nxtT = T + (long double) (nxt.l - (T-X.y) * nxt.v) / nxt.w;
                }
            }
            if(dist[nxt.x] < nxtT) continue;
            if(check[nxt.x]) continue;
            Q.push( { nxt.x, nxtT } );
            dist[nxt.x] = nxtT;
        }
    }
    cout.precision(6);
    cout<<fixed;
    cout<<dist[N]<<"\n";
}

void preprocess(){
    ll i,j,k;
}

int main(){
    setup();preprocess();
    ll t=1;
//    cin>>t;
    for(ll i=0;i<t;i++){
        solve(t+1);
    }
    return 0;
}