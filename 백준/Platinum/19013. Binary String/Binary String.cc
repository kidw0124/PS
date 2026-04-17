#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t LL;
typedef __uint128_t ULL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for (auto i = (a); i < (b); i++)
#define each(x, a) for (auto& x: a)
// #define endl '\n'

#define debug if constexpr (xdebug) cout << "[DEBUG] "
#define debugv(x) if constexpr (xdebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugc(c) if constexpr (xdebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

#ifndef ONLINE_JUDGE
constexpr bool xdebug = true;
#else
constexpr bool xdebug = false;
#endif
void setup(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll powm(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)%rem)if(b&1)p=(p*a)%rem;return p;}

const ll mod=1e9+7;
map<pll,ll>mp;
#ifndef ONLINE_JUDGE
string ans_str;

std::random_device rd;

// random_device 를 통해 난수 생성 엔진을 초기화 한다.
std::mt19937 gen(rd());

// 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
ll random(ll a, ll b){
    std::uniform_int_distribution<int> dis(a, b);
    return dis(gen);
}

ll get(ll a, ll b){
    ll type= random(0,1);
    ll r=count(ans_str.begin()+a-1,ans_str.begin()+b,'1');
    ll x= random(0,b-a+1);
    switch (type) {
        case 0:
            return r;
        case 1:
            while (x==r)x= random(0,b-a+1);
            return x;
        default:
            cerr<<"E1";
            exit(0);
    }
}

#endif
int main() {
    setup();
    ll i,j,cnt=0;
    string str;

#ifndef ONLINE_JUDGE
    for(i=0;i<1000;i++){
        ans_str+= random(0,1)?'0':'1';
    }
#endif
    for(i=1;i<=500;i++){
        ll one=0,zero=0;
        for(j=0;one<3&&zero<3;j++){
            if(mp.find({i,1000-j})==mp.end()){
                cout<<"? "<<i<<" "<<1000-j<<endl;
                cout.flush();
#ifndef ONLINE_JUDGE
                mp[{i,1000-j}]= get(i,1000-j);
#else
                cin>>mp[{i,1000-j}];
#endif
                cnt++;
            }
            if(mp.find({i+1,1000-j})==mp.end()){
                cout<<"? "<<i+1<<" "<<1000-j<<endl;
                cout.flush();
#ifndef ONLINE_JUDGE
                mp[{i+1,1000-j}]= get(i+1,1000-j);
#else
                cin>>mp[{i+1,1000-j}];
#endif
                cnt++;
            }
            switch (mp[{i,1000-j}]-mp[{i+1,1000-j}]){
                case 0:
                    zero++;
                    break;
                case 1:
                    one++;
                    break;
            }
        }
        if(one==3)str+='1';
        else str+='0';
    }
    for(i=501;i<=1000;i++){
        ll one=0,zero=0;
        for(j=0;one<3&&zero<3;j++){
            if(mp.find({1+j,i})==mp.end()){
                cout<<"? "<<1+j<<" "<<i<<endl;
                cout.flush();
#ifndef ONLINE_JUDGE
                mp[{1+j,i}]=get(1+j,i);
#else
                cin>>mp[{1+j,i}];
#endif
                cnt++;
            }
            if(mp.find({1+j,i-1})==mp.end()){
                cout<<"? "<<1+j<<" "<<i-1<<endl;
                cout.flush();
#ifndef ONLINE_JUDGE
                mp[{1+j,i-1}]=get(1+j,i-1);
#else
                cin>>mp[{1+j,i-1}];
#endif
                cnt++;
            }
            switch (mp[{1+j,i}]-mp[{1+j,i-1}]) {
                case 0:
                    zero++;
                    break;
                case 1:
                    one++;
                    break;
            }
        }
        if(one==3)str+='1';
        else str+='0';

    }
    cout<<"! "<<str<<endl;
    cout.flush();
    debug<<cnt<<endl;
#ifndef ONLINE_JUDGE
    cout<<"! "<<ans_str<<endl;
    cout.flush();
    for(i=0;i<1000;i++){
        if(str[i]!=ans_str[i])cout<<i+1<<"!";
    }
#endif



}