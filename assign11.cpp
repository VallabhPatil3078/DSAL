#include<bits/stdc++.h>
#include<fstream>
using namespace std;

class Student{
    int roll_no;
    string name;
    char div;
    string add;

public:
    Student(){
        roll_no = 0;
        name = "";
        div = ' ';
        add = "";
    }
    Student(int r, string n, char d, string a){
        roll_no = r;
        name = n;
        div = d;
        add = a; 
    }

    friend fstream &operator<<(fstream &out1, Student &s);
    friend fstream &operator>>(fstream &in1, Student &s);
    friend ostream &operator<<(ostream &out1, Student &s);

    void display(fstream &in, Student &s){
        in.open("datafile.txt", ios::in);
        while(true){
            in>>s;
            if(in.eof()){
                break;
            }
            cout<<s;
        }
        in.close();
    }
    void search(fstream &in, Student &s, int x){
        in.open("datafile.txt", ios::in);
        while(true){
            in>>s;
            if(s.roll_no == x){
                cout<<s;
                break;
            }
            if(in.eof()){
                cout<<"Record not found"<<endl;
                break;
            }
        }
        in.close();
    }
    void delete1(fstream &in, Student &s, int x, int n){
        Student arr[n];
        in.open("datafile.txt", ios::in);
        for(int i=0;i<n;i++){
            in>>s;
            arr[i] = s;
        }
        in.close();
        in.open("datafile.txt", ios::out | ios::trunc);
        for(int i=0;i<n;i++){
            if(arr[i].roll_no == x){
                continue;
            }
            else{
                in<<arr[i];
                cout<<arr[i];
            }
        }
        in.close();
    }
};

fstream &operator<<(fstream &out1, Student &s){
    out1<<s.roll_no<<" ";
    out1<<s.name<<" ";
    out1<<s.div<<" ";
    out1<<s.add<<" ";
    out1<<endl;
    return out1;
}

fstream &operator>>(fstream &in1, Student &s){
    in1>>s.roll_no;
    in1>>s.name;
    in1>>s.div;
    in1>>s.add;
    return in1;
}

ostream &operator<<(ostream &out1, Student &s){
    out1<<s.roll_no<<" ";
    out1<<s.name<<" ";
    out1<<s.div<<" ";
    out1<<s.add<<" ";
    cout<<endl;
    return out1;
}


int main(){

    Student s1;
    fstream file1;
    int n;
    int c = 1;
    while(c > 0){
        cout<<"MENU"<<endl;
        cout<<"1.Add record to file"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"Enter your choice:";
        cin>>c;
        if(c == 1){
            file1.open("datafile.txt", ios::out);
            cout<<"Enter number of entries: ";
            cin>>n;
            for(int i=0;i<n;i++){
                int roll_no;
                string name;
                char div;
                string add;
                cout<<"Enter roll_no:";
                cin>>roll_no;
                cout<<"Enter name:";
                cin>>name;
                cout<<"Enter division:";
                cin>>div;
                cout<<"Enter address:";
                cin>>add;
                Student s(roll_no, name, div, add);
                file1<<s;
            }
            file1.close();
        }
        else if(c == 2){
            s1.display(file1, s1);
        }
        else if(c==3)
        {
            int x;
            cout<<"Enter the roll no to search:";
            cin>>x;
            s1.search(file1, s1, x);
        }
        else if(c==4)
        {
            int x;
            cout<<"Enter roll no to delete:";
            cin>>x;
            s1.delete1(file1, s1, x, n);
        }
    }
    
    return 0;
}