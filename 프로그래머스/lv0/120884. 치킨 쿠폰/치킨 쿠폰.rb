def solution(chicken)
    answer = 0
    while(chicken>=10) do
        tmp=chicken/10
        answer+=tmp
        chicken%=10
        chicken+=tmp
    end
    return answer
end