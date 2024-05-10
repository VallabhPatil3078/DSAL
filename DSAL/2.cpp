#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

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
};

Node* insert(Node* root, int data){
    if(root == NULL){
        return new Node(data);
    }
    if(root->data > data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

bool searchNode(Node* root, int x){
    Node* temp = root;
    while(temp != NULL){
        if(temp->data > x){
            temp = temp->left;
        }
        else if(temp->data < x){
            temp = temp->right;
        }
        else{
            return true;
        }
    }
    return false;
}

Node* deleteNode(Node* root, int x){
    if(x > root->data){
        root->right = deleteNode(root->right, x);
        return root;
    }
    else if(x < root->data){
        root->left = deleteNode(root->left, x);
        return root;
    }
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
    }
}

int main(){
    
    return 0;
}