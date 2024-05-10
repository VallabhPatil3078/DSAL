#include<bits/stdc++.h>
using namespace std;
#define size 10

class Contact{
    string name;
    long int number;

public:
    Contact(){
        name = "";
        number = 0;
    }

    Contact(string name, long int number){
        this->name = name;
        this->number = number;
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

    int hashFunction(long int key){
        int hash = 0;

        while(key != 0){
            hash += key % 10;
            key /= 10;
        }

        cout << key << " : " << hash;
        return (hash % size);
    }

    void insert_without_replacement(string name, long int number){
        int hash = hashFunction(number);

        while(clients[hash].name != "" && clients[hash].name != name){
            hash = (hash + 1) % size;
        }

        clients[hash].name = name;
        clients[hash].number = number;
        cout<<"Inserted!!"<<endl;
    }

    void insert_with_replacement(string name, long int number){
        int hash = hashFunction(number);

        while(clients[hash].name != "" && clients[hash].name != name){
            int prev = hashFunction(clients[hash].number);

            if(prev != hash){
                string pname = clients[hash].name;
                long int pnumber = clients[hash].number;

                clients[hash].name = name;
                clients[hash].number = number;

                name = pname;
                number = pnumber;
            }

            hash = (hash + 1) % size;

        }

        clients[hash].name = name;
        clients[hash].number = number;
        cout<<"Inserted!!!"<<endl;
    }

    void search(long int number){
        
        int count = 0;

        int hash = hashFunction(number);

        for(int i=0;i<size;i++){
            count++;

            if(clients[hash].number = number){
                cout<<"Contact found and required comparsions are: "<<count<<endl;
                cout<<"Name: "<<clients[hash].name<<endl;
                cout<<"Number: "<<clients[hash].number<<endl;
                return;
            }

            hash = (hash + 1) % size;
        }

        cout<<"Data not found!!!"<<endl;

    }

    void remove(long int number){
        int hash = hashFunction(number);

        for(int i=0;i<size;i++){
            if(clients[hash].number == number){
                clients[hash].name = "";
                clients[hash].number = 0;
                cout<<"Data removed successfully"<<endl;
            }
            hash = (hash + 1) % size;
        }

        cout<<"Data not found"<<endl;
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<i<<"."<<clients[i].name<<" : "<<clients[i].number<<endl;
        }
    }
};

int main(){

    Hashmap* hmp = new Hashmap();

    bool flag = true;

    while (flag)
    {

        cout << "1. Insert Data without replacement" << endl;
        cout << "2. Insert With Replacement" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Remove all contacts" << endl;
        cout << "5. Display all contacts" << endl;
        cout << "6. Exit..." << endl;

        string name = "";
        long int number = 0;

        int ch;
        cout << "Enter Yor choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout << "\nInsert without Replacement " << endl;
            cout << "\nEnter name: ";
            cin >> name;
            cout << "\nEnter number: ";
            cin >> number;
            hmp->insert_without_replacement(name, number);
            break;
        }
        case 2:
        {
            cout << "\nInsert with Replacement " << endl;
            cout << "\nEnter name: ";
            cin >> name;
            cout << "\nEnter number: ";
            cin >> number;
            hmp->insert_with_replacement(name, number);
            break;
        }
        case 3:
        {
            cout << "\nSearch for a contact " << endl;
            cout << "\nEnter number to search: ";
            cin >> number;
            hmp->search(number);
            break;
        }
        case 4:
        {
            cout << "\n Delete for a contact " << endl;
            cout << "\nEnter number to delete: ";
            cin >> number;
            hmp->remove(number);
            break;
        }
        case 5:
        {
            cout << "\t\t## Contacts ##" << endl;
            hmp->print();
            break;
        }
        case 6:
        {
            cout << "Exiting...." << endl;
            flag = false;
            break;
        }
        default:
        {
            cout << "Wrong Input!!!" << endl;
            break;
        }
        }
    }
    
    return 0;
}