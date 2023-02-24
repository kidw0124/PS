object Solution {
    def solution(Chicken: Int): Int = {
        var chicken=Chicken :Int
        var answer=0:Int;
        while(chicken>=10){
            var tmp=chicken/10:Int
            answer+=tmp;
            chicken%=10;
            chicken+=tmp;
        }
        return answer;
    }
}