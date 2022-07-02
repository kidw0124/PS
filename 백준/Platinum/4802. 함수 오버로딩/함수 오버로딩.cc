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
struct dataa{
    vector<char>par;
    char ret;
};

void get_pos(const string&str,map<ll,ll>&pos,ll st){
    pos[st]=2;
    if(isupper(str[st]))return;
    else{
        pos[st]=4;
        ll n=str[st+2]-'0';
        for(ll i=0;i<n;i++){
            get_pos(str,pos,st+pos[st]);
            pos[st]+=pos[st+pos[st]];
        }
    }
}

ll ans(const string&str,map<ll,ll>&pos,ll st,char ret,map<pair<ll,char>,ll>&cnt,const vector<vector<dataa>>&func,map<pair<ll,char>,pair<dataa,ll>>&rev){
    if(cnt.find({st,ret})!=cnt.end())return cnt[{st,ret}];
    if(isupper(str[st])){
        if(ret==str[st]){
            cnt[{st,ret}]=1;
        }
        else cnt[{st,ret}]=0;
    }
    else{
        ll n=str[st+2]-'0';
        ll a=0;
        ll j=0;
        for(const dataa&k:func[str[st]-'a']){
            j++;
            if(a>1000)break;
            if(k.par.size()!=n||k.ret!=ret)continue;
            else{
                ll now=1;
                ll loc=st+4;
                for(ll i=0;i<n;i++){
                    now*=ans(str,pos,loc,k.par[i],cnt,func,rev);
                    if(now<1)break;
                    now=min(now,1001ll);
                    loc+=pos[loc];
                }
                if(now>0){
                    rev[{st,ret}]={k,j};
                }
                a+=now;
            }
        }
        cnt[{st,ret}]=min(a,1001ll);
    }
    return cnt[{st,ret}];
}

void dfsforans(const string&str,map<ll,ll>&pos,ll st,char ret,map<pair<ll,char>,ll>&cnt,const vector<vector<dataa>>&func,map<pair<ll,char>,pair<dataa,ll>>&rev){
    if(isupper(str[st])){
        cout<<' '<<str[st];
    }
    else{
        ll n=str[st+2]-'0';
        cout<<' '<<str[st]<<rev[{st,ret}].second<<' '<<n;
        ll a=0;
        ll j=0;
        ll loc=st+4;
        for(ll i=0;i<n;i++){
            dfsforans(str,pos,loc,rev[{st,ret}].first.par[i],cnt,func,rev);
            loc+=pos[loc];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string str;
    ll id;
    char bef=0;
    vector<vector<dataa>>func(26);
    while(true){
        getline(cin,str);
        if(str=="#"){
            break;
        }
        stringstream ss;
        ss.str(str);
        char t;
        ss>>t;
        dataa x;
        ll n;
        ss>>n;
        x.par.resize(n);
        for(i=0;i<n;i++){
            ss>>x.par[i];
        }
        ss>>x.ret;
        func[t-'a'].push_back(x);
    }
    while(true){
        getline(cin,str);
        if(str=="#")break;
        map<ll,ll>pos;
        map<pair<ll,char>,pair<dataa,ll>>rev;
        map<pair<ll,char>,ll>cnt;
        get_pos(str,pos,4);
        ll now=ans(str,pos,4,str[0],cnt,func,rev);
        switch(now){
        case 0:
            cout<<"impossible\n";
            break;
        case 1:
            cout<<str.substr(0,3);
            dfsforans(str,pos,4,str[0],cnt,func,rev);
            cout<<'\n';
            break;
        default:
            cout<<"ambiguous ";
            if(now>1000){
                cout<<"> 1000\n";
            }
            else cout<<now<<'\n';
        }
    }


    return 0;
}
