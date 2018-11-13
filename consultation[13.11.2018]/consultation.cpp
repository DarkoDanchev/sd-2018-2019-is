#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct SNode
{
    T data;
    SNode<T>* next;

    SNode(const T& dt, SNode<T>* nxt = nullptr)
    {
        data = dt;
        next = nxt;
    }
};

template<typename T>
struct DNode
{
    T data;
    DNode<T>* next;
    DNode<T>* previous;

    DNode(const T& data, DNode<T>* next, DNode<T>* previous)
    {
        this->data = data;
        this->next = next;
        this->previous = previous;
    }
};

template <typename T>
T getMiddle(SNode<T>* first)
{
    SNode<T> * cur = first, *mid = first;
    /// mid ще сочи средния елемент
    while(cur != nullptr)
    {
        cur = cur->next;
        if(cur != nullptr)
        {
            cur = cur->next;
        }
        mid = mid->next;
    }
    return mid->data;

}

template<typename T>
SNode<T>* reverse(SNode<T>* first)
{
    SNode<T> *crr=first;
    SNode<T> *next=nullptr;
    SNode<T> *prev=nullptr;
    while(crr)
    {
    next=crr->next;
    crr->next=prev;
    prev=crr;
    crr=next;
    }
    first=prev;
    return first;
}
///
template<typename T>
SNode<T>* reverse(SNode<T>*& first)
{
    SNode<T> *crr=first;
    SNode<T> *next=nullptr;
    SNode<T> *prev=nullptr;
    while(crr)
    {
    next=crr->next;
    crr->next=prev;
    prev=crr;
    crr=next;
    }
    first=prev;
    return first;
}

template <typename T>
bool isIncreasing(SNode<T>* first) {
    if(first == nullptr) return false;
    SNode<T>* curr = first;
    while(curr->next != nullptr)
    {
        if(curr->data >= curr->next->data) {
            return false;
        }
        curr = curr->next;
    }
    return true;
}
template<typename T>
SNode<T>* krum(SNode<T>* first)
{
    SNode<T>* crr = first;
    if(!first) return nullptr;
    while(crr->next)
    {
        if(crr->data < crr->next->data)
        {
        SNode<T>* toBeKrumed= crr->next;
        crr->next= crr->next->next;
        delete toBeKrumed;
        }
        else crr = crr->next;
    }
    return first;
}

///[1,2,3,4,5,6] - > [1]
///[2 , 2 , 1, 2] -> [2,2,1]

template <typename T>
struct Skip_Node
{

    int level;
    T data;
    vector<Skip_Node<T>*> forward;
    Skip_Node(const T & _data):data(_data){}
};

Skip_Node<int> *buildSkipList(size_t n)
{
    Skip_Node<int>* first = nullptr, *cur = nullptr;

    first = new Skip_Node<int>(0);
    cur = first;
    for(int i = 1;i <= n;i++)
    {
        cur->forward.push_back(new Skip_Node<int>(i));
        cur = cur->forward[0];
    }
    cur = first;
    for(int i = 0;i<=n;i++)
    {
        if(cur->data % 2 != 0)
        {
            if((cur->forward[0]) != nullptr)
            {
            Skip_Node<int> & tobeSkipped = (cur->forward[0])->forward[0];
            cur->forward.push_back(toBeSkipped);
            }
        }
        cur = cur->forward[0];
    }

    return first;
}



int main()
{

    return 0;
}
