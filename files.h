#ifndef FILES_H
#define FILES_H
#include <fstream>
#include <sstream>
#include "graph.h"
#include "souvenir.h"

void readStadiums(graph &g, List<stadium>& list, string fileName){

    ifstream infile;

       infile.open(fileName);

       string line;            // IN - each line
       stadium toAdd;          // IN - stadium being aded

       if (!infile){
           cout << "file not found. " <<endl;
       }


       int count = 0;
       do{
           getline(infile, line);
           toAdd.setName(line);

           getline(infile, line);
           toAdd.setTeamName(line);

           getline(infile, line);
           toAdd.setAddress(line);

           getline(infile, line);
           toAdd.setphone(line);

           getline(infile, line);
           toAdd.setOpenDate(line);

           getline(infile, line);
           toAdd.setCapacity(line);

           getline(infile, line);
           toAdd.setType(line);

           getline(infile, line);
           toAdd.setFieldSurface(line);

           //x and y coordinates of pixels
           getline(infile, line);
           toAdd.setXCoor(stoi(line));
           getline(infile, line);
           toAdd.setYCoor(stoi(line));

           getline(infile, line);

           if (count < 30){
               cout << "add to user add" <<endl;
               g.addStadium(toAdd);

               count++;
           }
           else {
               cout << "add to default" <<endl;
               list.InsertAfter(toAdd, list.End());

           }

       }while(infile);
       infile.close();
}

void readEdges(graph &g,                        // IN - graph object
               string fileName){                // IN - name of stadium file

    ifstream infile;        // IN - name of file
    infile.open(fileName);

    string line;            // IN - each read line
    string s1;              // IN - temp subtring
    string s2;              // IN - temp substring
    int distance;           // IN - distance of edge

    if (!infile){
        cout << "file not found. " <<endl;
    }
    while (infile){
        getline(infile, line);
        s1 = line.substr(0, line.find(","));
        line = line.substr(line.find(",")+2);
        s2 = line.substr(0, line.find(","));
        line = line.substr(line.find(",")+1);
        distance = stoi(line);
        g.addEdge(s1,s2,distance);
        g.addEdge(s2,s1,distance);
    }
    infile.close();
}


void readSouvenirs(souvenirs& s,            // IN & OUT - souvenir object
                   string fileName){        // IN - name of file
    ifstream infile;            // IN - input stream
      infile.open(fileName);

      string line;                // IN - line to read
      souvenir toAdd;             // IN - souvenir being added

      if (!infile){
          cout << "file not found. " <<endl;
      }

      while (!infile.eof()){
          getline(infile, line);
          toAdd.setName(line.substr(0, line.find(",")));
          line = line.substr(line.find(",")+3);
          toAdd.setPrice(line);

          s.addSouvenir(toAdd);
      }
}

void saveStadiums(graph &g, List<stadium>& newS, string fileName){

    List<stadium> list = g.getStadiumListForDijkstras();
       node<stadium>* w = list.Begin();
       node<stadium>* w2 = newS.Begin();

       ofstream outfile;

       outfile.open(fileName);

       stringstream ss;                            // OUT - stream of strings

       string tostr;

       int coordinate;

       do{
           ss << w->_item.getStadiumName() <<endl;
           ss << w->_item.getTeamName() <<endl;
           ss << w->_item.getAddress() <<endl;
           ss << w->_item.getPhone() <<endl;
           ss << w->_item.getOpenDate() <<endl;
           ss << w->_item.getCapacity() <<endl;
           ss << w->_item.getType() <<endl;
           ss << w->_item.getFieldSurface() <<endl;
           coordinate = w->_item.getXCoor();
           ss << to_string(coordinate) <<endl;
           coordinate = w->_item.getYCoor();
           ss << to_string(coordinate);

           if (w->next != nullptr){
               ss << endl <<endl;
           }

           tostr = ss.str();
           outfile << tostr;

           ss.str( string());
           ss.clear();


           w = w->next;

       }while(w);

       ss.str( string());
       ss.clear();

       if (w2 != nullptr){
           ss << endl <<endl;
       }
       while(w2){
           ss << w2->_item.getStadiumName() <<endl;
           ss << w2->_item.getTeamName() <<endl;
           ss << w2->_item.getAddress() <<endl;
           ss << w2->_item.getPhone() <<endl;
           ss << w2->_item.getOpenDate() <<endl;
           ss << w2->_item.getCapacity() <<endl;
           ss << w2->_item.getType() <<endl;
           ss << w2->_item.getFieldSurface() <<endl;
           coordinate = w2->_item.getXCoor();
           ss << to_string(coordinate) <<endl;
           coordinate = w2->_item.getYCoor();
           ss << to_string(coordinate);

           if (w2->next != nullptr){
               ss << endl <<endl;
           }
           tostr = ss.str();
           outfile << tostr;

           ss.str( string());
           ss.clear();

           w2 = w2->next;
       }

       outfile.close();

}

void saveSouvenirs(souvenirs& s,        // IN - the souvenirs object to read
                   string fileName){    // IN - name of file

    ofstream outfile;                   // OUT - output stream
     outfile.open(fileName);

     for (int i = 0; i < s.getSize(); i++){
         if (i == s.getSize()-1){
             outfile << s[i].getName() << ", $" << s[i].getPrice();
         }
         else{
             outfile << s[i].getName() << ", $" << s[i].getPrice() <<endl;
         }
     }

     outfile.close();
}
#endif // FILES_H
