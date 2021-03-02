#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

// Provide the definition for Graph here, along with anything else you need to make it work...


struct Pairs {
    string vertex;
    string edge;
    Pairs(string a, string b) {
        this->vertex =a;
        this->edge=b;
    }
};

struct Edge{
    std::string label;
    std:: string vertex;
    Edge(std::string label, std::string vertex) {
        this ->label = label;
        this->vertex= vertex;
    }
};

struct Vertex {
    std::string label;
    std::vector<Edge*> adjList;
    
    Vertex(std::string label){
        this->label = label;
    }
};

struct Triplet {
    string parent;
    string vertex;
    string edge;
    
    Triplet(string p, string v, string e){
        this->parent = p;
        this->vertex = v;
        this->edge = e;
    }
};

struct Graph {
    std::vector<Vertex*> vertices;
    Graph() {
        
}
    void vertexInsert(std::string newVert){
        Vertex* v= new Vertex(newVert);
            vertices.push_back(v);
        }

    void edgeInsert(std::string title, std::string from,std::string to) {
        int source=0, dst=0;
        
        for(int i=0;i<vertices.size();i++){
            if (vertices[i]->label==from){
                source=i;}
        
            if(vertices[i]->label==to){
                dst=i;}
        }
        
    
        vertices[source]->adjList.push_back(new Edge(title,to));
        vertices[dst]->adjList.push_back(new Edge(title,from));
        
        
    }
    bool contains(std::vector<std::string>queue,std::string value) {
        for(int i=0;i<queue.size(); i++) {
            if(queue[i]==value) {
                return true;
            }
        }
        return false;
    }
    void print() {
        for (int i=0;i<vertices.size(); i++) {
            if(vertices[i] !=NULL) {
                std::cout<<vertices[i]->label<<": ";
                for(int j=0;j<vertices[i]->adjList.size();j++) {
                    std::cout<<vertices[i]->adjList[j]->label<<" ";
                }
                std::cout<<std::endl;
            }
        }
    }
    bool chain(string start,string dest){
        std::deque<string>q;
        q.push_front(start);
        
        std::vector<string> seen;
        std::vector<Triplet*> parent;
        parent.push_back(new Triplet(start, " ", " "));
        std::deque<Pairs*> path;
        
        while(!q.empty()){
            string curr=q.at(0);
            q.pop_front();
            seen.push_back(curr);
            //std:: cout<<"Now visting " << curr <<std::endl;
            
            if(curr == dest){
                string temp = curr;
                
                while(temp!=start) {
                    int k;
                    for(k=0;k<parent.size();k++){
                        if(parent[k]->vertex==temp) {
                            break;
                        }
                    }
                    path.push_front(new Pairs(parent[k]->vertex, parent[k]->edge));
                    temp = parent[k]->parent;
                }
                cout<<seen[0];
                
                for(int i=0;i<path.size();i++) {
                    std:: cout<< "("<<path[i]->edge << ") " <<path[i]->vertex;
                }
               cout<<endl;
                return true;
            }
            int n;
            for(n=0;n<vertices.size();n++){
                if(vertices[n]->label==curr) {
                    break;
            }
        }
            Vertex* v= vertices[n];
            
            for(int i=0;i<v->adjList.size();i++) {
                if(!contains(seen,v->adjList[i]->vertex)){
                    q.push_back(v->adjList[i]->vertex);
                    seen.push_back(v->adjList[i]->vertex);
                    parent.push_back(new Triplet (curr,v->adjList[i]->vertex, v->adjList[i]->label));
                }
            }
        }
                cout<< start << "is not connected to " <<dest<<endl;
        return false;
    }
};

int main(int argc, const char * argv[]) {
  

        // The graph that stores the movie database
    Graph imdb;
    
    
    // Each actor is a vertex
    imdb.vertexInsert("Al Pacino");
    imdb.vertexInsert("Robert De Niro");
    imdb.vertexInsert("Marlon Brando");
    imdb.vertexInsert("Mark Hamill");
    imdb.vertexInsert("Harrison Ford");
    imdb.vertexInsert("Sean Connery");
    imdb.vertexInsert("Kevin Costner");
    imdb.vertexInsert("John Cena");
    
    // If two actors have been in a movie together,
    // they are connected by an edge
    // The edge is labelled witht the name of the movie
    
    imdb.edgeInsert("The Godfather", "Al Pacino", "Marlon Brando");
    imdb.edgeInsert("Heat", "Al Pacino", "Robert De Niro");
    
    imdb.edgeInsert("Star Wars", "Mark Hamill", "Harrison Ford");
    imdb.edgeInsert("Indiana Jones", "Harrison Ford", "Sean Connery");
    imdb.edgeInsert("The Untouchables", "Sean Connery", "Kevin Costner");
    imdb.edgeInsert("The Untouchables", "Robert De Niro", "Kevin Costner");
    imdb.edgeInsert("The Untouchables", "Robert De Niro", "Sean Connery");
    
    
    imdb.chain("Marlon Brando", "Robert De Niro");
    imdb.chain("Sean Connery", "Harrison Ford");
    imdb.chain("Kevin Costner", "Al Pacino");
    imdb.chain("Mark Hamill", "John Cena");

//    Expected output:
//
//    Marlon Brando (The Godfather) Al Pacino (Heat) Robert De Niro
//    Sean Connery (Indiana Jones) Harrison Ford
//    Kevin Costner (The Untouchables) Robert De Niro (Heat) Al Pacino
//    Mark Hamill is not connected to John Cena
    
    return 0;
}
