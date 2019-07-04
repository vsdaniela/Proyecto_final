#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

template <class T>
class linked_list
{
    struct node
    {
        T dato;
        node * p_next;
        node * p_prev;
        node(const T & d, node * n1=nullptr, node * n2= nullptr){
            dato=d;
            p_next=n1;
            p_prev=n2;
        }
    };
    private:
        node * p_head;
        node * p_last;
    public:
    class iterator
    {
        private:
            node* n;
        public:
            iterator(node * n_= nullptr){
                n=n_;
            }
            T & operator * (){
                return n->dato;
            }
            iterator & operator ++(){
                n=n->p_next;
                return *this;
            }
            iterator & operator --(){
                n=n->p_prev;
                return *this;
            }
            bool operator != (const iterator & it){
                return n!=it.n;
            }
            ~iterator()=default;
    };
    public:
        linked_list(): p_head(nullptr),p_last(nullptr){
        }
        ~linked_list(){
            node * del= p_head;
            node * del2= p_last;
            while(del){
                p_head=del->p_next;
                delete del;
                del=p_head;
            }
            while(del2){
                p_last=del2->p_next;
                delete del2;
                del2=p_last;
            }
        }
        void push_back(const T& d){
            node* tmp=new node(d);
            if(!p_last) p_head=p_last=tmp;
            p_last->p_next=tmp;
            tmp->p_next= nullptr;
            tmp->p_prev=p_last;
             p_last=tmp;
        }
        void push_front(const T& d){
            node* tmp=new node(d);
            if(!p_head) p_head=p_last=tmp;
            else{
                tmp=p_head;
                p_head=new node(d,p_head,tmp);
            }
        }
        void remove_front(){
            if(!p_head) return;
            node * del= p_head;
            p_head=p_head->p_next;
            delete del;
        }
        void remove_back(){
            if(!p_last) return;
            node * del= p_last;
            p_last=p_last->p_prev;
            delete del;
        }
       /* void remove_this(node &n){
            node * del= n;
            n=n->p_prev;
            delete del;
        }*/
        iterator begin(){
            return iterator(p_head);
        }
        iterator end(){
            return iterator(p_last);
        }
};
#endif

