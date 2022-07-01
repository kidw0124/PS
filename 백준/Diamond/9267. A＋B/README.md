# [Diamond V] A+B - 9267 

[문제 링크](https://www.acmicpc.net/problem/9267) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

확장 유클리드 호제법(extended_euclidean), 수학(math), 정수론(number_theory)

### 문제 설명

<p>두 메모리 셀을 가지고 있는 컴퓨터가 있다. 각 메모리 셀은 <code>a</code>와 <code>b</code>로 나타낸다. 두 셀에는 정수를 저장할 수 있다. 컴퓨터가 수행할 수 있는 명령은 두 종류로 <code>a+=b</code>와 <code>b+=a</code> 이다. 첫 번째 명령은 <code>a</code>에 저장된 값을 <code>b</code>에 저장된 값만큼 증가시키는 것이고, 두 번째 명령은 <code>b</code>에 저장된 값을 <code>a</code>에 저장된 값만큼 증가시키는 것이다.</p>

<p>컴퓨터의 프로그램은 위의 두 명령으로 이루어져 있다. 프로그램의 명령은 순서대로 수행된다.</p>

<p><code>a</code>와 <code>b</code>에 저장되어 있는 값과 <code>S</code>가 주어졌을 때, 두 연산으로 <code>S</code>를 만드는 프로그램을 만들 수 있는지 없는지를 구하는 프로그램을 작성하시오. <code>S</code>는 두 셀중 하나에 저장되어 있으면 된다.</p>

### 입력 

 <p>첫째 줄에 <code>a</code>, <code>b</code>, <code>S</code>가 주어진다. (0 ≤ <code>a</code>, <code>b</code>, <code>S</code> ≤ 10<sup>18</sup>)</p>

### 출력 

 <p>두 셀 중 하나에 <code>S</code>가 저장되는 프로그램을 만들 수 있으면 YES를, 없으면 NO를 출력한다.</p>

