#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa,M,le,ri;
vector<int> pq;
 
int main(){
    cin>>n>>m>>k>>fa;
    int i,j;
    for(i=0;i<fa;i++){
        int t1,t2;
        cin>>t1>>t2;
        pq.push_back(t2);
        if(M<t1)M=t1;
    }
    sort(pq.begin(),pq.end());
    le=M,ri=m;
    while(le<ri){
        int mid=(le+ri)/2;
        int now=pq[0],cnt=1;
        for(i=0;i<fa;i++){
            if(now+mid>pq[i])continue;
            else now=pq[i],cnt++;
        }
        if(cnt<=k)ri=mid;
        else le=mid+1;
    }
    cout<<le;
}