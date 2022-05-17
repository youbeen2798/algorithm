#include <iostream>
#define INF 1000000000

using namespace std;

int number = 6;

//전체 그래프 초기화
int a[6][6] = {
	{0,2,5,1,INF, INF},
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0}
};

int d[6]; //방문한 노드
bool visited[6]; //거리

//가장 최소 거리를 가지는 정점 반환
int getSmallIndex() {
	int min = INF;
	int index = 0;

	for (int i = 0; i < number; i++) {
		if (d[i] < min && visited[i] == 0) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}
	visited[start] = 1;
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex();
		visited[current] = 1;
		for (int j = 0; j < number; j++) {
			if (visited[j] == 0) {
				if (d[j] > d[current] + a[current][j]) {
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main() {
	dijkstra(0);

	for (int i = 0; i < number; i++) {
		cout << d[i] << " ";
	}
}
