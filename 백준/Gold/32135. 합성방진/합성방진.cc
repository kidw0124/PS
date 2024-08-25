#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

void preprocess() {

}

bool isprime(ll n) {
    if(n<2)return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

void solve() {
    ll i,j;
    ll n;
    cin>>n;
    srand(time(0));
    vector<ll> arr;
    vector<ll> brr;
    do{
        arr.clear();
        brr.clear();
        for(i=1;i<=n;i+=2){
            arr.push_back(i);
        }
        for(i=2;i<=n;i+=2){
            brr.push_back(i);
        }
        shuffle(arr.begin(),arr.end(),default_random_engine(rand()));
        shuffle(brr.begin(),brr.end(),default_random_engine(rand()));
    }while(isprime(arr[0]+brr.back()) || isprime(arr.back()+brr[0]));
    arr.insert(arr.end(),brr.begin(),brr.end());
    for(i=0;i<n;i++){
        for(auto x:arr){
            cout<<x<<" ";
        }
        cout<<"\n";
        rotate(arr.begin(),arr.begin()+1,arr.end());
    }

}

int main() {
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    clock_t beg = clock();
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    preprocess();
    ll t=1;
//    cin>>t;
    while(t--)solve();
#ifdef kidw0124
    cout<<clock()-beg<<"ms\n";
#endif
}
