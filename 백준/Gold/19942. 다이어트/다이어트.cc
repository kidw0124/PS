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
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

ll n,mm,M=1e15,x;
string ss="a";
string sss;
struct data{
    ll p,f,s,v,c;
    void input(){
        cin>>p>>f>>s>>v;
    }
    void inputt(){
        cin>>p>>f>>s>>v>>c;
    }
    void reset(){
        p=f=s=v=c=0;
    }
    void add(data&r){
        p+=r.p,f+=r.f,s+=r.s,v+=r.v,c+=r.c;
    }
}goal,arr[20],p;

bool visit[20];

void cc(ll x){
    for(ll i=0;i<n;i++){
        visit[i]=x%2;
        x/=2;
    }
}

void kk(){
    ll a=0;
    for(ll i=0;i<n;i++){
        if(visit[i]){
            p.add(arr[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    goal.input();
    for(i=0;i<n;i++){
        arr[i].inputt();
    }
    mm=1<<n;
    for(i=0;i<mm;i++){
        cc(i);
        p.reset();
        kk();
        if(p.p>=goal.p&&p.f>=goal.f&&p.s>=goal.s&&p.v>=goal.v&&M>=p.c){
            sss="";
            for(j=0;j<n;j++){
                if(visit[j])sss+=j;
            }
            if(sss<ss||M>p.c){
                M=p.c;
                x=i;
                ss=sss;
            }
        }
    }
    cc(x);
    if(M==1e15){
        cout<<-1;
        return 0;
    }
    cout<<M<<'\n';
    for(i=0;i<n;i++){
        if(visit[i])cout<<i+1<<' ';
    }
    return 0;
}
