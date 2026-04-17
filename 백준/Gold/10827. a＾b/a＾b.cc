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
ll POW(ll a, ll b, ll rem=1ull<<63-1){ll p=1;for(;b;b/=2,a=(a*a)% rem)if(b&1)p=(p*a)%rem;return p;}

string operator*(string a, int n){
    if(n==0)return "";
    if(n==1)return a;
    string k=a*(n/2);
    return k+k+a*(n%2);
}

string excludezero(string str){
    int i;
    for(i=(str[0]=='-');i<str.size()-1;i++){
        if(str[i]!='0')break;
    }
    string k=str[0]=='-'?"-":"";
    k+=str.substr(i);
    return k;
}

string add(string a, string b){
    int i,j;
    if(a[0]=='-'){
        for(i=0;i<a.size();i++){
            a[i]='0'-(a[i]-'0');
        }
        a=a.substr(1);
    }
    if(b[0]=='-'){
        for(i=0;i<b.size();i++){
            b[i]='0'-(b[i]-'0');
        }
        b=b.substr(1);
    }
    if(a.size()<b.size())swap(a,b);
    string tmp=(string)"0"*(int)(a.size()-b.size());
    b=tmp+b;
    int carry=0;
    string str="";
    for(i=a.size()-1;i>=0;i--){
        int t=(a[i]-'0')+(b[i]-'0')+carry;
        carry=(t+20)/10-2;
        int r=(t+20)%10;
        str+=(char)(r+'0');
    }
    if(carry>0){
        str+=(char)(carry+'0');
    }
    else if(carry<-1){
        str+=(char)(carry+1+'9');
    }
    reverse(str.begin(),str.end());
    if(carry<0){
        return excludezero("-"+add("1"+((string)"0"*str.size()),"-"+str));
    }
    else{
        return excludezero(str);
    }
}

string sub(string a, string b){
    if(b[0]=='-')return add(a,b.substr(1));
    else return add(a,"-"+b);
}

string mul(char a, char b){
    return to_string((a-'0')*(b-'0'));
}

void mul(const string&a, char b,string&str){
    for(int i=0;i<a.size();i++){
        str+="0";
        str=add(str,mul(a[i],b));
    }
}

string mul(const string&a, const string&b){
    string str="";
    string tmp;
    for(int i=0;i<b.size();i++){
        str+="0";
        tmp="";
        mul(a,b[i],tmp);
        str=add(str,tmp);
    }
    return excludezero(str);
}

pair<string,int> gethalf(const string&a){
    string ret="";
    int carry=0;
    for(int i=0;i<a.size();i++){
        ret+=carry*5+(a[i]-'0')/2+'0';
        carry=a[i]%2;
    }
    return {excludezero(ret),carry};
}

string mul2(const string& a, const string& b){
    if(a=="0"||b=="0")return "0";
    if(b=="1")return a;
    string hb;int c=b[b.size()-1]%2;
    string aa=mul2(a,gethalf(b).first);
    if(c)return add(add(aa,aa),a);
    return add(aa,aa);
}

string divint(const string&a, const string&b){

}

string pow(const string& a, const string&b){
    if(a=="0")return "0";
    if(b=="0")return "1";
    if(b=="1")return a;
    string hb;int c=b[b.size()-1]%2;
    string aa=pow(a,gethalf(b).first);
    if(c)return mul2(mul2(aa,aa),a);
    return mul2(aa,aa);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    string a,b;
    cin>>a>>b;
    int len=a.size();
    int dot=a.find('.');
    a=a.substr(0,dot)+a.substr(dot+1);
    dot=len-dot-1;
    string c=pow(a,b);
    dot*=stol(b);
    if(c.size()<=dot){
        cout<<"0.";
        for(i=0;i<dot-c.size();i++){
            cout<<"0";
        }
        cout<<c;
        return 0;
    }
    c=c.substr(0,c.size()-dot)+"."+c.substr(c.size()-dot);
    cout<<c;

    return 0;
}
