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

    friend class BinaryTree;

};

class BinaryTree{

    Node* root;

public:

    Node* create(){
        int data;
        cout<<"Enter data(-1 for no data): ";
        cin>>data;

        if(data == -1){
            return NULL;
        }
        else{
            Node* p = new Node(data);

            bool flag;
            cout<<"Do you want to continue(1.Yes/0.No): ";
            cin>>flag;
            if(flag){
                cout<<"Enter the left value of "<<data<<": "<<endl;
                p->left = create();
                cout<<"Enter the right value of "<<data<<": "<<endl;
                p->right = create();
            }

            return p;
        }
    }

    void recInorder(Node* root){
        if(root == NULL){
            return;
        }
        recInorder(root->left);
        cout<<root->data<<" ";
        recInorder(root->right);
    }

    void recPreorder(Node* root){
        if(root == NULL){
            return;
        }
        cout<<root->data<<" ";
        recPreorder(root->left);
        recPreorder(root->right);
    }

    void recPostorder(Node* root){
        if(root == NULL){
            return;
        }
        recPostorder(root->left);
        recPostorder(root->right);
        cout<<root->data<<" ";
    }

    void itrInorder(Node* root){
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

    void itrPreorder(Node* root){
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

    void itrPostorder(Node* root){
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

    void swap(Node* root){
        Node* temp;
        if(root != NULL){
            swap(root->left);
            swap(root->right);

            temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
    }

    int height(Node* root){
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);

        return max(left, right) + 1;
    }

    Node* copyTree(Node* root){
        if(root == NULL){
            return NULL;
        }
        Node* copy = new Node(root->data);
        copy->left = copyTree(root->left);
        copy->right = copyTree(root->right);
        return copy;
    }

    int internalNodes(Node* root){
        if(root == NULL){
            return 0;
        }
        int left = internalNodes(root->left);
        int right = internalNodes(root->right);

        return left + right + 1;
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

    void deleteTree(Node* root){
        if(root != NULL){
            deleteTree(root->left);
            deleteTree(root->right);

            cout<<"Deleted node is: "<<root->data<<endl;
            delete root;
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
};

int main(){
    // 5 1 6 1 7 0 -1 1 1 8 0 9 0
    BinaryTree* BT;
    Node* root = BT->create();

    while(true){
        int choice;
        cout<<"\n1.Preorder Traversal(recurrsive/iterative)"<<endl;
        cout<<"2.Inorder Traversal(recurrsive/iterative)"<<endl;
        cout<<"3.Postorder Traversal(recurrsive/iterative)"<<endl;
        cout<<"4.Swap the tree"<<endl;
        cout<<"5.Calculate height of tree"<<endl;
        cout<<"6.Copy tree"<<endl;
        cout<<"7.Find total no of internal nodes in the tree"<<endl;
        cout<<"8.Find leaf nodes in the tree"<<endl;
        cout<<"9.Delete the tree"<<endl;
        cout<<"11.Level order traversal"<<endl;
        cout<<"10.exit\n"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;

        if(choice == 1){
            cout<<"Preorder(recurrsively): ";
            BT->recPreorder(root);
            cout<<endl;
            cout<<"Preorder(iteratively): ";
            BT->itrPreorder(root);
        }
        else if(choice == 2){
            cout<<"Inorder(recurrsively): ";
            BT->recInorder(root);
            cout<<endl;
            cout<<"Inorder(iteratively): ";
            BT->itrInorder(root);
        }
        else if(choice == 3){
            cout<<"Postorder(recurrsively): ";
            BT->recPostorder(root);
            cout<<endl;
            cout<<"Postorder(iteratively): ";
            BT->itrPostorder(root);
        }
        else if(choice == 4){
            cout<<"Tree has been successfully swapped"<<endl;
            BT->swap(root);
        }
        else if(choice == 5){
            cout<<"Height of tree: "<<BT->height(root)<<endl;
        }
        else if(choice == 6){
            Node* copied = BT->copyTree(root);
            cout<<"Tree has been successfully copied in the root (copied)"<<endl;
        }
        else if(choice == 7){
            cout<<"Internal nodes are: "<<BT->internalNodes(root)<<endl;
        }
        else if(choice == 8){
            cout<<"Leaf nodes are: "<<BT->leaves(root)<<endl;
        }
        else if(choice == 9){
            BT->deleteTree(root);
            cout<<"Tree has been successfully deleted"<<endl;
        }
        else if(choice == 10){
            break;
        }
        else if(choice == 11){
            cout<<"Level order traversal: ";
            BT->levelOrder(root);
        }
    }

    return 0;
}