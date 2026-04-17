#include <bits/stdc++.h>

#define fastio cin.tie(0)->sync_with_stdio(0)

using ll = long long;

using ld = double;

using namespace std;

struct po{

    ll a,b,c;

    ld get(ld x) { return a * x *x + b*x+c; }

};

struct Line {

    ll a, b;

    ld get(ld x) { return a * x + b; }

    bool operator<(const Line&r)const{

        return a==r.a?b<r.b:a>r.a;

    }

    bool operator==(const Line&r)const{

        return a==r.a;

    }

    Line operator-(const Line&r)const{

        return {a-r.a,b-r.b};

    }

    po operator*(const Line&r)const{

        return {a*r.a,a*r.b+b*r.a,b*r.b};

    }

    ld intersect(const Line&r){

        return (r.b-b)/(ld)(a-r.a);

    }

};

template<typename T>

vector<T> uni(vector<T> vct){

    vector<T> ret;

    for(auto k:vct){

        if(ret.size()>0&&ret.back()==k)continue;

        else ret.push_back(k);

    }

    return ret;

};

void solve() {

    int n,i,j; cin >> n;

    vector<Line>xrr(n),yrr(n);

    for(i = 0; i < n; i++) {

        cin>>xrr[i].b>>yrr[i].b;

        cin>>xrr[i].a>>yrr[i].a;

    }

    auto get_lower_hull = [](vector<Line>&vct) -> pair<vector<Line>,vector<ld>> {

        sort(vct.begin(), vct.end());

        vector<Line>hull;

        vector<ld>ins;

        for(auto k:vct){

            if(hull.size()>0&&hull.back()==k)continue;

            while(hull.size()>=2){

                Line top=hull.back();

                hull.pop_back();

                ld int1=ins.back();

                ins.pop_back();

                ld int2=hull.back().intersect(k);

                if(int1<int2){

                    hull.push_back(top);

                    ins.push_back(int1);

                    break;

                }

            }

            if(hull.size()>0)ins.push_back(hull.back().intersect(k));

            hull.push_back(k);

        }

        ll i=0;

        while(i<ins.size()&&ins[i]<0)i++;

        vector<Line>h;vector<ld>in;

        for(;i<ins.size();i++){

            h.push_back(hull[i]);

            in.push_back(ins[i]);

        }

        h.push_back(hull[i]);

        return {h,in};

    };

    auto get_upper_hull = [](vector<Line>&vct) -> pair<vector<Line>,vector<ld>>{

        for(auto&k:vct){

            k.a=-k.a,k.b=-k.b;

        }

        sort(vct.begin(), vct.end());

        vct=uni<Line>(vct);

        vector<Line>hull;

        vector<ld>ins;

        for(auto k:vct){

            if(hull.size()>0&&hull.back()==k)continue;

            while(hull.size()>=2){

                Line top=hull.back();

                hull.pop_back();

                ld int1=ins.back();

                ins.pop_back();

                ld int2=hull.back().intersect(k);

                if(int1<int2){

                    hull.push_back(top);

                    ins.push_back(int1);

                    break;

                }

            }

            if(hull.size()>0)ins.push_back(hull.back().intersect(k));

            hull.push_back(k);

        }

        ll i=0;

        while(i<ins.size()&&ins[i]<0)i++;

        vector<Line>h;vector<ld>in;

        for(;i<ins.size();i++){

            h.push_back(hull[i]);

            in.push_back(ins[i]);

        }

        h.push_back(hull[i]);

        for(auto&k:h){

            k.a=-k.a,k.b=-k.b;

        }

        return {h,in};

    };

    auto [x_lower_hull,x_lower_ins]=get_lower_hull(xrr);

    auto [x_upper_hull,x_upper_ins]=get_upper_hull(xrr);

    auto [y_lower_hull,y_lower_ins]=get_lower_hull(yrr);

    auto [y_upper_hull,y_upper_ins]=get_upper_hull(yrr);

    vector<Line>xcomb,ycomb;

    vector<ld>xins,yins;

    auto comb = [](vector<Line>&x_lower_hull,vector<Line>&x_upper_hull

            ,vector<ld>&x_lower_ins,vector<ld>&x_upper_ins)-> pair<vector<Line>,vector<ld>>{

        vector<Line>xcomb;

        vector<ld>xins;

        ll i=0,j=0;

        while(i<x_lower_ins.size()&&j<x_upper_ins.size()){

            xcomb.push_back(x_upper_hull[j]-x_lower_hull[i]);

            if(x_lower_ins[i]<x_upper_ins[j]){

                xins.push_back(x_lower_ins[i]);

                i++;

            }

            else{

                xins.push_back(x_upper_ins[j]);

                j++;

            }

        }

        while(i<x_lower_ins.size()){

            xcomb.push_back(x_upper_hull[j]-x_lower_hull[i]);

            xins.push_back(x_lower_ins[i]);

            i++;

        }

        while(j<x_upper_ins.size()){

            xcomb.push_back(x_upper_hull[j]-x_lower_hull[i]);

            xins.push_back(x_upper_ins[j]);

            j++;

        }

        xcomb.push_back(x_upper_hull[j]-x_lower_hull[i]);

        return {xcomb,xins};

    };

    auto px=comb(x_lower_hull,x_upper_hull,x_lower_ins,x_upper_ins);

    xcomb=px.first,xins=px.second;

    auto py=comb(y_lower_hull,y_upper_hull,y_lower_ins,y_upper_ins);

    ycomb=py.first,yins=py.second;

    ld ans=1e20;

    i=0,j=0;

    auto get_ans=[](ld st, ld en,Line& a, Line& b)->ld{

        ld eps=1e-12;

        po tmp=a*b;

        if(tmp.a<eps &&tmp.a>-eps){

            if(tmp.b<eps &&tmp.b>-eps){

                return tmp.c;

            }

            else{

                if(tmp.b>0){

                    return a.get(st)*b.get(st);

                }

                else {

                    return a.get(en)*b.get(en);

                }

            }

        }

        else{

            ld ptpt=-(tmp.b/(ld)(2*tmp.a));

            if(tmp.a>0) {

                if (ptpt < st) {

                    return a.get(st) * b.get(st);

                } else if (ptpt > en) {

                    return a.get(en) * b.get(en);

                } else return a.get(ptpt) * b.get(ptpt);

            }

            else return min(a.get(en) * b.get(en),a.get(st) * b.get(st));

        }

    };

    while(i<xins.size()&&j<yins.size()){

        ld rxs,rxe,rys,rye;

        rxe=max((ld)0,xins[i]),rye=max((ld)0,yins[j]);

        rxs=max((ld)0,(i-1>=0?xins[i-1]:0)),rys=max((ld)0,(j-1>=0?yins[j-1]:0));

        ld st=max(rxs,rys);

        if(rxe<rye){

            ans=min(ans,get_ans(st,rxe,xcomb[i],ycomb[j]));

            i++;

        }

        else{

            ans=min(ans,get_ans(st,rye,xcomb[i],ycomb[j]));

            j++;

        }

    }

    while(i<xins.size()){

        ld rxs,rxe,rys;

        rxe=max((ld)0,xins[i]);

        rxs=max((ld)0,(i-1>=0?xins[i-1]:0)),rys=max((ld)0,(j-1>=0?yins[j-1]:0));

        ld st=max(rxs,rys);

        ans=min(ans,get_ans(st,rxe,xcomb[i],ycomb[j]));

        i++;

    }

    while(j<yins.size()){

        ld rxs,rys,rye;

        rye=max((ld)0,yins[j]);

        rxs=max((ld)0,(i-1>=0?xins[i-1]:0)),rys=max((ld)0,(j-1>=0?yins[j-1]:0));

        ld st=max(rxs,rys);

        ans=min(ans,get_ans(st,rye,xcomb[i],ycomb[j]));

        j++;

    }

    ld rxs=max((ld)0,(i-1>=0?xins[i-1]:0)),rys=max((ld)0,(j-1>=0?yins[j-1]:0));

    ld st=max(rxs,rys);

    ans=min(ans,get_ans(st,1e18,xcomb[i],ycomb[j]));

    cout<<ans;

}

int main() {

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#else

    fastio;

#endif

    cout<<setprecision(10)<<fixed;

    solve();

}