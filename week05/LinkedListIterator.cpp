#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* next;

    Node(const T& data, Node<T>* next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class LinkedList
{
private:
    Node<T>* first;
    Node<T>* last;
    size_t count;

    void copy(const LinkedList& other)
    {
        Node<T>* temp = other.first;
        for(size_t i = 0; i < other.count; i++)
        {
            push_back(temp->data);
            temp = temp->next;
        }

    }
    void destroy()
    {
        while(count > 0)
        {
            this->pop_front();
        }
    }
public:
    LinkedList()
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    LinkedList(const LinkedList& other)
    {
        copy(other);
    }
    LinkedList& operator=(const LinkedList& other)
    {
        if(this != &other)
        {
            destroy();
            copy(other);
        }

        return *this;
    }
    ~LinkedList()
    {
        destroy();
    }
    void print() const
    {
        Node<T>* temp = first;
        while(temp)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }

    }
    size_t size() const
    {
        return this->count;
    }
    void push_back(T data)
    {
        Node<T>* temp = new Node<T>(data,nullptr);
        if(temp)
        {
            if(this->count == 0)
            {
                this->first = temp;
                this->last = temp;
            }
            else
            {
                this->last->next = temp;
                this->last = temp;
            }

            count++;
        }
    }
    void push_front(T data)
    {
        Node<T>* temp = new Node<T>(data,first);
        first = temp;
        count++;
    }
    void pop_back()
    {
        Node<T>* temp = last;
        Node<T>* start = first;
        while(start->next != last)
        {
            start = start->next;
        }
        last = start;
        delete temp;
        count--;

    }

    void push(size_t index,T data)
    {
        Node<T>* temp2 = first;
        Node<T>* temp = new Node<T>(data, nullptr);
        while(index != 0)
        {
            temp2 = temp2->next;
            index--;
        }
        temp->next = temp2->next;
        temp2->next = temp;
        count++;


    }

    T operator[](size_t index) const
    {
        Node<T>* temp = first;
        for(int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    void pop_front()
    {
        Node<T>* temp = first;
        first = first->next;
        delete temp;
        count--;
    }
    Node<T>* goToElement(size_t index)
    {
        if(index < 0 || index >= this->count)
        {
            cout<<"Index can't be smaller than 0 or bigger than list length"<<endl;
            return NULL;
        }
        Node<T>* current = this->first;
        for(size_t i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current;
}
    void pop(size_t index)
    {
    if(!this->size() == 0)
    {
        if(index == 0) this->pop_front();
        else
        {
            Node<T>* removed = this->goToElement(index);
            Node<T>* temp = this->goToElement(index-1);

            if(index == this->size()-1) this->last = temp;
            temp->next = removed->next;
            delete removed;
            this->count--;
        }
    }

    }
    /*
        iterator implementation
    */

    // Inner class iterator
    class iterator {
    friend class LinkedList;
    private:
      Node<T> *current;

      iterator(Node<T> *newNode) : current(newNode) {}
    public:
      iterator() : current(nullptr) {}

      bool operator!=(const iterator& itr) const {
        return current != itr.current;
      }

      bool operator==(const iterator& itr) const {
        return current == itr.current;
      }

      T& operator*() const {
        return current->next->data;
      }

      //postfix
      iterator operator++(int) {
        iterator temp = *this;
        current = current->next;
        return temp;
      }

      //prefix
      iterator& operator++(){
        iterator temp = *this;
        current = current->next;
        return temp;
      }
    };

    iterator begin() const {
      return iterator(first);
    }

    iterator end() const {
      return iterator(last);
    }

    iterator insert(iterator position,const T& value) {
      if(position != nullptr)
      {
        Node<T>* newNode = new Node<T>(value, position.current->next);
        if (position.current == last) last = newNode;
        position.current->next = newNode;
        this->count++;

        return position;
      }
      throw "Cannot insert at position";

    }

    iterator erase(iterator position) {
      Node<T> *toDelete = position.current->next;
      position.current->next = position.current->next->next;
      if (toDelete == last) last = position.current;
      delete toDelete;

      return position;
    }

};
int main()
{

  LinkedList<int> v;

  v.push_back(5);

  //v.insert(v.begin(),2);
  try
  {
    v.insert(v.end(),4);
    v.insert(v.end(),5);
  }
  catch(const char* msg)
  {
    cout<<msg<<endl;
  }
  //v.insert(v.begin(),5);


  cout<<"Size: "<<v.size()<<" Begining: "<<*v.insert(v.end(),2)<<endl;

  /*auto iter = v.begin();
  iter = v.insert(iter, 1);
  iter++;
  v.insert(iter++,3);
  iter++;
  v.insert(iter,10);

  iter = v.begin();
  iter++;
  //v.erase(iter);*/

  /*for(auto itr = v.begin();itr != v.end();++itr)
    std::cout << *itr << std::endl;*/

  return 0;
}
