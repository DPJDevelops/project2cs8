#ifndef STADIUM_H
#define STADIUM_H
#include <iostream>
#include <sstream>

using namespace std;

class stadium
{
public:

    stadium();
    stadium(string, // IN -  stadium name to set
            string, // IN -  team name to set
            string, // IN -  address to set
            string, // IN -  phone to set
            string, // IN -  open date to set
            string, // IN -  capacity to set
            string, // IN -  league to set
            string, // IN -  field surface to set
            int x = 0,
            int y = 0);

    bool operator == (const stadium& other); // IN - stadium to copy

    string getStadiumName(){
        return _sName;
    }

    string getTeamName(){
        return _teamName;
    }

    string getAddress(){
        return _address;
    }

    string getPhone(){
        return _phone;
    }

    string getOpenDate(){
        return _openDate;
    }

    string getCapacity(){
        return _capacity;
    }

    string getType(){
        return _type;
    }
    string getFieldSurface(){
        return _surface;
    }


    int getXCoor()
    {
        return xPixel;
    }

    int getYCoor()
    {
        return yPixel;
    }

    string getAllInfo();

    void setName(string name){          // IN - stadium name to set
        _sName = name;
    }

    void setTeamName(string tname){     // IN - team name to set
        _teamName = tname;
    }

    void setAddress(string address){    // IN -  address to set
        _address = address;
    }

    void setphone(string phone){        // IN -  phone to set
        _phone = phone;
    }

    void setOpenDate(string openDate){  // IN -  openDate to set
        _openDate = openDate;
    }

    void setCapacity(string capacity){  // IN -  capacity to set
        _capacity = capacity;
    }

    void setType(string type){          // IN -  type to set
        _type = type;
    }

    void setFieldSurface(string surface){   // IN -  surface to set
        _surface = surface;
    }

    void setXCoor(int xpos)             // IN -  x pos to set(for map)
    {
        xPixel = xpos;
    }

    void setYCoor(int ypos)             // IN -  y pos to set(for map)
    {
        yPixel = ypos;
    }

    friend ostream& operator << (ostream& outs,         // OUT -  output stream
                                 const stadium& s){     // IN -  stadium to out
        outs << s._sName;
        return outs;
    }

private:
    string _sName;      //ATT - stadium name
    string _teamName;   //ATT - team name
    string _address;    //ATT - stadium address
    string _phone;      //ATT - stadium phone
    string _openDate;   //ATT - stadium open date
    string _capacity;   //ATT - stadium capacity
    string _type;       //ATT - stadium league type
    string _surface;    //ATT - stadium field surface

    int xPixel;         //ATT - x coor of stadium on map
    int yPixel;         //ATT - y coor of stadium on map
};

#endif // STADIUM_H
