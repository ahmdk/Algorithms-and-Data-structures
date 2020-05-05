/* Given a non-empty array of integers, return the k most frequent elements.*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

struct compare
{
    bool operator()(std::pair<int, int> a, std::pair<int, int> b)
    {
        if (a.second < b.second)
            return true;
        if (a.second == b.second)
            return true;
        return false;
    }
};

std::vector<int> topKFrequent(std::vector<int> &nums, int k)
{
    std::vector<int> result;
    std::unordered_map<int, int> hashmap;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, compare> heap;
    for (auto num : nums)
    {
        hashmap[num] += 1;
    }
    for (auto i = hashmap.begin(); i != hashmap.end(); i++)
    {
        heap.push(*i);
    }
    for (int i = 0; i < k; ++i)
    {
        result.push_back((heap.top().first));
        heap.pop();
    }
    return result;
}
