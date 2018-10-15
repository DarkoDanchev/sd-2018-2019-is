#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node<T>(const T& dt,Node<T>* nxt = nullptr)
    {
        data = dt;
        next = nxt;
    }
};

template <typename T>
class Stack
{
private:
    Node<T>* topElement;
    size_t size;
    void copy(const Stack<T>& other)
    {
        if(other.topElement == nullptr)
        {
            this->topElement = nullptr;
            this->size = 0;
            return;
        }
        this->topElement = new Node<T>(other.topElement->data,other.topElement->next);

        Node<T>* temp1 = this->topElement;
        Node<T>* temp2 = other.topElement;

        while(temp2)
        {
            temp1->next = new Node<T>(temp2->next->data,temp2->next->next);
            temp2 = temp2->next;
            temp1 = temp1->next;
        }

        /*
            Not optimal
        */
        /*
        Stack<T> reverseStack;
        reverseStack.reverseCopy(other);
        this->reverseCopy(reverseStack);
        */
    }

    void print() const
    {
        Node<T>* temp = topElement;

        while(temp != nullptr)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }

    void reverseCopy(const Stack<T>& other)
    {
        Node<T>* temp = other.topElement;

        while(temp)
        {
            this->push(temp->data);
            temp = temp->next;
        }
    }
    void erase()
    {
        while(!this->isEmpty())
        {
            this->pop();
        }
    }
public:
    Stack()
    {
        this->topElement = nullptr;
        this->size = 0;
    }
    Stack(const Stack& other)
    {
        this->copy(other);
    }
    Stack& operator=(const Stack& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }

        return *this;
    }

    ~Stack()
    {
        this->erase();
    }
    void push(const T& element)
    {
        Node<T>* addElement = new Node<T>(element);
        if(this->isEmpty())
        {
           this->topElement = addElement;
        }
        else
        {
            addElement->next = this->topElement;
            this->topElement = addElement;
        }
        this->size++;
    }
    void pop()
    {
        if(!this->isEmpty())
        {
            Node<T>* temp = this->topElement;
            this->topElement = this->topElement->next;
            delete temp;
            this->size--;
        }
    }
    const T& top() const
    {
       if(!this->isEmpty())
       {
           return this->topElement->data;
       }
       throw "Empty stack";

	}
    bool isEmpty() const
    {
        return this->size == 0;
        //return this->topElement == nullptr;
    }
    size_t getSize() const
    {
        return this->size;
    }
};

int main()
{
    Stack<int> st;
    st.push(5);
    try
    {
        int top = st.top();
        cout<<top<<endl;
    }
    catch(const char* msg)
    {
        cout<<msg;
    }
}
