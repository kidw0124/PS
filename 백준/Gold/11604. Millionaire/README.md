# [Gold I] Millionaire - 11604 

[문제 링크](https://www.acmicpc.net/problem/11604) 

### 성능 요약

메모리: 18276 KB, 시간: 84 ms

### 분류

다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2024년 7월 9일 06:04:52

### 문제 설명

<p>Congratulations! You were selected to take part in the TV game show Who Wants to Be a Millionaire! Like most people, you are somewhat risk-averse, so you might rather take <span>$</span>250,000 than a 50% chance of winning <span>$</span>1,000,000. On the other hand, if you happen to already be rich, then you might as well take a chance on the latter. Before appearing on the show, you want to devise a strategy to maximize the expected happiness derived from your winnings.</p>

<p>More precisely, if your present net worth is W dollars, then winning v dollars gives you ln(1 + v/W) units of happiness. Thus, the game’s expected happiness is Σ<sub>v</sub>P(v) ln(1+v/W), where P(v) is the probability that you’ll win v dollars, and the summation is taken over all possible values of v. Since happiness units are too abstract, you will be asked to measure the value of the game in dollars. That is, compute D such that a guaranteed payout of D dollars makes you as happy as a chance on the show, assuming optimal play.</p>

<p>On the show, you will be presented with a series of questions on trivia, each associated with a prize value of v<sub>i</sub> dollars. Your analysis of past episodes reveals that if you attempt the ith question, your chances of being correct are p<sub>i</sub>.</p>

<p>After answering correctly, you may choose to continue or to quit. If you quit, you win the value of the last correctly answered question; otherwise, the game continues and you must attempt the next question. If you correctly answer all the questions, you walk away with the value of the last question.</p>

<p>If you answer a question incorrectly, however, the game ends immediately and you win the value of the last correctly answered question that is labeled as safe, or nothing if you never solved a safe question.</p>

<p>For example, the game in the first sample input is worth 0.5 ln(1 + 5000/4000) ≈ 0.405 units of happiness. Getting <span>$</span>2,000 would likewise grant ln(1 + 2000/4000) ≈ 0.405 happiness.</p>

### 입력 

 <p>The first line of input contains two space-separated integers n and W (1 ≤ n ≤ 10<sup>5</sup> , 1 ≤ W ≤ 10<sup>6</sup>). Line i + 1 describes the ith question. It starts with a string, which is one of safe or unsafe, indicating whether the ith question is safe or not. The string is followed by a real number p<sub>i</sub> and an integer v<sub>i</sub> (0 ≤ p<sub>i</sub> ≤ 1, 1 ≤ v<sub>i</sub> < v<sub>i+1</sub> ≤ 10<sup>6</sup>).</p>

### 출력 

 <p>Print, on a single line, a <code>$</code> sign immediately followed by D, rounded and displayed to exactly two decimal places. See the samples for format clarification.</p>

