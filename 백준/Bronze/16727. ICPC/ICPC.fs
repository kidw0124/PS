open System
let a,b = let p = Console.ReadLine().Split(' ') |> Array.map int in p.[0],p.[1]
let c,d = let p = Console.ReadLine().Split(' ') |> Array.map int in p.[0],p.[1]
if a+d>b+c then printfn "Persepolis"
elif a+d<b+c then printfn "Esteghlal"
elif d>b then printfn "Persepolis"
elif d<b then printfn "Esteghlal"
else printfn "Penalty"