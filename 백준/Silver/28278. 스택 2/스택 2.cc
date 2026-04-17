#include<stdio.h>
#include<memory.h>
#include<iostream>
typedef long long ll;

class stack_int
{
public:
    stack_int(){
        memset(this->data,0,sizeof(this->data));
        this->end=0;
    }
    ~stack_int(){}
    bool empty(){
        return this->end==0;
    }
    bool full(){
        return this->end==this->MAX_SIZE;
    }
    size_t size(){
        return this->end;
    }
    int top(){
        if(this->empty()){
            return -1;
        }
        else{
            return data[this->size()-1];
        }
    }
    void push(int data){
        if(!this->full()){
            this->data[this->end++]=data;
        }
    }
    void pop(){
        if(!this->empty()){
            this->data[--this->end]=0;
        }
    }
protected:
private:
    const static size_t MAX_SIZE=1000005;
    int data[MAX_SIZE];
    int end;
};

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    stack_int stk;
    int n;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::string x;
        std::cin>>x;
        if(x=="1"){
            int m;
            std::cin>>m;
            stk.push(m);
        }
        else if(x=="2"){
            std::cout<<stk.top()<<'\n';
            stk.pop();
        }
        else if(x=="3"){
            std::cout<<stk.size()<<'\n';
        }
        else if(x=="4"){
            std::cout<<stk.empty()<<'\n';
        }
        else if(x=="5"){
            std::cout<<stk.top()<<'\n';
        }
    }
    return 0;
}
