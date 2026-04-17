#include<bits/stdc++.h>
using namespace std;

vector<string> s;

string spa="   ";

string pows(string str, int m){
    string h=str;
    for(int i=1;i<m;i++){
        h+=str;
    }
    return h;
}

void star(int shift){
    int c=s.size();
    int i;
    string sshift=pows(spa,shift);
    for(i=0;i<c;i++){
        s.push_back(s[i]+s[i]);
        s[i]=(sshift+s[i]+sshift);
    }
}

int main(){
    int n,k,i,j;
    cin>>n;
    s.push_back("  *   ");
    s.push_back(" * *  ");
    s.push_back("***** ");
    k=(int)(log((double)n/3.0)/log(2.0)+0.00001);
    for(i=0;i<k;i++){
        star(1<<i);
    }
    for(i=0;i<n;i++){
        cout<<s[i]<<endl;
    }
}
