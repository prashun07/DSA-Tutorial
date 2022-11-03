#include <iostream>
#include <list>
using namespace std;
template <typename T>
class Queue
{
public:
    virtual void push(T data) = 0;
    virtual void pop() = 0;
    virtual int size() = 0;
    virtual int isEmpty() = 0;
    virtual T front() = 0;
    virtual T back() = 0;
};
template <class T>
class my_queue : public Queue<T>
{
    list<T> l;

public:
    T front()
    {
        return l.front();
    }
    T back()
    {
        return l.back();
    }
    void push(T data)
    {
        l.push_back(data);
    };
    void pop()
    {
        l.pop_front();
    };
    int size()
    {
        return l.size();
    }
    int isEmpty()
    {
        return l.empty();
    }
};
int main()
{
    // my_queue<int> queue;
    my_queue<string>queue;
    // queue.push(10);
    // queue.push(20);
    // queue.push(30);
    // queue.push(40);
    queue.push("My");
    queue.push("Name");
    queue.push("is");
    queue.push("Prashun");
        cout << queue.size() << endl;
    int Size=queue.size();
    for (int i = 0; i < Size; i++)
    {
        cout << "Queue Front: " << queue.front() << " " << queue.size() << endl;
        queue.pop();
    }
    
    // queue.pop();
    cout << (queue.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}