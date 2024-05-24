# 최단 경로 (Shortest Path)
[메인으로 돌아가기](https://github.com/Altu-Bitu-6/Notice) 

## 💻 튜터링

### 라이브 코딩
| 문제 번호 | 문제 이름 | 난이도 | 풀이 링크 | 분류 |
| :-: | :-: | :-: | :-: | :-: |
| [1753](https://www.acmicpc.net/problem/1753) | [최단경로](https://www.acmicpc.net/problem/1753) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> | [바로가기](https://github.com/Altu-Bitu-6/Notice/blob/main/13_최단경로/라이브코딩/1753.cpp) | 다익스트라 |
| [11404](https://www.acmicpc.net/problem/11404) | [플로이드](https://www.acmicpc.net/problem/11404) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> | [바로가기](https://github.com/Altu-Bitu-6/Notice/blob/main/13_최단경로/라이브코딩/11404.cpp) | 플로이드-워셜 |
| [11657](https://www.acmicpc.net/problem/11657) | [타임머신](https://www.acmicpc.net/problem/11657) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> | [바로가기](https://github.com/Altu-Bitu-6/Notice/blob/main/13_최단경로/라이브코딩/11657.cpp) | 벨만-포드 |

## ✏️ 과제

### 마감기한

~ 5 / 28 (화) 18:59 - 과제 제출 </br>
~ 5 / 30 (목) 23:59 - 추가 제출 </br>

### 필수
| 문제 번호 | 문제 이름 | 난이도 | 풀이 링크 | 분류 |
| :-: | :-: | :-: | :-: | :-: |
| [15685](https://www.acmicpc.net/problem/15685) | [드래곤 커브](https://www.acmicpc.net/problem/15685) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/> |  | 구현, 시뮬레이션 |
| [1238](https://www.acmicpc.net/problem/1238) | [파티](https://www.acmicpc.net/problem/1238) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/> |  | 다익스트라 |
| [2458](https://www.acmicpc.net/problem/2458) | [키 순서](https://www.acmicpc.net/problem/2458) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/12.svg"/> |  | 플로이드-워셜 |

### 도전
| 문제 번호 | 문제 이름 | 난이도 | 풀이 링크 | 분류 |
| :-: | :-: | :-: | :-: | :-: |
| [합승 택시 요금](https://school.programmers.co.kr/learn/courses/30/lessons/72413) | [합승 택시 요금](https://school.programmers.co.kr/learn/courses/30/lessons/72413) | **Lv.3** |  | 플로이드-워셜 |
| [1865](https://www.acmicpc.net/problem/1865) | [웜홀](https://www.acmicpc.net/problem/1865) | <img height="25px" width="25px" src="https://static.solved.ac/tier_small/13.svg"/> |  | 벨만-포드 |
---

### 힌트
<details><summary>드래곤 커브</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;뱀의 머리와 꼬리에 변화가 생기고 있네요! 어떤 자료구조가 필요할까요? 뱀의 현재 위치를 직접 나타내보는 것도 좋을 것 같네요.</div></details>
<details><summary>파티</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;이제 어떤 지점을 가기만 하는 게 아니라 오기도 해야 하니 다익스트라 알고리즘을 여러 번 사용해야겠습니다!</div></details>
<details><summary>키 순서</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;두 사람 사이의 키 순위를 비교해볼까요? 나와 상대방과의 키 순위를 안다는 것은 내가 상대방과의 키 우열을 알거나 상대방이 나와의 키 우열을 안다는 것과 같습니다.</div></details>
<details><summary>합승 택시 요금</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;함께 합승할 수 있는 지점은 총 몇 개인가요? 계산에 고려해야 할 가능한 시작, 도착 지점의 쌍이 어떻게 될까요?</div></details>
<details><summary>웜홀</summary><div markdown="1">&nbsp;&nbsp;&nbsp;&nbsp;시간이 뒤로 갈 수 있다네요? 음수 가중치일때 사용할 수 있는 알고리즘을 배웠었죠! 것보다 벨만 포드는 분명 출발점이 특정한 한 점일때 가능한 알고리즘이라고 배웠는데,시작지점이 정해져있지 않네요. 그런데 특정 정점 하나만 확인하면 해당 정점과 단절된 노드가 포함된 음수 사이클을 발견할 수 없죠! 우리는 최단거리에는 관심이 없고, 오로지 음수 사이클의 존재 여부만 확인하고 싶은 상황에서 어떻게 하면 될까요?</div></details>

---