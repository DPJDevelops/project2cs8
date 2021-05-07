
#ifndef GRAPH_H
#define GRAPH_H
#include <cassert>
#include <vector>
#include "list.h"
#include "stadium.h"

struct stadiumNode{

    stadiumNode(){}
    stadiumNode(string src, string des, int dist, bool visited = false){
        _src = src;
        _des = des;
        _distancetoSrc = dist;
        _visited = visited;
    }
    string _src;        // ATT - the source stadium
    string _des;        // ATT - the destination stadium
    int _distancetoSrc; // ATT - the distance to the source
    bool _visited;      // ATT - if this stadium has been visited

    friend ostream& operator << (ostream& out,              // OUT - output str
                                 const stadiumNode& l){     // IN -  node to out
        out << l._src << ", " << l._des << ", " << l._distancetoSrc;
        return out;
    }

};
class graph
{
public:

    friend class MainWindow;
    graph();
    ~graph();


    stadium getStadiumInfo(string stadiumName); // IN -  stadium name

    stadiumNode getedge(string stadiumSrc, // IN -  stadium source name
                        string stadiumDes);// IN -  stadium destination name

    List<stadiumNode> getedges(string stadiumSrc); // IN -  stadium source name


    void addStadium(stadium s); // IN -  stadium to add to list

    void addEdge(string src,        // IN -  stadium source to add
                 string des,        // IN -  stadium desintaton to add
                 int distance);     // IN -  distance between


    List<stadium> getAmericanLeagueStadiums();

    List<stadium> getNationalLeagueStadiums();

    List<stadium> getStadiumWithGrassField();

    List<stadium> getStadiumListForDijkstras();



    int getSize();



    List<stadiumNode> shortestPath(string src,  // IN -  stadium source name
                                   string des,  // IN -  stadium destin name
        const List<stadium>& = List<stadium>());// IN -  list to visit

    List<stadiumNode> shortestPath(const List<stadium>&,// IN -  list to visit
                                   string src);         // IN -  stadium to strt




    stadiumNode getDistance(string des,     // IN - destination
                const List<stadiumNode>&);  // IN - list of nodes visited

    void checkSingleVertex(List<stadiumNode>& getsReturned, // IN -  list to chk
                           string src);                     // IN -  source std

    void dijkstras(List<stadiumNode>& getsReturned,  // IN -  stadium connection
                   List<stadiumNode> edges);         // IN - used to cal path

    bool allVisited(const List<stadiumNode>&);  // IN -  list to check

    bool allVisited(const List<stadiumNode>&,   // IN -  list to check against
                    const List<stadium>&);      // IN -  list to check

    bool checkVisited(const List<stadiumNode>& me,// IN -  list to check
                      string des);                // IN -  stadium name to check

    stadiumNode shortestTotalDistance
            (const List<stadiumNode>&);// IN - list with distances

    stadiumNode shortestTotalDistance
        (const List<stadiumNode>& result_dijkstras, // IN -  previous alg result
                    const List<stadium>& toVisit,   // IN - stadiums to visit
                const List<stadiumNode>& visited);  // IN - stadiums visited

    void initForShortestPath(const List<stadium>&, // IN - stadiums to visit
                             List<stadiumNode>&,   // IN - init this
                             string src);          // IN - start here

    bool checkExist(const List<stadiumNode>&, // IN - check this list
                    string toCheck);          // IN - if this exits

    void removeStadium(List<stadiumNode>&,      // IN - list to remove val
                       string toRemove);        // IN - nm of stadium to rem

    void removeStadium(List<stadium>&,         // IN - list to remove val
                       string toRemove);       // IN - nm of stadium to rem


private:


    List<stadium> sort(string LeagueType = "all",   // IN - sort by league
                       bool grassSurface = false,   // IN - sort by surface
                       bool byTeamName = false,     // IN - sort by team name
                       bool byDate = false);        // IN - sort by open date


    int getLength(List<stadiumNode>);

    List<stadium> stadiums;             // ATT - list of stadiums
    List<List<stadiumNode> > adjList;   // ATT - list of edges
    int _size;                          // ATT - total # of stadiums
};

#endif // GRAPH_H
