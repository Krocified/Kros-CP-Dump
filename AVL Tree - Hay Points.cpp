#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int salary;
	char word[51];
	
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

struct node *newNode(int sal, char wrd[]) {
	struct node *nNode = (struct node *)malloc(sizeof(struct node));
	nNode->salary = sal;
	strcpy(nNode->word,wrd);
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

struct node *insertVal(struct node *localRoot, int sal, char wrd[]) {
	if (localRoot == NULL) return newNode(sal, wrd);
	if (strcmp(localRoot->word,wrd)<0) {
		localRoot->right = insertVal(localRoot->right, sal, wrd);
	} else if (strcmp(localRoot->word,wrd)>0) {
		localRoot->left = insertVal(localRoot->left, sal, wrd);
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

int total = 0;
void searchVal(struct node *localRoot, char wrd[]) {
	
	if(strcmp(wrd,".")==0){
		printf("%d\n",total);
		total=0;
	}
	
	if (localRoot == NULL) {
	}
	
	while(localRoot){
		if (strcmp(localRoot->word,wrd)<0 && localRoot->right!=NULL) {
			localRoot = localRoot->right;
		} else if (strcmp(localRoot->word,wrd)>0 && localRoot->left!=NULL) {	
			localRoot = localRoot->left;
		} else {
			// KETEMU!
			break;
		}
	}
	
	if(strcmp(localRoot->word, wrd)==0){
		total+=localRoot->salary;
	} 
}


void inOrder(struct node *localRoot) {
	if (localRoot == NULL) return;
	inOrder(localRoot->left);
	printf("%s %d\n", localRoot->word, localRoot->salary);
	inOrder(localRoot->right);
}

int main() {
	
	int m,n;
	char line[101];
	scanf("%d%d",&m,&n);
	
	struct node *haytree = NULL;
	for(int i=0;i<m+1;i++){
		fgets(line,100,stdin);
		
		char *token = strtok(line," ");
		char wrd[51];
		char num[51];
		int flag = 0;
		
		while(token!=NULL){
			if(flag==0) {
				strcpy(wrd,token);
				flag++;
			} else {
				strcpy(num,token);
			}
			token = strtok(NULL," ");
		}
		
		num[strlen(num)-1] = '\0';
		
		int sal = atoi(num);
		
		haytree = insertVal(haytree, sal, wrd);
		
	}
	
	char sent[21];
	while(scanf("%s",sent)==1){
		
		searchVal(haytree, sent);
		
	}
	
	
	return 0;
}
