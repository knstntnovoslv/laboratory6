#pragma once
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include "help.hpp"
#define inf 3200
using namespace std;
template<typename T>
struct edge{
    int start;
    int finish;
    T distance;
};
template<typename T>
class graph{
private:
    list<int>* adjency;
    int amount; // количество вершин
    T** distances;
public:
    graph(int v, T** data){
        amount =  v;
        adjency = new list<int>[v];
        distances = new T*[amount];
        for(int i = 0; i < amount; i++){
            distances[i] = new T[amount];
        }
        for(int i = 0; i < amount; i++){
            for(int j = 0; j < amount; j++){
                distances[i][j] = data[i][j];
            }
        }
    };
    graph(vector<edge<T>> edges, int vertex_amount){
        amount = vertex_amount;
        distances =  new T*[amount];
        for(int i = 0; i < amount; i++){
            distances[i] = new T[amount];
        }
        for(int i = 0; i < amount; i++){
            for(int j = 0; j < amount; j++){
                distances[i][j] = inf;
            }
        }
        adjency = new list<int>[amount];
        for(int i = 0; i < edges.size(); ++i){
            int first = edges[i].start;
            int second = edges[i].finish;
            int dist = edges[i].distance;
            adjency[first].push_back(second);
            distances[first][second] = dist;
        }
    }
    void add_edge(int first, int last){
        adjency[first].push_back(last);
    }
    int get_amount(){
        return amount;
    }
    list<int> get_adj(int index){
        if(index < amount) {
            return adjency[index];
        }
    }
    void bfs(int s) {
        bool *visited = new bool[amount];
        for (int i=0; i < amount; ++i) {visited[i] = false;}

        queue<int> queue;

        visited[s] = true;
        queue.push(s);

        list<int>::iterator i;

        while(!queue.empty())
        {
            s = queue.front();
            cout << s << " ";
            queue.pop();


            //queue all adjacent nodes of s if not visited
            for (i=adjency[s].begin(); i!=adjency[s].end(); ++i)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push(*i);
                }
            }

        }
    }

    void dfs_util(int v, bool visited[]){
        visited[v] = true;
        cout << v << " ";

        list<int>::iterator i;
        for (i = adjency[v].begin(); i != adjency[v].end(); ++i)
        {
            if (!visited[*i])
                dfs_util(*i, visited);
        }
    }
    void dfs(int v){
        bool *visited = new bool[amount];
        for (int i=0; i < amount; ++i)
        {
            visited[i] = false;
        }
        dfs_util(v, visited);
    }
    int** floyd_warshall(int** parent){
        int** dist = new int*[amount];
        for(int i = 0; i < amount; i++){
            dist[i] = new int[amount];
        }
        for(int i = 0; i < amount; i++){
            for(int j = 0; j < amount; j++){
                dist[i][j] = distances[i][j];
                parent[i][j] = i;
            }
        }
        for (int k = 0; k < amount; ++k)
        {

            for (int i = 0; i < amount; ++i)
            {

                for (int j = 0; j < amount; ++j)
                {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }
        return dist;
    }

};
