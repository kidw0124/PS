# [Diamond IV] 최대공약수 행렬식 - 3752 

[문제 링크](https://www.acmicpc.net/problem/3752) 

### 성능 요약

메모리: 2036 KB, 시간: 92 ms

### 분류

수학, 정수론, 선형대수학, 오일러 피 함수

### 제출 일자

2026년 04월 18일 01:08:27

### 문제 설명

<p>집합 S = {x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>n</sub>}가 인수에 대해서 닫혀있으려면, 모든 x<sub>i</sub> ∈ S에 대해서, x<sub>i</sub>의 모든 약수 d는 d ∈ S를 만족해야 한다.</p>

<p>인수에 대해 닫힌 집합 S를 최대공약수 행렬 (S) = (s<sub>ij</sub>), s<sub>ij</sub> = GCD(x<sub>i</sub>,x<sub>j</sub>)로 만든 뒤, 이 행렬의 행렬식 (determinant)를 구하는 프로그램을 작성하시오.</p>

<p>\(D_n = \begin{vmatrix}  \text{gcd}\left(x_1,x_1\right) & \text{gcd}\left(x_1,x_2\right) & \text{gcd}\left(x_1,x_3\right) & \dots & \text{gcd}\left(x_1,x_n\right) \\ \text{gcd}\left(x_2,x_1\right) & \text{gcd}\left(x_2,x_2\right) & \text{gcd}\left(x_2,x_3\right) & \dots & \text{gcd}\left(x_2,x_n\right) \\ \text{gcd}\left(x_3,x_1\right) & \text{gcd}\left(x_3,x_2\right) & \text{gcd}\left(x_3,x_3\right) & \dots & \text{gcd}\left(x_3,x_n\right) \\ \dots & \dots & \dots & \dots & \dots \\ \text{gcd}\left(x_n,x_1\right) & \text{gcd}\left(x_n,x_2\right) & \text{gcd}\left(x_n,x_3\right) & \dots & \text{gcd}\left(x_n,x_n\right) \\ \end{vmatrix}\)</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 집합 S의 원소 개수 n(0 < n < 1,000)이 주어진다. </p>

<p>다음 줄에는 집합의 원소 x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>n</sub>이 주어진다. (0 < x<sub>i</sub> < 2*10<sup>9</sup>, x<sub>i</sub>는 정수)</p>

### 출력 

 <p>각 테스트 케이스에 대해서 입력으로 주어진 집합 S의 최대공약수 행렬식을 1,000,000,007로 나눈 나머지를 출력한다.</p>

