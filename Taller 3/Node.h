#include <iostream>
#include <vector>
using namespace std;

class Node{
    private:
        int id;
        string serverName;
        string type;
        vector<Node*> neighbors;

    public:
        Node(int id,string serverName,string type){
            this->id=id;
            this->serverName = serverName;
            this->type = type;
        }
        int getId(){
            return this->id;
        }
        string getServerName(){
            return this->serverName;
        }
        string getType(){
            return this->type;
        }
};