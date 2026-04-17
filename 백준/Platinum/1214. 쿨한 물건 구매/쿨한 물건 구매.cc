#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

LL gcd(LL a, LL b){
    if(a<b)swap(a,b);
    return a%b?gcd(b,a%b):b;
}

LL p,q,d,g,m,mm;

int main(){
    m=(LL)1e9;
    cin>>d>>p>>q;
    if(p<q)swap(p,q);
    if(!(d%p)||!(d%q)){
        cout<<d;
        return 0;
    }else{
        m=(d/p+1)*p;
    }
    mm=m;
    for(LL i=1;i<=mm/p;i++){
        LL t=mm-p*i;
        if(!((d-t)%q)){
            cout<<d;
            return 0;
        }else{
            t+=((d-t)/q+1)*q;
        }
        if(m-t)m=min(m,t);
        else break;
    }
    cout<<m;
//    g=gcd(p,q);
//    p/=g;
//    q/=g;
//    if(!(d%g)){
//        d/=g;
//    }else{
//        d=d/g+1;
//    }
//    if(d>=((p+1)*(q+1))/2-1||!(d%p)||!(d%q)){
//        cout<<d*g;
//        return 0;
//    }else{
//        LL kp=p*(d/p+1);
//        if(m>kp)m=kp;
//        LL kq=q*(d/q+1);
//        if(m>kq)m=kq;
//        for(int i=p;i<=m;i+=q){
//            if(!((d-i)%p)){
//                cout<<d*g;
//                return 0;
//            }else if(i>=d){
//                if(m>i)m=i;
//            }else{
//                LL k=p*((d-i)/p+1)+i;
//                if(m>k)m=k;
//            }
//        }
//        cout<<m*g;
//        return 0;
//    }
}
