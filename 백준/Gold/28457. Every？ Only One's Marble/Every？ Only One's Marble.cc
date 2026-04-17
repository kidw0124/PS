#include<bits/stdc++.h>

using namespace std;

using ll = long long;

using ld = long double;

using pll = pair<ll,ll>;

#ifdef DWOO

constexpr bool ddebug = true;

#else

constexpr bool ddebug = false;

#endif

#define debug if constexpr(ddebug) cout << "[DEBUG] "

#define debugv(x) if constexpr (ddebug) cout << "[DEBUG] " << #x << " == " << x << '\n';

void setup(){

#ifdef DWOO

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

#else

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#endif

}

void preprocess(){

}

void solve(ll testcase){

    ll n,i,j;

    ll s,w,g,m;

    cin>>n>>s>>w>>g;

    vector<pll>cards(g);

    for(auto &[a,b]:cards)cin>>a>>b;

    vector<pair<char,ll>>arr(4*n-4);

    vector<bool>vis(4*n-4);

    arr[0].first='O';

    for(i=1;i<=n-2;i++){

        cin>>arr[i].first;

        if(arr[i].first=='L')cin>>arr[i].second;

    }

    arr[n-1].first='M';

    for(i=n;i<=2*n-3;i++){

        cin>>arr[i].first;

        if(arr[i].first=='L')cin>>arr[i].second;

    }

    arr[2*n-2].first='S';

    for(i=2*n-1;i<=3*n-4;i++){

        cin>>arr[i].first;

        if(arr[i].first=='L')cin>>arr[i].second;

    }

    arr[3*n-3].first='W';

    for(i=3*n-2;i<=4*n-5;i++){

        cin>>arr[i].first;

        if(arr[i].first=='L')cin>>arr[i].second;

    }

    for(auto [a,b]:arr)debug<<a<<' '<<b<<'\n';

    cin>>m;

    ll now=0,gn=0,t=0,save=0;

    for(i=0;i<m;i++){

        ll da,db;

        cin>>da>>db;

        if(arr[now].first=='M'&&t<3){

            if(da==db)t=3;

            else t++;

        }

        else{

            now+=da+db;

            if(now>=4*n-4){

                s+=w*((now)/(4*n-4));

                now%=4*n-4;

            }

            debug<<arr[now].first<<' '<<now<<' '<<s<<'\n';

            if(t==3)t=0;

            if(arr[now].first=='G'){

                auto [a,b]=cards[gn++];

                if(gn==g)gn=0;

                if(a==1){

                    s+=b;

                }

                else if(a==2){

                    s-=b;

                    if(s<0){

                        cout<<"LOSE\n";

                        return;

                    }

                }

                else if(a==3){

                    s-=b;

                    save+=b;

                    if(s<0){

                        cout<<"LOSE\n";

                        return;

                    }

                }

                else{

                    now+=b;

                    while(now>=4*n-4){

                        now-=4*n-4;

                        s+=w;

                    }

                }

            }

            if(arr[now].first=='S'){

                s+=save;

                save=0;

            }

            else if(arr[now].first=='W'){

                now=0;

                s+=w;

            }

            else if(arr[now].first=='O'){

            }

            else if(arr[now].first=='L'){

                if(!vis[now]&&s>=arr[now].second){

                    s-=arr[now].second;

                    vis[now]=1;

                }

            }

            debug<<arr[now].first<<' '<<now<<' '<<s<<'\n';

        }

    }

    for(i=0;i<4*n-4;i++){

        debug<<arr[i].first<<' '<<arr[i].second<<'\n';

        if(arr[i].first=='L'&&!vis[i]){

            cout<<"LOSE\n";

            return;

        }

    }

    cout<<"WIN\n";

}

int main(){

    setup();

    preprocess();

    ll t=1;

//    cin>>t;

    for(ll testcase = 1; testcase<=t;testcase++)solve(testcase);

}