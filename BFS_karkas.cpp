#include <vector>
#include <queue>
#include <iostream>

//Построение каркаса связного графа методом поиска в ширину (помимо матрицы на вход подается вершина, с которой начинать обход)							

using namespace std;

const int n = 4;			// Порядок графа

int M_answer[n][n];			// Матрица смежности полученного какркаса

vector<int> bfs(int a, vector<vector<int>> g, int M[n][n])
{
	vector<int> dist(n, n);
	for (int j = 0; j < dist.size(); j++)
	{
		cout << j << " - " << dist[j] << "; ";
	}
	dist[a] = 0;
	queue<int> q;
	q.push(a);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (int u : g[v])
		{
			if (dist[u] > dist[v] + 1)
			{
				M[v][u] = 1;
				M[u][v] = M[v][u];
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
	return dist;
}

int main()
{
	int M[n][n];			// Матрица смежности
	int a = 1;				// Начальная вершина
	vector<vector<int>> g;	// Список смежности
	g.resize(n + 1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> M[i][j];
			M[j][i] = M[i][j];
			if (M[i][j])
			{
				g[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			M_answer[i][j] = 0;
		}
	}
	vector<int> answer;
	answer = bfs(a, g, M_answer);
	cout << endl;
	for (int j = 0; j < answer.size(); j++)
	{
		cout << j << " - " << answer[j] << "; ";
	}
	cout << '\n' << endl;
	print_matrix(M_answer);
	return 0;
}