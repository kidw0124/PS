#define private public
#include<bitset>
#undef private
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
const int MX=7000+5;
const int alpha_num=26;
string arr,brr;

void lcs(int st1, int en1, int st2, int en2, string&str){
    int i,j;
    if(st2>en2)return;
    if(st2==en2){
        char x=brr[st2];
        for(i=st1;i<=en1;i++){
            if(arr[i]==x){
                str+=(char)x;
                return;
            }
        }
        return;
    }
    int mid2=(st2+en2)>>1;
    vector<vector<int>>lcsleft(2,vector<int>(en1-st1+2)),lcsright(2,vector<int>(en1-st1+2));
    for(i=st2;i<=mid2;i++){
        char x=brr[i];
        for(j=st1;j<=en1;j++){
            if(arr[j]==x)lcsleft[0][j-st1+1]=lcsleft[1][j-st1]+1;
            else lcsleft[0][j-st1+1]=max(lcsleft[1][j-st1+1],lcsleft[0][j-st1]);
        }
        lcsleft[1]=lcsleft[0];
    }
    for(i=en2;i>mid2;i--){
        char x=brr[i];
        for(j=en1;j>=st1;j--){
            if(arr[j]==x)lcsright[0][j-st1]=lcsright[1][j-st1+1]+1;
            else lcsright[0][j-st1]=max(lcsright[1][j-st1],lcsright[0][j-st1+1]);
        }
        lcsright[1]=lcsright[0];
    }
    int mid1=st1;
//    cout<<mid1<<' '<<lcsleft[1][mid1-st1]<<' '<<lcsright[1][mid1-st1]<<'\n';
    for(i=st1+1;i<=en1+1;i++){
//        cout<<i<<' '<<lcsleft[1][i-st1]<<' '<<lcsright[1][i-st1]<<'\n';
        if(lcsleft[1][i-st1]+lcsright[1][i-st1]>lcsleft[1][mid1-st1]+lcsright[1][mid1-st1])mid1=i;
    }
    lcs(st1,mid1-1,st2,mid2,str);
    lcs(mid1,en1,mid2+1,en2,str);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>i>>j>>arr>>brr;
    string str="";
    lcs(0,arr.size()-1,0,brr.size()-1,str);
    cout<<str.size()<<'\n'<<str;

    return 0;
}
