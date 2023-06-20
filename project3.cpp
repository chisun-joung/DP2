#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Queue : private std::list<T>
{
public:
    void Push(const T& data) {
        std::list<T>::push_back(data);
    }
    T Pop() {
        T data = std::list<T>::front();
        std::list<T>::pop_front();
        return data;
    }
    T& Top() {
        return std::list<T>::front();
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