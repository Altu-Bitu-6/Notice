# 스택_큐_덱
[메인으로 돌아가기](https://github.com/Altu-Bitu-5/Notice) 
## 💻 튜터링 
### 라이브 코딩
| 문제 번호 | 문제 이름 | 난이도 | 풀이 링크 | 분류 |
| :-: | :-: | :-: | :-: | :-: |
| [10828](https://www.acmicpc.net/problem/10828) | [스택](https://www.acmicpc.net/problem/10828) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/7.svg"/> | [바로가기](https://github.com/Altu-Bitu-6/Notice/blob/main/02_스택_큐_덱/라이브코딩/10828_v2.cpp) | 자료 구조, 구현, 스택 |
| [10845](https://www.acmicpc.net/problem/10845) | [큐](https://www.acmicpc.net/problem/10845) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/7.svg"/> | [바로가기](https://github.com/Altu-Bitu-6/Notice/blob/main/02_스택_큐_덱/라이브코딩/10845_v2.cpp) | 자료 구조, 큐 |
| [10866](https://www.acmicpc.net/problem/10866) | [덱](https://www.acmicpc.net/problem/10866) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/7.svg"/> | [바로가기](https://github.com/Altu-Bitu-6/Notice/blob/main/02_스택_큐_덱/라이브코딩/10866_v2.cpp) | 자료 구조, 덱, 구현 |
## ✏️ 과제 
### 마감기한
~ 2 / 27 (화) 18:59 - 과제 제출 </br>
~ 2 / 29 (목) 23:59 - 추가 제출 </br>
### 필수
| 문제 번호 | 문제 이름 | 난이도 | 풀이 링크 | 분류 |
| :-: | :-: | :-: | :-: | :-: |
| [1158](https://www.acmicpc.net/problem/1158) | [요세푸스 문제](https://www.acmicpc.net/problem/1158) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/7.svg"/> | [바로가기](https://github.com/Altu-Bitu-6/Notice/blob/main/02_스택_큐_덱/필수/1158.cpp) | 자료 구조, 구현, 큐 |
| [4949](https://www.acmicpc.net/problem/4949) | [균형잡힌 세상](https://www.acmicpc.net/problem/4949) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/7.svg"/> | [바로가기](https://github.com/Altu-Bitu-6/Notice/blob/main/02_스택_큐_덱/필수/4949.cpp) | 자료 구조, 스택, 문자열 |
| [10757](https://www.acmicpc.net/problem/10757) | [큰 수 A+B](https://www.acmicpc.net/problem/10757) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/1.svg"/> | [바로가기](https://github.com/Altu-Bitu-6/Notice/blob/main/02_스택_큐_덱/필수/10757.cpp) | 구현, 임의 정밀도 / 큰 수 연산, 사칙연산, 수학 |
### 도전
| 문제 번호 | 문제 이름 | 난이도 | 풀이 링크 | 분류 |
| :-: | :-: | :-: | :-: | :-: |
| [1918](https://www.acmicpc.net/problem/1918) | [후위 표기식](https://www.acmicpc.net/problem/1918) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/14.svg"/> | [바로가기](https://github.com/Altu-Bitu-6/Notice/blob/main/02_스택_큐_덱/도전/1918.cpp) | 자료 구조, 스택 |
| [17298](https://www.acmicpc.net/problem/17298) | [오큰수](https://www.acmicpc.net/problem/17298) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> | [바로가기](https://github.com/Altu-Bitu-6/Notice/blob/main/02_스택_큐_덱/도전/17298.cpp) | 자료 구조, 스택 |
---
 ### 힌트
<details><summary>요세푸스 문제</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;원형의 사람들을 관리하려면, 앞에서 제거하고 다시 뒤에 추가해야 합니다!</div></details>
<details><summary>균형잡힌 세상</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;오른쪽 괄호(닫는 괄호)를 기준으로 균형을 이루지 못하는 경우를 고려해볼까요?</div></details>
<details><summary>오큰수</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;스택에 새로 들어오는 값(==오른쪽에 있는 값) 이 스택 top 값보다 크면 스택에 있는 원소들의 오큰수가 됩니다!</div></details>
<details><summary>후위 표기식</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;중위표기식과 후위표기식의 차이를 알아볼까요? 피연산자의 순서는 중위 표기식과 동일해요. 따라서 연산자의 순서가 중요할 것 같네요! 중위표기식과 후위표기식을 비교하며 어떤 연산자가 먼저 출력되었는지 살펴봅시다. "연산자 우선순위"를 어떻게 설정해야 후위표기식으로 바꿀 수 있을까요?</div></details>
<details><summary>큰 수 A+B</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;주어지는 a와 b는 0보다 크고 10의 100승보다 작은 정수로, C++에서 사용할 수 있는 정수 자료형의 크기를 벗어나요. 어떻게 하면 바로 a+b를 더하지 않는 방법으로, 그 결과를 구할 수 있을까요?</div></details>

---
