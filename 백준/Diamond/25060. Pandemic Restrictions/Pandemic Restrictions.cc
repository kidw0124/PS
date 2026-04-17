#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using ld = long double;

#ifdef ONLINEJUDGE
constexpr bool isdebug=false;
#else
constexpr bool isdebug=true;
#endif

#define debug if(isdebug)cout


struct point{
    ld x,y;
    point operator-(const point &r)const{
        return{x-r.x,y-r.y};
    }
    ld norm(){
        return x*x+y*y;
    }
};

ld dist2(point A, point B){
    return (A-B).norm();
}
ld S(point A, point B, point C){
    ld ret=A.x*B.y+B.x*C.y+C.x*A.y
           -(A.y*B.x+B.y*C.x+C.y*A.x);
    return abs(ret)/2;
}

ld fermat(point A, point B, point C){
    ld ab2=dist2(A, B),bc2=dist2(B, C),ca2=dist2(C, A);
    if(ab2 > bc2 && ab2 > ca2){
        swap(A,C);
    }
    else if(bc2 > ab2 && bc2 > ca2){

    }
    else{
        swap(A,B);
    }
    ab2=dist2(A, B),bc2=dist2(B, C),ca2=dist2(C, A);
    ld cosA=(ab2+ca2-bc2)/(2*sqrt(ab2)*sqrt(ca2));
    if(cosA<=-0.5){
        return sqrt(ab2)+sqrt(ca2);
    }
    else{
        return sqrt((ab2+bc2+ca2)/2+2*sqrt((ld)3)*S(A,B,C));
    }
}
const ld eps=1e-12;

point tern(ld x, point A, point B, point C){
    ld st=min({A.y,B.y,C.y}),en=max({A.y,B.y,C.y});
    while(st+eps<en){
        ld m1=(st*2+en)/3;
        ld m2=(st+en*2)/3;
        point M1={x,m1};
        point M2={x,m2};
        ld v1=max({fermat(A, B, M1),fermat(A, C, M1),fermat(B, C, M1)});
        ld v2=max({fermat(A, B, M2),fermat(A, C, M2),fermat(B, C, M2)});
        if(v1>v2)st=m1;
        else en=m2;
    }
    return {x,st};
}

void solve()
{
    point A,B,C;
    cout<<setprecision(10)<<fixed;
    cin>>A.x>>A.y;
    cin>>B.x>>B.y;
    cin>>C.x>>C.y;
//    point ans={A.x+B.x+C.x-min({A.x,B.x,C.x})-max({A.x,B.x,C.x})
//               ,A.y+B.y+C.y-min({A.y,B.y,C.y})-max({A.y,B.y,C.y})};
//    point tmp={2.3842,0.4151};
//    debug<<fermat(A,B,tmp)<<' '<<fermat(B,C,tmp)<<' '<<fermat(C,A,tmp)<<'\n';
    ld st=min({A.x,B.x,C.x}),en=max({A.x,B.x,C.x});
    while(st+eps<en){
        ld m1=(st*2+en)/3;
        ld m2=(st+en*2)/3;
        point M1=tern(m1,A,B,C);
        point M2=tern(m2,A,B,C);
        ld v1=max({fermat(A, B, M1),fermat(A, C, M1),fermat(B, C, M1)});
        ld v2=max({fermat(A, B, M2),fermat(A, C, M2),fermat(B, C, M2)});
//        debug<<st<<' '<<en<<' '<<m1<<' '<<v1<<' '<<m2<<' '<<v2<<'\n';
        if(v1>v2)st=m1;
        else en=m2;
    }
    point ans=tern(st,A,B,C);
    cout<<max({fermat(A, B, ans),fermat(A, C, ans),fermat(B, C, ans)});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
//    cin >> t;
    while(t--)solve();
    return 0;
}