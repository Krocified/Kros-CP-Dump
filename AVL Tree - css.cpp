#include<stdio.h>
#include<stdlib.h>

struct node {
	
	int id;
	int attr;
	int val;
	int prio;
	
	int height;
	
	struct node *left;
	struct node *right;
};

int max(int a, int b) {
	return (a < b) ? b : a;
}

int getHeight(struct node *localRoot) {
	if (localRoot == NULL) return 0;
	return localRoot->height;
}

int getBalFactor(struct node *localRoot) {
	if (localRoot == NULL) return 0;
	return getHeight(localRoot->left) - getHeight(localRoot->right);
}

struct node *newNode(int nid, int nattr, int nval, int nprio) {
	struct node *nNode = (struct node *)malloc(sizeof(struct node));
	
	nNode->id = nid;
	nNode->attr = nattr;
	nNode->val = nval;
	nNode->prio = nprio;
	nNode->left = NULL;
	nNode->right = NULL;
	nNode->height = 1;
	
	return nNode;
}

struct node *leftRotate(struct node *x) {
	
	struct node *y = x->right;
	struct node *B = y->left;
	
	// rotate
	y->left = x;
	x->right = B;
	
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	return y;
}

struct node *rightRotate(struct node *y) {
	struct node *x = y->left;
	struct node *B = x->right;
	
	// rotate
	x->right = y;
	y->left = B;

	y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
	x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
	return x;
}

struct node *reBalance(struct node *localRoot) {
	
	localRoot->height = max(getHeight(localRoot->left),	getHeight(localRoot->right)) + 1;
	int bfact = getBalFactor(localRoot);
	
	if (bfact > 1 && getBalFactor(localRoot->left) < 0) {
		localRoot->left = leftRotate(localRoot->left);
		return rightRotate(localRoot);
	}
	if (bfact > 1 && getBalFactor(localRoot->left) >= 0) {
		return rightRotate(localRoot);
	}
	if (bfact < -1 && getBalFactor(localRoot->right) <= 0) {
		return leftRotate(localRoot);
	}
	if (bfact < -1 && getBalFactor(localRoot->right) > 0) {
		localRoot->right = rightRotate(localRoot->right);
		return leftRotate(localRoot);
	}
	return localRoot;
}

struct node *insertVal(struct node *localRoot, int nid, int nattr, int nval, int nprio) {
	
	if (localRoot == NULL) return newNode(nid, nattr, nval, nprio);
	
	if (localRoot->id < nid) {
		localRoot->right = insertVal(localRoot->right, nid, nattr, nval, nprio);
	} else if (localRoot->id > nid) {
		localRoot->left = insertVal(localRoot->left, nid, nattr, nval, nprio);
	} else {
		if (localRoot->attr < nattr) {
			localRoot->right = insertVal(localRoot->right, nid, nattr, nval, nprio);
		} else if (localRoot->attr > nattr) {
			localRoot->left = insertVal(localRoot->left, nid, nattr, nval, nprio);
		} else {
			if(localRoot->prio <= nprio){
				localRoot->val = nval;
				localRoot->prio = nprio;
			}
			return localRoot;
		}
	}
	return reBalance(localRoot);
}

struct node *successor(struct node *localRoot) {
	
	struct node *current = localRoot->right;
	while(current != NULL && current->left != NULL) {
		current = current->left;
	}
	return current;
}

void searchVal(struct node *localRoot, int id, int attr) {
	
	if (localRoot == NULL) {
	}
	
	while(localRoot){
		if (localRoot->id < id && localRoot->right!=NULL) {
			localRoot = localRoot->right;
		} else if (localRoot->id > id && localRoot->left!=NULL) {	
			localRoot = localRoot->left;
		} else {
			if (localRoot->attr < attr && localRoot->right!=NULL) {
				localRoot = localRoot->right;
			} else if (localRoot->attr > attr && localRoot->left!=NULL) {	
				localRoot = localRoot->left;
			} else {
				printf("%d\n",localRoot->val);
				break;	
			}
		}
	}
}


void inOrder(struct node *localRoot) {
	if (localRoot == NULL) return;
	inOrder(localRoot->left);
	printf("%d %d %d %d\n", localRoot->id, localRoot->attr, localRoot->val, localRoot->prio);
	inOrder(localRoot->right);
}

int main() {
	
	int m, n;
	struct node *css = NULL;
	
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++){
		int ni=0,a=0,v=0,p=0;
		scanf("%d%d%d%d", &ni,&a,&v,&p);
		css = insertVal(css,ni,a,v,p);
	}
	
	for(int i=0;i<m;i++){
		int qi,qa;
		scanf("%d%d",&qi,&qa);
		
		searchVal(css,qi,qa);
	}
	
	
	return 0;
}
