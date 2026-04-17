# [Platinum V] Talk jail - 28341 

[문제 링크](https://www.acmicpc.net/problem/28341) 

### 성능 요약

메모리: 7028 KB, 시간: 40 ms

### 분류

자료 구조, 그리디 알고리즘, 정렬, 트리, 집합과 맵, 해 구성하기, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

### 제출 일자

2026년 04월 18일 01:08:28

### 문제 설명

<blockquote>
<p>How have you been?</p>

<p>I want to play a game.</p>

<p>This game will be played on a smartphone, on which you spend most of your time.</p>

<p>On the ’Talk.’</p>

<p>Are you happy because you got unlimited 3G?</p>

<p>Tonight, we shall see how far you go in order not to turn your phone off.</p>

<p>Will you get a push or turn it off?</p>

<p>Your choice.</p>

<p>— Jigsaw</p>
</blockquote>

<p>Jigsaw invited $N$ people to the “Talk jail” room. Here is a brief description of how Talk room works. Everyone can send messages, and all messages are delivered to everyone in the room, including the sender. However, a new message arrived on someone’s smartphone is not displayed immediately if the chat room window is not open. Instead, it is kept in the <strong>unread</strong> status. As soon as one <strong>opens</strong> the Talk jail room window, the status of all messages that have been arrived so far changes to the <strong>read</strong> status. Also, while the chat room window is open, newly arrived messages will be displayed and marked as read immediately. One can close the chat room window, but the messages will still arrive. One can send a message only when he/she has the chat room window open.</p>

<p>Moreover, when one opens the chat room window, one can see $3$ pieces of information on each message: the sent time, the sender, and the number of people who have not read the message yet.</p>

<p>This simple chatting service can actually serve as a jail as follows. When a lot of people send messages in the Talk jail room, everyone’s phone will keep beeping continuously, which makes it impossible for him/her to manage ordinary life. Even if someone tries to leave the room, Jigsaw invites him/her back immediately: so it is impossible to leave the room. As a result, people will complain in the room which yields more messages and more beeps…</p>

<p>Jigsaw will never send any message to the room but will keep inviting leavers back to the room. Being so frustrated, people eventually choose one or the other: (A) just suck it up and live with it or (B) ignore the smartphone entirely and live free.</p>

<p>Jigsaw just opened the chat room window and checked out the $M$ messages that have been sent ever since the room was created. Based on this, he can infer that certain people have not read certain messages with certainty. That is, for each message, he may be able to infer whether someone has read the message or not (sometimes, such inference may not be possible). He calls those who have not read the message for sure, “the wretched addict.”</p>

<p>For each message, your job is to figure out how many people Jigsaw can identify as “the wretched addicts” because you can infer that they have not read the message.</p>

### 입력 

 <p>The input consists of $T$ test cases. The first line of the input contains $T$.</p>

<p>Each test case starts with two integers $N$ ($1 ≤ N ≤ 60\,000$) and $M$ ($1 ≤ M ≤ 60\,000$), separated by a whitespace. The following $M$ lines contain three integers each: $t_i$, $p_i$, and $c_i$ where $t_i$ ($0 ≤ t_i < 2^{31}$) denotes the sent time, $p_i$ ($1 ≤ p_i ≤ N$) denotes the sender, and $c_i$ ($0 ≤ c_i < N$) denotes the number of people who have not read the message $i$. No two messages have the same value of $t_i$. The input is consistent and valid.</p>

### 출력 

 <p>For each test case, you must output “<code>#</code>Test case number” in the first line. You must output the number of people who are certain that have not read the $i$-th message yet in a separate line.</p>

