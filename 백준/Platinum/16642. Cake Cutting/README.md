# [Platinum II] Cake Cutting - 16642 

[문제 링크](https://www.acmicpc.net/problem/16642) 

### 성능 요약

메모리: 2252 KB, 시간: 4 ms

### 분류

미적분학, 수학, 삼분 탐색

### 제출 일자

2025년 5월 28일 06:05:21

### 문제 설명

<p>키파는 SNUCSE(Seoul National University Cake Styling Engineering)에서 2년간 열심히 수련한 끝에 <a href="https://boj.kr/14445" target="_blank">이전</a>과는 다르게 드디어 케이크를 원형으로 만들 수 있게 되었습니다! 그래서 반지름이 <em>R</em>이고 높이가 <em>h</em>인 원기둥 모양의 케이크를 만들었습니다. 그리고 윗면에 생크림을 바르려고 했습니다. 왼쪽에서 오른쪽으로 크림을 살살 바르다가...</p>

<p>힘 조절을 잘못해서 생크림이 불균일하게 발라졌습니다! 정확히는 케이크의 윗면의 지름을 왼쪽 끝부터 길이가 <em>a</em><sub>1</sub>, <em>a</em><sub>2</sub>, …, <em>a</em><sub><em>n</em></sub>인 <em>n</em>개의 부분으로 나누었을 때, [각각의 선분을 윗면에 평행이고 원래의 선분에 수직이게 움직인] 면과 케이크의 윗면의 교집합에 발라진 생크림의 높이가 <em>b</em><sub>1</sub>, <em>b</em><sub>2</sub>, …, <em>b</em><sub><em>n</em></sub>이 되었습니다.</p>

<p style="text-align: center;"><img alt="n = 4인 경우의 예시" src="https://upload.acmicpc.net/fea42bbf-8ea9-4332-88a9-db43a17d7559/-/preview/"><br>
<em>n</em> = 4인 경우의 예시. 다홍색, 노랑색, 연두색, 하늘색 부분에 칠해진 생크림의 높이가 각각 <em>b</em><sub>1</sub>, <em>b</em><sub>2</sub>, <em>b</em><sub>3</sub>, <em>b</em><sub>4</sub></p>

<p>키파는 이 케이크를 진정한 친구 한 명과 나누어 먹으려고 합니다. 생크림의 얼룩과 잘린 방향이 다른 것은 원치 않았기 때문에, 위 그림에서 점선 방향, 즉 케이크의 얼룩과 평행한 방향으로 케이크를 자르려고 합니다. 이때 키파는 케이크를 공정하게 나누어 먹지 못한 것에 대한 불만을 가지게 되는데, 이 불만은 두 조각의 빵의 부피를 <em>V</em><sub>1</sub>, <em>V</em><sub>2</sub>, 생크림의 부피를 <em>v</em><sub>1</sub>, <em>v</em><sub>2</sub>라 했을 때, (<em>V</em><sub>1</sub> - <em>V</em><sub>2</sub>)<sup>2</sup> + (<em>v</em><sub>1</sub> - <em>v</em><sub>2</sub>)<sup>2</sup>입니다.</p>

<p>키파의 불만을 최소화해 주세요.</p>

### 입력 

 <p>첫째 줄에 200보다 작거나 같은 양의 정수 <em>R</em>과 <em>h</em>가 공백을 사이에 두고 주어집니다.</p>

<p>둘째 줄에 10<sup>3</sup>보다 작거나 같은 양의 정수 <em>n</em>이 주어집니다.</p>

<p>셋째 줄에 <em>n</em>개의 양의 실수 <em>a</em><sub>1</sub>, <em>a</em><sub>2</sub>, …, <em>a</em><sub><em>n</em></sub>이 공백을 사이에 두고 주어집니다. 주어지는 실수는 소수점 아래 최대 세 자리를 넘지 않으며, <em>a</em><sub>1</sub> + <em>a</em><sub>2</sub> + … + <em>a<sub>n</sub></em> = 2<em>R</em>임이 보장됩니다.</p>

<p>넷째 줄에 <em>n</em>개의 음이 아닌 실수 <em>b</em><sub>1</sub>, <em>b</em><sub>2</sub>, …, <em>b</em><sub><em>n</em></sub>이 공백을 사이에 두고 주어집니다. 주어지는 실수는 0.5보다 크거나 같고, 1보다 작거나 같으며, 소수점 아래 최대 세 자리를 넘지 않습니다.</p>

### 출력 

 <p>첫째 줄에 최소화된 키파의 불만을 출력합니다. 참값과 10<sup>-6</sup> 이하의 절대/상대 오차는 정답으로 처리됩니다.</p>

