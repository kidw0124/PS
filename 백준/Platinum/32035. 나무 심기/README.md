# [Platinum III] 나무 심기 - 32035 

[문제 링크](https://www.acmicpc.net/problem/32035) 

### 성능 요약

메모리: 2152 KB, 시간: 0 ms

### 분류

애드 혹, 많은 조건 분기, 해 구성하기

### 제출 일자

2024년 7월 15일 06:37:54

### 문제 설명

<p>승연이는 나무를 심으려 한다. 이를 위해 무한 격자 위에서 몇 개의 칸을 골라 나무 씨앗을 뿌릴 것이다. 나무 씨앗에는 신비한 힘이 있어, 주변 나무 씨앗의 영향을 받아 사과나무 혹은 복숭아나무 중 하나로 자라난다.</p>

<p>씨앗이 자라 어떤 나무가 되는지는 다음 규칙을 따른다. 변을 맞댄 두 칸에 모두 씨앗이 있다면 그 두 씨앗을 서로 <strong>인접</strong>하다고 한다. <strong>인접</strong>한 씨앗의 수가 짝수인 씨앗은 사과나무가 된다. 반면 <strong>인접</strong>한 씨앗의 수가 홀수인 씨앗은 복숭아나무가 된다.</p>

<p style="text-align:center;"><img alt="변을 맞댄 두 칸에 들어있는 씨앗은 인접함" src="https://upload.acmicpc.net/71dcc6ca-c7ad-4ee7-9c1b-817ea63b2c2a/-/preview/" style="max-width: 100%; width: 200px;"></p>

<p>승연이가 위와 같이 5개의 씨앗을 심었다고 하자. 서로 <strong>인접</strong>한 씨앗은 파란색 화살표와 같이 나타난다. 가운데 씨앗은 3개의 씨앗과 <strong>인접</strong>해 있으므로 복숭아나무가 된다.</p>

<p style="text-align:center;"><img alt="세 개의 사과나무와 두 개의 복숭아나무가 열린 모습" src="https://upload.acmicpc.net/f46b1c54-1e72-4477-bddf-e4dcf9eb5ab8/-/preview/" style="max-width: 100%; width: 200px;"></p>

<p>결과적으로 위와 같이 3개의 사과나무와 2개의 복숭아나무가 열리게 된다.</p>

<p>씨앗을 심을 때는 씨앗들이 격자에서 모두 연결되어 있어야 한다. 즉 임의의 두 씨앗에 대해, 서로 <strong>인접</strong>한 씨앗만 거쳐서 두 씨앗 사이를 이동할 수 있어야 한다. 예를 들어 아래와 같은 배치는 불가능하다.</p>

<p style="text-align:center;"><img alt="모든 씨앗이 연결되어 있지 않아 불가능한 배치의 예시" src="https://upload.acmicpc.net/b9973e57-1dc6-43a4-b5bc-cfe11287ae50/-/preview/" style="max-width: 100%; width: 200px;"></p>

<p>승연이는 사과나무 <em>A</em>개, 복숭아나무 <em>B</em>개를 심으려 한다. 이것이 가능한지 여부와, 가능하다면 나무 배치를 출력하라.</p>

### 입력 

 <p>첫 줄에 음이 아닌 정수 <em>A</em>, <em>B</em>가 공백을 사이에 두고 주어진다. (<em>A</em> ≥ 0; <em>B</em> ≥ 0; 1 ≤ <em>A</em> + <em>B</em> ≤ 200)</p>

### 출력 

 <p>첫 줄에, 배치가 가능하다면 <span style="color:#e74c3c;"><code>YES</code></span>를, 아니면 <span style="color:#e74c3c;"><code>NO</code></span>를 출력한다.</p>

<p>배치가 가능할 경우, 둘째 줄에 행과 열의 수 <em>R</em>와 <em>C</em>를 공백을 사이에 두고 출력한다. (1 ≤ <em>R</em>, <em>C</em> ≤ 200)</p>

<p>셋째 줄부터 <em>R</em>개의 줄에 걸쳐, 각 줄에 <em>C</em>개의 문자를 공백 없이 출력한다. 각 문자는 <span style="color:#e74c3c;"><code>O</code></span> 혹은 <span style="color:#e74c3c;"><code>.</code></span> 중 하나이며, 씨앗이 있는 자리에 <span style="color:#e74c3c;"><code>O</code></span>, 없는 자리에 <span style="color:#e74c3c;"><code>.</code></span>를 출력한다.</p>

