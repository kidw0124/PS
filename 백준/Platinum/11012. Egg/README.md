# [Platinum II] Egg - 11012 

[문제 링크](https://www.acmicpc.net/problem/11012) 

### 성능 요약

메모리: 60200 KB, 시간: 500 ms

### 분류

자료 구조, 세그먼트 트리, 스위핑, 오프라인 쿼리, 퍼시스턴트 세그먼트 트리

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>You are a president deeply loved by many folks in your country. Every time you go on a parade (which is your main job, what else should a president do), the folks would throw eggs at you — because you love eggs! The folks passionately send their eggs to you, and you always can catch the eggs. In fact, egg-catching is exactly what makes you look forward to the parade every day! A folk would throw an egg at you for each time your parade comes to his home. You are given n coordinates on a 2D-map, these are where the folks that will throw an egg at you each time they see you on a parade. Note that the coordinates may repeat, since several folks may live together. There are in total m days left in your term and the area to parade each day are set. A parade always takes place in an axis-parallel rectangle area, as stated clearly in the constitution and as the president you have no choice but to follow it. You are given m 2D-ranges [ℓ, r]×[b, t] describing the parades.</p>

### 입력 

 <p>Input begins with an integer T (1 ≤ T ≤ 20) indicating the number of test cases. The first line of each test case contains two integers n (0 < n ≤ 10000) and m (0 ≤ m ≤ 50000) separated by a blank where n is the number of folks throwing eggs and m is the number of days left in your term. Each of the following n lines contains two integers x and y (0 ≤ x, y ≤ 10<sup>5</sup>) indicating that there is a folk’s home located at (x, y). Then m more lines follow. Each of them contains four integer ℓ, r, b, t (0 ≤ ℓ ≤ r ≤ 10<sup>5</sup>, 0 ≤ b ≤ t ≤ 10<sup>5</sup>) separated by blanks. [ℓ, r] × [b, t] corresponds to a parade area.</p>

### 출력 

 <p>For each test case, output the total sum of eggs you receive on one line.</p>

