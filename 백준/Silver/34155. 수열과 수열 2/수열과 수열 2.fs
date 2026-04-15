open System
let n = Console.ReadLine()|>int64
let arr = Console.ReadLine().Split(' ') |> Array.map int
let mutable ans=1L
for i=1 to int n do
  if arr.[i-1]=i then ans<-ans*(n-1L) else ans<-ans*(n-2L)
  ans<-ans%998244353L
printf "%d"(ans)
