function solution(n, times) {
    let l=1,r=1000000000000000000;
    while(l<r){
        let mid=Math.floor((l+r)/2);
        let now=0;
        times.forEach(a=>now+=Math.floor(mid/a))
        if(now<n){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    return l;
}