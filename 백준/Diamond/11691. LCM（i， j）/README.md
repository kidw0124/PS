# [Diamond V] LCM(i, j) - 11691 

[문제 링크](https://www.acmicpc.net/problem/11691) 

### 성능 요약

메모리: 19332 KB, 시간: 44 ms

### 분류

수학, 뫼비우스 반전 공식, 정수론

### 문제 설명

<p>재현이는 다음과 같은 소스를 작성했다.</p>

<div><div id="highlighter_50158" class="syntaxhighlighter  c"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div><div class="line number2 index1 alt1">2</div><div class="line number3 index2 alt2">3</div><div class="line number4 index3 alt1">4</div><div class="line number5 index4 alt2">5</div><div class="line number6 index5 alt1">6</div><div class="line number7 index6 alt2">7</div><div class="line number8 index7 alt1">8</div><div class="line number9 index8 alt2">9</div><div class="line number10 index9 alt1">10</div><div class="line number11 index10 alt2">11</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="c color1 bold">long</code> <code class="c color1 bold">long</code> <code class="c plain">mod = 1000000007;</code></div><div class="line number2 index1 alt1"><code class="c color1 bold">long</code> <code class="c color1 bold">long</code> <code class="c plain">all_pair_lcm(</code><code class="c color1 bold">int</code> <code class="c plain">n) {</code></div><div class="line number3 index2 alt2"><code class="c spaces">    </code><code class="c color1 bold">long</code> <code class="c color1 bold">long</code> <code class="c plain">ans = 0;</code></div><div class="line number4 index3 alt1"><code class="c spaces">    </code><code class="c keyword bold">for</code> <code class="c plain">(</code><code class="c color1 bold">int</code> <code class="c plain">i=1; i<=n-1; i++) {</code></div><div class="line number5 index4 alt2"><code class="c spaces">        </code><code class="c keyword bold">for</code> <code class="c plain">(</code><code class="c color1 bold">int</code> <code class="c plain">j=i+1; j<=n; j++) {</code></div><div class="line number6 index5 alt1"><code class="c spaces">            </code><code class="c plain">ans += lcm(i, j);</code></div><div class="line number7 index6 alt2"><code class="c spaces">            </code><code class="c plain">ans %= mod;</code></div><div class="line number8 index7 alt1"><code class="c spaces">        </code><code class="c plain">}</code></div><div class="line number9 index8 alt2"><code class="c spaces">    </code><code class="c plain">}</code></div><div class="line number10 index9 alt1"><code class="c spaces">    </code><code class="c keyword bold">return</code> <code class="c plain">ans;</code></div><div class="line number11 index10 alt2"><code class="c plain">}</code></div></div></td></tr></tbody></table></div></div>

<p>n이 큰 경우에 위의 소스를 그대로 실행하면 시간초과가 난다.</p>

<p>n이 주어졌을 때, <code>all_pair_lcm(n)</code>을 리턴값을 출력하는 프로그램을 작성하시오.</p>

<p><code>lcm(i, j)</code>는 i와 j의 최소공배수를 구하는 함수이다.</p>

### 입력 

 <p>첫째 줄에 n이 주어진다. (1 ≤ n ≤ 10<sup>6</sup>)</p>

### 출력 

 <p>첫째 줄에 <code>all_pair_lcm(n)</code>을 리턴값을 출력한다.</p>

