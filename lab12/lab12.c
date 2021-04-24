#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

int calculate_distance(p_graph graph, int *path, int start)
{
  int distance = 0;

  for (int vertex = start; vertex != path[vertex]; vertex = path[vertex])
    distance += get_edge_weight(graph, vertex, path[vertex]); // Add the weight of the edge between the curr vertex and next vertex

  return distance;
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m); // Reads the number of vertexes and edges

  int vertA, vertB, weight;
  int firstVert;
  p_graph graph;

  graph = initialize_graph(n);

  // Build the graph
  for (int edge = 0; edge < m; edge++)
  {
    scanf("%d %d %d", &vertA, &vertB, &weight);
    if (edge == 0)
    {
      firstVert = vertA;
    }

    insert_bidirect_edge(graph, vertA, vertB, weight);
    insert_bidirect_edge(graph, vertB, vertA, weight);
  }

  // Fix those methods
  // I need to find the second smallest path, just need to run dijkstra two times, but the second
  // one needs to be with the removed edges

  int *shortest_path = dijkstra(graph, firstVert);
  int path_to_rs = calculate_distance(graph, shortest_path, vertB);
  printf("%d\n", path_to_rs);

  free(shortest_path);

  destroy_graph(graph);

  return 0;
}