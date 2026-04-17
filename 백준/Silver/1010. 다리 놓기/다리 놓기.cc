#include<bits/stdc++.h>
using namespace std;
long long arr[34][34];
int main(){
    for(int i=0;i<34;i++){
        arr[i][0]=arr[i][i]=1;
    }
    for(int i=1;i<34;i++){
        for(int j=1;j<=i;j++){
            arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        cout<<arr[b][a]<<endl;
    }
}
