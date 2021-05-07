#include "souvenir.h"
souvenirs::souvenirs()
{
    _s = new souvenir[1];
       _size = 0;
}

souvenirs::~souvenirs()
{
  delete [] _s;
}

souvenirs::souvenirs(const souvenirs& other)
{
  *this = other;
}

souvenirs& souvenirs::operator = (const souvenirs& other)
{
    this->_s = new souvenir[other._size];
    this->_size = other._size;
    for (int i = 0; i < this->_size; i++){
        this->_s[i] = other._s[i];
    }
    return *this;
}

souvenir& souvenirs::operator [](int index)
{
 return _s[index];
}

int souvenirs::getSize()
{
    return _size;
}

void souvenirs::addSouvenir(souvenir addMe)
{
    souvenirs temp(*this);

    this->_s = new souvenir[this->_size+1];
    for (int i = 0; i < this->_size; i++){
        this->_s[i] = temp._s[i];
    }
    this->_s[_size] = addMe;
    this->_size++;
}
void souvenirs::removeSouvenir(int index)
{
    assert(this->_size >=1);

    souvenirs temp(*this);

    this->_s = new souvenir[this->_size-1];
    for (int i = 0; i < this->_size; i++){
        if (i != index){
            this->_s[i] = temp._s[i];
        }
    }
    this->_size--;

}

int souvenirs::getItemCount(string itemName)
{
    int count = 0;
    for (int i = 0; i < this->_size; i++){
        if (_s[i].getName() == itemName){
            count++;
        }
    }
    return count;

}

bool souvenirs::operator == (const souvenirs& other)
{
    if (this->_size != other._size){
         return false;
     }
     for (int i = 0; i < this->_size; i++){
         if (this->_s[i].getName() != other._s[i].getName()){
             return false;
         }
     }
     return true;
}
