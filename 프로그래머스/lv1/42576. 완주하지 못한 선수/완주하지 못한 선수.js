function solution(participant, completion) {
    participant.sort();
    completion.sort();
    completion.push("A");
    participant.reverse();
    completion.reverse();
    answer='';
    participant.forEach((a,b)=>{
        if(a!=completion[b]){
            answer=a;
        }
    });
    return answer;
}