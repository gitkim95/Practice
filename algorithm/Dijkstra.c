#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define INF 1000000
#define MAX_VERTICES 100
#define N 6 // 정점의 갯수

// 전역변수
int dist[N];
int	map[N][N] =
{
	{0,2,INF,1,INF,INF},
	{2,0,3,2,INF,INF},
	{INF,3,0,INF,INF,5},
	{1,2,INF,0,1,INF},
	{INF,INF,INF,1,0,2},
	{INF,INF,5,INF,2,0}
};
int	visit[N];

void	INIT_arr(void)
{
	int	i;

	i = 0;
	while (i < N)
	{
		dist[i] = INF;
		visit[i] = FALSE;
		i++;
	}
}

int	FIND_leastdistance(void)
{
	int	i;
	int	min_dist;
	int	min_idx;

	i = 0;
	min_dist = INF;
	min_idx = -1;
	while (i < N)
	{
		if (visit[i] == FALSE && dist[i] < min_dist)
		{
			min_dist = dist[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

void	Dijkstra(void)
{
	int	i;
	int start;
	int	new_node;

	INIT_arr();
	start = 0; // 시작 정점 설정
	visit[start] = TRUE;
	dist[start] = 0;
	i = 0;
	while (i < N)
	{
		dist[i] = map[start][i];
		i++;
	}
	while (1)
	{
		new_node = FIND_leastdistance();
		if (new_node == -1)
			break ;
		visit[new_node] = TRUE;
		i = 0;
		while (i < N)
		{
			if (visit[i] == FALSE && dist[i] > dist[new_node] + map[new_node][i])
				dist[i] = dist[new_node] + map[new_node][i];
			i++;
		}
	}
}

int main() {
    Dijkstra();
    // 결과 출력
    for (int i = 0; i < N; i++) {
        printf("Distance from node 0 to node %d: %d\n", i, dist[i]);
    }
    return 0;
}