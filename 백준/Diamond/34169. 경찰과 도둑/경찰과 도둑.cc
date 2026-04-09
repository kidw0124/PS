#include <bits/stdc++.h>
#include <immintrin.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
using ll = unsigned long long;
using pll = pair<ll, ll>;
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll modpow(ll a, ll b, ll m){
    ll res=1;
    a%=m;
    while(b){
        if(b&1)res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    return res;
}


void solve(ll testcase) {
    ll i;
    ll p,n,f,d,j,a,b;
    ll tot=0,cnt=0;
    cin>>p>>n>>f>>d>>j>>a>>b;
    ll g=gcd(p-1,n);
    a%=p,b%=p;
    if(n==0){
        tot=cnt=1;
    }
    else if(p==2){
        if(a==0)cnt=5,tot=6;
        else if(b==0)cnt=tot=1;
        else cnt=2,tot=3;
    }
    else if(p%4==1){
        auto sqrt_m1=[p](){
            ll q=p-1,s=0;
            while((q&1)==0)q>>=1,s++;
            ll z=2;
            while(modpow(z,(p-1)>>1,p)!=p-1){
                z++;
            }
            ll c=modpow(z,q,p);
            ll r=modpow(p-1,(p+1)>>2,p);
            ll t=modpow(p-1,q,p);
            ll m=s;
            while(t!=1){
                ll i=1;
                ll t2=t*t%p;
                while(t2!=1){
                    t2=t2*t2%p;
                    i++;
                }
                ll b=modpow(c,1ll<<(m-i-1),p);
                r=r*b%p;
                c=b*b%p;
                t=t*c%p;
                m=i;
            }
            return r;
        };
        ll s=sqrt_m1();
        ll as=a*s%p;
        tot=p*p*1 // (x,y,0)
            +1*1*(p-1) // (0,0,z)
            +(p-1)*1*(p-1) // (x,x,z)
            +(p-1)*1*(p-1) // (x,-x,z)
            +(p-1)*1*(p-1) // (x,sx,z)
            +(p-1)*1*(p-1) // (x,-sx,z)
                ;
        tot*=2; // max 8e18 < LLMAX
        cnt=p*p*1*2; // (x,y,0)
        if(b==0)cnt+=1*1*(p-1)*2; // (0,0,z)
        if(a==0 && b==0){
            ;
        }
        else if(a==0){
            if(f==1 && j==1){
                ;
            }
            else if(f==0 && d==1){
                cnt+=g*1*(p-1)*8; // X^N=b^N
                if(modpow(p-1,(p-1)/g,p)==1){
                    cnt+=g*1*(p-1)*8; // X^N+b^N=0
                }
            }
            else{
                cnt+=g*1*(p-1)*4; // X^N=b^N
                if(modpow(p-1,(p-1)/g,p)==1){
                    cnt+=g*1*(p-1)*4; // X^N+b^N=0
                }
            }
        }
        else if(b==0){
            if(f==1 && j==1){
                ;
            }
            else if(f==0 && d==1){
                // x=y
                if(modpow(a,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*2; // (1-a^N)X^N=0
                }
                else if(modpow(a,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*2; // (1+a^N)X^N=0
                }

                // x=-y
                if(modpow(p-a,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*2; // (1-(-a)^N)X^N=0
                }
                else if(modpow(p-a,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*2; // (1+(-a)^N)X^N=0
                }
                
                // x=as
                if(modpow(as,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*2; // (1-a^N)X^N=0
                }
                else if(modpow(as,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*2; // (1+a^N)X^N=0
                }
                
                // x=-as
                if(modpow(p-as,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*2; // (1-(-a)^N)X^N=0
                }
                else if(modpow(p-as,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*2; // (1+(-a)^N)X^N=0
                }
            }
            else{
                // x=y
                if(modpow(a,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*1; // (1-a^N)X^N=0
                }
                else if(modpow(a,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*1; // (1+a^N)X^N=0
                }

                // x=-y
                if(modpow(p-a,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*1; // (1-(-a)^N)X^N=0
                }
                else if(modpow(p-a,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*1; // (1+(-a)^N)X^N=0
                }
                
                // x=as
                if(modpow(as,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*1; // (1-a^N)X^N=0
                }
                else if(modpow(as,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*1; // (1+a^N)X^N=0
                }
                
                // x=-as
                if(modpow(p-as,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*1; // (1-(-a)^N)X^N=0
                }
                else if(modpow(p-as,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*1; // (1+(-a)^N)X^N=0
                }
            }
        }
        else{
            if(f==1 && j==1){
                ;
            }
            else if(f==0 && d==1){
                // x=y
                if(modpow(a,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*2; // (1-c^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*2; // (1-c^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(a,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*2; // (1+c^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*2; // (1+c^N)X^N=0
                    }
                }

                // x=-y
                if(modpow(p-a,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*2; // (1-(-a)^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*2; // (1-(-a)^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(p-a,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*2; // (1+a^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*2; // (1+a^N)X^N=0
                    }
                }
                
                // x=as
                if(modpow(as,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*2; // (1-c^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*2; // (1-c^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(as,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*2; // (1+c^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*2; // (1+c^N)X^N=0
                    }
                }
                
                // x=-as
                if(modpow(p-as,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*2; // (1-(-a)^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*2; // (1-(-a)^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(p-as,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*2; // (1+a^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*2; // (1+a^N)X^N=0
                    }
                }
            }
            else{
                // x=y
                if(modpow(a,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*1; // (1-c^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*1; // (1-c^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(a,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*1; // (1+c^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*1; // (1+c^N)X^N=0
                    }
                }

                // x=-y
                if(modpow(p-a,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*1; // (1-(-a)^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*1; // (1-(-a)^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(p-a,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*1; // (1+a^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*1; // (1+a^N)X^N=0
                    }
                }
                
                // x=as
                if(modpow(as,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*1; // (1-c^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*1; // (1-c^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(as,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*1; // (1+c^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*1; // (1+c^N)X^N=0
                    }
                }
                
                // x=-as
                if(modpow(p-as,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*1; // (1-(-a)^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*1; // (1-(-a)^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(p-as,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*1; // (1+a^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*1; // (1+a^N)X^N=0
                    }
                }
            }
        }
    }
    else{
        tot=p*p*1 // (x,y,0)
           +1*1*(p-1) // (0,0,z)
           +(p-1)*1*(p-1) // (x,x,z)
           +(p-1)*1*(p-1) // (x,-x,z)
           ;
        tot*=2; // max 8e18 < LLMAX
        cnt=p*p*1*2; // (x,y,0)
        if(b==0)cnt+=1*1*(p-1)*2; // (0,0,z)
        if(a==0 && b==0){
            ;
        }
        else if(a==0){
            if(f==1 && j==1){
                ;
            }
            else if(f==0 && d==1){
                cnt+=g*1*(p-1)*4; // X^N=b^N
                if(modpow(p-1,(p-1)/g,p)==1){
                    cnt+=g*1*(p-1)*4; // X^N+b^N=0
                }
            }
            else{
                cnt+=g*1*(p-1)*2; // X^N=b^N
                if(modpow(p-1,(p-1)/g,p)==1){
                    cnt+=g*1*(p-1)*2; // X^N+b^N=0
                }
            }
        }
        else if(b==0){
            if(f==1 && j==1){
                ;
            }
            else if(f==0 && d==1){
                // x=y
                if(modpow(a,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*2; // (1-a^N)X^N=0
                }
                else if(modpow(a,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*2; // (1+a^N)X^N=0
                }

                // x=-y
                if(modpow(p-a,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*2; // (1-(-a)^N)X^N=0
                }
                else if(modpow(p-a,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*2; // (1+(-a)^N)X^N=0
                }

            }
            else{
                // x=y
                if(modpow(a,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*1; // (1-a^N)X^N=0
                }
                else if(modpow(a,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*1; // (1+a^N)X^N=0
                }

                // x=-y
                if(modpow(p-a,n,p)==1){
                    cnt+=(p-1)*1*(p-1)*1; // (1-(-a)^N)X^N=0
                }
                else if(modpow(p-a,n,p)==p-1){
                    cnt+=(p-1)*1*(p-1)*1; // (1+(-a)^N)X^N=0
                }
            }
        }
        else{
            if(f==1 && j==1){
                ;
            }
            else if(f==0 && d==1){
                // x=y
                if(modpow(a,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*2; // (1-c^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*2; // (1-c^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(a,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*2; // (1+c^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*2; // (1+c^N)X^N=0
                    }
                }

                // x=-y
                if(modpow(p-a,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*2; // (1-(-a)^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*2; // (1-(-a)^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(p-a,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*2; // (1+a^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*2; // (1+a^N)X^N=0
                    }
                }
            }
            else{
                // x=y
                if(modpow(a,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*1; // (1-c^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*1; // (1-c^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(a,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*1; // (1+c^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*1; // (1+c^N)X^N=0
                    }
                }

                // x=-y
                if(modpow(p-a,n,p)==1){
                    cnt+=(g-1)*1*(p-1)*1; // (1-(-a)^N)X^N=0
                }
                else{
                    cnt+=g*1*(p-1)*1; // (1-(-a)^N)X^N=0
                }
                if(modpow(p-1,(p-1)/g,p)==1){
                    if(modpow(p-a,n,p)==p-1){
                        cnt+=(g-1)*1*(p-1)*1; // (1+a^N)X^N=0
                    }
                    else{
                        cnt+=g*1*(p-1)*1; // (1+a^N)X^N=0
                    }
                }
            }
        }
    }
    ll gc=gcd(tot,cnt);
//    debug<< "tot: " << tot << ", cnt: " << cnt << ", gcd: " << g << "\n";
    tot/=gc;
    cnt/=gc;
//    debug << "Reduced tot: " << tot << ", Reduced cnt: " << cnt << "\n";
    if(tot==0)cout<<"-1\n";
    else if(tot==cnt)cout<<"1\n";
    else if(cnt==0)cout<<"0\n";
    else cout<<cnt<<"/"<<tot<<"\n";
}

void setup() {
    if (ddebug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
}

void preprocess() { ll i, j, k; }

signed main() {
    setup();
    preprocess();
    ll t = 1;
    cin >> t;
    for (ll testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
    }
    return 0;
}
