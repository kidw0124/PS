def solution(n, times):
    answer = 0
    l,r=1,1000000000000000000
    while l<r:
        mid=(l+r)//2;
        now=0;
        for k in times:
            now+=mid//k
        if now<n:
            l=mid+1;
        else:
            r=mid;
    return l