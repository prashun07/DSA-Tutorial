#include <iostream>
#include <list>
using namespace std;

template <typename T>class Queue //Abstract class (Interface in C++)
{
public:
    virtual void push(T data) = 0;
    virtual void pop() = 0;
    virtual int size() = 0;
    virtual int isEmpty() = 0;
    virtual T front() = 0;
    virtual T back() = 0;
};
template <typename T>
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
    my_queue<int> q;
    my_queue<string>queue;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
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
    cout<<"another queue"<<endl;
      int n=q.size();
    for (int i = 0; i < n; i++)
    {
        cout << "Queue Front: " << q.front() << " " << q.size() << endl;
        q.pop();
    }
    
    // queue.pop();
    cout << (queue.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}