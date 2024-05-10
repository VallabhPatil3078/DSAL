#include<bits/stdc++.h>
#define size 10
using namespace std;

class Node{
    string key;
    string meaning;
    Node* next;

public:
    Node(string key, string meaning){
        this->key = key;
        this->meaning = meaning;
        this->next = NULL;
    }

    friend class Hashmap;
};

class Hashmap{
    Node* Dict[size];

public:
    Hashmap(){
        for(int i=0;i<size;i++){
            Dict[i] = NULL;
        }
    }

    int getHash(string key){
        int hash = 0;
        for(char ch : key){
            hash += ch;
        }
        return hash % size;
    }

    void insert(string key, string meaning){
        Node* new_node = new Node(key, meaning);
        int hash = getHash(key);
        if(Dict[hash] == NULL){
            Dict[hash] = new_node;
            cout<<"Inserted"<<endl;
        }
        else{
            Node* temp = Dict[hash];
            while(temp->next){
                temp = temp->next;
            }
            temp->next = new_node;            
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            Node* temp = Dict[i];
            cout<<i<<" -> ";
            while(temp){
                cout<<temp->key<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    void search(string key){
        int hash = getHash(key);
        Node* temp = Dict[hash];
        while(temp->key != key && temp != NULL){
            temp = temp->next;
        }
        
    }
};

int main(){
    
    return 0;
}