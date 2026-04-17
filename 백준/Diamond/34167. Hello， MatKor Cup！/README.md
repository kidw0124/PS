# [Diamond IV] Hello, MatKor Cup! - 34167 

[문제 링크](https://www.acmicpc.net/problem/34167) 

### 성능 요약

메모리: 13676 KB, 시간: 136 ms

### 분류

수학, 애드 혹, 정수론, 해 구성하기, 재귀, 유클리드 호제법, 선형대수학, 역추적, 가우스 소거법

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p><strong>이 문제는 인터랙티브 문제입니다.</strong></p>

<p>MatKor Cup은 $N$문제로 이루어진 점수대회이다. 이번 대회에는 참가자로 참가하기로 한 하늘이는 문제의 배점이 궁금해 동우에게 물어보기로 했다.</p>

<p>그러나 동우는 형평성에 어긋난다며, 대신 $K$개의 문제 인덱스를 물어보면 그 문제들의 점수의 합을 알려주기로 했다. 하늘이는 문제별로 점수를 모두 알아내는 것은 포기하고 총점(문제별 점수의 합)을 알아내고자 한다. $i(1\le i\le N)$번째 문제의 배점을 $S_i(0\le S_i\le 10^6)$라고 하자.</p>

<p>하늘이는 다음과 같이 출력하여 질문할 수 있다. 이를 <strong>질문 쿼리</strong>라고 하자.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>? </code></span>$a_1$ $a_2$ $\cdots$ $a_K$ : 모든 $a_i$는 서로 달라야 하며, $\sum_{i=1}^{K}S_{a_i}$를 물어본다.</li>
</ul>

<p>하늘이가 총점을 $s$라고 생각한다면, 다음과 같이 출력할 수 있다. 이를 <strong>정답 쿼리</strong>라고 하자.</p>

<ul>
	<li><span style="color:#e74c3c;"><code>! </code></span>$s$</li>
</ul>

<p>최소 질문 횟수로 답을 구해보자.</p>

### 입력 

 <p>컴퓨터는 동우, 유저는 하늘이가 되어 이 문제를 해결하면 된다.</p>

<p>컴퓨터가 첫 번째 줄에 정수 $N(1\le N\le 1\, 000)$과 $K(1\le K\le N)$을 입력으로 준다.</p>

<p>유저는 이후 <strong>질문 쿼리</strong>를 최대 $1\, 000$번, 모든 질문이 끝난 후 단 $1$번 <strong>정답 쿼리</strong>를 출력할 수 있다. 각 줄의 마지막에는 줄 바꿈을 출력해야 하며, 출력 이후 flush를 해야 한다.</p>

<p>컴퓨터는 각 쿼리에 대해 다음 행동을 한다.</p>

<ul>
	<li><strong>질문 쿼리</strong>가 주어진 경우, $\sum_{i=1}^{K}S_{a_i}$를 입력으로 준다.</li>
	<li><strong>정답 쿼리</strong>가 주어진 경우, $s$가 맞았는 지 검사한 후 추가적인 입력을 주지 않고 프로그램을 종료한다.</li>
</ul>

<p>주어진 $N,K$에 대해 어떠한 경우에도 반드시 $s$를 알 수 있는 최소 <strong>질문 쿼리</strong>의 수를 $Q$라고 할 때, $Q$번 이하의 <strong>질문 쿼리</strong> 이후 <strong>정답 쿼리</strong>를 통해 $s$를 맞추었다면 정답으로 판단한다. 주어진 조건 내에서 $Q\le 1\, 000$임은 증명할 수 있다.</p>

<p>다음과 같은 경우 <strong class="result-wa">틀렸습니다</strong>를 띄운다.</p>

<ul>
	<li>$Q+1$번 이상 <strong>질문 쿼리</strong>를 출력한 경우

	<ul>
		<li>만약 $1\, 000$번 이하로 <strong>질문 쿼리</strong>를 출력한 경우, 모든 쿼리를 처리한 후 <strong class="result-wa">틀렸습니다</strong>를 띄운다.</li>
		<li>만약 $1\, 000$번 초과로 <strong>질문 쿼리</strong>를 출력한 경우, $1\, 001$번째 질문이 들어온 후 <strong class="result-wa">틀렸습니다</strong>를 띄운다.</li>
	</ul>
	</li>
	<li><strong>정답 쿼리</strong>를 통해 출력한 답이 정답이 아닌 경우</li>
</ul>

<p>단, 다음과 같이 유저가 비정상적인 출력으로 질문할 경우, 잘못된 입력을 주거나, <strong class="result-wa">틀렸습니다</strong> 혹은 <strong class="result-tle">시간초과</strong> 등 의도되지 않은 결과가 나올 수 있다.</p>

<ul>
	<li><strong>질문 쿼리</strong>의 경우

	<ul>
		<li><span style="color:#e74c3c;"><code>?</code></span>를 줄의 처음에 출력하지 않은 경우</li>
		<li>$i\ne j\land a_i=a_j$가 존재하는 경우</li>
		<li>$1\le a_i\le N$의 정수를 만족하지 않는 경우</li>
		<li>한 줄에 $K$개의 인덱스를 출력하지 않은 경우</li>
	</ul>
	</li>
	<li><strong>정답 쿼리</strong>의 경우
	<ul>
		<li><span style="color:#e74c3c;"><code>!</code></span>를 줄의 처음에 출력하지 않은 경우</li>
		<li>$0\le s\le 10^9$의 정수를 만족하지 않는 경우</li>
		<li>한 개보다 적거나 많은 정수를 출력한 경우</li>
	</ul>
	</li>
	<li>기타 문제 조건에 맞지 않은 출력을 한 경우</li>
	<li>정답 쿼리 출력 이후 추가적인 출력이 있는 경우</li>
	<li>정답 쿼리를 출력하지 않은 경우</li>
	<li>한 줄을 출력한 후 flush를 하지 않은 경우</li>
</ul>

### 출력 

 Empty

