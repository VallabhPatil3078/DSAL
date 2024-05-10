#include<bits/stdc++.h>
using namespace std;

#define size 10

class Contact{
    string name;
    long int no;

public:

    Contact(){
        name = "";
        no = 0;
    }

    Contact(string name, long int no){
        this->name = name;
        this->no = no;
    }

    friend class Hashmap;
};

class Hashmap{
    Contact* clients;

public: 

    Hashmap(){
        clients = new Contact[size];
        for(int i=0;i<size;i++){
            clients[i] = Contact();
        }
    }

    int getHash(long int n){
        int hash = 0;
        while(n){
            hash += n % 10;
            n /= 10;
        }
        return hash % size;
    }

    void insertR(string name, long int no){
        int hash = getHash(no);
        while(clients[hash].name != "" && clients[hash].name != name){
            hash = (hash+1) % size;
        }
        clients[hash].name = name;
        clients[hash].no = no;
    }

    void insertWR(string name, long int no){
        int hash = getHash(no);
        int prev = getHash(clients[hash].no);

        while(clients[hash].name != "" && clients[hash].name != name){
            if(prev != hash){
                string pname = clients[hash].name;
                long int pno = clients[hash].no;

                clients[hash].name = name;
                clients[hash].no = no;

                name = pname;
                no = pno;
            }
            hash = (hash + 1) % size;
        }

        clients[hash].name = name;
        clients[hash].no = no;
    }

    void search(long int no){
        int hash = getHash(no);
        int cnt = 0;
        for(int i=0;i<size;i++){
            cnt++;
            if(clients[hash].no == no){
                return;
            }
            hash = (hash + 1) % size;
        }
    }

    void remove(long int no){
        int hash = getHash(no);
        for(int i=0;i<size;i++){
            if(clients[hash].no == no){
                clients[hash].name = "";
                clients[hash].no = 0;
                return;
            }
            hash = (hash + 1) % size;
        }
    }

};

int main(){

    Hashmap* hmp = new Hashmap();
    
    return 0;
}