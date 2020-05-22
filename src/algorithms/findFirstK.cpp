// find index of the first occurrence of a value = k in a sorted array/vector
// the same can be achieved using the standard library's std::lower_bound function
#include <iostream>
#include <vector>

int findFirstKHelper(std::vector<int> &vec, int k, int start, int end)
{
    int result = -1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(vec[mid] == k) {result = mid; end = mid - 1;}
        else if(vec[mid] < k) {start = mid + 1;}
        else {end = mid - 1;}
    }
    return result;
}

int findFirstK(std::vector<int> &vec, int k)
{
    return findFirstKHelper(vec, k, 0, vec.size() - 1);
}

int main()
{
    std::vector<int> vec{1, 2, 2, 2, 3, 3, 4, 5, 6, 6, 7, 7, 9};
    int index = findFirstK(vec, 6);
    std::cout << index << std::endl;
    return 0;
}
