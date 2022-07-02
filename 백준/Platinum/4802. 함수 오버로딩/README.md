# [Platinum I] 함수 오버로딩 - 4802 

[문제 링크](https://www.acmicpc.net/problem/4802) 

### 성능 요약

메모리: 3320 KB, 시간: 888 ms

### 분류

애드 혹(ad_hoc), 다이나믹 프로그래밍(dp), 트리에서의 다이나믹 프로그래밍(dp_tree), 구현(implementation), 파싱(parsing), 문자열(string), 트리(trees)

### 문제 설명

<p>프로그래머는 다양한 프로그래밍언어에서 함수를 오버로드할 수 있다. 함수 오버로드란 같은 함수의 이름을 가지고 있으나, 매개변수가 다른 함수이다. 그러나, Ada와 같은 언어에서는 리턴 타입도 오버로드할 수 있다. 즉, 같은 이름과 매개변수를 가지고 있으나, 리턴타입이 다를 수도 있는 것이다.</p>

<p>다음은 함수 오버로딩의 예이다.</p>

<div><div id="highlighter_535581" class="syntaxhighlighter  c"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div><div class="line number2 index1 alt1">2</div><div class="line number3 index2 alt2">3</div><div class="line number4 index3 alt1">4</div><div class="line number5 index4 alt2">5</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="c color1 bold">char</code> <code class="c plain">f(</code><code class="c color1 bold">float</code> <code class="c plain">x, </code><code class="c color1 bold">int</code> <code class="c plain">y)</code></div><div class="line number2 index1 alt1"><code class="c color1 bold">char</code> <code class="c plain">f(</code><code class="c color1 bold">float</code> <code class="c plain">x, </code><code class="c color1 bold">float</code> <code class="c plain">y)</code></div><div class="line number3 index2 alt2"><code class="c color1 bold">float</code> <code class="c plain">f(</code><code class="c color1 bold">float</code> <code class="c plain">x, </code><code class="c color1 bold">float</code> <code class="c plain">y)</code></div><div class="line number4 index3 alt1"><code class="c color1 bold">float</code> <code class="c plain">g(</code><code class="c color1 bold">float</code> <code class="c plain">x, </code><code class="c color1 bold">int</code> <code class="c plain">y)</code></div><div class="line number5 index4 alt2"><code class="c color1 bold">float</code> <code class="c plain">g(</code><code class="c color1 bold">int</code> <code class="c plain">x, </code><code class="c color1 bold">float</code> <code class="c plain">y)</code></div></div></td></tr></tbody></table></div></div>

<p>위와 같이 함수 선언이 있을 때, 아래와 같은 변수 선언과 함수 호출을 포함한 프로그램을 작성할 수 있다.</p>

<div><div id="highlighter_744642" class="syntaxhighlighter  c"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div><div class="line number2 index1 alt1">2</div><div class="line number3 index2 alt2">3</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="c color1 bold">float</code> <code class="c plain">a = 1.0, b = 2.0;</code></div><div class="line number2 index1 alt1"><code class="c color1 bold">int</code> <code class="c plain">c = 3;</code></div><div class="line number3 index2 alt2"><code class="c color1 bold">float</code> <code class="c plain">d = g(c, f(a, b));</code></div></div></td></tr></tbody></table></div></div>

<p><code>f</code>의 처음 두 선언은 위의 함수 <code>f</code>에 해당하지 않는다. 하지만, 세 번째 함수는 <code>f(<float>, <float>)</code>와 같은 형식이라 매개변수의 타입이 같고, 리턴 타입도 <code>g(<int>, <float>)</code>의 <code>float</code>과 같기 때문에 해당한다. 따라서, 3번째 <code>f</code>와 두 번째 <code>g</code>를 사용할 수 있다.</p>

<p>이렇게 3번째 <code>f</code>와 2번째 <code>g</code>를 사용했기 때문에, 다음과 같이 숫자와 함께 표현할 수 있다.</p>

<div><div id="highlighter_225163" class="syntaxhighlighter  c"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="c plain">d = g2(c, f3(a, b))</code></div></div></td></tr></tbody></table></div></div>

<p>하지만, 위의 함수 선언을 이용해서 <code>c = g(a, f(a, c))</code>는 사용할 수 없다.</p>

<p>마지막으로 다음과 같은 함수 선언이 있다고 하자.</p>

<div><div id="highlighter_950812" class="syntaxhighlighter  c"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div><div class="line number2 index1 alt1">2</div><div class="line number3 index2 alt2">3</div><div class="line number4 index3 alt1">4</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="c color1 bold">float</code> <code class="c plain">x(</code><code class="c color1 bold">float</code> <code class="c plain">w)</code></div><div class="line number2 index1 alt1"><code class="c color1 bold">int</code> <code class="c plain">x(</code><code class="c color1 bold">float</code> <code class="c plain">w)</code></div><div class="line number3 index2 alt2"><code class="c color1 bold">char</code> <code class="c plain">y(</code><code class="c color1 bold">float</code> <code class="c plain">v)</code></div><div class="line number4 index3 alt1"><code class="c color1 bold">char</code> <code class="c plain">y(</code><code class="c color1 bold">int</code> <code class="c plain">v)</code></div></div></td></tr></tbody></table></div></div>

<p>위와 같은 선언에서 다음과 같은 함수 호출은 애매모호(ambiguous)하기 때문에 사용할 수 없다.</p>

<div><div id="highlighter_428224" class="syntaxhighlighter  c"><table border="0" cellpadding="0" cellspacing="0"><tbody><tr><td class="gutter"><div class="line number1 index0 alt2">1</div><div class="line number2 index1 alt1">2</div></td><td class="code"><div class="container"><div class="line number1 index0 alt2"><code class="c color1 bold">float</code> <code class="c plain">a = 1.0</code></div><div class="line number2 index1 alt1"><code class="c color1 bold">char</code> <code class="c plain">c = y(x(a))</code></div></div></td></tr></tbody></table></div></div>

### 입력 

 <p>입력은 여러 개의 함수 선언과 함수 호출으로 이루어져 있다. 함수 선언은 한 줄에 하나씩 주어지며, 다음과 같은 형태이다.</p>

<pre>name num_params param(1) param(2) ... param(num_params) rettype</pre>

<p>name은 함수의 이름이고, param(i)는 i번째 매개변수의 데이터 타입이다. rettype은 함수의 리턴값의 데이터 타입이다. (이 문제에서 void 함수는 없다) num_params는 적어도 1이고 많아야 9이다. 매개변수는 이름을 갖지 않는다. 함수의 이름은 알파벳 소문자 한글자이고, 데이터 타입은 알파벳 대문자 한글자이다. 같은 이름을 갖는 다른 함수는 연속으로 나타나며, 같은 이름을 갖는 함수는 많아야 500개이다. 두 함수의 선언이 정확하게 일치하는 경우는 없다.</p>

<p>문제에서 설명한 것 처럼 함수에 숫자를 붙여서 나타내는 것의 숫자를 시리얼 넘버라고 한다. 이때, 시리얼 넘버는 새로운 함수의 이름이 시작할 때 1이 되고, 선언이 나타날때마다 1씩 증가한다.</p>

<p>함수 선언의 마지막에는 '#'가 주어진다. 그 다음줄부터 함수 호출이 한 줄에 하나씩 주어진다.</p>

<p>함수 호출은 다음과 같은 문법을 따른다.</p>

<pre><function_call> := <data_type> = <right_hand_side>
<right_hand_side> := <fname> <num_params> <param_list>
<param_list> := <param> | <param_list> <param>
<param> := <data_type> | <right_hand_side>
<data_type> := <upper_case_letter>
<num_params> := '1' | '2' | ... | '9'
<fname> := <lower_case_letter>
</pre>

<p>:=와 |는 문법 정의에만 등장하는 기호이고, 실제 함수 호출에는 나타나지 않는다. 각 함수 호출에서 호출하는 함수의 이름은 500개를 넘지 않는다. 함수 호출의 마지막 줄에는 '#'가 하나 주어진다.</p>

### 출력 

 <p>입력으로 주어진 각 함수 호출에 대해서, 만약 어떤 함수를 사용했는지 유일하게 결정할 수 있다면, 입력 함수 호출에서 함수의 이름에 시리얼 넘버만 추가한 형태로 출력한다. 만약, 해당하는 함수가 없어서 호출할 수 없다면 "impossible"을 출력하고, 애매모호해서 호출하는 방법이 여러 가지라면, "ambiguous"를 출력하고, 경우의 수를 출력한다. 만약, 1000가지를 넘는 방법으로 호출할 수 있다면 "> 1000"을 경우의 수 대신 출력한다.</p>

