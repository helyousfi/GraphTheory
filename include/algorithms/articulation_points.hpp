#pragma once
#ifndef ARTICULATION_POINTS_FINDER
#define ARTICULATION_POINTS_FINDER

#include <iostream>
#include <vector>
#include "adjacency_list_graph.hpp"

// Define DLL export/import macro
#ifdef GRAPH_LIBRARY_EXPORTS
#define GRAPH_LIBRARY_API __declspec(dllexport)
#else
#define GRAPH_LIBRARY_API __declspec(dllimport)
#endif

namespace GraphLibrary {
	class GRAPH_LIBRARY_API ArticulationPointFinder {
		public : 
			ArticulationPointFinder(Graph* graph);
			
			std::vector<int> findArticulationPoints();
		private:
			Graph* graph;
			int numVertices;
			int outEdgeCount;
			std::vector<int> ids;
			std::vector<int> lows;
			std::vector<bool> visited;
			std::vector<bool> isArticulation;
			int idCounter;

			void DFSUtil(int root,
				int at,
				int parent);
	};
}

#endif // !ARTICULATION_POINTS_FINDER
