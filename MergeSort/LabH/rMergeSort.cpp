#include "rMergeSort.hpp"

rMergeSort::rMergeSort(){
    rArraySize = 100;
    rArrayEnd = 0;
    
    int *recArray = new int[rArraySize];
    
    rArray = recArray;
}

rMergeSort::~rMergeSort(){
    delete [] rArray;
}

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void rMergeSort::recMergeSort(int l, int r)
{
   if (l < r)
   {
      int m = l+(r-l)/2; //Same as (l+r)/2 but avoids overflow for large l & h
      recMergeSort(l, m);
      recMergeSort(m+1, r);
      rMerge(l, m, r);
   }
}
 
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void rMergeSort::rMerge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int *L, *R;
    L = new int[n1];
    R = new int[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = rArray[l + i];
    for (j = 0; j < n2; j++)
        R[j] = rArray[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            rArray[k] = L[i];
            i++;
        }
        else
        {
            rArray[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        rArray[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        rArray[k] = R[j];
        j++;
        k++;
    }
    
    delete [] L;
    delete [] R;
}
 

void rMergeSort::rAddInt(int x){
    if(rArrayEnd == rArraySize){
        rExpandArray();
        rArray[rArrayEnd++] = x;
        return;
    } else{
        rArray[rArrayEnd++] = x;
        return;
    }
}

void rMergeSort::rExpandArray(){
    rArraySize *= 2;
    int *newArray = new int[rArraySize];
    for(int i=0; i<rArrayEnd; i++){
        newArray[i] = rArray[i];
    }
    delete [] rArray;
    rArray = newArray;
}


void rMergeSort::printArray(int size){
    int i;
    for (i=0; i < size; i++){
        std::cout << rArray[i] << " ";
        
    }
        
}
 
/* Driver program to test above functions */
//int main()
//{
//    int arr[] = {12, 11, 13, 5, 6, 7};
//    int arr_size = sizeof(arr)/sizeof(arr[0]);
// 
//    printf("Given array is \n");
//    printArray(arr, arr_size);
// 
//    rMergeSort(arr, 0, arr_size - 1);
// 
//    printf("\nSorted array is \n");
//    printArray(arr, arr_size);
//    return 0;
//}