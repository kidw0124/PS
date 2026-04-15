#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
using ld=long double;
#ifdef kidw0124
constexpr bool ddebug=true;
#else
constexpr bool ddebug=false;
#endif

void setup(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }
    else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess(){
    ll i,j,k;

}
struct Point{
    ll x,y;
    Point operator-(const Point&r)const{
        return {x-r.x,y-r.y};
    }
};
struct Line{
    Point pos, dir;
};

void solve(ll tc){
    ll i,j,k;
    ll x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    pll st,en;
    cin>>st.first>>st.second;
    cin>>en.first>>en.second;
    const ld eps=1e-12;
    auto is_between=[=](ld s, ld e, ld x){
        return s<e?(s-eps<x&&x<e+eps):(e-eps<x&&x<s+eps);
    };
    auto outer=[](const Point a, const Point b){
        return a.x*b.y-a.y*b.x;
    };
    auto get_segment_cross=[&](const Line&a, const Line&b){
        ll mdet=outer(b.dir,a.dir);
        if(mdet==0)return false;
        ld t1=-outer(b.pos-a.pos,b.dir)/(ld)mdet;
        ld t2=outer(a.dir,b.pos-a.pos)/(ld)mdet;
        if(!is_between(0,1,t1)||!is_between(0,1,t2))return false;
        return true;
    };
    if(is_between(x1,x2,st.first)&&is_between(x1,x2,en.first)
       &&is_between(y1,y2,st.second)&&is_between(y1,y2,en.second)){
        cout<<"STOP\n";
        return;
    }
    else{
        Line tt={{st.first,st.second},{en.first-st.first,en.second-st.second}};
        Line tmp={{x1,y1},{x2-x1,0}};
        if(get_segment_cross(tmp,tt)){
            cout<<"STOP\n";
            return;
        }
        tmp={{x2,y1},{0,y2-y1}};
        if(get_segment_cross(tmp,tt)){
            cout<<"STOP\n";
            return;
        }
        tmp={{x1,y2},{x2-x1,0}};
        if(get_segment_cross(tmp,tt)){
            cout<<"STOP\n";
            return;
        }
        tmp={{x1,y1},{0,y2-y1}};
        if(get_segment_cross(tmp,tt)){
            cout<<"STOP\n";
            return;
        }
        cout<<"OK\n";
    }
}

int main(){
    setup();
    ll t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve(i+1);
    }
}