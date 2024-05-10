#include<bits/stdc++.h>
using namespace std;

class Node{
    int dest;
    Node* next;

public:
    Node(){
        dest = 0;
        next = NULL;
    }
    Node(int d){
        this->dest = d;
        this->next = NULL;
    }
    friend class Graph;
};

class Graph{
    int nv;
    string* places;
    Node** adjList;

public:
    Graph(){
        nv = 0;
        places = NULL;
        adjList = NULL;
    }

    Graph(int nv){
        this->nv = nv;
        adjList = new Node*[nv];
        for(int i=0;i<nv;i++){
            adjList[i] = nullptr;
        }
        places = new string[nv];
    }

    int getIndex(string place){
        for(int i=0;i<nv;i++){
            if(places[i] == place){
                return i;
            }
        }
        return -1;
    }

    void addEdge(int s, int d){
        Node* temp = new Node(d);
        temp->next = adjList[s];
        adjList[s] = temp;
    }

    void create(){
        for(int i=0;i<nv;i++){
            cout<<"Enter element at index "<<i<<": ";
            cin>>places[i];
        }
        string des;
        for(int i=0;i<nv;i++){
            for(int j=0;j<nv-1;j++){
                cout<<"Enter connection of "<<places[i]<<": ";
                cin>>des;
                int srcId = getIndex(places[i]);
                int desId = getIndex(des);

                if(srcId == -1 || desId == -1){
                    break;
                }

                addEdge(srcId, desId);
            }
        }
    }

    void display(){
        for(int i=0;i<nv;i++){
            Node* temp = adjList[i];
            cout<<places[i]<<" -> ";
            while(temp){
                cout<<places[temp->dest]<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    void bfs(int src){
        bool visited[nv];
        for(int i=0;i<nv;i++){
            visited[i] = false;
        }
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cout<<places[curr]<<" ";

            Node* temp = adjList[curr];
            while(temp){
                int side = temp->dest;
                if(!visited[side]){
                    visited[side] = true;
                    q.push(side);
                }
                temp = temp->next;
            }
        }
        cout<<endl;
    }

    void dfs(int src){
        bool visited[nv];
        for(int i=0;i<nv;i++){
            visited[i] = false;
        }
        stack<int> st;
        st.push(src);
        visited[src] = true;
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            cout<<places[curr]<<" ";

            Node* temp = adjList[curr];

            while(temp){
                int side = temp->dest;
                if(!visited[side]){
                    visited[side] = true;
                    st.push(side);
                }
                temp = temp->next;
            }
        }
        cout<<endl;
    }
};

int main(){
    
    int nv;
    cout<<"Enter no of vertices: ";
    cin>>nv;

    Graph* g = new Graph(nv);

    g->create();
    cout<<endl;
    g->display();
    cout<<endl;

    int srcId = g->getIndex("a");
    g->bfs(srcId);
    g->dfs(srcId);

    return 0;
}