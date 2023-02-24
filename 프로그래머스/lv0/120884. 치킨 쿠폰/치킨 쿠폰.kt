class Solution {
    fun solution(Chicken: Int): Int {
        var chicken:Int = Chicken
        var answer: Int = 0
        while(chicken>=10){
            var tmp:Int=chicken/10
            answer +=tmp
            chicken%=10
            chicken+=tmp
        }
        return answer
    }
}