import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        Arrays.sort(participant);
        Arrays.sort(completion);
        completion=Arrays.copyOf(completion,completion.length+1);
        completion[completion.length-1]="A";
        for(int i=0;i<participant.length;i++){
            if(!participant[i].equals(completion[i])){
                return participant[i];
            }
        }
        return answer;
    }
}