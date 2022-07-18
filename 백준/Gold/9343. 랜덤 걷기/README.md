# [Gold I] 랜덤 걷기 - 9343 

[문제 링크](https://www.acmicpc.net/problem/9343) 

### 성능 요약

메모리: 25460 KB, 시간: 44 ms

### 분류

조합론(combinatorics), 페르마의 소정리(flt), 수학(math), 모듈로 곱셈 역원(modular_multiplicative_inverse), 정수론(number_theory)

### 문제 설명

<p>선영이는 매우 긴 직선의 원점에 서 있다. 선영이는 왼쪽이나 오른쪽으로 한 번에 한 칸씩 이동할 수 있다.</p>

<p>2N번 움직여서 시작한 위치로 돌아오는 랜덤 걷기 문제의 경로의 수는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-mo class="mjx-s3"><mjx-c class="mjx-c28 TEX-S3"></mjx-c></mjx-mo><mjx-mtable style="min-width: 1.388em;"><mjx-table><mjx-itable><mjx-mtr><mjx-mtd style="padding-bottom: 0.2em;"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-tstrut></mjx-tstrut></mjx-mtd></mjx-mtr><mjx-mtr><mjx-mtd style="padding-top: 0.2em;"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-tstrut></mjx-tstrut></mjx-mtd></mjx-mtr></mjx-itable></mjx-table></mjx-mtable><mjx-mo class="mjx-s3"><mjx-c class="mjx-c29 TEX-S3"></mjx-c></mjx-mo></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">(</mo><mtable columnspacing="1em" rowspacing="4pt"><mtr><mtd><mn>2</mn><mi>N</mi></mtd></mtr><mtr><mtd><mi>N</mi></mtd></mtr></mtable><mo data-mjx-texclass="CLOSE">)</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\begin{pmatrix}  2N  \\  N  \end{pmatrix}\)</span></mjx-container> 이다. 시작한 점으로 다시 이동해야 하기 때문에, 왼쪽으로 이동한 횟수와 오른쪽으로 이동한 횟수가 같아야 한다. 따라서, N번 오른쪽으로, N번 왼쪽으로 움직이면 되기 때문이다.</p>

<p>선영이는 위의 문제에서 음수 좌표로 이동할 수 있다. 음수 좌표로 이동할 수 없는 조건을 추가했을 때, 경로의 수를 구하는 프로그램을 작성하시오. 예를 들어, N = 1인 경우에 선영이는 0 → 1 → 0으로 이동할 수 있다. 하지만, 0 → -1 → 0 으로는 이동할 수 없다.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 개수 T ≤ 1000 가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, N (1 ≤ N ≤ 1,000,000)이 주어진다.</p>

### 출력 

 <p>각 테스트 케이스 마다 음수 좌표를 방문하지 않고 시작점으로 도아오는 랜덤 걷기의 경로의 수를 1,000,000,007로 나눈 나머지를 출력한다.</p>

