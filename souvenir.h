
#ifndef SOUVENIR_H
#define SOUVENIR_H
#include <iostream>
#include <cassert>
using namespace std;


struct souvenir{


    souvenir(){}

    souvenir(string name,       // IN -  name of souvenir
             string price){     // IN - price of souvenir
        _name = name;
        _price = price;
    }

    string getName(){
        return _name;
    }


    string getPrice(){
        return _price;
    }


    void setName(string name){  // IN -  name of souvenir
        _name = name;
    }


    void setPrice(string price){    // IN -  price of souvenir
        _price = price;
    }

private:
    string _name;       //ATT- name of souvenir
    string _price;      //ATT- price of souvenir
};


class souvenirs
{
public:

    souvenirs();

    ~souvenirs();


    souvenirs(const souvenirs& other); // IN -  souvenir arr to copy

    souvenirs& operator = (const souvenirs& other); //IN -  souvenir arr to copy

    souvenir& operator [](int index);               // IN -  index to access

    bool operator == (const souvenirs& other);
    



    int getSize();
    int getItemCount(string itemName);


    void addSouvenir(souvenir);     // IN -  souvenir to add to arr

    void removeSouvenir(int index); // IN -  index of souv to rem

private:
    souvenir* _s;   //ATT - souvenir array
    int _size;      //ATT - number of souvenirs
};

#endif // SOUVENIR_H
