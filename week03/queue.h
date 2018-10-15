#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T& dt,Node<T>* nxt = nullptr)
    {
        data = dt;
        next = nxt;
    }
};

template <typename T>
class Queue
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t size;
    void copy(const Queue& other)
    {
        Node<T>* temp = other.first;
        for(size_t i = 0; i < other.getSize(); i++)
        {
            this->push(temp->data);
            temp = temp->next;
        }
    }
    void erase()
    {
        while(!empty())
        {
            this->pop();
        }
    }
public:
    Queue()
    {
        this->first = nullptr;
        this->last = nullptr;
        this->size = 0;
    }
    Queue(const Queue& other)
    {
        this->copy(other);
    }
    Queue& operator=(const Queue& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }

        return *this;
    }
    const T& front() const
    {
        if(this->first != nullptr)
        {
            return this->first->data;
        }

        return NULL;
    }
    const T& back() const
    {
        if(this->last != nullptr)
        {
            return this->last->data;
        }
    }
    void pop()
    {
        if(!empty())
        {
           Node<T>* temp = first;
           this->first = this->first->next;
           delete temp;
           this->size--;
        }
    }
    void push(const T& data)
    {
        Node<T>* newNode = new Node(data);
        if(empty())
        {
            this->first = newNode;
            this->last = newNode;
        }
        else
        {
            this->last->next = newNode;
            this->last = newNode;
        }
        this->size++;
    }
    bool empty() const
    {
        return this->size == 0;
    }
    size_t getSize() const
    {
        return this->size;
    }
    ~Queue()
    {
        this->erase();
    }
};