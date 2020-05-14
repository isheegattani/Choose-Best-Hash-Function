#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "ItemCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
    unsigned int d=0;
    d = barcode/1000000;
    return d;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d;
    d = barcode / 100000;
    d = d % 10;
    return d;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d;
    d = barcode / 10000;
    d = d % 10;
    return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
  // TO BE COMPLETED
    unsigned int d;
    d = barcode / 1000;
    d = d % 10;
    return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d;
    d = barcode / 100;
    d = d % 10;
    return d;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct6(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d;
    d = barcode / 10;
    d = d % 10;
    return d;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct7(unsigned int barcode) {
    // TO BE COMPLETED
    unsigned int d;
    d = barcode % 10;
    return d;
}


// Constructor for struct Item
Item::Item(string itemColor, string itemShape, string itemBrand,
		 unsigned int barcode):itemColor_(itemColor),itemShape_(itemShape), itemBrand_(itemBrand),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemColor;
    string itemShape;
    string itemBrand;
    unsigned int barcode;
    while (myfile >> itemColor >> itemShape >> itemBrand >> barcode) {
			if (itemColor.size() > 0)
      	addItem(itemColor, itemShape, itemBrand, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemCollection::addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode) {
    Item t;
    t.barcode_ = barcode;
    t.itemBrand_ = itemBrand;
    t.itemColor_ = itemColor;
    t.itemShape_ = itemShape;


    hT1.insert({ barcode ,t });
    hT2.insert({ barcode ,t });
    hT3.insert({ barcode ,t });
    hT4.insert({ barcode ,t });
    hT5.insert({ barcode ,t });
    hT6.insert({ barcode ,t });
    hT7.insert({ barcode ,t });
 
        


    
  // TO BE COMPLETED
  // function that adds the specified pair of glasses to main display (i.e., to all hash tables)
}

bool ItemCollection::removeItem(unsigned int barcode) {
  // TO BE COMPLETED
  // function that removes the pair of glasses specified by the barcode from the display
  // if pair is found, then it is removed and the function returns true
  // else returns false
    hT1.erase(barcode);
    hT2.erase(barcode);
    hT3.erase(barcode);
    hT4.erase(barcode);
    hT5.erase(barcode);
    hT6.erase(barcode);
    hT7.erase(barcode);

   
    return true;
}

unsigned int ItemCollection::bestHashing() {
    // TO BE COMPLETED
    // function that decides the best has function, i.e. the ones among
    // fct1-fct7 that creates the most balanced hash table for the current
    // ItemCollection data member allItems

      // Hints:
      // Calculate the balance of each hashtable, one by one.
    unsigned int balance[8];
    unsigned int min_loc;

    int min = hT1.bucket_size(1), max = hT1.bucket_size(1);
    for (unsigned i = 0; i < 10; ++i)
    {
        if (hT1.bucket_size(i) <= min)
            min = hT1.bucket_size(i);
        if (hT1.bucket_size(i) >= max)
            max = hT1.bucket_size(i);
        // Call bucket_size() to get the size of each bucket
    }
    balance[0] = max - min;
    min = hT2.bucket_size(1), max = hT2.bucket_size(1);
    for (unsigned i = 0; i < 10; ++i)
    {
        if (hT2.bucket_size(i) <= min)
            min = hT2.bucket_size(i);
        if (hT2.bucket_size(i) >= max)
            max = hT2.bucket_size(i);
        // Call bucket_size() to get the size of each bucket
    }
    balance[1] = max - min;
    min = hT3.bucket_size(1), max = hT3.bucket_size(1);
    for (unsigned i = 0; i < 10; ++i)
    {
        if (hT3.bucket_size(i) <= min)
            min = hT3.bucket_size(i);
        if (hT3.bucket_size(i) >= max)
            max = hT3.bucket_size(i);
        // Call bucket_size() to get the size of each bucket
    }
    balance[2] = max - min;
    min = hT4.bucket_size(1), max = hT4.bucket_size(1);
    for (unsigned i = 0; i < 10; ++i)
    {
        if (hT4.bucket_size(i) <= min)
            min = hT4.bucket_size(i);
        if (hT4.bucket_size(i) > max)
            max = hT4.bucket_size(i);
        // Call bucket_size() to get the size of each bucket
    }
    balance[3] = max - min;
    min = hT5.bucket_size(1), max = hT5.bucket_size(1);
    for (unsigned i = 0; i < 10; ++i)
    {
        if (hT5.bucket_size(i) <= min)
            min = hT5.bucket_size(i);
        if (hT5.bucket_size(i) >= max)
            max = hT5.bucket_size(i);
        // Call bucket_size() to get the size of each bucket
    }
    balance[4] = max - min;
    min = hT6.bucket_size(1), max = hT6.bucket_size(1);
    for (unsigned i = 0; i < 10; ++i)
    {
        if (hT6.bucket_size(i) <= min)
            min = hT6.bucket_size(i);
        if (hT6.bucket_size(i) >= max)
            max = hT6.bucket_size(i);
        // Call bucket_size() to get the size of each bucket
    }
    balance[5] = max - min;
    min = hT7.bucket_size(1), max = hT7.bucket_size(1);
    for (unsigned i = 0; i < 10; ++i)
    {
        if (hT7.bucket_size(i) <= min)
            min = hT7.bucket_size(i);
        if (hT7.bucket_size(i) >= max)
            max = hT7.bucket_size(i);
        // Call bucket_size() to get the size of each bucket
    }
    balance[6] = max - min;
    min_loc = balance[0];
    // Then, calculate the lowest balance
    int a;
    for (int i = 0; i < 7; i++)
    {
        if (balance[i] <= min_loc)
            min_loc = balance[i];

    }
    for (int i = 0; i < 7; i++)
    {
        if (balance[i] == min_loc)
            return i + 1;

    }
}

// ALREADY COMPLETED
size_t ItemCollection::size() {    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}
