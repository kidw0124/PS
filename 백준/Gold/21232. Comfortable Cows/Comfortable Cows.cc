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

int arr[2000][2000];
bool chk[2000][2000];
const int ddx[4]={0,0,-1,1},ddy[4]={-1,1,0,0};
int n,cnt=0;
queue<pii>stk;

void upd(int x, int y){
    for(int i=0;i<4;i++){
        int nx=x+ddx[i],ny=y+ddy[i];
        arr[nx][ny]++;
    }
}

void dfs(int x,int y){
    stk.push({x,y});
    upd(x,y);
    chk[x][y]=true;
    while(!stk.empty()){
        int x=stk.front().first,y=stk.front().second;
        if(arr[x][y]==3){
            for(int i=0;i<4;i++){
                int nx=x+ddx[i],ny=y+ddy[i];
                if(!chk[nx][ny]){
                    cnt++;
                    upd(nx,ny);
                    chk[nx][ny]=true;
                    stk.push({nx,ny});
                }
            }
        }
        for(int i=0;i<4;i++){
            int nx=x+ddx[i],ny=y+ddy[i];
            if(arr[nx][ny]==3&&chk[nx][ny]){
                for(int j=0;j<4;j++){
                    int nnx=nx+ddx[j],nny=ny+ddy[j];
                    if(!chk[nnx][nny]){
                        upd(nnx,nny);
                        cnt++;
                        chk[nnx][nny]=true;
                        stk.push({nnx,nny});
                    }
                }

            }
        }
        stk.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>n;
    for(i=0;i<n;i++){
        int t1,t2;
        cin>>t1>>t2;
        t1+=500;t2+=500;
        if(chk[t1][t2]){
            cnt--;
        }
        else dfs(t1,t2);

        cout<<cnt<<'\n';
    }

    return 0;
}
