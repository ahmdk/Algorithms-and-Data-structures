#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

struct Node
{
    int x;
    int y;
    Node(): x(0), y(0){}
    Node(int _x, int _y) : x(_x), y(_y){}    
    bool operator==(struct Node &lhs)
    {
        return (x == lhs.x && y == lhs.y);
    }    
    friend std::ostream& operator<<(std::ostream &os, Node &node)
    {
        return os << "(" << node.x << ", " << node.y << ")";
    }
};

struct mycomp
{
    bool operator()(Node &rhs, Node &lhs)
    {
        return ((pow(rhs.x, 2) + pow(rhs.y,2)) > (pow(lhs.x, 2) + pow(lhs.y,2)));         
    }    
};

int main()
{
    std::vector<Node> nodes{{1,2},{-1,3},{5,7},{3,2},{9,-2}};
    std::priority_queue<Node, std::vector<Node>, mycomp> pq{nodes.begin(), nodes.end()};
    Node a = pq.top();
    std::cout << a << std::endl;
    return 0;
}
