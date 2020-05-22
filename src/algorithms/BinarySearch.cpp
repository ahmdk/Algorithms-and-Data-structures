#include <iostream>

int binarySearch(int *arr, int val, int start, int end)
{
    int mid;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(arr[mid] == val){ return mid; }
        if(arr[mid] > val) { end = mid - 1; continue; }
        if(arr[mid] < val) { start = mid + 1; continue; }
    }
    return -1;    
}

int main()
{
    int test[] = {8, 25, 32, 47, 59, 78, 83, 91, 100, 115, 190};
    int index_found = binarySearch(test, 59 , 0, 10);
    std::cout << index_found << std::endl;
}   
