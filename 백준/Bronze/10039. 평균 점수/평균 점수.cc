#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(){
    int i,j;    
    int sum=0;
    for(i=0;i<5;i++){
        cin>>j;
        sum+=max(j,40)/5;
    }
    
    cout<<sum;
    return 0;
}