#ifndef BINARY_FILE_H
#define BINARY_FILE_H
#include <iostream>
#include <fstream>
#include "linked_list.h"
#include "imagen.h"
class binary_file
{
public:
    void save_array(linked_list <imagen> &v)
    {
        ofstream f;
        f.open("fichero_proyecto.txt",ios::binary);
        linked_list <imagen>::iterator it= v.begin();
        int  tmp; int tmp_2;
        for(linked_list <imagen>::iterator it= v.begin();it!=v.end();++it){
            f.write((char*)&(*it).id, sizeof(int));
            tmp=(*it).path.size();
            f.write((char *)&tmp, sizeof(int));
            f.write( (*it).path.c_str(), (*it).path.size());
            tmp_2=(*it).name.size();
            f.write((char *)&tmp_2, sizeof(int));
            f.write( (*it).name.c_str(), (*it).name.size());
        }
        f.close();
    }
    void load_array(linked_list <imagen> &v)
    {
        ifstream fin;
        fin.open("f4.bin",ios::binary);
        imagen s;
        linked_list <imagen>::iterator it= v.begin();
        int tmp, tmp_2;
        while(fin.read((char*)&s.id,sizeof(int))){
                fin.read((char *)&tmp,sizeof(tmp));
                char * t= new char [tmp];
                fin.read(t,tmp);
                s.path=t;
                v.push_back(s);
                fin.read((char *)&tmp_2,sizeof(tmp_2));
                char * t_2= new char [tmp_2];
                fin.read(t_2,tmp_2);
                s.name=t;
                v.push_back(s);
                delete []t;
                delete []t_2;
        }
        fin.close();
    }
};

#endif // BINARY_FILE_H
