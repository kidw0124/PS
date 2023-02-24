#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int chicken) {
    int answer = 0;
    while(chicken>=10){
        int tmp=chicken/10;
        answer+=tmp;
        chicken%=10;
        chicken+=tmp;
    }
    return answer;
}