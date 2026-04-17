#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
    int i,j;
    int N,sum=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        int t,tt;
        scanf("%d %d",&t,&tt);
        sum+=t*tt;
    }
    cout<<sum;

    return 0;
}
