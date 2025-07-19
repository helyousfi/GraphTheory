#include "pch.h"
#include "articulation_points.hpp"

#undef min

namespace GraphLibrary {

	ArticulationPointFinder::ArticulationPointFinder(Graph* p_graph) :
		graph(p_graph), numVertices(p_graph->getNumVertices()), idCounter(0), outEdgeCount(0)
	{
		ids = std::vector<int>(numVertices, 0);
		lows = std::vector<int>(numVertices, 0);
		visited = std::vector<bool>(numVertices, false);
		isArticulation = std::vector<bool>(numVertices, false);
	}

	std::vector<int> ArticulationPointFinder::findArticulationPoints()
	{
		for (int i = 0; i < numVertices; i++)
		{
			if (!visited[i])
			{
				outEdgeCount = 0;
				DFSUtil(i, i, -1);
				if (outEdgeCount > 1)
					isArticulation[i] = true;
			}
		}

		std::vector<int> articulationPoints;
		for (int i = 0; i < numVertices; ++i)
		{
			if (isArticulation[i])
				articulationPoints.push_back(i);
		}
		return articulationPoints;
	}

	void ArticulationPointFinder::DFSUtil(int root, int at, int parent)
	{
		if (parent == root)
			outEdgeCount++;

		visited[at] = true;
		ids[at] = lows[at] = ++idCounter;

		auto matrix = graph->getMatrix();
		for (int to = 0; to < numVertices; ++to)
		{
			if (matrix[at][to] != 0)
			{
				if (to == parent)
					continue;

				if (!visited[to])
				{
					DFSUtil(root, to, at);

					// Correctly update low-link value of `at` using child's low
					lows[at] = std::min(lows[at], lows[to]);

					// Articulation point condition for non-root
					if (ids[at] <= lows[to] && parent != root)
						isArticulation[at] = true;
				}
				else
				{
					// Back edge
					lows[at] = std::min(lows[at], ids[to]);
				}
			}
		}
	}
}
