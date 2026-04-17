#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

ll POW(ll a, ll b, ll MMM) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret;}
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a * (b / gcd(a, b)); }
#define rep(i,a,b) for(LL i = a; i < b; i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()

map<char,int> str_to_base64;
map<int,char> base64_to_str;
vector<int> ans;
vector<char> aaa;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL i,j;
    string s;
    cin>>s;
    int l=s.size();
    for(i=0;i<26;i++){
        str_to_base64.insert(make_pair('A'+i,i));
        str_to_base64.insert(make_pair('a'+i,26+i));
        if(i<10)str_to_base64.insert(make_pair('0'+i,52+i));
        base64_to_str.insert(make_pair(i,'A'+i));
        base64_to_str.insert(make_pair(i+26,'a'+i));
        if(i<10)base64_to_str.insert(make_pair(52+i,'0'+i));
    }
    str_to_base64.insert(make_pair('+',62));
    str_to_base64.insert(make_pair('/',63));
    base64_to_str.insert(make_pair(62,'+'));
    base64_to_str.insert(make_pair(63,'/'));
    for(i=0;i<l;i++){
        int t=s[i];
        for(j=7;j>=0;j--){
            ans.push_back(t/(1<<j));
            t%=(1<<j);
        }
    }
    l=ans.size();
    int lo=23-(l-1)%24,ln=5-(l-1)%6;
    for(i=0;i<l+lo;){
        int t=0;
        if(i>=l+ln){
            i+=6;
            aaa.push_back('=');
            continue;
        }
        for(j=5;j>=0;i++,j--){
            if(i<l)t+=ans[i]*(1<<j);
        }
        aaa.push_back(base64_to_str[t]);
    }
    l=aaa.size();
    for(i=0;i<l;i++){
        cout<<aaa[i];
    }
    return 0;
}
