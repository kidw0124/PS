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
ll t,n;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cin>>n;
        deque<ll>arr(n);
        string k;
        cin>>k;
        k=k.substr(0,k.size()-1);
        k=k.substr(1,k.size()-1);
        vector<ll>comma;
        comma.push_back(0-1);
        for(i=0;i<k.size();i++){
            if(k[i]==',')comma.push_back(i);
        }
        for(i=0;i<n-1;i++){
            arr[i]=stoll(k.substr(comma[i]+1,comma[i+1]-comma[i]));
        }
        if(n)arr[i]=stoll(k.substr(comma[i]+1));
        bool rev=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='R'){
                rev=!rev;
            }
            else{
                if(arr.size()==0){
                    cout<<"error";
                    break;
                }
                else if(rev){
                    arr.pop_back();
                }
                else arr.pop_front();
            }
        }
        if(s.size()==i){
            if(!arr.size()){
                cout<<"[]\n";
                continue;
            }
            if(rev){
                cout<<"[";
                for(i=arr.size()-1;i>0;i--){
                    cout<<arr[i]<<",";
                }
                cout<<(arr.size()?to_string(arr[i]):"")<<"]";
            }
            else{
                cout<<"[";
                for(i=0;i<arr.size()-1;i++){
                    cout<<arr[i]<<",";
                }
                cout<<(arr.size()?to_string(arr[i]):"")<<"]";

            }
        }
        cout<<'\n';
    }

    return 0;
}
