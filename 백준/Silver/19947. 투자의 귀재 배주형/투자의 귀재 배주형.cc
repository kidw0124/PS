#include<bits/stdc++.h>
using namespace std;

int maxin[11];

int main(){
    int n;
    int y;
    cin>>n>>y;
    maxin[0]=n;
    for(int i=1;i<=y;i++){
        if(i>=5)maxin[i]=max(maxin[i],(int)(1.35*maxin[i-5]));
        if(i>=3)maxin[i]=max(maxin[i],(int)(1.2*maxin[i-3]));
        if(i>=1)maxin[i]=max(maxin[i],(int)(1.05*maxin[i-1]));
    }
    cout<<(int)(maxin[y]);
}