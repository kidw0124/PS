func solution(chicken int) int {
    var answer int = 0
    for ;chicken>=10; {
        var tmp int =chicken/10
        answer+=tmp
        chicken%=10
        chicken+=tmp
    }
    return answer
}