import Foundation

func solution(_ Chicken:Int) -> Int {
    var answer = 0;
    var chicken = Chicken;
    while(chicken>=10){
        var tmp=chicken/10;
        answer+=tmp;
        chicken%=10;
        chicken+=tmp;
    }
    return answer;
    return 0
}