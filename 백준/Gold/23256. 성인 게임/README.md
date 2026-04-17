# [Gold IV] 성인 게임 - 23256 

[문제 링크](https://www.acmicpc.net/problem/23256) 

### 성능 요약

메모리: 17652 KB, 시간: 16 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>채완이가 좋아하는 성인 게임에는 칼 아이템이 있다.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 338px; height: 300px;"></p>

<p>칼의 칼날은 $2\times 2$ 크기의 정사각형 $N$개가 한 칸씩 맞물려 연결되어 있는 형태이다.</p>

<p>아래는 $N = 6$일 때의 칼날을 나타낸 그림이다.</p>

<p style="text-align: center;"><img alt="" src="" style="height: 197px; width: 600px;"></p>

<p>칼날은 $1\times 1$, $2\times 1$ 크기의 광석을 겹치지 않고 빈 칸이 없도록 적절히 붙여 만들 수 있다.</p>

<p>$N$이 주어질 때 만들 수 있는 서로 다른 칼날의 개수를 구하는 프로그램을 작성하시오.</p>

<p>광석은 어떤 경우에도 모자라지 않을 만큼 충분히 존재한다.</p>

<p>$2 \times 1$, $1 \times 1$ 크기의 광석은 각각 다음과 같고 회전시킬 수 있다.</p>

<p style="text-align: center;"><img alt="" src="" style="height: 53px; width: 100px;"><img alt="" src="" style="height: 53px; width: 53px;"></p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 수 $T$가 주어진다.</p>

<p>이후 $T$개의 줄에 걸쳐 $N$이 주어진다.</p>

### 출력 

 <p>각 테스트 케이스마다 만들 수 있는 서로 다른 칼날의 개수를 $1\,000\,000\,007$로 나눈 나머지를 출력하라.</p>

