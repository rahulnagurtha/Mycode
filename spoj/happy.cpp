#include <bits/stdc++.h>

using namespace std;

typedef struct tree{
	int key;
	struct tree* left;
	struct tree* right;
	struct tree* parent;
}node;

node head;

void insert(node* one) {
	node* temp1 =NULL;
	node* temp2 =NULL;


	if(head.key==-99999) {
		head.key=one->key;
		return;
	}

	temp1 = &head;
	temp2 = NULL;
	while(temp1!=NULL) {
		temp2=temp1;
		if( (temp1->key) <= (one->key) ) {
			temp1=(temp1->right);
		}
		else {
			temp1=(temp1->left);
		}
	}
	if( (temp2->key) > (one->key) ) {
		temp2 -> left = one;
		one -> parent =temp2;
	}
	else {
		temp2 -> right = one;
		one -> parent = temp2;
	}
}

void display(node *one) {

	if (one!=NULL)
	{
		display(one->left);
		cout << one->key << " ";
		display(one->right);
	}
}

node* search(int one) {
	node *temp1,*temp2;
	temp1=&head;
	temp2=NULL;
	while(temp1->key!=one) {
		// printf("%d->",temp1->key);
		if(temp1->key < one) temp1=temp1->right;
		else temp1=temp1->left;
	}
	// printf("\nreturned %d\n",temp1->key);

	return temp1;
}


int treemin(node *one) {
	int ans;
	node *temp1,*temp2;
	temp1=one;
	temp2=NULL;
	while(temp1!=NULL) {
		temp2=temp1;
		temp1=temp1->left;
	}
	return (temp2->key);
}



int treemax(node *one) {
	int ans;
	node *temp1,*temp2;
	temp1=one;
	temp2=NULL;
	while(temp1!=NULL) {
		temp2=temp1;
		temp1=temp1->right;
	}
	return (temp2->key);
}


int successor(node *one) {
	node *temp1;
	temp1=one;
	if(one->right != NULL) {
		printf("%d is the successor\n",treemin(one->right));
		return treemin(one->right);
	}
	else {
		while( (temp1->parent!=NULL) && (temp1!=temp1->parent->left) ) {
			printf("%d -> ",temp1->key);
			temp1=temp1->parent;
		}
		printf("\n\n");
		if(temp1->parent==NULL) {
			printf("no successor for this\n");
			return 0;
		}
		else {
			printf("%d is the successor of %d\n",temp1->parent->key,one->key);
			return temp1->parent->key;
		}
	}
}


int predecessor(node *one) {
	node *temp1;
	temp1=one;
	if(one->left != NULL) {
		printf("%d is the predecessor\n",treemax(one->left));
		return treemax(one->left);
	}
	else {
		while( (temp1->parent != NULL) && (temp1 != temp1->parent->right) ) {
			printf("%d -> ",temp1->key);
			temp1=temp1->parent;
		}
		printf("\n\n");
		if(temp1->parent==NULL) {
			printf("no predecessor for this\n");
			return 0;
		}
		else {
			printf("%d is the predecessor of %d\n",temp1->parent->key,one->key);
			return temp1->parent->key;
		}
	}
}


void transplant(node *one,node *two) {
	node *temp1,*temp2;
	if(one->parent==NULL) {
		one->left=two->left;
		one->right=two->right;
		one->key=two->key;
		if(one->left!=NULL) one->left->parent=one;
		if(one->right!=NULL) one->right->parent=one;
	}
	else if(one==one->parent->left) {
		one->parent->left=two;
		two->parent=one->parent;
	}
	else {
		one->parent->right=two;
		two->parent=one->parent;
	}
}


void deletenode(int one) {
	node *temp1,*temp2,*temp3;
	temp1=search(one);
	if(temp1->left==NULL && temp1->right==NULL) {
		if(temp1->parent==NULL) {
			temp1->key=one;
		}
		else if(temp1->parent->left==temp1) {
			temp1->parent->left=NULL;
		}
		else {
			temp1->parent->right=NULL;
		}
	}
	else if(temp1->left==NULL && temp1->right!=NULL) {
		transplant(temp1,temp1->right);
	}
	else if(temp1->left!=NULL && temp1->right==NULL) {
		transplant(temp1,temp1->left);
	}
	else {
		temp2=search(successor(temp1));
		if(temp2==temp1->right) {
			temp1->right=temp2->right;
			if(temp2->right!=NULL) temp2->right->parent=temp1;
			temp1->key=temp2->key;

		}
		else {
			if(temp2->right!=NULL) transplant(temp2,temp2->right);
			else if(temp2->parent->left==temp2) temp2->parent->left=NULL;
			else temp2->parent->right=NULL;
			temp1->key=temp2->key;
		}
	}
}



int main()
{
	int n,ele;
	node* temp;
	head.key=-99999;
	head.left=NULL;
	head.right=NULL;
	head.parent=NULL;
	cout << "how many numbers ?\n" ;
	cin >> n ;
	printf("enter the key\n");
	for (int i = 0; i < n; ++i) {
		temp= new node;   // temp=(node*)malloc(sizeof(node));
		cin >> ele ;
		temp->parent=NULL;
		temp->key=ele;
		temp->left=NULL;
		temp->right=NULL;
		insert(temp);
	}
	display(&head);
	printf("\nwhat do you want to delete?\n");
	for (int i = 0; i < n; ++i)
	{
		cin >> ele ;
		deletenode(ele);
		printf("%d is root\n",head.key);
		display(&head);
		cout << endl ;
	}
	printf("\n\n");
	printf("\n\n\n\n");
	display(&head);
	printf("\n");
    return 0;
}















// void deletenode(int one) {
// 	node *temp1,*temp2;
// 	// printf("searching for %d\n",one);
// 	temp1=search(one);
// 	// printf("search complete, %d found\n",temp1->key);
// 	if(temp1->left==NULL && temp1->right==NULL) {
// 		if(temp1->parent!=NULL) {
// 			temp1->parent->left=NULL;
// 			temp1->parent->right=NULL;
// 			delete temp1;
// 		}
// 		else {
// 			head.key=-9999;
// 			delete temp1;
// 		}
// 	}
// 	else if(temp1->left==NULL && temp1->right!=NULL) {
// 		transplant(temp1,temp1->right);
// 		delete temp1;
// 	}
// 	else if(temp1->left!=NULL && temp1->right==NULL) {
// 		transplant(temp1,temp1->left);
// 		delete temp1;
// 	}
// 	else {
// 		temp2=search(treemin(temp1->right));
// 		// printf("treemiin is %d\n",temp2->key);
// 		if(temp2->parent==temp1) {
// 			// printf("1\n");
// 			temp2->left=temp1->left;
// 			// printf("2\n");
// 			temp1->left->parent=temp1->right;
// 			if(temp1->parent!=NULL) {
// 				// printf("3\n");
// 				temp2->parent=temp1->parent;
// 				if(temp1->parent->left==temp1) temp1->parent->left=temp2;
// 				else temp1->parent->right=temp2;
// 				delete temp1;
// 			}
// 			else {
// 				// printf("4\n");
// 				head.left=temp2->left;
// 				head.right=temp2->right;
// 				head.key=temp2->key;
// 			}
// 		}
// 		else {
// 			temp2->right->parent=temp2->parent;
// 			temp2->parent->left=temp2->right;
// 			temp1->key=temp2->key;
// 			// temp2->parent=temp1->parent;
// 			// temp2->left=temp1->left;
// 			// temp2->right=temp1->right;
// 			delete temp1;
// 		}
// 	}
// }
