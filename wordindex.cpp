#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	char something[6];
	int key;
	
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

struct node *newNode(char thing[], int key) {
	struct node *nNode = (struct node *)malloc(sizeof(struct node));
	strcpy(nNode->something,thing);
	nNode->key = key;
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

struct node *insertVal(struct node *localRoot, char thing[], int key) {
	if (localRoot == NULL) return newNode(thing, key);
	if (strcmp(localRoot->something,thing)<0) {
		localRoot->right = insertVal(localRoot->right, thing, key);
	} else if (strcmp(localRoot->something,thing)>0) {
		localRoot->left = insertVal(localRoot->left, thing, key);
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

void searchVal(struct node *localRoot, char thing[]) {
	
	if (localRoot == NULL) {
	}
	
	while(localRoot){
		if (strcmp(localRoot->something,thing)<0 && localRoot->right!=NULL) {
			localRoot = localRoot->right;
		} else if (strcmp(localRoot->something,thing)>0 && localRoot->left!=NULL) {	
			localRoot = localRoot->left;
		} else {
			// KETEMU!
			break;
		}
		
	}
	if(strcmp(localRoot->something,thing)==0){	
		printf("%d\n",localRoot->key);
	} else {
		printf("0\n");
	}
}

void inOrder(struct node *localRoot) {
	if (localRoot == NULL) return;
	inOrder(localRoot->left);
	printf("%s %d", localRoot->something, localRoot->key);
	inOrder(localRoot->right);
}

int main() {
	
	struct node *thingamagic = NULL;
	
	char wow[6];
	char init[6];
	
	int key=1;
	
	for(int i='a';i<='z';i++){
		init[0]=i;
		init[1]='\0';
		thingamagic = insertVal(thingamagic,init,key);
		key++;
	}
	
	for(int i='a';i<='z';i++){
		init[0] = i;
		for(int j=i+1;j<='z';j++){
			init[1] = j;
			init[2]='\0';
			thingamagic = insertVal(thingamagic,init,key);
			key++;
		}
	}
	
	for(int i='a';i<='z';i++){
		init[0] = i;
		for(int j=i+1;j<='z';j++){
			init[1] = j;
			for(int k=j+1;k<='z';k++){
				init[2]=k;
				thingamagic = insertVal(thingamagic,init,key);
				key++;
			}
		}
	}
	
	for(int i='a';i<='z';i++){
		init[0] = i;
		for(int j=i+1;j<='z';j++){
			init[1] = j;
			for(int k=j+1;k<='z';k++){
				init[2]=k;
				for(int l=k+1;l<='z';l++){
					init[3]=l;
					thingamagic = insertVal(thingamagic,init,key);
					key++;
				}
			}
		}
	}
	
	for(int i='a';i<='z';i++){
		init[0] = i;
		for(int j=i+1;j<='z';j++){
			init[1] = j;
			for(int k=j+1;k<='z';k++){
				init[2]=k;
				for(int l=k+1;l<='z';l++){
					init[3]=l;
					for(int m=l+1;m<='z';m++){
						init[4]=m;
						thingamagic = insertVal(thingamagic,init,key);
						key++;
					}
				}
			}
		}
	}
	
	while(scanf("%s",wow)!=EOF){
		
		searchVal(thingamagic,wow);
	}
	
	return 0;
}
