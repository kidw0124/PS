#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b) {
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

int n,m;
pair< char, vector<int> > data[2050];
int change[2050];

int main() {
    int i,j;
    cin>>n>>m;
    for(i=0; i<n; i++) {
        char cc;
        vector<int> ci;
        cin>>cc;
        for(j=0; j<m; j++) {
            int t;
            scanf("%1d",&t);
            ci.push_back(t);
            if(t==1) {
                if(cc=='L') {
                    change[j]-=1;
                } else {
                    change[j]+=1;
                }
            }
        }
        data[i]=make_pair(cc,ci);
    }
    int wh;
    int M=9999999;
    if(n==1) {
        cout<<"1\n0";
        return 0;
    }
    for(i=0; i<n; i++) {
        int mm=0;
        int loc=0;
        for(j=0; j<m; j++) {
            loc+=change[j];
            if(data[i].second[j]) {
                if(data[i].first=='L')loc+=1;
                else {
                    loc-=1;
                }
            }

            if(abs(loc)>mm) {
                mm=abs(loc);
            }
        }
        if(mm<M) {
            M=mm;
            wh=i+1;
        }
    }

    cout<<wh<<endl<<M;

    return 0;
}
