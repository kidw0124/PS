#define private public
#include <bitset>
#undef private
#include <bits/stdc++.h>
#include <immintrin.h>
#pragma comment(linker, "/STACK:336777216")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("inline")
using namespace std;
#ifdef kidw0124
constexpr bool ddebug = true;
#else
constexpr bool ddebug = false;
#endif
using ll = long long;
using ull = unsigned long long;
using pll = pair<int, int>;
#define debug \
  if constexpr (ddebug) cout << "[DEBUG] "
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ld= double;
 
using pt=array<int,3>;
int sid[7][7][7];
vector<pt> st;
int mt[48][48];
ull pc[48][3][65536];
ull lmm[200005],lmo[200005],rmm[200005],rom[200005];
int n,q;
pt sp;
int sop[200005],dop[200005],ans[200005];
struct qry{int l,r,id;};
vector<qry> qs;
 
inline ull mmul(ull a,ull b){
    ull res=0;
    ull p0=b&0xFFFF;
    ull p1=(b>>16)&0xFFFF;
    ull p2=(b>>32)&0xFFFF;
    while(a){
        int bit=__builtin_ctzll(a);
        a&=~(1ULL<<bit);
        res|=pc[bit][0][p0]|pc[bit][1][p1]|pc[bit][2][p2];
    }
    return res;
}
inline ull smul(int op,ull b){
    return pc[op][0][b&0xFFFF]|pc[op][1][(b>>16)&0xFFFF]|pc[op][2][(b>>32)&0xFFFF];
}
inline int cnt(ull mask){
    pt tmp[48];
    int c=0;
    while(mask){
        int bit=__builtin_ctzll(mask);
        mask&=~(1ULL<<bit);
        const pt& r=st[bit];
        int r0=(r[0]>0)?sp[r[0]-1]:-sp[-r[0]-1];
        int r1=(r[1]>0)?sp[r[1]-1]:-sp[-r[1]-1];
        int r2=(r[2]>0)?sp[r[2]-1]:-sp[-r[2]-1];
        tmp[c++]={r0,r1,r2};
    }
    sort(tmp,tmp+c);
    return unique(tmp,tmp+c)-tmp;
}
void dnc(int s,int e,int qss,int qse){
    int i,j,k;
    if(qss>=qse)return;
    if(s+1==e){
        int val=cnt(1ULL<<sop[s]);
        for(k=qss;k<qse;++k)ans[qs[k].id]=val;
        return;
    }
    int mid=(s+e)/2;
    auto its=qs.begin()+qss;
    auto ite=qs.begin()+qse;
    auto itcr=partition(its,ite,[mid](const qry& q){return(q.r<=mid)||(q.l>=mid);});
    auto itr=partition(its,itcr,[mid](const qry& q){return q.r<=mid;});
    int idxr=distance(qs.begin(),itr);
    int idxcr=distance(qs.begin(),itcr);
    if(idxcr<qse){
        int iden=sid[4][5][6];
        ull idmask=(1ULL<<iden);
        lmm[mid]=idmask;
        for(i=mid-1;i>=s;--i){
            lmm[i]=smul(sop[i],lmm[i+1]);
            if(i+1<mid)lmm[i]|=smul(dop[i],lmm[i+2]);
        }
        lmo[mid]=0;
        lmo[mid-1]=idmask;
        for(i=mid-2;i>=s;--i){
            lmo[i]=smul(sop[i],lmo[i+1]);
            if(i+1<mid-1)lmo[i]|=smul(dop[i],lmo[i+2]);
        }
        rmm[mid]=idmask;
        for(j=mid+1;j<=e;++j){
            rmm[j]=mmul(rmm[j-1],1ULL<<sop[j-1]);
            if(j-2>=mid)rmm[j]|=mmul(rmm[j-2],1ULL<<dop[j-2]);
        }
        rom[mid]=0;
        rom[mid+1]=idmask;
        for(j=mid+2;j<=e;++j){
            rom[j]=mmul(rom[j-1],1ULL<<sop[j-1]);
            if(j-2>=mid+1)rom[j]|=mmul(rom[j-2],1ULL<<dop[j-2]);
        }
        int br=dop[mid-1];
        for(k=idxcr;k<qse;++k){
            qry& cq=qs[k];
            ull res=mmul(lmm[cq.l],rmm[cq.r]);
            res|=mmul(mmul(lmo[cq.l],1ULL<<br),rom[cq.r]);
            ans[cq.id]=cnt(res);
        }
    }
    dnc(s,mid,qss,idxr);
    dnc(mid,e,idxr,idxcr);
}
void solve(int testcase){
    int i,j,k;
    string str;
    cin>>sp[0]>>sp[1]>>sp[2];
    cin>>str;
    n=str.size();
    n=str.size();
    int ids[9];
    auto rawop=[&](int t){
        int x=1,y=2,z=3;
        int rx,ry,rz;
        if(t==0){rx=x;ry=-z;rz=y;}
        else if(t==1){rx=z;ry=y;rz=-x;}
        else if(t==2){rx=-y;ry=x;rz=z;}
        else if(t==3){rx=x;ry=-y;rz=-z;}
        else if(t==4){rx=-x;ry=y;rz=-z;}
        else if(t==5){rx=-x;ry=-y;rz=z;}
        else if(t==6){rx=x;ry=y;rz=-z;}
        else if(t==7){rx=-x;ry=y;rz=z;}
        else{rx=x;ry=-y;rz=z;}
        return sid[rx+3][ry+3][rz+3];
    };
    for(k=0;k<9;++k)ids[k]=rawop(k);
    for(i=0;i<n;++i){
        int t=(str[i]=='X'?1:(str[i]=='Y'?2:3));
        sop[i]=ids[t-1];
    }
    for(i=0;i<n-1;++i){
        int u=(str[i]=='X'?1:(str[i]=='Y'?2:3));
        int v=(str[i+1]=='X'?1:(str[i+1]=='Y'?2:3));
        if(u==v)dop[i]=ids[2+u];
        else if((u==1&&v==2)||(u==2&&v==1))dop[i]=ids[6];
        else if((u==2&&v==3)||(u==3&&v==2))dop[i]=ids[7];
        else dop[i]=ids[8];
    }
    cin>>q;
    qs.resize(q);
    for(i=0;i<q;++i){
        cin>>qs[i].l>>qs[i].r;
        qs[i].l--;
        qs[i].id=i;
    }
    dnc(0,n,0,q);
    for(i=0;i<q;++i)cout<<ans[i]<<"\n";
}
void setup(){
    if(ddebug){
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    }else{
        ios_base::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
    }
}
void preprocess(){
    int i,j,k,base,tmp,bit;
    for(i=-3;i<=3;++i){
        if(!i)continue;
        for(j=-3;j<=3;++j){
            if(!j||abs(i)==abs(j))continue;
            for(k=-3;k<=3;++k){
                if(!k||abs(i)==abs(k)||abs(j)==abs(k))continue;
                sid[i+3][j+3][k+3]=st.size();
                st.push_back({i,j,k});
            }
        }
    }
    for(i=0;i<48;++i){
        for(j=0;j<48;++j){
            pt p=st[i];
            pt r=st[j];
            int res[3];
            for(k=0;k<3;++k){
                int idx=abs(r[k])-1;
                int val=p[idx];
                if(r[k]<0)val=-val;
                res[k]=val;
            }
            mt[i][j]=sid[res[0]+3][res[1]+3][res[2]+3];
        }
    }
    for(i=0;i<48;++i){
        for(j=0;j<3;++j){
            base=j<<4;
            for(k=0;k<65536;++k){
                ull res=0;
                tmp=k;
                while(tmp){
                    bit=__builtin_ctz(tmp);
                    tmp&=~(1<<bit);
                    res|=(1ULL<<mt[i][base+bit]);
                }
                pc[i][j][k]=res;
            }
        }
    }
}
signed main(){
    setup();
    preprocess();
    int t=1;
//    cin >> t;
    for(int testcase=1;testcase<=t;testcase++){
        solve(testcase);
    }
    return 0;
}
