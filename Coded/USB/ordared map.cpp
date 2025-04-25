#include <iostream>
#include <map>
using namespace std;
/*
std::map is a key-value container that maintains its keys in sorted 
order at all times. Generally std::map is implemented as a 
Self balancing BST like Red-Black Tree of key-value pairs, 
and not a hash map. This means when iterating the key-value pairs 
of a std::map the order will always be known but that 
insertion or lookup (search) is slower than std::unordered_map.

search time     | log(n)              

Insertion time  | log(n) + Rebalance  

Deletion time   | log(n) + Rebalance  

*/

// Traversing an ordered map
void print(map<int, string>& mymap) {

    cout << "\n\nkey value pairs in ordered map:\n\n";
    for (auto x : mymap)
        cout << x.first << " " << x.second << endl;

    //by using iterator
    /* map<int, string>::iterator i;
    for (i = mymap.begin(); i != mymap.end(); i++)
    {
        // i works as a pointer to pair<string, double>
        // type i->first has key part and i->second has value part
        cout << i->first << "  " << i->second << endl;
    }*/
}

int main()
{


    map<int, string> mymap;// key will be of int type and mapped value will be of string

    // inserting values by using [] operator
    mymap[70] = "Ali";
    mymap[1] = "Umar";
    mymap[3] = "Usman";
    mymap[2] = "Ayesha";
    mymap[100] = "Ali";

    print(mymap);

    //Insert function
    mymap.insert({ 6, "Fatima" });
   
    //Delete a value by providing its key
    mymap.erase(4);
    mymap.erase(70);

    print(mymap);
    return 0;

}
