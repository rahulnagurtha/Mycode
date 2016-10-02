/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

#define MAX 100001


using namespace std;

char str[MAX]; //input
int Rank[MAX], suffixArray[MAX]; //output
int cnt[MAX], Next[MAX]; //internal
bool bh[MAX], b2h[MAX];
int Height[MAX];
int Length_of_str;

/*The format for M table where preprocessing value are stored is
M[MAX_STRING_SIZE][logbase2(MAX_STRING_SIZE)].
Also it it observed that Value of logbase2(10^7)= 23.253496664.
Thus always fix logbase2 value to 25.
*/

int M[MAX][25];

bool smaller_first_char(int a, int b)
{
	return str[a] < str[b];
}


void print(int index)
{
	for(int i=index;i<strlen(str);++i)
	{
		cout<<str[i];
	}
	cout<<endl;
}

void suffixSort(int n)
{
	//sort suffixes according to their first characters
	for (int i=0; i<n; ++i)
	{
		suffixArray[i] = i;
	}
	sort(suffixArray, suffixArray + n, smaller_first_char);
	//{suffixArray contains the list of suffixes sorted by their first character}

	for (int i=0; i<n; ++i)
	{
		bh[i] = i == 0 || str[suffixArray[i]] != str[suffixArray[i-1]];
		b2h[i] = false;
	}

	for (int h = 1; h < n; h <<= 1)
	{
		//{bh[i] == false if the first h characters of suffixArray[i-1] == the first h characters of suffixArray[i]}
		int buckets = 0;
		for (int i=0, j; i < n; i = j)
		{
			j = i + 1;
			while (j < n && !bh[j]) j++;
			Next[i] = j;
			buckets++;
		}
		if (buckets == n) break; // We are done! Lucky bastards!
		//{suffixes are separted in buckets containing strings starting with the same h characters}

		for (int i = 0; i < n; i = Next[i])
		{
			cnt[i] = 0;
			for (int j = i; j < Next[i]; ++j)
			{
				Rank[suffixArray[j]] = i;
			}
		}

		cnt[Rank[n - h]]++;
		b2h[Rank[n - h]] = true;
		for (int i = 0; i < n; i = Next[i])
		{
			for (int j = i; j < Next[i]; ++j)
			{
				int s = suffixArray[j] - h;
				if (s >= 0){
					int head = Rank[s];
					Rank[s] = head + cnt[head]++;
					b2h[Rank[s]] = true;
				}
			}
			for (int j = i; j < Next[i]; ++j)
			{
				int s = suffixArray[j] - h;
				if (s >= 0 && b2h[Rank[s]]){
					for (int k = Rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
				}
			}
		}
		for (int i=0; i<n; ++i)
		{
			suffixArray[Rank[i]] = i;
			bh[i] |= b2h[i];
		}
	}
	for (int i=0; i<n; ++i)
	{
		Rank[suffixArray[i]] = i;
	}
}
// End of suffix array algorithm



/*
Begin of the O(n) longest common prefix algorithm
Refer to "Linear-Time Longest-Common-Prefix Computation in Suffix
Arrays and Its Applications" by Toru Kasai, Gunho Lee, Hiroki
Arimura, Setsuo Arikawa, and Kunsoo Park.
*/


/*
Note to say Suffix [i] always means the Ith suffix in LEXOGRAPHICALLY SORTED ORDER
ie Height[i]=LCPs of (Suffix   i-1 ,suffix  i)
*/


void getHeight(int n)
{
	for (int i=0; i<n; ++i) Rank[suffixArray[i]] = i;
	Height[0] = 0;
	for (int i=0, h=0; i<n; ++i)
	{
		if (Rank[i] > 0)
		{
			int j = suffixArray[Rank[i]-1];
			while (i + h < n && j + h < n && str[i+h] == str[j+h])
			{
				h++;
			}
			Height[Rank[i]] = h;
			if (h > 0) h--;
		}
	}
}
// End of longest common prefixes algorithm


/*When the LCP of consecutive pair of Suffixes is Knows 

THEN:
We can calculate the LCPs of any suffixes (i,j)
with the Help of Following Formula

************************************************
*  LCP(suffix i,suffix j)=LCP[RMQ(i + 1; j)]   * 
*                                              *
*  Also Note (i<j) As LCP (suff i,suff j) may  *
*  not necessarly equal LCP (Suff j,suff i).   *
************************************************
*/

void preprocesses(int N)
{
	int i, j;

	//initialize M for the intervals with length 1
	for (i = 0; i < N; i++)
		M[i][0] = i;

	//compute values from smaller to bigger intervals
	for (j = 1; 1 << j <= N; j++)
	{
		for (i = 0; i + (1 << j) - 1 < N; i++)
		{
			if (Height[M[i][j - 1]] < Height[M[i + (1 << (j - 1))][j - 1]])
			{
				M[i][j] = M[i][j - 1];
			}
			else
			{
				M[i][j] = M[i + (1 << (j - 1))][j - 1];
			}
		}
	}
}  
int RMQ(int i,int j)
{
	int k=log((double)(j-i+1))/log((double)2);
	int vv= j-(1<<k)+1 ;
	if(Height[M[i][k]]<=Height[ M[vv][ k] ])
		return M[i][k];
	else
		return M[ vv ][ k];
}
int LCP(int i,int j)
{
	/*Make sure we send i<j always */
	/* By doing this ,it resolve following
	suppose ,we send LCP(5,4) then it converts it to LCP(4,5)
	*/
	if(i>j)
		swap(i,j);

	/*conformation over*/

	if(i==j)
	{
		return (Length_of_str-suffixArray[i]);
	}
	else
	{
		return Height[RMQ(i+1,j)];
		//LCP(suffix i,suffix j)=LCPadj[RMQ(i + 1; j)] 
		//LCPadj=LCP of adjacent suffix =Height.
	}
}


int main()
{

	int Len,TestCase,x,y;
	char tc[10];
	gets(tc);
	TestCase=atoi(tc);

	scanf("%d",&TestCase);
	while(TestCase--)
	{
		gets(str);
		Len=strlen(str);
		Length_of_str=Len;

		suffixSort(Len);

		/*Printing Suffix Array*/
		printf("The Suffix Array is: \n");
		for(int i=0;i<(Len);++i)
		{
			printf("%d %s\n",suffixArray[i],(str+suffixArray[i]));
		}

		/*Calculate LCP of Adjacents /consecutive Suffix Pairs */
		getHeight(Len);

		/*Calculate LCP of Any two suffixes i,j using RMQ concept */
		preprocesses(Len);

		int org=Rank[0];		//SA[org]=The suffix that is equal to the original String

		/*******************************/
		printf("\nPrinting Length of Longest Common Prefix Between Suffix i and j\n");
		for(int i=0;i<Len;++i)
		{
			for(int j=0;j<Len;++j)
			{
				printf("The Length of LCP b/w (%d,%d)th suffixes ie.(%s,%s) is: %d\n",i,j,(str+suffixArray[i]),(str+suffixArray[j]),LCP(i,j));
			}
		}
		/********************************/

		/*Calculation of LCP between orginal string and all its suffix*/
		printf("\n\nThe Sum of LCP b/w the original string S and all its suffixes is: ");
		int res=0;
		for(int i=0;i<Len;++i)
		{
			res=res+LCP(i,org);
		}
		cout<<res<<endl;
	}
	//system("pause");
	return 0;
}