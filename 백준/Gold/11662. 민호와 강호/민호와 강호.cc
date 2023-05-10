#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

struct point{
    long double x,y;
    long double dist(point&r){
        return sqrt((x-r.x)*(x-r.x)+(y-r.y)*(y-r.y));
    }
    void input(){
        cin>>x>>y;
    }
};

long double eps = 1e-9;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    point A, B, C, D;
    A.input();
    B.input();
    C.input();
    D.input();
    while(abs(A.dist(B))>eps){
        point MA, MB, MC, MD;
        MA.x = (A.x * 2 + B.x) / 3;
        MA.y = (A.y * 2 + B.y) / 3;
        MB.x = (A.x + B.x * 2) / 3;
        MB.y = (A.y + B.y * 2) / 3;
        MC.x = (C.x * 2 + D.x) / 3;
        MC.y = (C.y * 2 + D.y) / 3;
        MD.x = (C.x + D.x * 2) / 3;
        MD.y = (C.y + D.y * 2) / 3;
        long double da = MC.dist(MA);
        long double db = MD.dist(MB);
        // cout<<fixed<<setprecision(10)<<da<<" "<<db<<endl;

        if(da < db){
            B = MB;
            D = MD;
        }else{
            A = MA;
            C = MC;
        }
    }
    cout<<fixed<<setprecision(10)<<C.dist(A)<<endl;

    
}