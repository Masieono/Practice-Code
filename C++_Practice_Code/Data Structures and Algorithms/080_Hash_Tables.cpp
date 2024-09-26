#include <iostream>
#include <list>
#include <string>

/*
    Hashtable - a data structure that stores unique keys to values, like <int, string> or <char, int>
    Each key/value pair is known as an entry.
    Insertion, lookup, and deletion of key/value pairs is very quick
    With a specified key, lookup of the value doesn't require searching the entire table
    Great with larger data sets, not ideal for small data sets.

    Hashing takes a key and computes an integer as an index number. The formula for this varies on the type of hashtable.

    A bucket is an indexed storage location for one or more entries.

    When a hash function generates the same hash for two or more entries, this is known as a collision.

    In the case of a collision, multiple entries are stored in a bucket as a linked list. 
    The less collisions, the more efficient the hashtable is.

    Runtime complexity: 
        Best case O(1) constant time. 
        Worst case O(n) linear time.
*/

using std::cout;
using std::endl;


class HashTable {
    private:
        static const int table_size = 10;

        std::list<std::pair<int, std::string>> table[table_size];
        // ^ an array of lists  ^ int is key, string is value

        // function to map keys to table indices
        int hash_function(int key)
        {
            return key % table_size;
        }

    public:

        void insert_item(int key, const std::string& value)
        {
            int index = hash_function(key);         // Get the index from the hash function
            table[index].emplace_back(key, value);  // Get the list at the hashed index
        }

        void remove_item(int key)
        {
            int index = hash_function(key);     // Get the index from the hash function
            auto& chain = table[index];         // Get the list at the hashed index

            // iterate through the list to find and remove the key
            for (auto it = chain.begin(); it != chain.end(); ++it)
            {
                if (it->first == key)
                {
                    chain.erase(it); // remove the key value pair
                    cout << "Item removed." << endl;
                    return;
                }
            }
            cout << "Key not found." << endl;
        }

        std::string search_item(int key)
        {
            int index = hash_function(key);     // Get the index from the hash hash_function
            auto& chain = table[index];         // Get the list at the hashed index

            // iterate through the list to find the key
            for (auto& pair : chain)
            {
                if (pair.first == key)
                {
                    return pair.second; // return the value associated with the key
                }
            }
            return "Key not found."; // If the key is not found in the list
        }

        void display_hash_table()
        {
            for(int i = 0; i < table_size; i++)
            {
                cout << "Index " << i << ": ";
                for (auto& pair : table[i])
                {
                    cout << "[" << pair.first << ": " << pair.second << "] -> ";
                }
                cout << "NULL" << endl;
            }
        }
};

int main () {

    HashTable hashtable;

    // insert some items into the table
    hashtable.insert_item(1, "Apple");
    hashtable.insert_item(11, "Banana");
    hashtable.insert_item(21, "Cherry");
    hashtable.insert_item(34, "Pear");
    hashtable.insert_item(45, "Grape");
    hashtable.insert_item(64, "Tomato");

    // display the hash table
    hashtable.display_hash_table();

    // search for a key
    cout << "Searching for key 11: " << hashtable.search_item(11) << endl;

    // remove an item
    hashtable.remove_item(11);

    // display the hash table after removal
    hashtable.display_hash_table();

    // search for removed item
    cout << "Searching again for key 11: " << hashtable.search_item(11) << endl;

    return 0;
}