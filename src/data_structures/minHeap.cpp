#include <iostream>
#include <vector>
#include <algorithm>

class Heap
{
    private:
    std::vector<int> vec;

    public:
    Heap(std::vector<int> &heap) : vec(heap)
    {
        makeHeap(vec);    
    }
    
    int getLeftChild(int parent)
    {
        return 2 * parent + 1;
    }

    int getRightChild(int parent)
    {
        return 2 * parent + 2;
    }

    int getParent(int child)
    {
        return (child - 1) / 2;      
    }

    void swapUp(int node)
    {
        if(node <= 0) return;
        int parent = getParent(node);
        if(vec[parent] > vec[node])
        {
            std::swap(vec[parent], vec[node]);
            swapUp(parent);
        }
    }

    void swapDown(int node)
    {
        int left = getLeftChild(node);
        int right = getRightChild(node);
        int smallest = node;

        if(left < (int)vec.size() && vec[left] < vec[smallest]) smallest = left;
        if(right < (int)vec.size() && vec[right] < vec[smallest]) smallest = right;
        if(smallest != node)
        {
            std::swap(vec[smallest], vec[node]);
            swapDown(smallest);
        }
    }

    void makeHeap(std::vector<int> &vec)
    {
        for(int i = (int)vec.size() / 2; i >= 0; --i)
        {
            swapDown(i);
        }
    }
    
    void insert(int k)
    {
        vec.push_back(k);
        swapUp(vec.size() - 1);        
    }

    int getMin()
    {
        int result = vec.front();
        std::swap(vec.front(), vec.back());
        vec.pop_back();
        swapDown(0);
        return result;
    }
    
    int getSize()
    {
        return vec.size();
    }
};

int main()
{
    std::vector<int> data{4, 10, 3, 40, 2, 97, 67, 55, 38, 12, 18, 74};
    Heap heap(data);
    int heapSize = heap.getSize();
    for(int i = 0; i < heapSize; ++i)
    {
        std::cout << heap.getMin() << " ";
    }
    return 0;
}
