#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll i,j,k;
    ll n,m,r,p=0;
    string str;
    getline(cin,str);
    while(getline(cin,str)){
        stringstream ss(str);
        vector<string>arr,brr,crr;
        while(ss>>str)arr.push_back(str);
        brr.push_back(arr[0]);
        i=1;
        while(i+1<arr.size()){
            if(arr[i]=="of"){
                if(!isalpha(brr.back().back())){
                    brr.push_back(arr[i++]);
                }
                else if(arr[i+1]=="Korea"){
                    brr.back().front()=towupper(brr.back().front());
                    brr.back()="K-"+brr.back();
                    i+=2;
                }
                else if(arr[i+1]=="Korea."){
                    brr.back().front()=towupper(brr.back().front());
                    brr.back()="K-"+brr.back()+".";
                    i+=2;
                }
                else if(arr[i+1]=="Korea,"){
                    brr.back().front()=towupper(brr.back().front());
                    brr.back()="K-"+brr.back()+",";
                    i+=2;
                }
                else if(arr[i+1]=="Korea?"){
                    brr.back().front()=towupper(brr.back().front());
                    brr.back()="K-"+brr.back()+"?";
                    i+=2;
                }
                else if(arr[i+1]=="Korea!"){
                    brr.back().front()=towupper(brr.back().front());
                    brr.back()="K-"+brr.back()+"!";
                    i+=2;
                }
                else{
                    brr.push_back(arr[i++]);
                }
            }
            else brr.push_back(arr[i++]);
        }
        if(i<arr.size())brr.push_back(arr[i]);
        reverse(brr.begin(),brr.end());
        crr.push_back(brr[0]);
        i=1;
        while(i<brr.size()){
            if(brr[i]=="Korea"){
                crr.back().front()=towupper(crr.back().front());
                crr.back()="K-"+crr.back();
                i++;
            }
            else crr.push_back(brr[i++]);
        }
        reverse(crr.begin(),crr.end());
        for(auto k:crr){
            cout<<k<<' ';
        }
        cout<<'\n';
    }
}
