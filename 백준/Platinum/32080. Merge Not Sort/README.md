# [Platinum III] Merge Not Sort - 32080 

[문제 링크](https://www.acmicpc.net/problem/32080) 

### 성능 요약

메모리: 2296 KB, 시간: 8 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>You are currently researching the Merge Sort algorithm. Merge Sort is a sorting algorithm that is based on the principle of Divide and Conquer. It works by dividing an array into two subarrays of equal length, sorting each subarrays, then merging the sorted subarrays back together to form the final sorted array.</p>

<p>You are particularly interested in the merging routine. Common merge implementation will combine two subarrays by iteratively comparing their first elements, and move the smaller one to a new merged array. More precisely, the merge algorithm can be presented by the following pseudocode.</p>

<pre>Merge(A[1..N], B[1..N]):
    C = []
    i = 1
    j = 1
    while i ≤ N AND j ≤ N:
        if A[i] < B[j]:
            append A[i] to C
            i = i + 1
        else:
            append B[j] to C
            j = j + 1
    while i ≤ N:
        append A[i] to C
        i = i + 1
    while j ≤ N:
        append B[j] to C
        j = j + 1
    return C
</pre>

<p>During your research, you are keen to understand the behaviour of the merge algorithm when arrays $A$ and $B$ are not necessarily sorted. For example, if $A = [3, 1, 6]$ and $B = [4, 5, 2]$, then $\text{Merge}(A, B) = [3, 1, 4, 5, 2, 6]$.</p>

<p>To further increase the understanding of the merge algorithm, you decided to work on the following problem. You are given an array $C$ of length $2 \cdot N$ such that it is a permutation of $1$ to $2 \cdot N$. Construct any two arrays $A$ and $B$ of the same length $N$, such that $\text{Merge}(A, B) = C$, or determine if it is impossible to do so.</p>

### 입력 

 <p>The first line consists of an integer $N$ ($1 ≤ N ≤ 1000$).</p>

<p>The following line consists of $2 \cdot N$ integers $C_i$. The array $C$ is a permutation of $1$ to $2 \cdot N$.</p>

### 출력 

 <p>If it is impossible to construct two arrays $A$ and $B$ of length $N$ such that $\text{Merge}(A, B) = C$, then output <code>-1</code>.</p>

<p>Otherwise, output the arrays $A$ and $B$ in two lines. The first line consists of $N$ integers $A_i$. The second line consists of $N$ integers $B_i$. If there are several possible answers, output any of them.</p>

