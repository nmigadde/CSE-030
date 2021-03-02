#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

struct Hash{
    int BUCKET;

    list<string> *table;
public:
    Hash(int V);

    void insertItem(string x);

    void deleteItem(int key);

    unsigned long hashFunction(unsigned char *x){
        unsigned long hash = 5381;
        int c;

        while(c = *x++)
            hash = ((hash << 5) + hash) + c;

        return(hash);
    }

    void displayHash();

    bool searchHash(int size, string key);
};

Hash::Hash(int b){
        this->BUCKET = b;
        table = new list<string>[BUCKET];
    }

void Hash::insertItem(string key){
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key){
    long index = hashFunction(key);

    list<int> :: iterator i;
    for (i = table[index].begin();
            i !=table[index].end(); i++){
        if(*i == key)
            break;
    }

    if(i != table[index].end())
        table[index].erase(i);
}

void Hash::displayHash(){
    for (int i = 0; i < BUCKET; i++){
        cout << i;
        for (auto x: table[i])
            cout << "-->" << x;
        cout << endl;
    }
}

bool Hash::searchHash(int size, string key){
    for (int i = 0; i < size; i++){
        if (key == table[i]){
            return true;
        }
    }
    return false;
}

bool search(string* array, int size, string key){
    for (int i = 0; i < size; i++) {
        if (key == array[i]){
            return true;
        }
    }
    return false;
}


int main(int argc, const char * argv[]) {
    
    const int N = 500000;
    
    ifstream in("words.txt");
    
    string word;
    
    string* words = new string[N];

    Hash h(5000);

    int count = 0;
    
    while (in >> word) {
        words[count] = word;
        h.insertItem(word);
        count++;
    }
    
    cout << "Total: " << count << endl << endl;
    
    cout << "| Matching Progress:                      |\n|";
    int matched = 0;
    
    for (int i = 0; i < N; i++){
        string curr = words[i];
        reverse(curr.begin(), curr.end());
        
        /*if (search(words, N, curr)){
            //cout << words[i] << " = " << curr << endl;
            matched ++;
        }*/

        if (h.searchHash(N, curr)){
            matched ++;
        }

        if (i % (N/40) == 0) cout << "-";
    }
    cout << "|" << endl;
    
    
    cout << "Matched: " << matched << endl;
    return 0;
}
