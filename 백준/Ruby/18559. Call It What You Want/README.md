# [Ruby V] Call It What You Want - 18559 

[문제 링크](https://www.acmicpc.net/problem/18559) 

### 성능 요약

메모리: 50756 KB, 시간: 628 ms

### 분류

수학, 뫼비우스 반전 공식, 정수론

### 문제 설명

<p>As a stereotyped math fanatic, Taylor is expert on utilizing scientific computing tools but he is poor at programming infrastructures, which brings him endless powerlessness.</p>

<p>Recently he worked on factoring polynomials of the form (\(x^n −1\)) over the integers, which aims to express any polynomial of that form as some product of irreducible factors whose coefficients are all in the integers.</p>

<p>With knowledge of the cyclotomic polynomial, he has known that \(x^n - 1 = \prod_{d|n}{\Phi_d(x)}\) where each factor of that is just an irreducible polynomial over the integers. Moreover, \(\Phi_n(x) = \prod_{1 \le k \le n, \text{gcd}(n, k) = 1}{\left(x - w_n^k\right)}\), where \(w_n = \cos{\left(\frac{2\pi}{n}\right)} + \sqrt{-1}\sin{\left(\frac{2\pi}{n}\right)}\) is the unit complex root of degree \(n\) and \(\text{gcd}(n, k)\) is the greatest common divisor of \(n\) and \(k\).</p>

<p>Although he found such a conclusion, he couldn’t obtain the result of some high-degree polynomial in a few seconds. Could you please help him accomplish some factorizations of (\(x^n − 1\))?</p>

<p>Here are some examples:</p>

<ul>
	<li>\(\Phi_1(x) = x - 1\);</li>
	<li>\(\Phi_2(x) = x + 1, x^2 - 1 = (x-1)(x+1)\);</li>
	<li>\(\Phi_3(x) = x^2 + x + 1, x^3 - 1 = (x-1)(x^2+x+1)\);</li>
	<li>\(\Phi_4(x) = x^2 + 1, x^4 - 1 = (x-1)(x+1)(x^2+1)\);</li>
	<li>\(\Phi_6(x) = x^2 - x + 1, x^6 - 1 = (x-1)(x+1)(x^2-x+1)(x^2+x+1)\);</li>
	<li>\(\Phi_{12}(x) = x^4 - x^2 + 1, x^{12} - 1 = (x-1)(x+1)(x^2-x+1)(x^2+1)(x^2+x+1)(x^4-x^2+1)\).</li>
</ul>

<p>Oops! You might have some observations such as the degree of \(\Phi_n(x)\) equals to \(\phi(n)\), coefficients of \(\Phi_n(x)\) are the same back-to-front as front-to-back except for \(\Phi_1(x)\), \(\Phi_{p^e}(x) = \Phi_p\left(x^{p^{e-1}}\right)\) when \(p\) is prime, etc. , but they might be worthless for solving.</p>

### 입력 

 <p>The first line contains one integer \(T\), indicating the number of test cases.</p>

<p>Each of the following \(T\) lines describes a test case and contains only one integer \(n\).</p>

<p>\(1 \le T \le 100, 2 \le n \le 10^5\).</p>

<p>It is guaranteed that the sum of \(n\) in all test cases does not exceed \(5 \cdot 10^6\).</p>

### 출력 

 <p>For each test case, output the factorization as a string without any space in one line, where the polynomials should be sorted in a particular order and each polynomial should be printed in a particular format and enclosed in a pair of parentheses.</p>

<p><strong>Order of polynomials</strong>: The order of polynomial \(f(x)\) is lower than that of polynomial \(g(x)\) if and only if there exists a non-negative integer \(m\) such that the coefficient of \(x^k\) (\(k = m + 1, m + 2, \dots\)) in \(f(x)\) equals to that of \(g(x)\) but the coefficient of \(x^m\) in \(f(x)\) is less than that of \(g(x)\).</p>

<p><strong>Output format of one polynomial</strong>: Output all the terms of the polynomial from high-degree to lowdegree, each of which should be formed as \(\pm c_kx^k\). Additionally,</p>

<ol>
	<li>One term should be omitted if its coefficient is zero.</li>
	<li>The sign of the first term (\(\pm\)) should be omitted if the coefficient of that item is positive.</li>
	<li>When \(c_k = 1\), \(c_k\) should be omitted unless \(k = 0\).</li>
	<li>\(x^0\) should be omitted while \(x^1\) should be written as a simple \(x\).</li>
</ol>

<p>It is guaranteed that the size of the standard output file does not exceed 26 MiB.</p>

