open System
let a,b,c = let p = Console.ReadLine().Split(' ') |> Array.map int in p.[0],p.[1],p.[2]
printfn "%d" (if (a<=c && c<b) then 1 else 0)