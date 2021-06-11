#include <stdio.h>
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    
    if(right < n && arr[largest] < arr[right])
    {
         largest = right;
    }
    
    if(largest != i)
    {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[], int arrLength)
{
    // build max heap
    for(int i = arrLength/2-1; i >= 0; i--)
    {
        heapify(arr,arrLength,i);
    }
    
    for(int i = arrLength -1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        //heapify root element
        heapify(arr,i,0);
    }
    
     
}



int main()
{
    int arr[] = {1, 12, 9, 5, 6, 10};
    int arrLength = sizeof(arr) / sizeof(arr[0]);
    heapsort(arr,arrLength);
    for(int i = 0; i <= arrLength -1; i++)
    {
       printf("%d\n",arr[i]);  
    }
  //  return 0;
}