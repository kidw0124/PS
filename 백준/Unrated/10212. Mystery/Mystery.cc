#include<bits/stdc++.h>
using namespace std;
int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0,1);
    if(distribution(gen)){
        cout<<"Yonsei";
    }
    else{
        cout<<"Korea";
    }
}