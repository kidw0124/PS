#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,j,k,sum=0;
    vector<int>arr(9);
    for(i=0;i<9;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr.begin(),arr.end());
    for(i=0;i<9;i++){
        for(j=i+1;j<9;j++){
            if(sum-arr[i]-arr[j]==100){
                for(k=0;k<9;k++){
                    if(k!=i&&k!=j)cout<<arr[k]<<' ';
                }
                return 0;
            }
        }
    }
}