#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){if(a&&b)return a*(b/gcd(a,b)); return a+b;}
ll POW(ll a, ll b, ll rem){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}
ll n,a,b,m,ans;
vector<int>room;
vector<int>score;
vector<bool>good;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n>>a>>b>>m;
    room.resize(n);
    score.resize(n);
    iota(all(room),0);
    good.resize(m);
    a--;
    if(a<=b){
        good[0]=true;
    }
    for(i=1;i<m;i++){
        for(j=0;j<n;j++){
            cin>>score[j];
        }
        for(j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            score[j]-=tmp;
        }
        for(j=0;j<n-1;j++){
            int ra=room[j],rb=room[j+1];
            if(score[ra]>=0&&score[rb]>=0&&score[rb]>=score[ra]+2){
                swap(room[j],room[j+1]);
                score[ra]+=2;
                score[rb]-=2;
            }
            else if(score[ra]>=0&&score[rb]<0){

            }
            else if(score[rb]>=0&&score[ra]<0){
                swap(room[j],room[j+1]);
                score[ra]+=2;
                score[rb]-=2;
            }
            else if(score[rb]>=score[ra]+4){
                swap(room[j],room[j+1]);
                score[ra]+=2;
                score[rb]-=2;
            }
        }
        int h=find(all(room),0)-find(all(room),a);
        if(abs(h)<=b)good[i]=true;
    }
    cout<<count(all(good),true)<<' ';
    int x=0,mx=0;
    for(i=0;i<m;i++){
        if(good[i])x++;
        else x=0;
        if(mx<x)mx=x;
    }
    cout<<mx;
    return 0;
}
