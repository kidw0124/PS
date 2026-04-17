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
string str[10];

int mx[5]={1,0,0,0,-1},my[5]={0,-1,0,1,0};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j,k,l,m=101;
    for(i=0;i<10;i++)cin>>str[i];
    for(i=0;i<1024;i++){
        string str2[10];
        ll cnt=0;
        for(j=0;j<10;j++){
            str2[j]=str[j];
        }
        for(j=0;j<10;j++){
            if((i>>j)&1){
                cnt++;
                for(k=0;k<5;k++){
                    if(mx[k]<0||mx[k]>=10||j+my[k]<0||j+my[k]>=10)continue;
                    if(str2[mx[k]][j+my[k]]=='#')str2[mx[k]][j+my[k]]='O';
                    else str2[mx[k]][j+my[k]]='#';
                }
            }
        }
        for(j=1;j<10;j++){
            for(l=0;l<10;l++){
                if(str2[j-1][l]=='O'){
                    cnt++;
                    for(k=0;k<5;k++){
                        if(j+mx[k]<0||j+mx[k]>=10||l+my[k]<0||l+my[k]>=10)continue;
                        if(str2[j+mx[k]][l+my[k]]=='#')str2[j+mx[k]][l+my[k]]='O';
                        else str2[j+mx[k]][l+my[k]]='#';
                    }
                }
            }
        }
        for(j=0;j<10;j++){
            for(k=0;k<10;k++){
                if(str2[j][k]=='O')cnt=101;
            }
        }
        m=min(m,cnt);
    }
    cout<<(m+1)%102-1;
    return 0;
}
