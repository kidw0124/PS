#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using ld = long double;
#ifdef kidw0124
    constexpr bool xdebug = true;
#else
    constexpr bool xdebug = false;
#endif
#define debug if constexpr (xdebug) cout<<"[DEBUG] "
void setup(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#endif
}

struct Node{
    ll n=0;
    vector<Node*> chi;
    Node* par= nullptr;
    ~Node(){
        ll n=chi.size();
        for(ll i=0;i<n;i++){
            delete chi[i];
        }
    }
};

void preprocess(){
    ll i,j,k;


}

ll func(Node* r){
    if(r->n){
        return r->n;
    }
    vector<ll>tmp;
    for(auto k:r->chi){
        tmp.push_back(func(k));
    }
    sort(tmp.begin(),tmp.end());
    for(ll i=0;i<tmp.size()/2+1;i++){
        r->n+=tmp[i];
    }
    return r->n;
}

void solve(ll testcase){
    ll i,j,k;
    string str;
    cin>>str;
    Node root;
    Node*now=&root;
    for(i=0;i<str.size();i++){
        if(str[i]=='['){
            now->chi.push_back(new Node());
            now->chi.back()->par = now;
            now=now->chi.back();
        }
        else if(str[i]==']'){
            now=now->par;
        }
        else{
            ll en=find(str.begin()+i,str.end(),']')-str.begin()-i;
            ll num = stoll(str.substr(i,en));
            now->n = num/2+1;
            i=i+en-1;
        }
    }
    cout<<func(&root)<<'\n';
}


int main(){
    setup();
    preprocess();
    ll te=1;
    cin>>te;
    for(ll tc=1;tc<=te;tc++){
        solve(tc);
    }
}