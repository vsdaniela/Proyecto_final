
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
using namespace std;
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

    public:
        class iterator
        {
            public:
                node* n;

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
        linked_list(): p_head(nullptr){
        }
        ~linked_list(){
            node * del= p_head;

            while(del){
                p_head=del->p_next;
                delete del;
                del=p_head;
            }
        }
        void push_front(const T& d){
            node* tmp= new node(d,p_head,nullptr);
            node* t_b=p_head;
            if(!p_head) p_head=tmp;
            else{
                p_head->p_prev=tmp;
                p_head=tmp;
            }
        }
        void push_back(const T& d){
            node* tmp= new node(d);
            node* t_l=p_head;
            if(!p_head) p_head=tmp;
            else{
                while(t_l->p_next)
                    t_l=t_l->p_next;
                t_l->p_next=new node(d,nullptr,t_l);
             }
        }
        void remove_front(){
            if(!p_head) return;
             node * del = p_head;
             p_head = p_head -> p_next;
             delete del;
        }
        void remove_back(){
            node * tmp = p_head;
            if(p_head)
            {
                while(tmp->p_next)
                {
                    tmp = tmp->p_next;
                    if(tmp)
                    {
                        node * del=tmp;
                        tmp=tmp->p_prev;
                        tmp->p_next=nullptr;
                        delete del;
                    }
                }
            }
        }
        void remove_this(iterator i){
            node * del= i.n;
            if(del->p_prev && del->p_next){
                node * tmp_prev = del->p_prev;
                node * tmp_next = del->p_next;
                tmp_prev -> p_next = tmp_next;
                tmp_next -> p_prev = tmp_prev;
                delete del;
            }
            else if(del==p_head){
                remove_front();
            }
            else{
                remove_back();
            }
        }
        iterator begin(){
            return iterator(p_head);
        }
        iterator end(){
            node* tmp_l = p_head;
            if(!tmp_l->p_next) return iterator(tmp_l);
            while(tmp_l){
                tmp_l=tmp_l->p_next;
                if(tmp_l->p_next==nullptr) return iterator(tmp_l);
            }
        }
};

#endif // LINKED_LIST_H
