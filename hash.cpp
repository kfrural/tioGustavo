#include <iostream>
#include <vector>
#include <cstdlib> // For abs()

using namespace std;

constexpr int HASH_TABLE_SIZE = 7;

struct txt{
    string key;
    int count;
};

class HashTable {
public:
    void insert(const string& key) {
        int pos = hash_key(key);
        //cout << "pos: " << pos << endl;
        
        for (auto& entry : table[pos]) {
            if (entry.key == key) {
                entry.count++;
                return;
            }
        }
        
        table[pos].push_back({key, 1});
    }

     bool search(const string& key) const {
        int pos = hash_key(key);
        for (const auto& entry : table[pos]) {
            if (entry.key == key)
                return true;
        }
        return false;
    }

    void remove(const string& key) {
        int pos = hash_key(key);
        auto& bucket = table[pos];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                bucket.erase(it);
                return;
            }
        }
    }
    
    void print() const {
        for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
            cout << "Posicao " << i << ": ";
            for (const auto& entry : table[i]) {
                cout << "{" << entry.key << ": " << entry.count << "} ";
            }
            cout << endl;
        }
    }

private:
    vector<txt> table[HASH_TABLE_SIZE];

    int hash_key(const string& key) const {
        unsigned long hash = 5381;
        for (char c : key) {
            hash = ((hash << 5) + hash) + c; // hash * 33 + c
        }
        return static_cast<int>(hash % HASH_TABLE_SIZE);
    }
};

/*
unsigned long djb2_hash(const unsigned char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}*/

int main() {
    HashTable hashTable;
    
    hashTable.insert("hello");
    hashTable.insert("oi");
    hashTable.insert("hola");
    hashTable.insert("ola");
    hashTable.insert("ola");
    hashTable.insert("ola");
    hashTable.insert("ola");
    
    /*
    cout << "key 'hello' encontrado: " << hashTable.search("hello") << endl;
    cout << "key 'oi' encontrado: " << hashTable.search("oi") << endl;
    cout << "key 'hola' encontrado: " << hashTable.search("hola") << endl;
    cout << "key 'ola' encontrado: " << hashTable.search("ola") << endl;
    */
    
    hashTable.print();
    
   /* cout << "key " << 3 << " encontrada " << hashTable.search(3) << endl;
    cout << "key " << 10 << " encontrada " << hashTable.search(10) << endl;
    cout << "key " << -6 << " encontrada " << hashTable.search(-6) << endl;
    cout << "key " << 6 << " encontrada " << hashTable.search(6) << endl;
    cout << "key " << 9 << " encontrada " << hashTable.search(9) << endl;
    
    hashTable.remove(3);
    
    cout << "key " << 3 << " encontrada " << hashTable.search(3) << endl;
*/
    return 0;
}
