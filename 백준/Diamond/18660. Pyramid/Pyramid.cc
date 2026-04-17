#include<bits/stdc++.h>
using namespace std;using P=int64_t;using L=__int128;
void solve(P _){P l,r;cin>>l>>r;L L=l,D=r-l,R=r;cout<<"Case #"<<_<<": "<<P(L>D?(2*L-1)*D*(D+1)*(D+2)/6:(L*(L-1)*(L-2)*(L-3)+2*L*D*((L+R-3)*(2*R-3*L+3)+6*D+6)+D*(D-1)*++D*++D)/24)<<'\n';}
int main(){cin.tie(0)->sync_with_stdio(0);P t,_=0;cin>>t;for(;_<t;)solve(++_);}