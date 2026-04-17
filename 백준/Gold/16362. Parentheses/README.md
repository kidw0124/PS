# [Gold I] Parentheses - 16362 

[문제 링크](https://www.acmicpc.net/problem/16362) 

### 성능 요약

메모리: 2556 KB, 시간: 0 ms

### 분류

많은 조건 분기, 자료 구조, 구현, 파싱, 스택, 문자열

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<p><img alt="" src="" style="width: 280px; height: 70px; float: right; margin-left:10px;">The correspondence among the operators and the operands can be clarified using parentheses. In a C program, for example, the expression <code>a-b-c</code> can be clarified as <code>(a-b)-c</code> since the minus operator is left associative.</p>

<p>The parentheses can be used to override the default precedences and associativities of operators. For instance, in the expression <code>a-(b-c)</code>, the left associativity of the minus operator is overridden by the parentheses.</p>

<p>A novice C programmer Dennis has been stressed too much in remembering the operator precedences and associativities. Therefore, he made a new language namely ICPC (I can parenthesize C), in which the operator-operand correspondence should be clarified fully using parentheses; except for this, all the other features are same as C. For instance, one should write <code>(a-b)-c</code> instead of <code>a-b-c</code> and <code>a+(b*c)</code> rather than <code>a+b*c</code>.</p>

<p>However, the usage of the parentheses can be too much in some cases. For the expression <code>a-b-c</code>, it is enough to write</p>

<p><code>(a-b)-c</code></p>

<p>but one can write it as</p>

<p><code>(a-<u>(</u>b<u>)</u>)-c</code></p>

<p>or as</p>

<p><code><u>(</u>(a-b)-c<u>)</u></code></p>

<p>where the pairs of parentheses underlined are superfluous.</p>

<p>Dennis wants to convert the C expression into the ICPC expression, in which the pairs of parentheses should be used exactly as needed. You have to help Dennis. For simplicity, you can assume that the input C expression contains only five binary arithmetic operators (<code>+</code>, <code>-</code>, <code>*</code>, <code>/</code>, and <code>%</code>), left and right parentheses <code>(</code> and <code>)</code>, and single-lowercase alphabet operands. Given such a C expression, write a program to determine whether it is an ICPC expression or not.</p>

<p>If the expression is not an error in ICPC, then it should not be an error in C. Once it is not an error in C, the usage of parentheses should be checked to determine whether it is a proper expression in ICPC or not. If the expression is not properly parenthesized, i.e., the number of parentheses is not exact as needed, then it is considered improper.</p>

<p>Beware that some of the input C expressions may be erroneous originally. For instance, <code>a%/b</code> is an error since it requires one more operand between <code>%</code> and <code>/</code> to be valid. As another example, <code>a b + c</code> is also an error since it requires one more operator between <code>a</code> and <code>b</code>.</p>

### 입력 

 <p>Your program is to read from standard input. The input consists of a single line containing a C expression. The expression is a string of single-lowercase alphabets, special symbols including left and right parentheses and five binary arithmetic operators (<code>+</code>, <code>-</code>, <code>*</code>, <code>/</code>, and <code>%</code>), and spaces. The input line contains at least one operand. The length of the input line (the number of characters in it) is no more than 1000 including the spaces and the single newline character at the end.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain one of the following words: <code>error</code>, <code>proper</code>, and <code>improper</code>. Print <code>error</code> if the input C expression is erroneous. Once it is not an error, print <code>proper</code> or <code>improper</code> depending on the parenthesized status of the expression: print <code>proper</code> if it is parenthesized properly with the exact number of parentheses needed for ICPC, and print <code>improper</code> otherwise.</p>

