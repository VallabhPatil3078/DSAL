#include<bits/stdc++.h>
using namespace std;

class Node{
    string key;
    string meaning;
    Node* left;
    Node* right;
    int height;

public:
    Node(){
        key = "";
        meaning = "";
        left = NULL;
        right = NULL;
        height = 0;
    }
    Node(string key, string meaning){
        this->key = key;
        this->meaning = meaning;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
    friend class AVL;
};

class AVL{
public:
    Node* root;

    AVL(){
        root = NULL;
    }

    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        return root->height;
    }

    int getBF(Node* root){
        if(root == NULL){
            return 0;
        }

        return height(root->left) - height(root->right);
    }

    Node* rotateRight(Node* root){
        Node* p = root->left;
        Node* pr = p->right;

        p->right = root;
        root->left = pr;

        root->height = 1 + max(height(root->left), height(root->right));
        p->height = 1 + max(height(p->left), height(p->right));

        return p;
    }

    Node* rotateLeft(Node* root){
        Node* p = root->right;
        Node* pl = p->left;

        p->left = root;
        root->right = pl;

        root->height = 1 + max(height(root->left), height(root->right));
        p->height = 1 + max(height(root->left), height(root->right));

        return p;
    }

    void insert(Node* root, string key, string meaning){
        if(root == NULL){
            root = new Node(key, meaning);
            return;
        }

        if(key < root->key){
            insert(root->left, key, meaning);
        }
        else if(key > root->key){
            insert(root->right, key, meaning);
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int BF = getBF(root);

        // LL
        if(BF > 1 && key < root->left->key){
            root = rotateRight(root);
        }

        // RR
        if(BF < -1 && key > root->right->key){
            root = rotateLeft(root);
        }

        // LR
        if(BF > 1 && key > root->left->key){
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }

        // RL
        if(BF < -1 && key < root->right->key){
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }

    Node* minVal(Node* root){
        Node* temp = root;
        while(temp){
            temp = temp->left;
        }
        return temp;
    }

    void remove(Node* root, string key){
        if(root == NULL){
            return;
        }
        if(key < root->key){
            remove(root->left, key);
        }
        else if(key > root->key){
            remove(root->right, key);
        }
        else{
            if(root->left == NULL || root->right == NULL){
                Node* temp = (root->left != NULL) ? root->left : root->right;

                if(temp == NULL){
                    delete root;
                    root = NULL;
                } 
                else{
                    *root = *temp;
                    delete temp;
                }
            }
            else{
                Node* temp = minVal(root->right);
                root->key = temp->key;
                root->meaning = temp->meaning;
                remove(root->right, temp->key);
            }
        }

        if(root == NULL){
            return;
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int BF = getBF(root);

        // LL
        if(BF > 1 && key < root->left->key){
            root = rotateRight(root);
        }

        // RR
        if(BF < -1 && key > root->right->key){
            root = rotateLeft(root);
        }

        // LR
        if(BF > 1 && key > root->left->key){
            root->left = rotateLeft(root->left);
            root = rotateRight(root);
        }

        // RL
        if(BF < -1 && key < root->right->key){
            root->right = rotateRight(root->right);
            root = rotateLeft(root);
        }
    }
};

int main(){
    
    return 0;
}