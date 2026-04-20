#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <immintrin.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("inline")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
using ll = long long;
using ull = unsigned long long;
using pll = pair<int, int>;
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ld= double;
 
struct SuffixAutomaton {
    struct State {
        int len, link;
        int next[26];
        State(int length):len(length),link(-1){
            memset(next,-1,sizeof(next));
        }
        State():State(0){}
    };
    vector<State>states;
    string s;
    int last;
    void extend(char c){
        int cur=states.size();
        states.push_back(State(states[last].len+1));
        int p=last;
        while(p!=-1&&states[p].next[c-'a']==-1){
            states[p].next[c-'a']=cur;
            p=states[p].link;
        }
        if(p==-1){
            states[cur].link=0;
        }
        else{
            int q=states[p].next[c-'a'];
            if(states[p].len+1==states[q].len){
                states[cur].link=q;
            }
            else{
                int clone=states.size();
                states.push_back(states[q]);
                states[clone].len=states[p].len+1;
                while(p!=-1&&states[p].next[c-'a']==q){
                    states[p].next[c-'a']=clone;
                    p=states[p].link;
                }
                states[q].link=states[cur].link=clone;
            }
        }
        last=cur;
    }
    SuffixAutomaton(const string &str):s(str){
        states.reserve(2*s.size());
        states.push_back(State(0));
        last=0;
        for(char c:s)extend(c);
    }
    vector<int> get_LMax(const string&rt){
        vector<int>LMax;
        LMax.reserve(rt.size());
        int v=0,l=0;
        for(const char&c:rt){
            while(v!=0&&states[v].next[c-'a']==-1){
                v=states[v].link;
                l=states[v].len;
            }
            if(states[v].next[c-'a']!=-1){
                v=states[v].next[c-'a'];
                l++;
            }
            LMax.push_back(l);
        }
        reverse(LMax.begin(),LMax.end());
        return LMax;
    }
};
constexpr int mod=998'244'353;
 
int modpow(int a,int b){
    int res=1;
    a%=mod;
    b%=mod-1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
 
constexpr ld lg3=1.5849625007211561814537389439478165087598144076924810604557526545;
struct WNumber{
    int a,b;
    WNumber(int _a,int _b):a(_a),b(_b){}
    WNumber():WNumber(0,0){}
    // 2^a*3^b
    bool operator<(const WNumber &other)const{
        if(a<=other.a&&b<=other.b)return true;
        else if(a>=other.a&&b>=other.b)return false;
        else if(a==other.a)return b<other.b;
        else if(b==other.b)return a<other.a;
        else return 0<(other.a-a)+(other.b-b)*lg3;
    }
    int to_mod(){
        return modpow(2,a)*modpow(3,b)%mod;
    }
};
constexpr ld ln2=0.6931471805599453094172321214581765680755001343602552541206800095;
constexpr ld ln3=1.0986122886681096913952452369225257046474905578227494517346943332;
struct Number{
    int a,b;
    Number(int _a,int _b):a(_a),b(_b){}
    Number():Number(0,0){}
    // 2^a*3^b
    // make < and = and > and make spaceship operator
    partial_ordering operator<=>(const Number &other)const{
        if(a==other.a&&b==other.b)return strong_ordering::equal;
        else if(a<=other.a&&b<=other.b)return strong_ordering::less;
        else if(a>=other.a&&b>=other.b)return strong_ordering::greater;
        else return 0<=>(other.a-a)+(other.b-b)*lg3;
    }
    int to_mod(){
        return modpow(2,a)*modpow(3,b)%mod;
    }
    ld to_log(){
        return a*ln2+b*ln3;
    }
};
constexpr ld eps=1e-12,INF=1e18;
 
 
 
void solve(int testcase) {
    int i,j,k;
    string s,t,rs,rt;
    cin>>s>>t;
    int n=t.size();
    rs=s;
    rt=t;
    reverse(rs.begin(),rs.end());
    reverse(rt.begin(),rt.end());
    SuffixAutomaton sam_rs(rs);
    vector<int>LMax=sam_rs.get_LMax(rt);
    vector<int>IMax(LMax);
    for(i=0;i<n;i++){
        IMax[i]+=i;
    }
    vector<int>dp(n+1),IMin(n);
    int p=n;
    for(i=n-1;i>=0;i--){
        dp[i]=1+dp[IMax[i]];
        if(dp[i]!=dp[i+1]){
            p=i+1;
        }
        IMin[i]=p;
    }
    cout<<fixed<<setprecision(15);
    vector<ld>score(n+1);
    vector<ld>lg(n+1,-INF);
    for(i=1;i<=n;i++)lg[i]=log((ld)i);
 
    auto eval=[&](int node,int time){
        if(node<time)return -INF;
        return score[node]+lg[node-time];
    };
    auto intersect=[&](int node1,int node2){
        if(node1<0||node2<0)return -1;
        int limit=min(node1,node2)-1;
        if(limit<0)return -1;
        if(eval(node1,0)>=eval(node2,0))return 0;
        if(node1<=node2)return -1;
        ld delta=score[node2]-score[node1];
        ld r=exp(delta);
        ld teq=(r*node2-node1)/expm1(delta);
        int t=(int)floor(teq+eps);
        if(t<0)t=0;
        if(t>limit)t=limit;
        while(t<=limit&&eval(node1,t)<eval(node2,t))t++;
        if(t>limit)return -1;
        while(t>0&&eval(node1,t-1)>=eval(node2,t-1))t--;
        return t;
    };
    struct Node{
        int best=-1;
        int melt=-1;
    };
    vector<Node>tree(n<<2);
    auto pull=[&](int node, int time){
        int l=node<<1,r=node<<1|1;
        if(eval(tree[l].best,time)>eval(tree[r].best,time)){
            tree[node].best=tree[l].best;
            tree[node].melt=max({tree[l].melt,tree[r].melt,intersect(tree[l].best,tree[r].best)});
        }
        else{
            tree[node].best=tree[r].best;
            tree[node].melt=max({tree[l].melt,tree[r].melt,intersect(tree[r].best,tree[l].best)});
        }
    };
 
    function<void(int,int)> heat=[&](int node,int time){
        if(tree[node].melt<time+eps)return;
        heat(node<<1,time);
        heat(node<<1|1,time);
        pull(node,time);
    };
 
    function<void(int,int,int,int)> update=[&](int node,int s,int e,int pos){
        if(s==e){
            tree[node].best=pos;
            tree[node].melt=-INF;
            return;
        }
        int mid=s+e>>1;
        if(pos<=mid)update(node<<1,s,mid,pos);
        else update(node<<1|1,mid+1,e,pos);
        pull(node,pos);
    };
    function<int(int,int,int,int,int,int)>query=[&](int node,int s,int e,int l,int r,int time)->int{
        if(r<s||e<l)return -1;
        heat(node,time);
        if(l<=s&&e<=r){
            return tree[node].best;
        }
        int mid=s+e>>1;
        int left=query(node<<1,s,mid,l,r,time);
        int right=query(node<<1|1,mid+1,e,l,r,time);
        if(left==-1)return right;
        if(right==-1)return left;
        if(eval(left,time)>eval(right,time))return left;
        else return right;
    };
    score[n]=0;
    update(1,0,n,n);
    for(i=n-1;i>=0;i--){
        int best=query(1,0,n,IMin[i],IMax[i],i);
        if(best==-1){
            score[i]=-INF;
            cerr<<"error\n";
        }
        else{
            score[i]=eval(best,i);
        }
        update(1,0,n,i);
    }
    cout<<dp[0]<<" "<<score[0]<<"\n";
 
 
 
    vector<pair<Number,int>> dp2(n+1,{Number(-1,-1),-n-1});
    /// wa1 : Number(0)
    /// wa2 : -n
    dp2[0]={Number(),0};
    /// wa3 : no init
    for(i=0;i<n;i++){
        dp2[i+1]=max(dp2[i+1]
                ,{dp2[i].first,dp2[i].second-1});
        if(LMax[i]<2)continue;
        dp2[i+2]=max(dp2[i+2]
                ,{Number(dp2[i].first.a+1,dp2[i].first.b),dp2[i].second-1});
        if(LMax[i]<3)continue;
        dp2[i+3]=max(dp2[i+3]
                ,{Number(dp2[i].first.a,dp2[i].first.b+1),dp2[i].second-1});
        if(LMax[i]<4)continue;
        dp2[i+4]=max(dp2[i+4]
                ,{Number(dp2[i].first.a+2,dp2[i].first.b),dp2[i].second-1});
    }
    cout<<dp2[n].first.to_log()<<" "<<-dp2[n].second<<"\n";
}
 
void setup() {
    if (ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}
 
void preprocess() {
    int i,j,k;
}
 
signed main() {
    setup();
    preprocess();
    int t = 1;
//    cin >> t;
    for (int testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}
