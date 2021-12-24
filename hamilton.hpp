#pragma once
#include "graph.hpp"
using namespace std;
template<typename T>
class help_graph{
public:
    vector<int> *adj_list;

    help_graph(vector<edge<T>> const &edges, int N)
    {
        adj_list = new vector<int>[N];

        for (int i = 0; i < (int) edges.size(); ++i)
        {
            int start = edges[i].start;
            int finish = edges[i].finish;
            adj_list[start].push_back(finish);
            adj_list[finish].push_back(start);
        }
    }
};
template<typename T>
void hamiltonian_paths(help_graph<T> const& g, int start, vector<bool> visited,
                       vector<int> &path, int vertexes_amount)
{
    if ((int) path.size() == vertexes_amount)
    {
        //print hamiltonian path
        for (int i : path) {cout << i << " ";}
        cout << endl;
        return;
    }

    //check if every edge starting from vertex v leads to
    //a solution or not
    for (int w : g.adj_list[start])
    {
        //process only unvisited vertices as Hamiltonian
        //path visits each vertex exactly once
        if (!visited[w])
        {
            visited[w] = true;
            path.push_back(w);

            //check if adding vertex w to the path leads
            //to a solution or not
            hamiltonian_paths(g, w, visited, path, vertexes_amount);

            //backtrack
            visited[w] = false;
            path.pop_back();

        }
    }
}
