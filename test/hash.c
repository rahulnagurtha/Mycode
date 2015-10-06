#include <stdio.h>
#include <stdlib.h>


///for simplicity i have chosen the size of hash table to be 10 in 1st question and
//as we cant get much time difference with these two functions, i have chosen the size of hash table to be 20 in 2nd question 

int select;
int size[20];

typedef struct collision {
    int key;
    struct collision *previous;
    struct collision *next;
} node;


struct block {
    struct collision *head;
} array[20];


void initialise() {
    int i;
    for (i = 0; i < 10; ++i) {
        array[i].head=NULL;
        size[i]=0;
    }
}


int hfunction(int one) {
    if(select==1) {
        return (one%10);
    }
    else {
        int temp1;
        float temp2;
        temp1=0.61*one;
        temp2=0.61*one-(float)temp1;
        temp2=10*temp2;
        temp1=(int)temp2;
        return temp1;
    }
}


int generate() {
    return (100000+(rand()%900000));
}


void display() {
    int i;
    node *temp1,*temp2;
    for (i = 0; i < 10; ++i) {
        temp1=array[i].head;
        if(temp1==NULL) {
            printf("->\n");
            continue;
        }
        while(temp1!=NULL) {
            printf("%d->",temp1->key);
            temp1=temp1->next;
        }
        printf("\n");
    }
}



void insert(int ele) {
    int slot;
    node *temp1,*temp2;
    slot=hfunction(ele);
    if(size[slot]==0) {
        size[slot]+=1;
        temp1= (node *)malloc(sizeof(node));
        // temp1=new node;
        temp1->key=ele;
        temp1->next=NULL;
        temp1->previous=NULL;
        array[slot].head=temp1;
    }
    else {
        size[slot]+=1;
        // temp1 = new node;
        temp1= (node *)malloc(sizeof(node));
        temp1->key=ele;
        temp1->previous=NULL;
        temp1->next=array[slot].head;
        array[slot].head->previous=temp1;
        array[slot].head=temp1;
    }
}


int search(int ele) {
	node *temp1,*temp2;
    int slot=hfunction(ele);
    temp1=array[slot].head;
    while(temp1!=NULL) {
        if(temp1->key==ele){
            return ele;
        }
        temp1=temp1->next;
    }
    return -1;
}


void sizedisplay() {
    int i;
	printf("the sizes of slots are:\n\n");
	for (i = 0; i < 10; ++i) {
		printf("%d\n",size[i]);
	}
	printf("\n");
}

void deletenode(int ele) {
    node *temp1,*temp2;
    int slot=hfunction(ele);
    temp1=array[slot].head;
    if(size[slot]==0) {
        printf("element not found in table\n");
        return;
    }
    while(temp1!=NULL) {
        if(temp1->key!=ele) {
            temp2=temp1;
            temp1=temp1->next;
            // if(temp1==NULL) printf("null\n");
            // else printf("not null\n");
        }
        else break;
    }
    if(temp1==NULL) {
        printf("element not found in table\n");
        return;
    }
    else if(temp1==array[slot].head) {
        if(size[slot]==1) {
            array[slot].head=NULL;
            size[slot] -=1;
            free(temp1);
            // delete temp1;
        }
        else {
            array[slot].head=array[slot].head->next;
            array[slot].head->previous=NULL;
            free(temp1);
            // delete temp1;
            size[slot] -=1;
        }
    }
    else {
        if(temp1->next==NULL) {
            temp1->previous->next=NULL;
            // delete temp1;
            free(temp1);
            size[slot] -=1;
        }
        else {
            temp1->previous->next=temp1->next;
            temp1->next->previous=temp1->previous;
            // delete temp1;
            free(temp1);
            size[slot] -=1;
        }
    }
}



// main code begins now

int main()
{
    int i,response,number;
    srand (time(NULL));
    printf("initialising hash table\n");
    initialise();
    printf("which hash funtion do you want ? \n");
    printf("1. key % 10\n2.step of 10*( (key*A) mod 1)\n");
    scanf("%d",&select);
    //inserting randomly 20 numbers into the hash table
    for (i = 0; i < 20; ++i) {
    	insert(generate());
    }

    printf("\nstatus of the table after inserting 20 random numbers into the table\n");
    display();
    printf("\n\n");

    while(1) {
        printf("1.insert a registration number\n");
        printf("2.delete a registration number\n");
        printf("3.search for a registration number\n");
        printf("4.display the sizes of hash table slots\n");
        printf("5.display the entire hash table\n");
        printf("6.exit\n");
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
            if(search(number)== number){
            	printf("element is in hash table\n");
            }
            else {
            	printf("its not there in hash table\n");
            }
        }
        else if(response==4) {
			sizedisplay();       
        }
        else if(response==5) {
            display();       
        }
        else if(response==6) {
            break;
        }

    }
    return 0;
}
