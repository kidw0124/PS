# [Bronze IV] Missed Alarm - 34798 

[문제 링크](https://www.acmicpc.net/problem/34798) 

### 성능 요약

메모리: 2088 KB, 시간: 0 ms

### 분류

구현, 문자열

### 제출 일자

2025년 11월 24일 22:07:41

### 문제 설명

<p>It is November 14, 2025. You are doing your last minute preparations for the 2025 Pacific Northwest Regional. You have Eurovision music blasting in your dorm room as you code up your final solution to Free Solo. You submit your solution to Kattis and watch as the green check marks slowly accumulate... you hit F5 one last time, and see that all test cases have passed!</p>

<p>With your coding preparations now complete, you decide to prepare all the materials that you will bring to the regional contest. You pack your trusty copies of CLRS and KT, along with language reference books for C, C++, Java, Kotlin, and Python. You print out a copy of the KACTL team reference document and also print your personal templates.</p>

<p>You check your phone. It is November 15, 2025. You realize you need to get a good night's sleep. You set your alarm and start preparing for bed. You're excited for the regional contest but not so excited it'll keep you up tonight. With your alarm set to go off at some point on the 15th, you get into bed and you're already asleep before your head hits your pillow.</p>

<p>You suddenly wake up and look at the clock. It's still November 15, 2025. Did you sleep through your alarm?</p>

### 입력 

 <p>The input consists of two lines.</p>

<p>The first line contains a time in the form <code>HH:MM</code>, indicating when you set your alarm. It is guaranteed that this is a valid time between <code>10:00</code> and <code>12:59</code>, inclusive.</p>

<p>The second line contains a time in the form <code>HH:MM</code>, indicating when you look at the clock. It is guaranteed that this is a valid time between <code>10:00</code> and <code>12:59</code>, inclusive. It is further guaranteed that this time is not exactly the same as your alarm.</p>

<p>A valid time will always have a minute value that is an integer between <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container> and <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>59</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$59$</span></mjx-container>, inclusive. The minute value will always be represented using two digits, possibly with a leading zero.</p>

### 출력 

 <p>Output <code>YES</code> if you woke up after your alarm. Output <code>NO</code> otherwise.</p>

