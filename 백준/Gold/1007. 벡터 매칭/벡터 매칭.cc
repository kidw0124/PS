#include<bits/stdc++.h>
using namespace std;

int n;

struct point{
    int x;
    int y;
    int pm=1;
};

int main(){
    int t;
    int i,j;
    cin>>t;
    struct point data[21];
    for(j=0;j<t;j++){
        double len=999999;
        cin>>n;
        memset(data,0,sizeof(data));
        for(i=0;i<n;i++){
            cin>>data[i].x>>data[i].y;
        }
        int p=1<<n;
        for(i=(1<<(n/2))-1;i<p;i++){
            int cnt=0;

            long long sx=0,sy=0;
            for(int k=0;k<n;k++){
                if((i>>k)&1)data[k].pm=-1,cnt++;
                else data[k].pm=1;
                sx+=data[k].pm*data[k].x;
                sy+=data[k].pm*data[k].y;
            }
            //cout<<cnt<<' '<<len<<' '<<sx<<' '<<sy<<endl;
            if(len*len>sx*sx+sy*sy&&cnt==n/2)len=sqrt(sx*sx+sy*sy);
        }
        cout<<setprecision(20)<<len<<endl;
    }
}
