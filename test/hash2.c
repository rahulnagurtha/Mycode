#include <stdio.h>
#include <stdlib.h>
#include <time.h>


///for simplicity i have chosen the size of hash table to be 10 in 1st question and
//as we cant get much time difference with these two functions, i have chosen the size of hash table to be 20 in 2nd question 


int size[23];

typedef struct collision {
    int key;
    struct collision *previous;
    struct collision *next;
} node;


struct block {
    struct collision *head;
} array[23];


void initialise() {
    int i;
    for (i = 0; i < 20; ++i) {
        array[i].head=NULL;
        size[i]=0;
    }
}


int hfunction(int one) {
    return (one%20);
}


int generate() {
    return (100000+(rand()%900000));
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

/////second funtion methods

int size1[23];


typedef struct collision1 {
    int key;
    struct collision1 *previous;
    struct collision1 *next;
} node1;


struct block1 {
    struct collision1 *head;
} array1[23];


void initialise1() {
    int i;
    for (i = 0; i < 20; ++i) {
        array1[i].head=NULL;
        size1[i]=0;
    }
}


int hfunction1(int one) {
        int temp1;
        float temp2;
        temp1=0.61*one;
        temp2=0.61*one-(float)temp1;
        temp2=20*temp2;
        temp1=(int)temp2;
        return temp1;
}


void insert1(int ele) {
    int slot;
    node1 *temp1,*temp2;
    slot=hfunction1(ele);
    if(size1[slot]==0) {
        size1[slot]+=1;
        temp1= (node1 *)malloc(sizeof(node1));
        // temp1=new node;
        temp1->key=ele;
        temp1->next=NULL;
        temp1->previous=NULL;
        array1[slot].head=temp1;
    }
    else {
        size1[slot]+=1;
        // temp1 = new node;
        temp1= (node1 *)malloc(sizeof(node1));
        temp1->key=ele;
        temp1->previous=NULL;
        temp1->next=array1[slot].head;
        array1[slot].head->previous=temp1;
        array1[slot].head=temp1;
    }
}


int search1(int ele) {
    node1 *temp1,*temp2;
    int slot=hfunction1(ele);
    temp1=array1[slot].head;
    while(temp1!=NULL) {
        if(temp1->key==ele){
            return ele;
        }
        temp1=temp1->next;
    }
    return -1;
}







// main code begins now


int check1[100005],check2[100005];

int main()
{
    int i,response,number;
    double time_spent;
    srand (time(NULL));
    // printf("initialising hash table\n");
    initialise();
    initialise1();
    printf("the hash funtions are :\n");
    printf("1. key % 20\n2.step of 20*( (key*A) mod 1)\n");
    printf("how many numbers do you want to enter(choose number <=1,00,000): ");
    scanf("%d",&number);
    for (i = 0; i < number; ++i) {
        check1[i]=generate();
        check2[i]=check1[i];
    	insert(check1[i]);
        insert1(check2[i]);
    }
    printf("with first function the search time is : \n");
    clock_t begin;
    begin=clock();
    for (i = 0; i < number; ++i) {
        search(check1[i]);
    }
    begin=clock()-begin;
    time_spent = (double)(begin) / CLOCKS_PER_SEC;
    printf("Elapsed: %f seconds\n", time_spent);

    //second function calculation

    printf("with second function the search time is : \n");
    begin=clock();
    for (i = 0; i < number; ++i) {
        search1(check2[i]);
    }
    begin=clock()-begin;
    time_spent = (double)(begin) / CLOCKS_PER_SEC;
    printf("Elapsed: %f seconds\n", time_spent);
    return 0;
}
