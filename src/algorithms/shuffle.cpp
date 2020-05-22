#include <iostream>
#include <vector>
#include <algorithm>   // std::swap
#include <cstdlib>     // srand()
#include <ctime>       // time()

void shuffle(std::vector<int> &vec)
{
    srand(time(NULL));
    for(int i = vec.size() - 1; i > 0; --i)
    {
        std::swap(vec[i], vec[rand() % (i + 1)]);
    }
}

void print(std::vector<int> &vec)
{
    for(auto v : vec)
    {
        std::cout << v << " ";
    }    
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10}; 
    shuffle(vec);
    print(vec);    
    return 0;
}
