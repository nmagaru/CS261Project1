#include <stdio.h>
#include <stdlib.h>

/* function to create a copy of the array in another specified array */
void makeArrayCopy(int fromArray[], int toArray[], int size)
{
 for (int i = 0; i < size; i++) {
	toArray[i] = fromArray[i];
 }
}

/* function to sort specified array */
void myFavoriteSort(int arr[], int size)
{
 int temp;

 for (int i = 0; i < size; i++) { /* loop through array vals */
	 for ( int j = i; j > 0; j--) { /* iterate through previous value if previous value less than current */
		 if (arr[j] < arr[j - 1]) {
			 temp = arr[j];
			 arr[j] = arr[j - 1];
			 arr[j - 1] = temp;
		}
	}
 }
}

/* function to compare each array val thru addition to a given target val */
int TwoSumFunction(int arr[], int size, int target, int* index1, int* index2)
{
 int arrsum = 0;
 int poscounter = 0;
 int negcounter = 0;

 while ( !((*index1 > (size - 1)) || (*index2 <  0)) ) {
	arrsum = arr[*index1] + arr[*index2];
	
	/* TEST: output statement to check correct array indeces and  sums */ 
	/* printf("%d\n", arrsum);								
	printf("%d and %d\n", *index1, *index2); */

	/* compare sum of each index value to target val */
	if (arrsum > target) {
		negcounter--;
		*index2 = size - 1 + negcounter;
	}
	else if (arrsum < target) {
		poscounter++;
		*index1 = poscounter;
	}
	else if (arrsum == target) {
		return 1;
	}
 }

 return -1; /* return -1 if while loop ends (no sum val is found) */
}

int main (int argc, char** argv)
{
 int val;

 /* create dynamic array first allocated with 100 ints */
 int* myarr;
 int arrsize = 100;
 myarr = (int * )malloc(sizeof(int) * arrsize);

 /* prompt the user for input */
 printf ("Enter in a list of numbers ito be stored in a dynamic array.\n");
 printf ("End the list with the terminal value of -999\n");
 
 /* loop until the user enters -999 */
 scanf ("%d", &val);

 int index = 0;
 int copysize = 0;

 while (val != -999) {
 	/* grow array size if needed, check for full array */
 	if (index == arrsize) {
		int* temparr = myarr;
		myarr = (int * )malloc(arrsize * 2 * sizeof(int));
		
		for (int i = 0; i < arrsize; i++) { /* copy vals to larger array */
			myarr[i] = temparr[i];
		}

		free(temparr);
		arrsize = arrsize * 2;
	}

    	/* store the value into an array */
    	myarr[index] = val;
    	index++;
	copysize++;

	/* TEST: output statement to test array filling */ 	
	/* printf("Added value: %d\n", val); */

    	/* get next value */
    	scanf("%d", &val);
 }

 /* call function to make a copy of the array of values */
 int* copyarr;
 copyarr = (int * )malloc(sizeof(int) * copysize);
 makeArrayCopy(myarr, copyarr, copysize);
 /* TEST: output statement to confirm copied array */	
 /* for (int i = 0; i < copysize; i++ ) {
 	printf("%d ", copyarr[i]);
 }
 printf("\n"); */ 

 /* call function to sort one of the arrays */
 myFavoriteSort(copyarr, copysize);
 /* TEST: output statement to test array sort */ 	
 /* for (int i = 0; i < copysize; i++) {
 	printf("%d ", copyarr[i]);
 }
 printf("\n"); */
	 					
 /* loop until the user enters -999 */
 printf ("Enter in a list of numbers to use for searching.  \n");
 printf ("End the list with a terminal value of -999\n");
 scanf ("%d", &val);

 int index1;
 int index2;
 int twosumresult;

 while (val != -999) {
        /* initialize vars to first and last indices for every val */
	index1 = 0;
	index2 = copysize - 1;

 	/* call function to perform target sum operation */
	/* returns 1 if sum is found, -1 if not found */
	twosumresult = TwoSumFunction(copyarr, copysize, val, &index1, &index2);

 	/* print out info about the target sum results  */
	printf("Target sum: %d\n", val);
	if (twosumresult == 1) {
		printf("Target found: sum of indeces %d and %d\n", index1, index2);
	}
	else if (twosumresult == -1) {
		printf("Target not found\n");
	}
   
 	/* get next value */
 	scanf("%d", &val);
 }

 printf ("Good bye\n");
 return 0;
} 
