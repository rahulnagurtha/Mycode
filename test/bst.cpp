#include <bits/stdc++.h>

using namespace std;


typedef struct tree{
	int key;
	int height;
	struct tree* left;
	struct tree* right;
	struct tree* parent;
}node;



void initialise(node **head) {
	*head=NULL;
	return;
}


void update(node *temp) {
	while(temp->parent!=NULL){
		if(temp->parent->left!=NULL && temp->parent->right!=NULL) {
			if (temp->parent->left==temp) {
				temp->parent->height = max((temp->parent->left->height)+1,temp->parent->right->height);
			}
			else {
				temp->parent->height = max(temp->parent->left->height,(temp->parent->right->height)+1);
			}
		}
		else {
			temp->parent->height += 1;
		}
		temp=temp->parent;
	}
	return;
}



void insert(node **head,int ele) {
	node *temp1,*temp2;
	// printf("yoo\n");
	if(*head==NULL) {
		temp1=new node;
		*head=temp1;
		// printf("here\n");
		(*head)->left=NULL;
		(*head)->parent=NULL;
		(*head)->right=NULL;
		(*head)->key=ele;
		(*head)->height=0;
		return;
	}
	else {
		temp1=*head;
		while(temp1!=NULL) {
			temp2=temp1;
			if(temp1->key <= ele) {
				temp1=temp1->right;
			}
			else {
				temp1=temp1->left;
			}
		}
		temp1 = new node;
		temp1->left=NULL;
		temp1->right=NULL;
		temp1->parent=temp2;
		temp1->key=ele;
		temp1->height=0;
		if(temp2->key<=ele) temp2->right=temp1;
		else temp2->left=temp1;
		update(temp1);
		return;
	}
}

void psearch(node *temp,int ele) {
	if(temp==NULL) {
		printf("element not found\n");
		return;
	}
	else if(ele==temp->key) {
		printf("ele found with height %d\n",temp->height);
		return;
	}
	else {
		if(temp->key <= ele) psearch(temp->right,ele);
		else psearch(temp->left,ele);
	}
}


void display(node *temp) {
	if(temp!=NULL) {
		display(temp->left);
		printf("%d  ",(temp->key));
		display(temp->right);
	}
}


// main code begins now

int main()
{
    node *head;
    int key,option;
    initialise(&head);
    while(1) {
    	printf("1.insert\n");
    	printf("2.search\n");
    	printf("3.display\n");
    	cin >> option ;
    	if (option==1) {
    		cin >> key ;
    		insert(&head,key);
    	}
    	else if(option==2) {
    		cin >> key ;
    		psearch(head,key);
    	}
    	else if(option==3) {
    		display(head);
    		printf("\n\n");
    	}
    }
    return 0;
}