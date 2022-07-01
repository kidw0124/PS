def solution(participant, completion):
    participant.sort();
    completion.sort();
    completion.append("A")
    for k in range(participant.__len__()):
        if participant[k]!=completion[k]:
            return participant[k]
    return answer