#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	vector<Node *> child;
	Node(int val){
		data=val;
	}
};

void makeTree(Node * root){
	cout<<root->data<<endl;
	int nodes;cout<<"Enter no of childs of this node:- ";cin>>nodes;

	for(int i=0;i<nodes;i++){
		int newVal;cin>>newVal;
		Node * t=new Node(newVal);
		root->child.push_back(t);
	}

	int curr_size=root->child.size();
	for(int i=0;i<curr_size;i++){
		makeTree(root->child[i]);	
	}
}
bool dfs(Node * root,int find){
	cout<<root->data<<" ";
	if(root->data==find)return true;

	for(Node * t :root->child){
		if(dfs(t,find))return true;
	}

	return false;
}

void bfs(Node * root,int find){
	queue<Node *>q;
	q.push(root);
	while(!q.empty()){
		int n=q.size();
		for(int i=0;i<n;i++){
			Node *newNode=q.front();q.pop();
			cout<<newNode->data<<" ";
			if(newNode->data==find)return;
			for(Node *t:newNode->child){
				q.push(t);
			}
		}
	}

}

void printTree(Node * root){
	queue<Node *>q;
	q.push(root);
	while(!q.empty()){
		int n=q.size();
		for(int i=0;i<n;i++){
			Node *newNode=q.front();q.pop();
			cout<<newNode->data<<" ";
			for(Node *t:newNode->child){
				q.push(t);
			}
		}
		cout<<endl;
	}

}
int main() {
	// Your code goes here;
	cout<<"Take input for the tree in level wise order:- ";
	cout<<"Enter the root->data ";
	int rootData;cin>>rootData;
	Node * root=new Node(rootData);

	makeTree(root);
	cout<<"Enter your choice:-  \n1.Print Tree \n 2.DFS  \n3.BFS \n4.Exit\n";
	while(1){
		int n;
		cout<<"Enter your choice:- ";cin>>n;
		if(n==1){
			printTree(root);
		}else{
			cout<<"Enter the value you want to find :- ";
			int find;cin>>find;
			if(n==2){
				dfs(root,find);cout<<endl;
			}
			else if(n==3){
				bfs(root,find);cout<<endl;
			}else{
				break;
			}
		}
	}
	return 0;
}