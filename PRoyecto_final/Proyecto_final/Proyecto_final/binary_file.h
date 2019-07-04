#ifndef BINARY_FILE_H
#define BINARY_FILE_H
#include <iostream>
#include <fstream>
#include "linked_list.h"
#include "image.h"
class binary_file
{
public:
    void save_array(linked_list <image> &v)
    {
        ofstream f;
        f.open("fichero_proyecto.txt",ios::binary);
        linked_list <image>::iterator it= v.begin();
        int  tmp; int tmp_2;
        for(linked_list <image>::iterator it= v.begin();it!=++v.end();++it){
            f.write((char*)&(*it).id, sizeof(int));
            tmp=(*it).path.size();
            f.write((char *)&tmp, sizeof(int));
            f.write( (*it).path.c_str(), (*it).path.size());
            tmp_2=(*it).label.size();
            f.write((char *)&tmp_2, sizeof(int));
            f.write( (*it).label.c_str(), (*it).label.size());
        }
        f.close();
    }
    void load_array(linked_list <image> &v)
    {
        ifstream fin;
        fin.open("fichero_proyecto.txt",ios::binary);
        image s;
        //linked_list <image>::iterator it= v.begin();
        int tmp, tmp_2;
        while(fin.read((char*)&s.id,sizeof(int))){    
                fin.read((char *)&tmp,sizeof(int));
                //char * t= new char [tmp];
                char t[tmp+1];
                fin.read(t,tmp);
                t[tmp]='/0';
                s.path=t;
                fin.read((char *)&tmp_2,sizeof(int));
                char t_2[tmp_2+1];
                fin.read(t_2,tmp_2);
                t_2[tmp_2]='\0';
                s.label=t_2;
                v.push_back(s);
                //delete []t;
                //delete []t_2;
        }
        fin.close();
    }
};

#endif // BINARY_FILE_H
