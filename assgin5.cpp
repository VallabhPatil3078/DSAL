#include<bits/stdc++.h>
using namespace std;
#define size 10

class Node{

public:

    string word;
    string meaning;
    Node* next;

    Node(){
        word = "";
        meaning = "";
        next = NULL;
    }

    Node(string word, string meaning){
        this->word = word;
        this->meaning = meaning;
        this->next = NULL;
    }

    friend class HashMap;

};

class HashMap{

    Node* dict[size];

public:

    HashMap(){
        for(int i=0;i<size;i++){
            dict[i] = NULL;
        }
    }

    int hashFunction(string word){
        int hash = 0;

        for(char ch : word){
            hash += (int)ch;
        }

        return hash % size;
    }

    void insert(string word, string meaning){

        int hash = hashFunction(word);
        Node* temp = new Node(word, meaning);

        if(dict[hash] == NULL){
            dict[hash] = temp;
            cout<<"Inserted successfully"<<endl;
        }
        else{
            Node* curr = dict[hash];
            while(curr->next){
                curr = curr->next;
            }
            curr->next = temp;
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            Node* temp = dict[i];
            cout<<i<<" -> ";
            while(temp){
                cout<<temp->word<<" ";
                temp = temp->next;
            } 
            cout<<endl;
        }
    }

    void search(string word){

        int hash = hashFunction(word);

        Node* temp = dict[hash];
        if(temp->word == word){
            cout<<"Data found"<<endl;
            cout<<temp->word<<" = "<<temp->meaning<<endl;
        }
        else{
            while(temp){
                if(temp->word == word){
                    cout<<"Data found"<<endl;
                    cout<<temp->word<<" = "<<temp->meaning<<endl;
                }
                temp = temp->next;
            }
        }
    }

    void update(string word){

        int hash = hashFunction(word);
        string new_meaning;
        Node* temp = dict[hash];

        if(dict[hash]->word == word){
            cout<<"Enter new meaning: ";
            cin>>new_meaning;
            dict[hash]->meaning = new_meaning;
        }
        else{
            while(temp){
                if(temp->word == word){
                    cout<<"Enter new meaning: ";
                    cin>>new_meaning;
                    temp->meaning = new_meaning;
                }
                temp = temp->next;
            }
        }
    }

    void deleteWord(string word){

        int hash = hashFunction(word);
        Node* curr = dict[hash];
        Node* prev = curr;

        while(curr){
            if(curr->word == word){
                if(curr == prev){
                    dict[hash] = curr->next;
                }
                else{
                    prev->next = curr->next;
                }
                return;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }

        cout<<"Data not found"<<endl;

    }
};

int main(){
    cout << "Seperate Hashing" << endl; // prints Hashing
    bool flag = true;

    string word, meaning = "";

    HashMap *hmp = new HashMap();

    while (flag)
    {
        int ch;
        cout
            << "\n1. Add Word\n2.Print Dictionary\n3.Search Word\n4.Update Word\n5.Delete Word\n6.exit"
            << endl;
        cout << "\nEnter Your Choice: " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter Word: ";
            cin >> word;
            cout << "Enter Meaning: ";
            cin >> meaning;

            hmp->insert(word, meaning);
            break;
        case 2:
            cout << "Dictionary " << endl;
            hmp->print();
            break;
        case 3:
            cout << "Search " << endl;
            cout << "Enter a word to search: ";
            cin >> word;
            hmp->search(word);
            break;
        case 4:
            cout << "Update" << endl;
            cout << "Enter a word to update: ";
            cin >> word;
            hmp->update(word);
            break;
        case 5:
            cout << "Delete" << endl;
            cout << "Enter a word to delete: ";
            cin >> word;
            hmp->deleteWord(word);
            break;
        case 6:
            cout << "Exit..." << endl;
            flag = false;
            break;
        }
    }
    
    return 0;
}