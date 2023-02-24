function solution(chicken) {
    var answer = 0;
    while(chicken>=10){
        var tmp=Math.floor(chicken/10,0);
        answer+=tmp;
        chicken%=10;
        chicken+=tmp;
    }
    return answer;
}