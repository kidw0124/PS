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

string add(string a, string b){
    int carry=0;
    string c;
    if(a.size()<b.size()){
        swap(a,b);
    }
    for(int i=0;i<a.size();i++){
        int k=a[a.size()-1-i]-'0'+carry;
        if(i<b.size())k+=b[b.size()-1-i]-'0';
        int s=k%10;
        carry=k/10;
        c=(char)(s+'0')+c;
    }
    if(carry==1){
        c="1"+c;
    }
    return c;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    string x,y;
    cin>>x;
    int cnt=0;
    while(x.size()>1){
        cnt++;
        string sum="0";
        for(i=0;i<x.size();i++){
            string k="";
            k+=x[i];
            sum=add(sum,k);
        }
        x=sum;
    }
    cout<<cnt<<'\n';
    if(x=="0"||x=="3"||x=="6"||x=="9"){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}
