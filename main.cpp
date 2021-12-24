#include "graph.hpp"
#include "hamilton.hpp"
#include "test.hpp"
int main(){
    int zero = 0;
    while(zero != 3){
        cout << endl << "Choose Test:" << endl;
        cout<<"1. Hamilton Path"<<endl<<"2. BFS, DFS and Floys Warshall"<<endl<<"3. Exit"<<endl;
        cin>>zero;
        switch(zero){
            case 1:{
                int vertex;
                int edges;
                cout<<"Input vertexes amount"<<"\n";
                cin>>vertex;
                cout<<"Input edges amount"<<"\n";
                cin>>edges;
                vector<edge<int>> alpha = make_edge<int>(edges);
                help_graph<int> g(alpha, vertex);
                vector<int> path;
                path.push_back(0);

                vector<bool> visited(vertex);
                visited[0] = true;

                cout << "complete graph hamiltonian paths: " << endl;

                hamiltonian_paths(g, 0, visited, path, vertex);
                break;
            }
            case 2:{
                int vertex;
                int edges;
                int bfsing;
                cout<<"Input vertexes amount"<<"\n";
                cin>>vertex;
                cout<<"Input edges amount"<<"\n";
                cin>>edges;
                vector<edge<int>> alpha = make_edge<int>(edges);
                graph<int> g(alpha, vertex);
                cout<<"Input vertex for dfs and bfs"<<"\n";
                cin>>bfsing;
                cout<<"depth first search (DFS) starting from vertex "<<bfsing<<"\n";
                g.dfs(bfsing);
                cout<<"\n";
                cout<<"Breadth first search (BFS) starting from vertex "<<bfsing<<"\n";
                g.bfs(bfsing);
                cout<<"\n";
                int** helpi = new int*[vertex];
                for(int i = 0; i < vertex; i++){
                    helpi[i] = new int[vertex];
                }
                int fw_start;
                int fw_finish;
                cout<<"Floyd Warshall"<<"\n";
                cout<<"Input start vertex"<<"\n";
                cin>>fw_start;
                cout<<"\n";
                cout<<"Input finish vertex"<<"\n";
                cin>>fw_finish;
                cout<<"\n";
                print_solution(g.floyd_warshall(helpi), g.get_amount());

                cout<<"Print path from "<<fw_start<<" to "<<fw_finish<<" with length "<<g.floyd_warshall(helpi)[fw_start][fw_finish]<<":"<<" ";
                print_path(fw_start, fw_finish, helpi);
                break;
            }
            case 3: {
                break;
            }
            default:{
                cout<<"Enter a number from the list"<<"\n";
            }
        }
    }
}