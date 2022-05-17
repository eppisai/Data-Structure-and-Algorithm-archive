#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int val = 0;
	vector<node*> vec;
};

bool goaltest(node* n,int goal){
	if(n->val == goal)return true;
	else return false;	
}

void construct(node* n,queue<node*>& closed){
	closed.push(n);
}

void removeseen(queue<node*>& open,queue<node*> closed){
	set<node*> st;
	while(!closed.empty()){
		node* val = closed.front();
		closed.pop();
		st.insert(val);
	}
	queue<node*> temp = open;
	while(!open.empty()){
		open.pop();
	}
	while(!temp.empty()){
		node* val = temp.front();
		if(st.find(val) == st.end()){
			open.push(val);
		}
		temp.pop();
	}
}

void append(queue<node*>& open,node* n){
	for(auto i : n->vec){
		open.push(i);
	}
}

queue<node*> breadthfirstsearch(node* first,int val){
	node* start = first;
	queue<node*> open;
	queue<node*> closed;
	open.push(start);
	queue<node*> em;
	while(!open.empty()){
		node* temp = open.front();
		if(goaltest(temp,val)){
			return closed;
		}
		open.pop();
		construct(temp,closed);
		append(open,temp);
		removeseen(open,closed);
	}
	return em;
}

void solve(){
	node* a = new node();
	node* b = new node();
	node* c = new node();
	node* d = new node();
	node* e = new node();
	node* f = new node();
	node* g = new node();
	node* h = new node();
	node* i = new node();
	node* j = new node();
	node* k = new node();
	node* l = new node();
	node* m = new node();
	node* n = new node();
	node* o = new node();
	node* p = new node();
	node* q = new node();
	node* r = new node();
	node* s = new node();
	node* t = new node();
	a->val = 1;
	b->val = 2;
	c->val = 3;
	d->val = 4;
	e->val = 5;
	f->val = 6;
	g->val = 7;
	h->val = 8;
	i->val = 9;
	j->val = 10;
	k->val = 11;
	l->val = 12;
	m->val = 13;
	n->val = 14;
	o->val = 15;
	p->val = 16;
	q->val = 17;
	r->val = 18;
	s->val = 19;
	t->val = 20;
	q->vec.push_back(r);
	q->vec.push_back(s);
	q->vec.push_back(t);
	n->vec.push_back(o);
	n->vec.push_back(p);
	m->vec.push_back(q);
	m->vec.push_back(n);
	j->vec.push_back(k);
	j->vec.push_back(l);
	i->vec.push_back(m);
	i->vec.push_back(j);
	e->vec.push_back(f);
	e->vec.push_back(g);
	e->vec.push_back(h);
	c->vec.push_back(d);
	c->vec.push_back(e);
	a->vec.push_back(b);
	a->vec.push_back(c);
	a->vec.push_back(i);
	int goal = 6768;
	queue<node*> ans;
	ans = breadthfirstsearch(a,goal);
	if(ans.empty())cout<<"value does not exist";
	while(!ans.empty()){
		node* temp = ans.front();
		cout<<temp->val<<" ";
		ans.pop();
	}
}

int main(){
    solve()
    return 0;

}