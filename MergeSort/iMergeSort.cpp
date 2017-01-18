#include "iMergeSort.hpp"

iMergeSort::iMergeSort(){
    iArraySize = 100;
    iArrayEnd = 0;
    
    int *itArray = new int[iArraySize];
    
    iArray = itArray;
}

iMergeSort::~iMergeSort(){
    delete [] iArray;
}

void iMergeSort::iMerge(int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int *L, *R;
    L = new int[n1];
    R = new int[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = iArray[l + i];
    for (j = 0; j < n2; j++)
        R[j] = iArray[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            iArray[k] = L[i];
            i++;
        }
        else{
            iArray[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1){
        iArray[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2){
        iArray[k] = R[j];
        j++;
        k++;
    }
    
    delete [] L;
    delete [] R;
    
}

void iMergeSort::itMergeSort(){
    int curr_size;  // For current size of subarrays to be merged
                   // curr_size varies from 1 to n/2
    int left_start; // For picking starting index of left subarray
                    // to be merged

    // Merge subarrays in bottom up manner.  First merge subarrays of
    // size 1 to create sorted subarrays of size 2, then merge subarrays
    // of size 2 to create sorted subarrays of size 4, and so on.
    for (curr_size=1; curr_size<=iArrayEnd; curr_size = 2*curr_size)
    {
        // Pick starting point of different subarrays of current size
        for (left_start=0; left_start<iArrayEnd; left_start += 2*curr_size)
        {
            // Find ending point of left subarray. mid+1 is starting 
            // point of right
            

            int right_end = min(left_start + 2*curr_size - 1, iArrayEnd);
            int mid = (left_start + right_end) / 2;
            // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
            iMerge(left_start, mid, right_end);
        }
    }
}

int iMergeSort::min(int x, int y){
    return (x<y)? x : y;
}

void iMergeSort::iAddInt(int x){
    if(iArrayEnd == iArraySize){
        iExpandArray();
        iArray[iArrayEnd++] = x;
        return;
    } else{
        iArray[iArrayEnd++] = x;
        return;
    }
}


void iMergeSort::iExpandArray(){
    iArraySize *= 2;
    int *newArray = new int[iArraySize];
    for(int i=0; i<iArrayEnd; i++){
        newArray[i] = iArray[i];
    }
    delete [] iArray;
    iArray = newArray;
}

void iMergeSort::printArray(int size){
    int i;
    for (i=0; i < size; i++){
        std::cout << iArray[i] << " ";
    }
        
}
 
///* Driver program to test above functions */
//int main()
//{
//    int arr[] = {12, 11, 13, 5, 6, 7};
//    int n = sizeof(arr)/sizeof(arr[0]);
// 
//    printf("Given array is \n");
//    printArray(arr, n);
// 
//    mergeSort(arr, n);
// 
//    printf("\nSorted array is \n");
//    printArray(arr, n);
//    return 0;
//}