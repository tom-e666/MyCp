#include<bits/stdc++.h>
using namespace std;
//making a tree
//iteration
struct node{
	int val;
	node *child_left, *child_right;
	node(int v){
		val=v;
		child_left=NULL;
		child_right=NULL;
	}
	void update(int v){
		val=v;
	}

};
std::vector<int> res;
void level_ruled_traversal(node* head) {
    if (head == NULL) return;
    queue<node*> q;
    q.push(head);
    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        res.emplace_back(current->val);
        if (current->child_left != NULL) q.push(current->child_left);
        if (current->child_right != NULL) q.push(current->child_right);
    }
}
int main(){
	auto head=new node(1);
	auto p=head;
	p->child_left=new node(2);
	p->child_right=new node(3);
	p->child_left->child_left=new node(4);
	p->child_left->child_right=new node(5);
	level_ruled_traversal(head);
	for(auto &i:res) cout<<i<<" ";
}