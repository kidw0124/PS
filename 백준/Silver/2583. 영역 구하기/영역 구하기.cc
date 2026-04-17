#include<bits/stdc++.h>
using namespace std;
#define visit vvist
int n,m,k;
int arr[130][130];
stack<pair<int,int> >s;
int visit[130][130];
vector<int>pq;
 
void func(){
    int i,j;
    for(i=1;i<n+1;i++){
        for(j=1;j<m+1;j++){
            if(arr[i][j]&&!visit[i][j]){
                while(!s.empty())s.pop();
                int c=1;
                visit[i][j]=1;
                if(arr[i+1][j]&&!visit[i+1][j])s.push(make_pair(i+1,j));
                if(arr[i-1][j]&&!visit[i-1][j])s.push(make_pair(i-1,j));
                if(arr[i][j+1]&&!visit[i][j+1])s.push(make_pair(i,j+1));
                if(arr[i][j-1]&&!visit[i][j-1])s.push(make_pair(i,j-1));
                while(!s.empty()){
                    pair<int,int> pp=s.top();
                    s.pop();
                    if(visit[pp.first][pp.second])continue;
                    visit[pp.first][pp.second]=1;
                    c++;
                    if(arr[pp.first+1][pp.second]&&!visit[pp.first+1][pp.second])s.push(make_pair(pp.first+1,pp.second));
                    if(arr[pp.first-1][pp.second]&&!visit[pp.first-1][pp.second])s.push(make_pair(pp.first-1,pp.second));
                    if(arr[pp.first][pp.second+1]&&!visit[pp.first][pp.second+1])s.push(make_pair(pp.first,pp.second+1));
                    if(arr[pp.first][pp.second-1]&&!visit[pp.first][pp.second-1])s.push(make_pair(pp.first,pp.second-1));
                }
                pq.push_back(c);
            }
        }
    }
}
 
int main(){
    cin>>m>>n>>k;;
    int i,j,l;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            arr[i+1][j+1]=1;
        }
    }
    for(i=0;i<k;i++){
        int t1,t2,t3,t4;
        cin>>t1>>t2>>t3>>t4;
        for(j=t1;j<t3;j++){
            for(l=t2;l<t4;l++){
                arr[j+1][l+1]=0;
            }
        }
    }
    func();
    cout<<pq.size()<<'\n';
    sort(pq.begin(),pq.end());
    for(i=0;i<pq.size();i++){
        cout<<pq[i]<<' ';
    }
}