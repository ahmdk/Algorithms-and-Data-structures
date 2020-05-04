#include <iostream>

int binarySearch(int *arr, int val, int start, int end)
{
    if(start > end) return -1;
    int mid = start + (end - start)/2;
    if(arr[start] == val) return start;
    if(arr[end] == val) return end;
    if(arr[mid] == val) return mid;    

    if(val > arr[mid])
    {
        return binarySearch(arr, val, mid+1, end);
    } else {
        return binarySearch(arr, val, start, mid);
    }    
    return -1;  // not found
}

int main()
{
    int test[] = {8, 25, 32, 47, 59, 78, 83, 91, 100, 115, 190};
    int found = binarySearch(test, 59 , 0, 10);
    std::cout << found << std::endl;
}   
