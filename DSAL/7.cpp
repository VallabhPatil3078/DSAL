#include<bits/stdc++.h>
using namespace std;

class Graph{
    int** adjMatrix;
    string* cities;
    int nv;

public:
    Graph(){
        nv = 0;
        adjMatrix = NULL;
        cities = NULL;
    }

    Graph(int nv){
        this->nv = nv;
        cities = new string[nv];
        adjMatrix = new int*[nv];
        for(int i=0;i<nv;i++){
            adjMatrix[i] = new int[nv];
            for(int j=0;j<nv;j++){
                adjMatrix[i][j] = 0;
            }
        }
    }

    int getIndex(string city){
        for(int i=0;i<nv;i++){
            if(cities[i] == city){
                return i;
            }
        }
        return -1;
    }

    void addEdge(int s, int d, int w){
        adjMatrix[s][d] = w;
        adjMatrix[d][s] = w;
    }

    void create(){
        for(int i=0;i<nv;i++){
            cout<<"Enter citiy at index "<<i+1<<": ";
            cin>>cities[i];
        }
        string des;
        int weight;
        for(int i=0;i<nv;i++){
            for(int i=0;i<nv-1;i++){
                cout<<"Add city connected to "<<cities[i]<<": ";
                cin>>des;
                cout<<"Add cost for connection: ";
                cin>>weight;

                int srcId = getIndex(cities[i]);
                int desId = getIndex(des);

                if(srcId == -1 || desId == -1){
                    break;
                }

                addEdge(srcId, desId, weight);
            }
        }
    }

    void display(){
        for(int i=0;i<nv;i++){
            cout<<cities[i]<<" -> ";
            for(int j=0;j<nv;j++){
                cout<<"("<<cities[j]<<", "<<adjMatrix[i][j]<<") ";
            }
            cout<<endl;
        }
    }

    int getMinVal(int key[], bool mst[]){
        int minIdx;
        int minVal = INT_MAX;
        for(int i=0;i<nv;i++){
            if(key[i] < minVal && mst[i] == false){
                minVal = key[i];
                minIdx = i;
            }
        }
        return minIdx;
    }

    void primsAlgo(){
        bool mst[nv];
        int key[nv];
        int parent[nv];
        for(int i=0;i<nv;i++){
            mst[i] = false;
            key[i] = INT_MAX;
        }
        key[0] = 0;
        parent[0] = -1;
        for(int i=0;i<nv-1;i++){
            int u = getMinVal(key, mst);
            mst[u] = true;

            for(int j=0;j<nv;j++){
                if(adjMatrix[u][j] && adjMatrix[u][j] < key[j] && mst[j] == false){
                    key[j] = adjMatrix[u][j];
                    parent[j] = u;
                }
            }
        }

        printMST(parent);
    }

    void printMST(int parent[]){
        int cost = 0;
        for(int i=1;i<nv;i++){
            cost += adjMatrix[i][parent[i]];
        }
        cout<<cost<<endl;
    }
};

int main(){
    
    return 0;
}