#include <bits/stdc++.h>

using namespace std;

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
    for (int i = 0; i < 10; ++i) {
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
    node *temp1,*temp2;
    for (int i = 0; i < 10; ++i) {
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
        temp1=new node;
        temp1->key=ele;
        temp1->next=NULL;
        temp1->previous=NULL;
        array[slot].head=temp1;
    }
    else {
        size[slot]+=1;
        temp1 = new node;
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
	printf("the sizes of slots are:\n\n");
	for (int i = 0; i < 10; ++i) {
		cout << size[i] << endl ;
	}
	printf("\n");
}

void deletenode(int ele) {
    node *temp1,*temp2;
    int slot=hfunction(ele);
    temp1=array[slot].head;
    if(size[slot]==0) {
        printf("no ele found\n");
        return;
    }
    while(temp1->key!=ele && temp1!=NULL) {
        temp2=temp1;
        temp1=temp1->next;
    }
    if(temp1==NULL) {
        printf("element not inserted so far\n");
        return;
    }
    else if(temp1==array[slot].head) {
        if(size[slot]==1) {
            array[slot].head=NULL;
            size[slot] -=1;
            delete temp1;
        }
        else {
            array[slot].head=array[slot].head->next;
            array[slot].head->previous=NULL;
            delete temp1;
            size[slot] -=1;
        }
    }
    else {
        if(temp1->next==NULL) {
            temp1->previous->next=NULL;
            delete temp1;
            size[slot] -=1;
        }
        else {
            temp1->previous->next=temp1->next;
            temp1->next->previous=temp1->previous;
            delete temp1;
            size[slot] -=1;
        }
    }
}



// main code begins now

int main()
{
    int response,number;
    srand (time(NULL));
    printf("initialising hash table\n");
    initialise();
    printf("which hash funtion do you want ? \n");
    printf("1. key % 20\n2.step of 20*( (key*A) mod 20)\n");
    cin >> select ;

    for (int i = 0; i < 10; ++i) {
    	insert(generate());
    }


    while(1) {
        printf("1.insert a registration number\n");
        printf("2.delete a registration number\n");
        printf("3.search for a registration number\n");
        printf("4.display the sizes of hash table slots\n");
        printf("5.exit\n");
        cin >> response ;
        if (response==1) {
            printf("enter a number to insert\n");
            cin >> number ;
            insert(number);
            printf("\n");
            display();
            printf("\n");
        }
        else if(response==2) {
            printf("enter a number to delete\n");
            cin >> number ;
            deletenode(number);
            printf("\n");
            display();
            printf("\n");
        }
        else if(response==3) {
        	printf("number to search? : ");
            cin >> number ;
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
            break;
        }

    }
    return 0;
}
