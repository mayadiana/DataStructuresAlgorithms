#include "ShortTest.h"
#include <assert.h>
#include "Map.h"
#include "MapIterator.h"
#include <iostream>
using namespace std;

void testAll() { //call each function to see if it is implemented
    Map m;
    assert(m.isEmpty() == true);
    assert(m.size() == 0); //add elements
    assert(m.add(5, 5) == NULL_TVALUE);
    assert(m.add(1, 111) == NULL_TVALUE);
    assert(m.add(10, 110) == NULL_TVALUE);
    assert(m.add(7, 7) == NULL_TVALUE);
    assert(m.add(1, 1) == 111);
    assert(m.add(10, 10) == 110);
    assert(m.add(-3, -3) == NULL_TVALUE);
    assert(m.size() == 5);
    assert(m.search(10) == 10);
    assert(m.search(16) == NULL_TVALUE);
    assert(m.remove(1) == 1);
    assert(m.remove(6) == NULL_TVALUE);
    assert(m.size() == 4);


    TElem e;
    MapIterator id = m.iterator();
    id.first();
    int s1 = 0, s2 = 0;
    while (id.valid()) {
        e = id.getCurrent();
        s1 += e.first;
        s2 += e.second;
        id.next();
    }
    assert(s1 == 19);
    assert(s2 == 19);

}

void testMostFrequent()
{
    Map m;
    assert(m.mostFrequent() == NULL_TVALUE);
    cout << "Test successful for when map is empty" << endl;

    m.add(1, 100);
    assert(m.mostFrequent() == 100);
    cout << "Test successful for when map has 1 element and that is the maximum frequency" << endl;

    m.add(2, 200);
    m.add(3, 100);
    assert(m.mostFrequent() == 100);
    cout << "Test successful for when map has multiple values and the most frequent one is: " << m.mostFrequent() << endl;

    m.add(4, 200);
    TValue frequency = m.mostFrequent();
    assert(frequency == 100 || frequency == 200);
    cout << "Test successful for when map has multiple values with equal frequencies and the most frequent one is: " << m.mostFrequent() << endl;
}