# [Diamond III] Etched Emerald Orbs - 26309 

[문제 링크](https://www.acmicpc.net/problem/26309) 

### 성능 요약

메모리: 2032 KB, 시간: 444 ms

### 분류

백트래킹, 수학, 정수론, 폴라드 로

### 제출 일자

2024년 6월 29일 22:24:44

### 문제 설명

<p>An archaeologist team found a tomb of the ancient tribe and discovered $2^{125}$ emerald orbs inside the tomb. The ancient tribe etched a numbers on each emerald orb. The archeologists spent two decades realizing that the ancient tribe etched each emerald orb with a unique number. Moreover, the numbers are from $1$ to $2^{125}$ in the ancient language.</p>

<p>Eddy, the only mathematician in the archaeologist team, recently figured out the relation between the number $k$ and the emerald orb numbered $k$. The weight of the emerald orb numbered $k$ is exactly $\frac{1}{k}$ grams. Since the number on each emerald orb is distinct from the number on any other emerald orb, there are no two emerald orbs having the same weight.</p>

<p>Eddy proposes a hypothesis: the ancient tribe used these emerald orbs to represent weight less than $1$ gram. It is trivial that the emerald orb numbered $k$ can represent $\frac{1}{k}$ gram. Then, Eddy tries to represent $\frac{2}{k}$ grams for $3 ≤ k ≤ 4 × 10^{18}$ with two emerald orbs. He successfully finds that the emerald orbs numbered $2$ and $6$ can represent $\frac{2}{3} = \frac{1}{2} + \frac{1}{6}$ grams. Similarly, the emerald orbs numbered $3$ and $15$ can represent $\frac{2}{5} = \frac{1}{3} + \frac{1}{15}$ grams.</p>

<p>Can you write a program to help Eddy to check whether two emerald orbs can represent $\frac{2}{k}$ grams for a given integer $k$? If there are multiple combinations of two emerald orbs representing $\frac{2}{k}$ grams, output the combination minimizing the sum of the numbers etched on them. If there is no such combination, output $-1$.</p>

### 입력 

 <p>The input contains only one positive integer $k$.</p>

### 출력 

 <p>If there is no solution, output $-1$. Otherwise, output two distinct integers $x$ and $y$ separated by a blank where $\frac{2}{k} = \frac{1}{x} + \frac{1}{y}$ and $1 ≤ x < y ≤ 2^{125}$. If there are multiple solutions, output the solution minimizing $x + y$.</p>

