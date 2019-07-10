#ifndef BST_H
#define BST_H
#include <iostream>
#include <QMessageBox>
using namespace std;
template <class K, class D>
class bst
{
    struct node
    {
            K key;
            D dato;
            node * p_child[2];
            node(const K & k, const D &d): key(k), dato(d)
            {
                p_child[0]=p_child[1]=nullptr;
            }
            ~node()=default;
    };
    private:
        node * p_root;
        bool find(node **&n, const K &key){
            n= &p_root;
            while(*n){
                if(key==(*n)->key) {return true;}
                n= &(*n)->p_child[key>(*n)->key];
            }
            return false;
        }
    public:
    struct iterator {
                node* n;
                iterator(node ** n_= nullptr){
                    n=n_;
                }
                D & operator * (){
                    return n->dato;
                }
                iterator r_po(){
                    if(n==nullptr){}
                    else{
                        return n;
                        r_po((*n)->p_child[0]);
                        r_po((*n)->p_child[1]);
                    }
                }
    };
    public:
        bst(): p_root(nullptr){}
        bool insert(const K &k, const D &d){
            node ** n=&p_root;
            if(find(n,k)) {return false;}// false porque ya existe
            *n= new node(k,d);//se inserta en la ultima dirección en que quedó n al buscar
        }
        D find(const K &k){
            node **n=&p_root;
            if (find(n,k)==true){
                return (*n)->dato;
            }
            else{

                QMessageBox n_f;
                n_f.setText("not_found");
                n_f.exec();

            }
        }
        D & operator [] (const K &k){
            node ** n=&p_root;
            if(!find(n,k)) {return (*n)->dato;}
            *n= new node(k);
        }
        void remove_leave(node ** &n){
            (*n)=nullptr;
        }
        bool remove (const K &k){
            node **n=&p_root;
            if(!find(n,k)){
                return false;
            }
            else{
                //caso cuando es hoja
                if((*n)->p_child[0]==nullptr && (*n)->p_child[1]==nullptr){
                    remove_leave(n);
                }

            //segundo caso: cuando tienes hijos
            /*else if((*n)->p_child[0] || (*n)->p_child[1]){
                if(!(*n)->p_child[1]){

                }

                else{
                    n=(*n)->p_child[0];
                    while((*n)->p_child[1])
                }
            }
            else{
                //cuando es la raiz :)
            }*/
            }
            return true;
        }
};
#endif
