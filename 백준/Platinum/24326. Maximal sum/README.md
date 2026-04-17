# [Platinum V] Maximal sum - 24326 

[문제 링크](https://www.acmicpc.net/problem/24326) 

### 성능 요약

메모리: 9684 KB, 시간: 172 ms

### 분류

수학, 정렬, 정수론, 소수 판정, 런타임 전의 전처리, 에라토스테네스의 체

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>A group of n bunnies found a garden with n carrots, arranged in a row. Both the bunnies and the carrots are numbered with integers from 1 to n. The bunnies have made preliminary evaluation for the sweetness of the carrots, which are expressed with the integers a<sub>1</sub>, ..., a<sub>n</sub> (some carrots may be spoiled and can have negative number for sweetness). The soil under only one carrot p is fertilized and this changes the sweetness of this carrot by an integer s. More precisely, the real sweetness of carrot p is a<sub>p</sub> + s.</p>

<p>Unfortunately, p and s are unknown to rabbits. However, they have massumptions about the pair of values (p, s).</p>

<p>Bunny number k makes jumps of length k, i.e. collects the carrots in positions that are multiples of k.</p>

<p>For each assumption j, they look for the maximum amount t<sub>j</sub> of the total real sweetness of the carrots that can be collected by a bunny. Help them by writing program maxs that finds the sum of the values of t<sub>j</sub> for all assumptions.</p>

### 입력 

 <p>From the first line of the standard input, your program reads an integer n - the number of carrots (and bunnies). From the next line read n integers a<sub>1</sub>, ..., a<sub>n</sub> - the preliminary evaluation of the sweetness of the carrots. From the next line read an integer m-the number of assumptions. From each of the next mlines, read two integers p and s – carrot's index and its’ sweetness change for the corresponding assumption.</p>

### 출력 

 <p>On one line of the standard output, print a number equal to t<sub>1</sub> + ... + t<sub>m</sub>, where t<sub>j</sub> is the maximum sum of carrots' sweetness under the j-th assumption.</p>

