#include <vector>
#include <algorithm>
bool graph[5][5];
std::vector<int> graph2[5];

bool isAdjacent(int** graph, int v1, int v2)
{
	if (graph[v1][v2] || graph[v2][v1])
		return true;
	else
		return false;
}

bool isAdjacent(std::vector<int>* graph, int v1, int v2)
{
	if (graph[v1].end() != std::find(graph2[v1].begin(), graph2[v1].end(), v2))
	{
		return true;
	}
	if (graph[v2].end() != std::find(graph2[v2].begin(), graph2[v2].end(), v1))
	{
		return true;
	}
}

int CountIndegree(int** graph, int vertex)
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (graph[i][vertex])
		{
			count++;
		}
	}
	return count;
}

int CountIndegree(std::vector<int>* graph, int vertex)
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (graph[i].end() != std::find(graph[i].begin(), graph[i].end(), vertex))
		{
			count++;
		}
	}
	return count;
}
int main()
{

}