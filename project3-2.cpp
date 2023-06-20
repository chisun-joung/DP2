#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Queue 
{
    std::list<T> lst;
public:
    void Push(const T& data) {
        lst.push_back(data);
    }
    T Pop() {
        T data = lst.front();
        lst.pop_front();
        return data;
    }
    T& Top() {
        return lst.front();
    }
};

int main()
{
    Queue<int> q;
    q.Push(10);
    q.Push(20);
    cout << q.Pop() << endl; // 10
    cout << q.Pop() << endl; // 20
}