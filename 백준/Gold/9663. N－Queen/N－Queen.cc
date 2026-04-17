#include<iostream>
#include<vector>
#include<iomanip>
#include<ctime>
using namespace std;
vector<int>arr;
int i,now;
long long cnt;
void ans(int n){
    if(n==i){
        cnt++;
        return;
    }
    for(int j=0;j<i;j++){
        int k;
        for(k=0;k<n;k++){
            if(arr[k]==j||abs(n-k)==abs(j-arr[k]))break;
        }
        if(k==n){
            arr[n]=j;
            ans(n+1);
        }
    }
}

int main(){
    //clock_t st,en;
    int n=50;
    cin>>n;
    
    i=n;
    //cout<<fixed<<setprecision(3);
    //for(i=1;i<n;i++){
        arr.resize(n,0);
        cnt=0;
        //st=clock();
        ans(0);
    cout<<cnt;
        //en=clock();
        //cout<<"n = "<<setw(3)<<i<<" : "<<"answer is "<<setw(10)<<cnt<<".\tTime : "<<setw(6)<<(en-st)/(double)CLK_TCK<<"s"<<'\n';
    //}

    //clock();
}
