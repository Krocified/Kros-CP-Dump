#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	char engword[51];
	char frgword[51];
	
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

struct node *newNode(char eng[], char frg[]) {
	struct node *nNode = (struct node *)malloc(sizeof(struct node));
	strcpy(nNode->engword,eng);
	strcpy(nNode->frgword,frg);
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

struct node *insertVal(struct node *localRoot, char eng[], char frg[]) {
	if (localRoot == NULL) return newNode(eng, frg);
	if (strcmp(localRoot->frgword,frg)<0) {
		localRoot->right = insertVal(localRoot->right, eng, frg);
	} else if (strcmp(localRoot->frgword,frg)>0) {
		localRoot->left = insertVal(localRoot->left, eng, frg);
	} else {
		return localRoot;
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

void searchVal(struct node *localRoot, char frg[]) {
	
	if (localRoot == NULL) {
	}
	
	while(localRoot){
		if (strcmp(localRoot->frgword,frg)<0 && localRoot->right!=NULL) {
			localRoot = localRoot->right;
		} else if (strcmp(localRoot->frgword,frg)>0 && localRoot->left!=NULL) {	
			localRoot = localRoot->left;
		} else {
			// KETEMU!
			break;
		}
		
	}
	
	if(strcmp(localRoot->frgword, frg)==0){
		printf("%s\n",localRoot->engword);
	} else {
		printf("eh\n");
	}
}


void inOrder(struct node *localRoot) {
	if (localRoot == NULL) return;
	inOrder(localRoot->left);
	printf("%s %s", localRoot->engword, localRoot->frgword);
	inOrder(localRoot->right);
}

int main() {
	
	char line[101];
	struct node *babel = NULL;
	while(1){
		fgets(line,100,stdin);
		
		if(line[0]=='\n') break;
		
		char *token = strtok(line," ");
		char eng[51];
		char frg[51];
		int flag = 0;
		
		
		
		while(token!=NULL){
			if(flag==0) {
				strcpy(eng,token);
				flag++;
			} else {
				strcpy(frg,token);
			}
			token = strtok(NULL," ");
		}
		
		frg[strlen(frg)-1] = '\0';
		
		babel = insertVal(babel,eng, frg);
		
	}
	
	char frgword[11];
	while(scanf("%s",frgword)==1){
		
		searchVal(babel, frgword);
		
	}
	
	
	return 0;
}
