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
ll arr[10];
string s;
int main(){
    ll i,j;
    cin>>s;
    for(i=1;i<s[0]-'0';i++){
        arr[i]+=pow(10,s.size()-1);
    }
    arr[i]+=stoll('0'+s.substr(1))+1;
    for(i=1;i<s.size();i++){
        string k=s.substr(0,i)+s.substr(i+1);
        for(j=i;j<k.size();j++)k[j]='9';
        for(j=1;j<s[i]-'0';j++){
            arr[j]+=stoll('0'+k)+1;
        }
        if(s[i]>'0'&&i+1<s.size()){
            arr[0]+=(stoll('0'+s.substr(0,i)))*(1+stoll('0'+k.substr(i)));
        }
        else if(s[i]>'0')arr[0]+=(stoll('0'+s.substr(0,i)));
        if(s[i]>'0'&&i+1<s.size())arr[s[i]-'0']+=stoll('0'+s.substr(0,i)+s.substr(i+1))+1;
        else if(s[i]>'0')arr[s[i]-'0']+=stoll('0'+s.substr(0,i))+1;
        else{
            if(i+1<s.size())arr[0]+=(stoll('0'+s.substr(0,i)+s.substr(i+1)))-stoll('0'+k.substr(i));
            else arr[0]+=stoll('0'+s.substr(0,i));
        }
        k=s.substr(0,i)+s.substr(i+1);
        for(j=i;j<k.size();j++)k[j]='0';
        for(j=s[i]-'0'+1;j<10;j++)arr[j]+=stoll('0'+k);
    }
    for(i=0;i<10;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}
