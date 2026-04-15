#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using pll=pair<ll,ll>;

struct Point{
    ll x,y;
    Point operator+(const Point& rhs) const { return Point{x + rhs.x, y + rhs.y}; }
    Point operator-(const Point& rhs) const { return Point{x - rhs.x, y - rhs.y}; }
    Point operator+=(const Point& rhs) { x += rhs.x; y += rhs.y; return *this; }
    bool operator<(const Point& rhs) const {
        return (x == rhs.x) ? y < rhs.y : x < rhs.x;
    }
};
inline ll outer(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
inline ll ccw(const Point& a, const Point& b, const Point& c) {
    return outer(b - a, c - a);
}

vector<Point> convex_hull(vector<Point>& dat) {
    if (dat.size() <= 3) return dat;
    vector<Point> upper, lower;
    sort(dat.begin(), dat.end(), [](const Point& a, const Point& b) {
        return (a.x == b.x) ? a.y < b.y : a.x < b.x;
    });
    for (const auto& p : dat) {
        while (upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), p) >= 0) upper.pop_back();
        while (lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), p) <= 0) lower.pop_back();
        upper.emplace_back(p);
        lower.emplace_back(p);
    }
    upper.insert(upper.end(), ++lower.rbegin(), --lower.rend());
    return upper;
}
void solve(ll testcase){
    ll i,j;
    ll n;
    cin>>n;
    vector<Point>arr(n),brr(n);
    for(auto&[_,k]:arr)cin>>k;
    arr.insert(arr.begin(),Point{0,0});
    for(i=1;i<=n;i++){
        arr[i].x=i;
        arr[i].y+=arr[i-1].y;
    }
    brr=arr;
    for(auto&p:brr)p.y+=1;
    vector<Point> upper,lower;
    for (const auto& p : arr) {
        while (upper.size() >= 2 && ccw(*++upper.rbegin(), *upper.rbegin(), p) >= 0) upper.pop_back();
        upper.emplace_back(p);
    }
    for(const auto& p : brr){
        while (lower.size() >= 2 && ccw(*++lower.rbegin(), *lower.rbegin(), p) <= 0) lower.pop_back();
        lower.emplace_back(p);
    }
    for(i=1;i<n;i++){
        auto it=lower_bound(upper.begin(), upper.end(),Point{i,(ll)1e18});
        auto pit=prev(it);
        ll lef=i-pit->x, rig=it->x-i;
        if(pit->y*rig+it->y*lef>=(arr[i].y+1)*(lef+rig)){
            cout<<"Impossible";
            return;
        }
        it=lower_bound(lower.begin(), lower.end(),Point{i,(ll)1e18});
        pit=prev(it);
        lef=i-pit->x, rig=it->x-i;
        if(pit->y*rig+it->y*lef<(arr[i].y)*(lef+rig)){
            cout<<"Impossible";
            return;
        }

    }
    ll st=0,en=lower.size()-1;
    auto func=[&](){
        if(ccw(upper[st],lower[en],lower[en-1])<0)return 1;
        if(ccw(lower[en],upper[st],upper[st+1])<0)return -1;
        return 0;
    };
    while(ll flag=func()){
        if(flag==1)en--;
        else st++;
    }
    cout<<fixed<<setprecision(6)<<(ld)(lower[en].y-upper[st].y)/(lower[en].x-upper[st].x);

}

void setup(){
#ifdef kidw0124
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
}

int main(){
    setup();
    ll tc=1;
//    cin>>tc;
    for(ll t=1;t<=tc;t++)solve(t);
}