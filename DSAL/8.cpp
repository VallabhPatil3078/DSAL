// OBST
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    double p;
    double q;
    Node* left;
    Node* right;

    Node(int key, double p, double q){
        this->key = key;
        this->p = p;
        this->q = q;
        this->left = NULL;
        this->right = NULL;
    }
};

double sum(double arr[], int i, int j){
    double s = 0;
    for(int k=i;k<=j;k++){
        s += arr[i];
    }
    return s;
}

double mincost(double p[], double q[], int keys[], int n){
    double dp[n][n];
    for(int i=0;i<n;i++){
        dp[i][i] = q[i];
    }
    for(int L=2;L<=n;L++){
        for(int i=0;i<n-L+1;i++){
            int j = i+L-1;
            dp[i][j] = INT_MAX;
            for(int r=i;r<=j;r++){
                double cost = ((r == i) ? 0:dp[i][r-1]) +
                              ((r == j) ? 0:dp[r+1][j]) +
                              (p[r] * sum(q, i, j)) +
                              (q[r] * (1 + sum(p, i, j)));
                if(cost < dp[i][j]){
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n-1];
}

Node* buildOBST(double p[], double q[], int keys[], int start, int end){
    int minCost = INT_MAX;
    int minIdx = -1;
    for(int i=start;i<=end;i++){
        double cost = ((i == start) ? 0:mincost(p, q, keys, i-1))+
                      ((i == end) ? 0:mincost(p, q, keys, end-i))+
                      (p[i] * (sum(q, start, end)))+
                      (q[i] * (1 + sum(p, start, end)));
        if(cost < minCost){
            minCost = cost;
            minIdx = i;
        }
    }

    Node* root = new Node(p[minIdx], q[minIdx], keys[minIdx]);
    root->left = buildOBST(p, q, keys, start, minIdx-1);
    root->right = buildOBST(p, q, keys, minIdx+1, end);

    return root;
}

int main(){
    
    return 0;
}