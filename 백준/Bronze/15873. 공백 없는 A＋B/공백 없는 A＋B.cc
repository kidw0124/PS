#include<ios>
main(){
    int a,b,n;
    scanf("%d",&n);
    if(n==1010)a=b=10;
    else if(n>=110)a=n/(b=10)/10;
    else if(n>100)b=n%(a=10);
    else{a=n/10,b=n%10;}
    printf("%d",a+b);
}
