#include<stdio.h>
#define max(x,y) (x>y)?x:y;

int arr[2][2000001]={0};

struct node
{
    int value;
    int weight;
}obj[501];


int main()
{
    int i,j,n,W,k;

    scanf("%i%i",&W,&n);

    i=0;
    while(++i <= n)
        scanf("%i%i",&obj[i].value,&obj[i].weight);

    i=0;
    while(++i <= n)
    {
        j = 0;

        if(i%2)
        {
            while(++j <= W)
            {
                if(obj[i].weight <= j)
                    arr[1][j] = max( obj[i].value + arr[0][ j-obj[i].weight ] , arr[0][j] )
                else
                    arr[1][j] = arr[0][j];
            }

        }

        else
        {
            while(++j <= W)
            {
                if(obj[i].weight <= j)
                    arr[0][j] = max( obj[i].value + arr[1][ j-obj[i].weight ] , arr[1][j] )
                else
                    arr[0][j] = arr[1][j];
            }
        }
    }


    if(n&1)
        printf("%i\n",arr[1][W]);
    else
        printf("%i\n",arr[0][W]);

    return 0;
}
