#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef  pair<int,int> pii;

LL gcd(LL a,LL b){
    if(a<b)swap(a,b);
    if(!(a%b))return b;
    return gcd(b,a%b);
}

int main(){
    vector<pii>data;
    int i,j,u,d,dd=0,uu,k;
    vector<int> C;
    int N,K;
    LL ans=0;
    scanf("%d %d",&N,&K);
    for(i=0;i<N;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        data.push_back(pii(t1,t2));
    }
    for(i=0;i<K;i++){
        int temp;
        scanf("%d",&temp);
        C.push_back(temp);
    }
    uu=K;
    sort(C.begin(),C.end());
    sort(data.begin(),data.end());
    priority_queue<int>gem;
    j=0;
    for(i=0;i<K;i++){
        while(j<N&&data[j].first<=C[i]){
            gem.push(data[j++].second);
        }
        if(!gem.empty()){
            ans+=gem.top();
            gem.pop();
        }
    }
    printf("%lld",ans);
    return 0;
}
