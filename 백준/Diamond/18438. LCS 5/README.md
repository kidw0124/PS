# [Diamond I] LCS 5 - 18438 

[문제 링크](https://www.acmicpc.net/problem/18438) 

### 성능 요약

메모리: 2300 KB, 시간: 300 ms

### 분류

분할 정복(divide_and_conquer), 다이나믹 프로그래밍(dp), 히르쉬버그(hirschberg)

### 문제 설명

<p>LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.</p>

<p>예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.</p>

### 입력 

 <p>첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 7000글자로 이루어져 있다.</p>

### 출력 

 <p>첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.</p>

<p>LCS가 여러 가지인 경우에는 아무거나 출력한다.</p>

