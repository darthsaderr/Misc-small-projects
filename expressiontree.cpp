//Sadie Jungers
//expression tree
#include<iostream>
#include "trees.h"
#include "stackclass.h"
#include <string>

const int A=5;
const int B=15;

int main(){
	string exp;
	sstack<Node*> qq;
	myTree spruce;
	cout << "Please enter a postfix expression: ";
	cin >> exp;
	exp=exp.c_str();
	int i;
	for(i=0;i<exp.length();i++){
		char s=exp[i];
		if(isalpha(s)){
			qq.push(spruce.makeNode(s));
		} else {///character is operator
			Node *op,*a,*b;
			op=spruce.makeNode(s);
			a=qq.pop();
			b=qq.pop();
			op->left=b;
			op->right=a;
			qq.push(op);
		}
	}
	char tree[A][B];
	int j,k;
	for(j=0;j<A;j++){
		for(k=0;k<B;k++){
			tree[j][k]=' ';
		}
	}
	char x,y,z;
	Node* rt=qq.pop();
	x=spruce.Visit(rt);
	tree[0][7]=x; ////root node
	if(rt->left){/////second tier
		y=spruce.Visit(rt->left);
		tree[1][4]=y;
	} if(rt->right) {
		z=spruce.Visit(rt->right);
		tree[1][10]=z;
	}
	if(rt->right || rt->left){////still second tier
		Node* m=rt->left;
		Node* n=rt->right;
		if(m->left){
			y=spruce.Visit(m->left);
			tree[2][2]=y;
		} if(m->right){
			z=spruce.Visit(m->right);
			tree[2][5]=z;
		} if(n->left){
			y=spruce.Visit(n->left);
			tree[2][8]=y;
		} if(n->right){
			z=spruce.Visit(n->right);
			tree[2][12]=z;
		}
		if(m->left || m->right){///third tier left
			Node* c=m->left;
			Node* d=m->right;
			if(c->left){
				y=spruce.Visit(c->left);
				tree[3][1]=y;
			} if(c->right){
				z=spruce.Visit(c->right);
				tree[3][3]=z;
			} if(d->left){
				y=spruce.Visit(d->left);
				tree[3][4]=y;
			} if(d->right){
				z=spruce.Visit(d->right);
				tree[3][6]=z;
			}
		if(n->left || n->right){///third tier right
			Node* g=n->left;
			Node* h=n->right;
			if(g->left){
				y=spruce.Visit(g->left);
				tree[3][7]=y;
			} if(g->right){
				z=spruce.Visit(g->right);
				tree[3][9]=z;
			} if(h->left){
				y=spruce.Visit(h->left);
				tree[3][11]=y;
			} if(h->right){
				z=spruce.Visit(h->right);
				tree[3][13]=z;
			}
			if(g->left || g->right) {///fourth tier right left
				Node* q=g->left;
				Node* r=g->right;
				if(q->left){
					y=spruce.Visit(q->left);
					tree[4][7]=y;
				} if(q->right){
					z=spruce.Visit(q->right);
					tree[4][8]=z;
				} if(r->left){
					y=spruce.Visit(r->left);
					tree[4][9]=y;
				} if(r->right){
					z=spruce.Visit(r->right);
					tree[4][10]=z;
				}
			}
			if(h->left || h->right){ ///fourth tier right right
				Node* o=h->left;
				Node* p=h->right;
				if(o->left){
					y=spruce.Visit(o->left);
					tree[4][11]=y;
				} if(o->right){
					z=spruce.Visit(o->right);
					tree[4][12]=z;
				} if(p->left){
					y=spruce.Visit(p->left);
					tree[4][13]=y;
				} if(p->right){
					z=spruce.Visit(p->right);
					tree[4][14]=z;
				}
			}
			if(c->left || c->right){
				Node* e=c->left;
				Node* f=c->right;
				if(e->left){
					y=spruce.Visit(e->left);
					tree[4][0]=y;
				} if(e->right){
					z=spruce.Visit(e->right);
					tree[4][1]=z;
				} if(f->left){
					y=spruce.Visit(f->left);
					tree[4][2]=y;
				} if(f->right){
					z=spruce.Visit(f->right);
					tree[4][3]=z;
				}
			}
			if(d->left || d->right){
				Node* u=d->left;
				Node* v=d->right;
				if(u->left){
					y=spruce.Visit(u->left);
					tree[4][4]=y;
				} if(u->right){
					z=spruce.Visit(u->right);
					tree[4][5]=z;
				} if(v->left){
					y=spruce.Visit(v->left);
					tree[4][6]=y;
				} if(v->right){
					z=spruce.Visit(v->right);
					tree[4][7]=z;
				}
			}
		}
	}
	}
	for(j=0;j<A;j++){
		for(k=0;k<B;k++){
			cout << tree[j][k] << " ";
		}
		cout << endl;
	}
	return 0;
}


