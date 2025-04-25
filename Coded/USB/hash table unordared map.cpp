#include <iostream>
#include <unordered_map>
using namespace std;

/*unordered_map is an associated container that stores elements formed 
by the combination of key-value and a mapped value. The key value is 
used to uniquely identify the element and the mapped value is the 
content associated with the key. Both key and value can be of any 
type predefined or user-defined. 

Internally unordered_map is implemented using Hash Table, the key 
provided to map are hashed into indices of a hash table that is why 
the performance of data structure depends on hash function a lot but 
on an average, the cost of search, insert and delete from the 
hash table is O(1).

Note: 
In the worst case, its time complexity can go from O(1) to O(n2),
especially for big prime numbers.
*/


// Traversing an unordered map

void print(unordered_map<int, string>& mymap) {
    cout << "\n\nkey value pairs in unordered map:\n\n";
    for (auto x : mymap)
        cout << x.first << " " << x.second << endl;

    //by using iterator
    /* unordered_map<int, string>::iterator i;
    for (i = mymap.begin(); i != mymap.end(); i++)
    {
        // i works as a pointer to pair<string, double>
        // type i->first has key part and i->second has value part
        cout << i->first << "  " << i->second << endl;
    }*/
}


int main()
{
    //un ordered map
    unordered_map<int, string> unMymap;

    // displaying values after applying hash functions on keys
    unordered_map<int, string>::hasher fn = unMymap.hash_function();
    cout << "\n\nhash values of keys that are used in unordared map\n\n";
    cout << "70: " << fn(70) << endl;
    cout << "1: " << fn(1) << endl;
    cout << "3: " << fn(3) << endl;
    cout << "2: " << fn(2) << endl;
    cout << "100: " << fn(100) << endl;


    // inserting values by using [] operator
    unMymap[70] = "Ali";
    unMymap[1] = "Umar";
    unMymap[3] = "Usman";
    unMymap[2] = "Ayesha";
    unMymap[100] = "Ali";

    print(unMymap);

    int key = 0;
    cout << "enter key to find value == ";
    cin >> key;

    unordered_map<int, string>::iterator i = unMymap.find(key);
    if (i == unMymap.end())
        cout << key << " not found\n\n";

    // If key found then iterator to that key is returned
    else
        cout << "value for key " << key <<" is ==> "<<i->second << "\n\n";

    //Insert function
    unMymap.insert({ 6, "Fatima" });

    //Delete a value by providing its key
    unMymap.erase(4);
    unMymap.erase(70);

    print(unMymap);
    return 0;

}
