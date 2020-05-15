#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int removeDuplicates(std::vector<int> &vec, std::map<int, int> &duplicates)
{
    int uniqueIdx = 1;
    for(int i = 1; i < (int)vec.size(); ++i)
    {
        if(vec[i-1] != vec[i])
        {
            vec[uniqueIdx++] = vec[i];
        } else
        {
            duplicates[vec[i]]++;
        }            
    }
    return uniqueIdx;
}

int main()
{
    /* C++ STL solution
      vec.erase(std::unique(vec.begin(), vec.end()), vec.end());    
    */ 
    std::vector<int> vec{1,1,2,3,4,4,4,5,6,7,8,8};
    std::map<int, int> duplicates;
    std::vector<int> vec2(vec.begin(), vec.begin() + removeDuplicates(vec, duplicates));  
    for(const auto &i : vec2)
    {
        std::cout << i << " ";
    }    
    std::cout << std::endl;    
    for(const auto &i : duplicates)
    {
        std::cout << i.first << " ";
    }    
    return 0;    
}
