#pragma once
#include "graph.hpp"
template<typename T>
vector<edge<T>> make_edge(int edge_amount){
    vector<edge<T>> edges;
    for(int i = 0; i < edge_amount; i++){
        edge<T> med;
        int start;
        int finish;
        int distance;
        cout<<"Add information about edge "<<i<<"\n";
        cout<<"Enter start vertex"<<"\n";
        cin>>start;

        cout<<"Enter finish vertex"<<"\n";
        cin>>finish;

        cout<<"Enter length of edge"<<"\n";
        cin>>distance;

        med.start = start;
        med.finish = finish;
        med. distance = distance;

        edges.push_back(med);
    }
    return edges;
}
