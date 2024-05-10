#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertNode(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else{
        root->right = insertNode(root->right, data);
    }
    return root;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftD = diameter(root->left);
    int rightD = diameter(root->right);
    int h = height(root->left) + height(root->right) + 1;

    return max(h, max(leftD, rightD));
}

Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left){
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right){
        temp = temp->right;
    }
    return temp;
}

void swapTree(Node* root){
    Node* temp;
    if(root != NULL){
        swapTree(root->left);
        swapTree(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

bool searchNode(Node* root, int x){
    Node* temp = root;
    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        if(temp->data > x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}

Node* deleteNode(Node* root, int value){
    if(root == NULL){
        return NULL;
    }
    if(root->data == value){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else if(root->data > value){
        root->left = deleteNode(root->left, value);
        return root;
    }
    else{
        root->right = deleteNode(root->right, value);
        return root;
    }
}

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main(){
    
    Node* root = NULL;

    cout<<"Enter root element of BST: ";
    int data;
    cin>>data;
    while(data != -1){
        root = insertNode(root, data);
        cout<<"Enter further elements(-1 to stop): ";
        cin>>data;
    }

    cout<<"levelorder traversal: ";
    levelOrder(root);
    cout<<endl;

    deleteNode(root, 4);

    cout<<"levelorder traversal: ";
    levelOrder(root);
    cout<<endl;

    deleteNode(root, 7);
    cout<<"levelorder traversal: ";
    levelOrder(root);
    cout<<endl;

    return 0;
}