#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;

constexpr ll mod = 1'000'000'007;

struct trie{
    ll cnt=0;
    vector<trie*>child;
    trie():cnt(0),child(26,NULL){}
    void insert(const string&str, int p){
        if(str.size()==p)return;
        else{
            if(!child[str[p]-'a'])child[str[p]-'a']=new trie();
            child[str[p]-'a']->cnt++;
            child[str[p]-'a']->insert(str,p+1);
        }
    }
    ll find(const string&str,int p,int e){
        if(e==p)return cnt;
        else if(!child[str[p]-'a'])return 0;
        else return child[str[p]-'a']->find(str,p+1,e);
    }
};

void solve() {
    ll i,j,k;
    ll n;
    cin>>n;
    trie*root=new trie();
    for(i=0;i<n;i++){
        string str;
        cin>>str;
        root->insert(str,0);
    }
    string str;
    cin>>str;
    vector<ll>dp(str.size()+1);
    dp[0]=1;
    for(i=0;i<str.size();i++){
        trie*nowtrie=root;
        ll j=i;
        while(j<str.size()){
            if(!nowtrie->child[str[j]-'a'])break;
            nowtrie=nowtrie->child[str[j]-'a'];
            dp[j+1]+=dp[i]*nowtrie->cnt;
            dp[j+1]%=mod;
            j++;
        }
    }
    cout<<dp[str.size()];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    cin.tie(0)->sync_with_stdio(0);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}