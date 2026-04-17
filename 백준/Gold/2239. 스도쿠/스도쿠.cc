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
const ll MAX=9;
int arr[9][9];

bool check(int x, int y, int z){
    for(int i=0;i<9;i++){
        if(arr[i][y]==z)return false;
        if(arr[x][i]==z)return false;
    }
    for(int i=x/3*3;i<x/3*3+3;i++){
        for(int j=y/3*3;j<y/3*3+3;j++){
            if(arr[i][j]==z)return false;
        }
    }
    return true;
}

void func(int x, int y){
    while(arr[x][y]&&x+y<16){
        if(x!=8)x++;
        else{
            x=0;y++;
        }
    }
    if(x==8&&y==8){
        if(arr[x][y]){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cout<<arr[j][i];
                }
                cout<<'\n';
            }
            exit(0);
        }
        else{
            for(int k=1;k<=9;k++){
                if(check(x,y,k)){
                    arr[x][y]=k;
                    for(int i=0;i<9;i++){
                        for(int j=0;j<9;j++){
                            cout<<arr[j][i];
                        }
                        cout<<'\n';
                    }
                    exit(0);
                }
            }
        }
    }
    else{
        for(int k=1;k<=9;k++){
            if(check(x,y,k)){
                arr[x][y]=k;
                func(x,y);
                arr[x][y]=0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    for(int i=0;i<9;i++){
        ll n;
        cin>>n;
        for(int j=8;j>=0;j--){
            arr[j][i]=n%10;
            n/=10;
        }
    }
    func(0,0);


    return 0;
}
