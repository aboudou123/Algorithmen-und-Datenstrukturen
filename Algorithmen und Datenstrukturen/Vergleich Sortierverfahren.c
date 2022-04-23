#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>

#define ASize 250000+1
#define ZUFALL_MAX 100

typedef int Item;
typedef Item Array[ASize];

void PrintArray(Array a, int n) {
/*
  int i;
  for (i=1; i<=3; i++) printf("%6d", a[i]);
  printf(" ... ");
  for (i=n-2; i<=n; i++) printf("%6d", a[i]);
  printf("\n");
*/
}

void PrintTime(int t1, int t2) { printf("%9d | ", t2-t1); }

void PrintTimeMittelwert(int t1, int t2, int n) { printf("%-9.4f | ", (t2-t1)/ (float) n); }

/*----------------------BubbleSort----------------------------*/

void BubbleSort(Array a, int n) {
/* Es wird der Bereich a[1] bis a[n] sortiert */
  int i, j;
  for (i=2; i<=n; i++) {
    for (j=n; j>=i; j--) {
      if (a[j-1] > a[j]) {
        Item buf = a[j]; a[j] = a[j-1]; a[j-1] = buf;
      }
    }
  }
}
/*------------------------------------------------------------*/

/*--------------------InsertionSort---------------------------*/

void InsertionSort(Array a, int n) {
/* Es wird der Bereich a[1] bis a[n] sortiert */
  int i, j;
  for (i=2; i<=n; i++) {
    Item x = a[i]; j = i;
    a[0] = x; 
    while (x<a[j-1]) { a[j] = a[j-1]; j--; }
    a[j] = x;
  }
}
/*------------------------------------------------------------*/


/*--------------------SelectionSort---------------------------*/

void SelectionSort(Array a, int n) {
/* Es wird der Bereich a[1] bis a[n] sortiert */
  int i, j,k;
  Item x;
  for (i=1; i<n; i++) {
	   k=i; x = a[i]; 
       for (j=i+1;j<=n;j++)
		   if (a[j]<x)
		   {
			   k=j; x=a[k];
		   }
	   a[k]=a[i];a[i]=x;
  }
}
/*------------------------------------------------------------*/

/*--------------------BucketSort---------------------------*/

void BucketSort(Array a, int n) {
/* Es wird der Bereich a[1] bis a[n] sortiert */
  int i, j,t=0;

  Item Eimer[ZUFALL_MAX+1];

  for (j=0;j<=ZUFALL_MAX;j++) Eimer[j]=0;

  for (j=0;j<=n;j++)
	  Eimer[a[j]]++;

  for (j=0;j<=ZUFALL_MAX;j++)
	  for (i=0; i<Eimer[j];i++)
		  a[t++]=j;
}
 
/*------------------------------------------------------------*/

void Fill(Array a, int n) {
  int i;
  srand(1234);
  for (i=0; i<=n; i++) a[i] = (Item) (rand()/(float)RAND_MAX*ZUFALL_MAX);
  PrintArray(a, n);
}

int main() {

  Array a;
  int n, t1, t2;
  int i;

  printf("       |  .    T = O(n^2)                        | T = O(n)   |\n");
  printf("    n  |Bubblesort |Insertionsort |Selectionsort | Bucketsort |\n");
  printf("-------+-----------+--------------+--------------+------------|\n");

  for (n=100; n<200000; n*=2) {

    printf("%6d | ", n);
 
    Fill(a, n); 
    t1 = clock(); BubbleSort(a, n);    t2 = clock();
    PrintArray(a, n); PrintTime(t1, t2);

    Fill(a, n);
    t1 = clock(); InsertionSort(a, n); t2 = clock();
    PrintArray(a, n); printf("   ");PrintTime(t1, t2); 

	Fill(a, n);
    t1 = clock(); SelectionSort(a, n); t2 = clock();
    PrintArray(a, n); printf("   ");PrintTime(t1, t2);
  
    Fill(a, n);
    t1 = clock();  for (i=1;i<1000;i++) BucketSort(a, n); t2 = clock();
    PrintArray(a, n); printf(" ");PrintTimeMittelwert(t1, t2, 1000);
    printf("\n");

  }
  
  system("PAUSE");
  
  return 0;
}
