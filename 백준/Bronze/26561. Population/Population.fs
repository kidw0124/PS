open System
let t=int(Console.ReadLine())
for i=1 to t do
    let a,b = let p = Console.ReadLine().Split(' ') |> Array.map int in p.[0],p.[1]
    printf "%d\n"(a+b/4-b/7)
