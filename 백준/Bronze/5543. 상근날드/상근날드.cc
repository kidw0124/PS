#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    LL i,j;
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    cout<<min(min(a,b),c)+min(d,e)-50;


    return 0;
}
