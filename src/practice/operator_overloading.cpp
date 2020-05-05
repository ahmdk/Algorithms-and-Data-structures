#include <iostream>
struct Point
{
    int x;
    int y;
    Point() : x(0), y(0){}
    Point(int _x) : x(_x), y(0){}
    Point(int _x, int _y) : x(_x), y(_y){}
};

std::ostream &operator<<(std::ostream &out, Point &Point)
{
    return out << "(" << Point.x << ", " << Point.y << ")";    
}

bool operator==(Point &lhs, Point &rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}
    
int main()
{
    Point a{10};
    Point b{5,8};
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;
}
