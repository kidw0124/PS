#include<bits/stdc++.h>
using namespace std;

long long n,k;

vector<long long>arr;

int main(){
    long long i,j;
    cin>>k>>n;
    long long pivot,fir,las,mp=0;
    for(i=0;i<k;i++){
        long long te;
        cin>>te;
        arr.push_back(te);
    }
    sort(arr.begin(),arr.end());
    fir=1;las=arr[k-1];
    while(las>=fir){
        pivot=(fir+las)>>1;
        long long nn=0;
        for(i=0;i<k;i++){
            nn+=arr[i]/pivot;
        }
        if(nn>=n){
            fir=pivot+1;
            mp=pivot;
        }
        else{
            las=pivot-1;
        }
    }
    cout<<mp;
}