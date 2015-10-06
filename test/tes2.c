#include <stdio.h>
#include <stdlib.h>



typedef struct tree{
    int key;
    struct tree* left;
    struct tree* right;
    struct tree* parent;
}node;


node head;



void display(node *one) {
    //inorder traversal
    node *temp1;
    temp1=one;
    if(temp1!=NULL) {
        display(temp1->left);
        printf("%d--",temp1->key);
        //printing right and left children
        if(temp1->left==NULL) printf("NULL,");
        else printf("%d,",temp1->left->key);
        if(temp1->right==NULL) printf("NULL\n");
        else printf("%d\n",temp1->right->key);
        display(temp1->right);
    }
}



void preorder(node *one) {
    //preorder traversal
    node *temp1;
    temp1=one;
    if(temp1!=NULL) {
        printf("%d ",temp1->key);
        preorder(temp1->left);
        preorder(temp1->right);
    }
}

void postorder(node *one) {
    //postorder traversal
    node *temp1;
    temp1=one;
    if(temp1!=NULL) {
        postorder(temp1->left);
        postorder(temp1->right);
        printf("%d ",temp1->key);
    }
}



void searchpath(int ele) {
    int flag=0;
    node *temp1,*temp2,*temp3;
    temp1=&head;
    if(temp1->key==-9999) {
        printf("element not found\n");
        return ;
    }


    //searching for a node
    while(temp1!=NULL) {
        if(temp1->key==ele) {
            printf("element found\n");
            flag=1;
            break;
        }

        //going left or right depending on the situation
        else if(temp1->key<ele) {
            temp1=temp1->right;         
        }
        else temp1=temp1->left;
    }

    //printing the path if it is in tree
    if(flag==1) {
        printf("the path is:\n");
        temp3=&head;
        while(temp3!=NULL) {
            if(temp3->key==ele) {
                printf("%d->\n",temp3->key);
                // printf("element found\n");
                // flag=1;
                break;
            }
            else if(temp3->key<ele) {
                printf("%d->",temp3->key);
                temp3=temp3->right;
            }
            else {
                printf("%d->",temp3->key);
                temp3=temp3->left;
            }
        }
    }
    if(temp1==NULL) printf("element not found\n");

}




int pless_search(int ele) {
    int flag=0;
    node *temp1,*temp2,*temp3;
    temp1=&head;
    if(temp1->key==-9999) {
        // printf("element not found\n");
        return 0;
    }


    //searching for a node
    while(temp1!=NULL) {
        if(temp1->key==ele) {
            printf("element found\n");
            flag=1;
            break;
        }

        //going left or right depending on the situation
        else if(temp1->key<ele) {
            temp1=temp1->right;         
        }
        else temp1=temp1->left;
    }

    if(flag==1) return 1;

    if(temp1==NULL) return 0;

}







void insert(int ele) {
    node *temp1,*temp2,*temp3;
    temp1=&head;
    if(temp1->key==-9999) {
        temp1->key=ele;
        return;
    }

    temp3=(node *)malloc(sizeof(node));
    temp3->left=NULL;
    temp3->right=NULL;
    temp3->parent=NULL;
    temp3->key=ele;

    while(temp1!=NULL) {
        temp2=temp1;
        if(temp1->key > ele ) temp1=temp1->left;
        else  temp1=temp1->right;
    }

    if(temp3->key < temp2->key) {
        temp2->left=temp3;
        temp3->parent=temp2;
    }
    else {
        temp2->right=temp3;
        temp3->parent=temp2;
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



int successor(node *one) {
    node *temp1;
    temp1=one;
    if(one->right != NULL) {
        // printf("%d is the successor\n",treemin(one->right));
        return treemin(one->right);
    }
    else {
        while( (temp1->parent!=NULL) && (temp1!=temp1->parent->left) ) {
            // printf("%d -> ",temp1->key);
            temp1=temp1->parent;
        }
        // printf("\n\n");
        if(temp1->parent==NULL) {
            // printf("no successor for this\n");
            return 0;
        }
        else {
            // printf("%d is the successor of %d\n",temp1->parent->key,one->key);
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


    if(!pless_search(one)) {
        printf("number not found\n");
        return;
    }

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
    printf("number deleted\n");
}



int main() {
    head.key=-9999;
    head.left=NULL;
    head.right=NULL;
    head.parent=NULL;
    int i,number,num,response;
    //task1
    insert(25);
    insert(15);
    insert(26);
    insert(18);
    insert(14);
    insert(31);
    ///task1 done

    while(1) {
        printf("1.insert a  number\n");
        printf("2.delete a  number\n");
        printf("3.search for a number\n");
        printf("4.display tree\n");
        printf("5.preorder traversal\n");
        printf("6.postorder traversal\n");
        printf("7.exit\n");
        scanf("%d",&response);
        if (response==1) {
            printf("enter a number to insert\n");
            scanf("%d",&number);
            insert(number);
            printf("\n");
            // display();
            printf("\n");
        }
        else if(response==2) {
            printf("enter a number to delete\n");
            scanf("%d",&number);
            deletenode(number);
            printf("\n");
            // display();
            printf("\n");
        }
        else if(response==3) {
            printf("number to search? : ");
            scanf("%d",&number);
            searchpath(number);
        }
        else if(response==4) {
            display(&head); 
            printf("\n");      
        }
        else if(response==5) {
            preorder(&head);
            printf("\n");       
        }
        else if(response==6) {
            postorder(&head);
            printf("\n");       
        }
        else if(response==7) {
            break;
        }
    }
    return 0;
}