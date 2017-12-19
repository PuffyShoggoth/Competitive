#include <cstdio>
#include <cstdlib>
using namespace std;
struct node {
	node *par, *rl[2];
	int ch, val, qt;
};
 
node *root=nullptr;
void rot(node *cn, int dr){
	
	node *P = cn->par;
	node *C = cn->rl[dr^1];
	if (P->par){
		if (((P->par)->rl[0])==P){
			(P->par)->rl[0]=cn;
		}
		else{ (P->par)->rl[1]=cn;}
	}
	cn->par=P->par;
	P->rl[dr]=C;
	if (C){	C->par=P; cn->ch-=(C->ch);}
	P->ch-=(cn->ch);
	cn->ch+=(P->ch);
	cn->rl[dr^1]=P;
	P->par=cn;
	return;
}
 
void splay(node* cn){
	int drp, drpp;
    while(1){
    	if (!cn->par) {break;}
    	node *P = cn->par;
    	drp=(((P->rl[0])==cn)?0:1);
    	if (!P->par){
    		rot(cn, drp);
    		break;
    	}
    	node *PP=P->par;
    	drpp=(((PP->rl[0])==P)?0:1);
    	if (drpp==drp){
    		rot(P, drpp); rot(cn, drp);
    	}
    	else{
    		rot(cn, drp); rot(cn, drpp);
    	}
    }
    root=cn;
    return;
}
 
void insert(int vl){
    node * cn = (node*) malloc(sizeof(node));
    cn->val=vl;
    cn->rl[0]=nullptr;
    cn->rl[1]=nullptr;
    cn->qt=1;
    cn->ch=1;
    if (!root){
    	cn->par=nullptr;
    	root=cn;
    	return;
    }
    int d;
    node * tp= root;
    while(1){
    	tp->ch+=1;
    	if (tp->val==vl){
    		tp->qt+=1; splay(tp); free(cn); cn=nullptr; return;
    	}
    	d=(tp->val<vl)?1:0;
    	if (!tp->rl[d]){
    		cn->par=tp;
    		tp->rl[d]=cn;
    		splay(cn);
    		return;
    	}
    	else{
    		tp=tp->rl[d];
    	}
 
 
    }
}
void dlte(int vl){
    if (!root) {return;}
    node * cn = root;
    int d;
    while(1==1){
    	if (cn->val==vl){
    		splay(cn);
    		if (cn->qt>1){
    			cn->qt-=1; cn->ch-=1;
    			return;
    		}
    		else{
    			if (cn->rl[0]){
    				node * tp =cn->rl[0];
    				tp->par=nullptr;
    				while(tp->rl[1]){
    					tp=tp->rl[1];
    				}
    				splay(tp);
    				if (cn->rl[1]){
    					tp->ch+=cn->rl[1]->ch;
    					tp->rl[1]=cn->rl[1];
    					cn->rl[1]->par=tp;
    				}
 
    			}
    			else{
    				if (cn->rl[1]){
    					root=cn->rl[1];
    					cn->rl[1]->par=nullptr;
    				}
    				else{
    					root=nullptr;
    				}
    			}
    			free(cn); cn=nullptr; return;
    		}
    	}
    	d=(cn->val<vl)?1:0;
    	if (!cn->rl[d]){splay(cn); return;}
    	else{cn=cn->rl[d];}
 
    }
}
int vsmll(int v){
	if (!root) {return -1;}
	node * cn = root;
	while(cn){
		if (cn->rl[0]){
			if ((cn->rl[0]->ch)>=v){
				cn=cn->rl[0];
			}
			else{
				v-=cn->rl[0]->ch;
				if (cn->qt>=v){
					splay(cn);
					return cn->val;
				}
				else{
					v-=cn->qt;
					cn=cn->rl[1];
				}
			}
 
		}
		else{
			if (cn->qt >=v){
				splay(cn);
				return cn->val;
			}
			else{
				v-=cn->qt;
				cn=cn->rl[1];
			}
		}
	}
	return -1;
}
int vind(int vl){
    if (!root) {return -1;}
    node * cn = root;
    while(1){
    	if (vl<cn->val){
    		if (!cn->rl[0]){splay(cn); return -1;}
    		cn=cn->rl[0];
    	}
    	else if (vl>cn->val){
    		if (!cn->rl[1]){splay(cn); return -1;}
    		cn=cn->rl[1];
    	}
    	else{
    		splay(cn);
    		if (!cn->rl[0]) return 1;
    		else return (cn->rl[0]->ch)+1;
    	}
    }
    return -1;
}
void ptree(node * cn){
	if (!cn) return;
	ptree(cn->rl[0]);
	for(int i=0; i<cn->qt; i++){
		printf("%i ", cn->val);
	}
	ptree(cn->rl[1]);
	return;
}
 
int main(){
    int n, m, x, lv=0;
    char ni;
    scanf("%i%i", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%i", &x);
        insert(x); 
    }
    for(int i=0; i<m; i++){
        do{ni=getchar();}while(ni>'S' || ni<'I');
        scanf("%i", &x);
        x=(x^lv);
        switch(ni){
            case ('I'):
                insert(x);
                break;
            case ('R'):
                dlte(x);
                break;
            case ('S'):
                lv=vsmll(x);
          		printf("%i\n", lv);
                break;
            case ('L'):
                lv=vind(x);
           		printf("%i\n", lv);
                break;
        };
    }
    ptree(root);
    return 0;
}