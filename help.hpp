#pragma once
#include <vector>
#include "iostream"
using namespace std;
#define inf 3200
template<typename T>
void print_vector(vector<T> alpha){
    for(int i = 0; i < alpha.size(); i++){
        cout<<alpha[i]<<" ";
    }
}
void print_solution(int** dist, int V){
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (dist[i][j] == 3200) {
                cout << "inf"<<" ";
            }
            else {
                cout << dist[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}
template<typename T>
void print_path(int i, int j, T p)
{
    if (i != j) print_path(i, p[i][j], p);
    cout<<j<<" ";
}