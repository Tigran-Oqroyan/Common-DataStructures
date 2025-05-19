#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable
{
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(int key);
    void insertItem(int key, string value);
    void removeItem(int key);
    string searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const
{
    int sum = 0;
    for (int i = 0; i < hashGroups; ++i)
    {
        sum += table[i].size();
    }
    if (!sum)
    {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key)
{
    return key % hashGroups;
}

void HashTable::insertItem(int key, string value)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    for (auto it = cell.begin(); it != cell.end(); ++it)
    {
        if (it->first == key)
        {
            it->second = value;
            return;
        }
    }
    cell.emplace_back(key, value);
}

void HashTable::removeItem(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    for (auto it = cell.begin(); it != cell.end(); ++it)
    {
        if (it->first == key)
        {
            cell.erase(it);
            return;
        }
    }
    cout << "Key " << key << " not found in table" << endl;
}

string HashTable::searchTable(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    for (auto it = cell.begin(); it != cell.end(); ++it)
    {
        if (it->first == key)
        {
            return it->second;
        }
    }
    return "Key not found";
}

void HashTable::printTable()
{
    for (int i = 0; i < hashGroups; ++i)
    {
        if (!table[i].empty())
        {
            cout << "Group " << i << endl;
            for (auto it = table[i].begin(); it != table[i].end(); ++it)
            {
                cout << "Key: " << it->first << " Value: " << it->second << endl;
            }
        }
    }
}

int main()
{
    HashTable hashTable;

    hashTable.insertItem( 231, "Tigran");
    hashTable.insertItem( 345, "Lilit");
    hashTable.insertItem( 787, "Arkadi");
    hashTable.insertItem( 345, "Erik");
    hashTable.insertItem( 346, "Ani");

    hashTable.printTable();
}