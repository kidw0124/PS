#include<bits/stdc++.h>
using namespace std;

vector<int>arr(15);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    arr[0]=1;
    int i;
    for(i=1;i<11;i++){
        if(i>=1){
            arr[i]+=arr[i-1];
        }
        if(i>=2){
            arr[i]+=arr[i-2];
        }
        if(i>=3){
            arr[i]+=arr[i-3];
        }
    }
    int n;
    cin>>n;
    for(i=0;i<n;i++){
        int t;
        cin>>t;
        cout<<arr[t]<<endl;
    }
}
