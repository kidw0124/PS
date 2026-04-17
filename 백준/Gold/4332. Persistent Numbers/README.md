# [Gold V] Persistent Numbers - 4332 

[문제 링크](https://www.acmicpc.net/problem/4332) 

### 성능 요약

메모리: 110404 KB, 시간: 124 ms

### 분류

수학, 그리디 알고리즘, 정수론

### 제출 일자

2026년 04월 18일 01:08:27

### 문제 설명

<p><img alt="" src="" style="float:right; height:175px; width:313px">The multiplicative persistence of a number is defined by Neil Sloane (Neil J.A. Sloane in The Persistence of a Number published in Journal of Recreational Mathematics 6, 1973, pp. 97-98., 1973) as the number of steps to reach a one-digit number when repeatedly multiplying the digits. Example:</p>

<p style="text-align: center;">679 -> 378 -> 168 -> 48 -> 32 -> 6.</p>

<p>That is, the persistence of 679 is 5. The persistence of a single digit number is 0. At the time of this writing it is known that there are numbers with the persistence of 11. It is not known whether there are numbers with the persistence of 12 but it is known that if they exists then the smallest of them would have more than 3000 digits.</p>

<p>The problem that you are to solve here is: what is the smallest number such that the first step of computing its persistence results in the given number?</p>

### 입력 

 <p>For each test case there is a single line of input containing a decimal number with up to 1000 digits. A line containing -1 follows the last test case.</p>

### 출력 

 <p>For each test case you are to output one line containing one integer number satisfying the condition stated above or a statement saying that there is no such number in the format shown below.</p>

