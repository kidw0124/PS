# [Bronze IV] Goodbye, Code Jam - 29738 

[문제 링크](https://www.acmicpc.net/problem/29738) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>매년 4~5월은 Google Code Jam이 열리는 기간이다. 슬프게도 Google은 2023년부터 Code Jam, Kick Start, Hash Code 등 다양한 형태로 운영해 왔던 Google Coding Competition을 종료하기로 했다. 더 이상 티셔츠를 받을 수 없다는 사실에 절망한 브실이는 Google Code Jam을 기억하는 문제를 만들기로 했다.</p>

<p>Google Code Jam은 Qualification Round, Round 1, Round 2, Round 3, World Finals의 순서로 진행된다. 30점 이상을 획득하면 다음 라운드로 진출하는 Qualification Round와 더 이상 다음 라운드가 없는 <strong>World Finals</strong>을 제외한 라운드는 다음 라운드에 진출하기 위해선 정해진 순위 안에 들어야 한다. 각각 <strong>Round 1</strong>은 상위 $4\,500$등, <strong>Round 2</strong>는 상위 $1\,000$등, <strong>Round 3</strong>은 상위 $25$등 안에 들어야 다음 라운드에 진출할 수 있다.</p>

<p>입력으로 Google Code Jam 참가자가 가장 마지막으로 참가한 라운드의 등수 $N$이 주어진다. 해당 참가자가 가장 마지막으로 참가한 라운드를 출력하라. 단 문제에서 주어지는 참가자는 Qualification Round는 모두 통과했다고 가정하므로 출력해야 할 라운드는 <strong>Round 1</strong>, <strong>Round 2</strong>, <strong>Round 3</strong>, <strong>World Finals</strong> 중 하나이다. 모든 참가자는 Google Code Jam에 참가하기만을 손꼽아 기다려 왔기 때문에 참가자가 등수 미달로 탈락하는 경우가 아닌 이상 중도 포기를 하는 경우는 없다.</p>

### 입력 

 <p>첫 번째 줄에 테스트케이스의 수 $T$가 주어진다. $(1 \le T \le 100)$</p>

<p>각 테스트케이스에 대해, 첫 번째 줄에 Google Code Jam 참가자가 가장 마지막으로 참가한 라운드의 등수 $N$이 주어진다. $(1 \le N \le 30\,000)$</p>

### 출력 

 <p>Google Code Jam은 다중 테스트케이스 문제에서 $x$번째 테스트케이스의 출력 앞에 <strong>Case #$x$: </strong>를 삽입하게 하는 전통이 있다. 브실이는 문제를 푸는 사람들이 이 규칙을 따르길 원하므로 출력형식을 다음과 같이 지정했다.</p>

<p>테스트케이스마다 <strong>Case #$x$: $y$</strong> 형식의 한 줄을 출력한다. 여기서 $x$는 $1$부터 시작하는 테스트케이스 번호이고 $y$는 해당 Google Code Jam 참가자가 가장 마지막으로 참가한 라운드에 해당하는 문자열이다.</p>

