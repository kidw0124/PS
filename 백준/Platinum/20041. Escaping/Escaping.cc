#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;

const ll mn=500000+5;

vector<pair<ll,ll> > arr;
pair<ll,ll> loc;
vector<ll> dt;


ll ddx[4]={0,0,1,-1};
ll ddy[4]={1,-1,0,0};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    ll i,j;
    for(i=0;i<n;i++){
        ll t1,t2;
        cin>>t1>>t2;
        arr.push_back({t1,t2});
    }
    cin>>loc.first>>loc.second;
    int c=4;
    for(i=0;i<n;i++){
        if(arr[i].first>loc.first){
            if(arr[i].first-loc.first>=abs(arr[i].second-loc.second)){
                c--;
                break;
            }
        }
    }
    for(i=0;i<n;i++){
        if(arr[i].first<loc.first){
            if(loc.first-arr[i].first>=abs(arr[i].second-loc.second)){
                c--;
                break;
            }
        }

    }
    for(i=0;i<n;i++){
        if(arr[i].second<loc.second){
            if(loc.second-arr[i].second>=abs(arr[i].first-loc.first)){
                c--;
                break;
            }
        }

    }
    for(i=0;i<n;i++){
        if(arr[i].second>loc.second){
            if(arr[i].second-loc.second>=abs(arr[i].first-loc.first)){
                c--;
                break;
            }
        }

    }
    if(c==0)cout<<"NO";
    else cout<<"YES";
    return 0;
}
