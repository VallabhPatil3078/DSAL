#include<bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;

public:
    Node(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    friend class BT;
};

class BT{
    Node* root;

public:
    Node* create(){
        int data;
        cout<<"Enter element: ";
        cin>>data;
        if(data == -1) return NULL;
        else{
            Node* p = new Node(data);

            bool flag;
            cout<<"Do you want to continue(1.Yes/0.No): ";
            cin>>flag;

            if(flag){
                cout<<"Enter value left to "<<data<<endl;
                p->left = create();
                cout<<"Enter value right to "<<data<<endl;
                p->right = create();
            }

            return p;
        }
    }

    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);

        return max(l, r) + 1;
    }

    Node* copyTree(Node* root){
        if(root == NULL) return NULL;
        Node* copy = new Node(root->data);
        copy->left = copyTree(root->left);
        copy->right = copyTree(root->right);
        return copy;
    }

    int internalNodes(Node* root){
        if(root == NULL){
            return 0;
        }

        int l = internalNodes(root->left);
        int r = internalNodes(root->right);

        return l + r + 1;
    }

    int leaves(Node* root){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        else{
            return leaves(root->left) + leaves(root->right);
        }
    }

    void preorder(Node* root){
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            cout<<root->data<<" ";
            if(root->right){
                st.push(root->right);
            }
            if(root->left){
                st.push(root->left);
            }
        }
    }

    void inorder(Node* root){
        stack<Node*> st;
        while(!st.empty() || root != NULL){
            if(root != NULL){
                st.push(root);
                root = root->left;
            }
            else{
                root = st.top();
                st.pop();
                cout<<root->data<<" ";
                root = root->right;
            }
        }
    }

    void postorder(Node* root){
        stack<Node*> st1;
        stack<Node*> st2;
        st1.push(root);
        Node* temp;
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();

            temp = st2.top();
            if(temp->left){
                st1.push(temp->left);
            }
            if(temp->right){
                st1.push(temp->right);
            }
        }

        while(!st2.empty()){
            cout<<st2.top()->data<<" ";
            st2.pop();
        }
    }
};

int main(){

    BT* bt;
    Node* root = bt->create();
    cout<<"Height: "<<bt->height(root)<<endl;
    return 0;
}