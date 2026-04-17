# [Platinum V] 잘못 생성된 데이터 - 32295 

[문제 링크](https://www.acmicpc.net/problem/32295) 

### 성능 요약

메모리: 13684 KB, 시간: 808 ms

### 분류

수학, 애드 혹, 트리, 확률론

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p>영희는 $1,2,\cdots,n$의 순열을 무작위로 생성하는 알고리즘을 가지고 있습니다. 이 알고리즘의 의사코드는 아래와 같습니다.</p>

<table align="center" border="0" cellpadding="0" cellspacing="0" class="table table-bordered" style="width: 600pt;">
	<tbody>
		<tr>
			<td style="border-color: rgba(0, 0, 0, 0);">
			<pre style="margin: 0; line-height: 125%"><span style="color: #888888"># 클래스 node는 이진 트리의 노드를 구성합니다.</span>
<span style="color: #888888"># node는 클래스 변수로 L,R,Lc,Rc,x를 가집니다.</span>
<span style="color: #888888"># L,R은 왼쪽과 오른쪽 자식 노드를 가리키는 포인터 또는 인덱스입니다.</span>
<span style="color: #888888"># Lc와 Rc는 왼쪽과 오른쪽에 추가할 수 있는 리프 노드의 수를 나타냅니다.</span>
<span style="color: #888888"># 예를 들어 새로운 노드에 대해 Lc와 Rc는 기본적으로 1입니다.</span>
<span style="color: #888888"># x는 노드가 저장하는 정수 값입니다.</span>

<span style="color: #008800; font-weight: bold">def</span> <span style="color: #0066BB; font-weight: bold">makenode</span>(a):
  <span style="color: #008800; font-weight: bold">return</span> (<span style="background-color: #fff0f0">"'x=a인 새로운 node의 포인터 또는 인덱스"'</span>)

<span style="color: #008800; font-weight: bold">def</span> <span style="color: #0066BB; font-weight: bold">insert</span>(rt,a):
  <span style="color: #008800; font-weight: bold">while</span> <span style="color: #007020">True</span>:
    <span style="color: #007020">range</span> <span style="color: #333333">=</span> rt<span style="color: #333333">.</span>Lc<span style="color: #333333">+</span>rt<span style="color: #333333">.</span>Rc
    v <span style="color: #333333">=</span> (<span style="background-color: #fff0f0">"'0 이상 range 미만의 무작위 정수"'</span>)
    <span style="color: #008800; font-weight: bold">if</span> v <span style="color: #333333"><</span> rt<span style="color: #333333">.</span>Lc: <span style="color: #888888"># 라인 A</span>
      rt<span style="color: #333333">.</span>Lc <span style="color: #333333">+=</span> <span style="color: #0000DD; font-weight: bold">1</span>
      <span style="color: #008800; font-weight: bold">if</span> rt<span style="color: #333333">.</span>Lc <span style="color: #333333">==</span> <span style="color: #0000DD; font-weight: bold">2</span>:
        rt<span style="color: #333333">.</span>L <span style="color: #333333">=</span> makenode(a)
        <span style="color: #008800; font-weight: bold">return</span>
      rt <span style="color: #333333">=</span> (<span style="background-color: #fff0f0">"'rt.L이 가리키는 node"'</span>)
    <span style="color: #008800; font-weight: bold">else</span>:
      rt<span style="color: #333333">.</span>Rc <span style="color: #333333">+=</span> <span style="color: #0000DD; font-weight: bold">1</span>
      <span style="color: #008800; font-weight: bold">if</span> rt<span style="color: #333333">.</span>Rc <span style="color: #333333">==</span> <span style="color: #0000DD; font-weight: bold">2</span>:
        rt<span style="color: #333333">.</span>R <span style="color: #333333">=</span> makenode(a)
        <span style="color: #008800; font-weight: bold">return</span>
      rt <span style="color: #333333">=</span> (<span style="background-color: #fff0f0">"'rt.R이 가리키는 node"'</span>)

<span style="color: #008800; font-weight: bold">def</span> <span style="color: #0066BB; font-weight: bold">inorder</span>(rt):
  <span style="color: #008800; font-weight: bold">if</span> rt<span style="color: #333333">.</span>Lc <span style="color: #333333">></span> <span style="color: #0000DD; font-weight: bold">1</span>:
    inorder(<span style="background-color: #fff0f0">"'rt.L이 가리키는 node"'</span>)
  <span style="color: #008800; font-weight: bold">print</span>(rt<span style="color: #333333">.</span>x)
  <span style="color: #008800; font-weight: bold">if</span> rt<span style="color: #333333">.</span>Rc <span style="color: #333333">></span> <span style="color: #0000DD; font-weight: bold">1</span>:
    inorder(<span style="background-color: #fff0f0">"'rt.R이 가리키는 node"'</span>)

<span style="color: #888888"># ...</span>
<span style="color: #888888"># 데이터를 생성하는 방법</span>
root<span style="color: #333333">=</span><span style="background-color: #fff0f0">"'makenode(1)의 반환값이 가리키는 node"'</span>
<span style="color: #008800; font-weight: bold">for</span> i <span style="color: #000000; font-weight: bold">in</span> <span style="color: #007020">range</span>(<span style="color: #0000DD; font-weight: bold">2</span>,n<span style="color: #333333">+</span><span style="color: #0000DD; font-weight: bold">1</span>):
  insert(root,i)
<span style="color: #888888"># 이제 inorder(root)의 출력은 무작위 순열이 됩니다.</span></pre>
			</td>
		</tr>
	</tbody>
</table>

<p>알고리즘을 실행하면 출력으로 $1,2,\cdots,n$의 순열을 무작위로 얻으며, $n!$가지 순열 각각은 얻을 확률이 동일합니다. 또한 이 알고리즘은 놀랍게도 $\mathcal{O}(n \log n)$이라는 평균 시간 복잡도를 가집니다.</p>

<p>영희에게 이 알고리즘을 배운 철수는 혼자서 이 알고리즘을 구현해 보았습니다. 하지만, 기억력이 좋지 않은 철수는 주석 처리된 <strong>"라인 A"</strong>의 코드 <code>v < rt.Lc</code>를 <code>v >= rt.Lc</code>로 <strong>잘못 작성하고 말았습니다!</strong> 오타가 있었다는 사실을 알아냈을 때, 철수는 이미 길이 $n=1\,000$의 순열을 무수히 많이 생성한 뒤였습니다.</p>

<p>철수의 실수는 생각보다 심각했습니다. 영희의 알고리즘은 모든 순열을 같은 확률로 반환하지만, <strong>철수가 잘못 구현한 알고리즘은 그렇지 않습니다.</strong> 따라서 잘못 구현된 알고리즘이 어떤 문제의 채점 데이터를 생성하는데 사용되었다는 사실이 밝혀질 경우 논란이 생길 것이 분명합니다. 하지만 이미 어떤 문제의 채점 데이터에 잘못 생성된 데이터가 섞이고 말았습니다. 데이터를 새로 생성하기에는 시간이 부족하므로, 여러분이 잘못 생성된 데이터를 걸러내 주어야 합니다.</p>

<p>영희의 알고리즘을 <strong>알고리즘 A</strong>, 철수의 알고리즘을 <strong>알고리즘 B</strong>라고 합시다. 길이 $n=1\,000$의 순열이 $m=1\,000$개 있으며, 각각은 알고리즘 A와 알고리즘 B 중 하나로 생성되었습니다. 순열을 생성하는 알고리즘은 <strong>공정한 동전을 던져서 결정되었습니다.</strong> 다시 말해, 순열이 알고리즘 A로 생성될 확률이 $50\%$, 알고리즘 B로 생성될 확률이 $50\%$입니다. 여러분은 각 순열이 어느 알고리즘에서 생성되었는지 알아내야 합니다.</p>

<p>물론, 두 알고리즘이 같은 순열을 생성할 수도 있으므로 <strong>모든 입력에 대해 정답을 $100\%$의 확률로 맞힐 수 있는 방법은 없습니다.</strong> 따라서 $1\,000$개의 순열 중 적어도 $900$개의 순열에 대해 정답을 맞혔을 경우 정답으로 인정됩니다.</p>

### 입력 

 <p>첫 번째 줄에 순열의 개수 $m$이 주어집니다. ($m=1\,000$)</p>

<p>그다음 줄부터 $2m$개의 줄에 걸쳐 순열의 정보가 주어집니다. 각 순열의 정보는 두 줄로 구성됩니다.</p>

<ul>
	<li>첫 번째 줄에 순열의 길이 $n$이 주어집니다. ($n=1\,000$)</li>
	<li>두 번째 줄에 순열의 원소를 나타내는 $n$개의 정수 $a_1,a_2,\cdots,a_n$이 공백으로 구분되어 주어집니다. ($1 \le a_i \le n$)</li>
</ul>

<p>모든 입력은 지문에 주어진 과정에 따라 생성되었습니다. 또한, 입력 파일의 개수는 최대 $150$개입니다.</p>

### 출력 

 <p>각 순열에 대해 순열이 <strong>알고리즘 A</strong>로 생성된 경우 <code>"<span style="color:#e74c3c;">Alice</span>"</code>, <strong>알고리즘 B</strong>로 생성된 경우 <code>"<span style="color:#e74c3c;">Bob</span>"</code>을 새로운 줄에 출력합니다.</p>

<p>입력된 $m=1\,000$개의 순열 중 적어도 $900$개에 대해 정답을 맞힐 경우 정답으로 인정됩니다.</p>

<p><strong>이 문제는 형식상 인터랙티브 문제입니다.</strong></p>

<p>각 줄을 출력한 후에는 표준 출력 버퍼를 flush해 주어야 합니다. 언어별로 표준 출력 버퍼를 flush하는 방법은 다음과 같습니다.</p>

<ul>
	<li>C: <code>fflush(stdout)</code></li>
	<li>C++: <code>cout.flush()</code></li>
	<li>Java: <code>System.out.flush()</code></li>
	<li>Python: <code>sys.stdout.flush()</code></li>
	<li>이외의 언어: 언어별 레퍼런스를 참고합니다.</li>
</ul>

