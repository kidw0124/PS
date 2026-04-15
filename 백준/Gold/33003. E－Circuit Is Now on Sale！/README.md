# [Gold IV] E-Circuit Is Now on Sale! - 33003 

[문제 링크](https://www.acmicpc.net/problem/33003) 

### 성능 요약

메모리: 2308 KB, 시간: 0 ms

### 분류

사칙연산, 깊이 우선 탐색, 그래프 이론, 그래프 탐색, 구현, 수학, 시뮬레이션

### 제출 일자

2026년 04월 15일 19:19:24

### 문제 설명

<p>Are you looking for math education tools for your children? Then, why not try this amazing product, <em>E-circuit</em>? This is the best toy to learn two-dimensional geometry, logic, and arithmetic!</p>

<p>The E-circuit consists of a grid space with a bunch of square blocks, called <em>units</em>. Each unit perfectly fits into a grid cell. They have some input and/or output terminals to transfer integer values. When a number of units are <em>appropriately</em> placed in the grid, they form a tree representing a mathematical formula.</p>

<p>The units have different functionalities, each represented by a single character as follows.</p>

<ul>
	<li>Digit (‘<code>0</code>’ to ‘<code>9</code>’): These units have one output terminal. Each of them sends the integer value indicated by the digit to its output.</li>
	<li>Connector (‘<code>#</code>’): These units have one input terminal and one output terminal. Each of them receives an integer value from its input and sends the value to its output without making any changes.</li>
	<li>Operator (‘<code>+</code>’, ‘<code>-</code>’, ‘<code>*</code>’, ‘<code>/</code>’): These units have two input terminals and one output terminal, do the following calculations on the values received from their inputs, and send the results to their outputs.
	<ul>
		<li>‘<code>+</code>’ operators compute the sum of the two input values.</li>
		<li>‘<code>-</code>’ operators compute the difference of the two input values, the larger one subtracted by the smaller one.</li>
		<li>‘<code>*</code>’ operators compute the product of the two input values.</li>
		<li>‘<code>/</code>’ operators compute the quotient of the input values, the larger one divided by the smaller one, truncating the fraction, if any.</li>
	</ul>
	</li>
	<li>Printer (‘<code>P</code>’): The printer has one input terminal and displays the input value. There should be exactly one printer unit on the grid.</li>
</ul>

<p>Two cells are adjacent if they share an edge. When two units are placed on adjacent cells, they are connected by using an input terminal of one unit and an output terminal of the other.</p>

<p>You are given an appropriate placement of units in which the units form a single tree representing a mathematical formula. A formal description of such a placement will be given in the Input section.</p>

<p>Your task is to calculate the value the printer displays for the given unit placement.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<blockquote>
<p>$n$ $m$</p>

<p>$x_{1,1}$ $\cdots$ $x_{1,m}$</p>

<p>$\vdots$</p>

<p>$x_{n,1}$ $\cdots$ $x_{n,m}$</p>
</blockquote>

<p>The first two integers $n$ and $m$ ($1 ≤ n ≤ 50$, $1 ≤ m ≤ 50$) mean that the grid has cells arranged in an $n \times m$ matrix. The following $n$ lines describe the placement of units. The character $x_{i,j}$ ($1 ≤ i ≤ n$, $1 ≤ j ≤ m$) specifies the unit on the cell $i$-th from the top and $j$-th from the left. Each character either represents the unit functionality, as described in the problem statement, or is the character ‘<code>.</code>’, meaning that the cell is empty.</p>

<p>It is guaranteed that the units are placed appropriately, that is,</p>

<ul>
	<li>the number of adjacent units of each unit equals the total number of its input and output terminals,</li>
	<li>the total number of input terminals and that of output terminals of all the units are equal, and</li>
	<li>all the units belong to the printer tree: a unit belongs to the printer tree if and only if it is the printer or adjacent to another unit belonging to the printer tree.</li>
</ul>

<p>It is also guaranteed that input values of ‘<code>/</code>’ operators are not zero and no units have an output value larger than $10^{18}$.</p>

### 출력 

 <p>Output a line containing the displayed value.</p>

