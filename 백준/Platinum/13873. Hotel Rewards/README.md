# [Platinum V] Hotel Rewards - 13873 

[문제 링크](https://www.acmicpc.net/problem/13873) 

### 성능 요약

메모리: 3700 KB, 시간: 12 ms

### 분류

자료 구조, 그리디 알고리즘, 우선순위 큐

### 제출 일자

2024년 9월 16일 23:19:57

### 문제 설명

<p>You are planning to spend your holidays touring Europe, staying each night in a different city for N consecutive nights. You have already chosen the hotel you want to stay in for each city, so you know the price P<sub>i</sub> of the room you’ll be staying at during the i-th night of your holidays, for i = 1, . . . , N.</p>

<p>You will book your accommodation through a website that has a very convenient rewards program, which works as follows. After staying for a night in a hotel you booked through this website you are awarded one point, and at any time you can exchange K of these points in your account for a free night in any hotel (which will however not give you another point).</p>

<p>For example, consider the case with N = 6 and K = 2 where the prices for the rooms are P<sub>1</sub> = 10, P<sub>2</sub> = 3, P<sub>3</sub> = 12, P<sub>4</sub> = 15, P<sub>5</sub> = 12 and P<sub>6</sub> = 18. After paying for the first four nights you would have four points in your account, which you could exchange to stay for free the remaining two nights, paying a total of P<sub>1</sub> + P<sub>2</sub> + P<sub>3</sub> + P<sub>4</sub> = 40 for your accommodation. However, if after the first three nights you use two of the three points you earned to stay the fourth night for free, then you can pay for the fifth night and use the final two points to get the sixth one for free. In this case, the total cost of your accommodation is P<sub>1</sub> + P<sub>2</sub> + P<sub>3</sub> + P<sub>5</sub> = 37, so this option is actually more convenient.</p>

<p>You want to make a program to find out what the minimum possible cost for your holidays’ accommodation is. You can safely assume that all hotels you want to stay always will have a room available for you, and that the order of the cities you are going to visit cannot be altered.</p>

### 입력 

 <p>The first line of input contains two integers N and K, representing the total number of nights your holidays will last, and the number of points you need in order to get a free night (1 ≤ N, K ≤ 10<sup>5</sup> ). The second line contains N integers P<sub>1</sub>, P<sub>2</sub>, . . . , P<sub>N</sub> , representing the price of the rooms you will be staying at during your holidays (1 ≤ P<sub>i</sub> ≤ 10<sup>4</sup> for i = 1, 2, . . . , N).</p>

### 출력 

 <p>Output a line with one integer representing the minimum cost of your accommodation for all of your holidays.</p>

