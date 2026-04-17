#include<stdio.h>
#include<memory.h>
#include<iostream>
#include<iomanip>
typedef double type;

class stack_type
{
public:
    stack_type(){
        memset(this->data,0,sizeof(this->data));
        this->end=0;
    }
    ~stack_type(){}
    bool empty(){
        return this->end==0;
    }
    bool full(){
        return this->end==this->MAX_SIZE;
    }
    size_t size(){
        return this->end;
    }
    type top(){
        if(this->empty()){
            return -1;
        }
        else{
            return data[this->size()-1];
        }
    }
    void push(type data){
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
    const static size_t MAX_SIZE=10005;
    type data[MAX_SIZE];
    int end;
};

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    stack_type stk;
    std::string str;
    int n;
    int arr[30];
    std::cin>>n>>str;
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }

    for(int i=0;i<str.size();i++){
        if('A'<=str[i]&&str[i]<='Z'){
            stk.push(arr[str[i]-'A']);
        }
        else if(str[i]=='+'){
            double x=stk.top();
            stk.pop();
            x+=stk.top();
            stk.pop();
            stk.push(x);
        }
        else if(str[i]=='-'){
            double x=stk.top();
            stk.pop();
            x=-x;
            x+=stk.top();
            stk.pop();
            stk.push(x);
        }
        else if(str[i]=='*'){
            double x=stk.top();
            stk.pop();
            x*=stk.top();
            stk.pop();
            stk.push(x);
        }
        else if(str[i]=='/'){
            double x=stk.top();
            stk.pop();
            x=1/x;
            x*=stk.top();
            stk.pop();
            stk.push(x);
        }
    }
    std::cout<<std::fixed<<std::setprecision(2)<<stk.top();

    return 0;
}
