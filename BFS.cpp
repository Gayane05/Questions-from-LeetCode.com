#include <iostream>
#include <list>
#include <queue>
// Basic BFS implementation in C++ for ints.

class Graph
{
private:
	int vertices;

	// vector element will be the node, and in list will be vertices adjacent to him/neighbours.
	std::vector<std::list<int>> adjacentVertices;

public:
	Graph(int n) :vertices(n) 
	{
		adjacentVertices.resize(vertices);
	};

	void addEdge(int edge, int to)
	{
		adjacentVertices[edge].push_back(to);
	}

	// Do traversal starting from the root edge.
	void BFS(int root)
	{
		// Keep bool vector for checking if the vertice also visited.
		std::vector<bool> visited(vertices, false);

		// Queue for processed and adjacent vertices.
		std::list<int> queue;

		int currentVertice = root;

		// Check the root as visited.
		visited[currentVertice] = true;

		// Nor currentVertices adjacent nodes must be visited.
		queue.push_back(currentVertice);

		while (!queue.empty())
		{
			currentVertice = queue.front();
			// Deque node.
			queue.pop_front();

			// Go through node's adjacent vertices and if they are not visited yet, enqueue them in queue
			// for further processing.
			for (auto i : adjacentVertices[currentVertice])
			{
				if (!visited[i])
				{
					queue.push_back(i);
					visited[i] = true;
				}
			}
		}
	}

	// Find the shortest path from root edge to taget vertice and return it.
	int BFS(int root, int target)
	{
		// How many steps are done to target node.
		int steps = 0;
		std::vector<bool> visited(vertices, false);
		std::list<int> queue;

		int currentVertice = root;
		visited[currentVertice] = true;

		queue.push_back(currentVertice);

		while (!queue.empty())
		{
			currentVertice = queue.front();
			queue.pop_front();
			steps++;

			for (auto i : adjacentVertices[currentVertice])
			{
				if (i == target)
				{
					return steps;
				}
 				if (!visited[i])
				{
					queue.push_back(i);
					visited[i] = true;
				}
			}
		}
		return -1;
	}

};


int main()
{

	Graph g(6);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(0, 3);

	// Connections for vertex 1
	g.addEdge(1, 3);
	g.addEdge(1, 4);

	// Connections for vertex 2
	g.addEdge(2, 0);
	g.addEdge(2, 4);

	// Connections for vertex 3
	g.addEdge(3, 1);
	g.addEdge(3, 4);
	g.addEdge(3, 5);

	// Connections for vertex 4
	g.addEdge(4, 1);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(4, 5);

	// Connections for vertex 5
	g.addEdge(5, 3);
	g.addEdge(5, 4);
	
	// Perform BFS and print result
	g.BFS(2);

	g.BFS(0,4);

	return 0;
}