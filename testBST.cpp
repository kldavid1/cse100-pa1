/*
 * Filename: testBST.cpp
 * Author: Kenneth David, Marianne Thio
 * Userid: kldavid, cs100sgz
 * Description: Tester class to test the implementations of the BSTInt methods
 * Date: Apr 11 2018
 * Sources of Help: None
 */
#include "BSTInt.h"
#include "BST.hpp"
#include "BSTIterator.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

/**
 * A test driver for the BST int class and class template.
 * PA1 CSE 100 2016
 * Author: Christine Alvarado and YOU
 * TODO: Add more tests
 */
int main() {

     BSTInt b1;

    /* Create an STL vector of some ints */
    /*test*/
    vector<int> v;
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    v.push_back(100);
    v.push_back(-33);

    /* Create an instance of BST holding int */
    BSTInt b;

    // Could use: for(auto item : v) { instead of the line below
    for(int item : v) {
        bool pr = b.insert(item);
        if(! pr ) {
            cout << "Incorrect bool return value when inserting " << item 
                 << endl;
            return -1;
        }
    }

    /* Test size immediately after inserting */
    cout << "Size after inserting is: " << b.size() << endl;
    if( b.size() != 5 ) {
      cout << "... which is incorrect." << endl;
      return -1;
    }


    /* Test size. */
    cout << "Size is: " << b.size() << endl;
    if(b.size() != v.size()) {
        cout << "... which is incorrect." << endl;
        return -1;
    }

    /* Test find return value. */
    // Test the items that are already in the tree
    for(int item : v) {
        if(!b.find(item)) {
            cout << "Incorrect return value when finding " << item << endl;
            return -1;
        }
    }

    /* Test find on item not in tree */
    int node = 50;
    bool dne = b.find(node);
    if(dne) {
      cout << "Incorrect bool return value when finding item that doesnt" <<
      " exist: " << node << endl;
    }

    /* Insert a duplicate element into the BST */
    node = 4;
    bool duplicate = b.insert(node);
    if(duplicate) {
      cout << "Incorrect bool return value when inserting duplicate item: ";
      cout << node << endl;
      return -1;
    }

    /* Testing if empty tree returns correct size */
    if( b1.size() != 0 ) {
      cout << "Incorrect size for empty BST.." << endl;
      cout << "Expected: 0 " << "Actual: " << b1.size() << endl;
      return -1;
    }

    /* Testing empty on non-empty BST */
    if( b.empty() ) {
      cout << "Incorrect bool return value for non-empty BST." << endl;
    }

    /* Testing empty on BST with no elements */
    if( !b1.empty() ) {
      cout << "Incorrect bool return value for empty BST." << endl;
    }

    /* Testing height on empty BST */
    int height = b1.height();
    if( height != -1 ) {
      cout << "Incorrect height for empty BST." << endl;
      cout << "Expected: -1  Actual: " << height << endl;
    }

    /* Testing height on BST with >1 elements */
    height = b.height();
    if( height != 2 ) {
      cout << "Height was " << height << endl;
      cout << ".... which is incorrect" << endl;
    }

    /* Testing height on BST with only root */
    b1.insert(50);
    height = b1.height();
    if( height!= 0 ) {
      cout << "Height for one node tree was " << height << endl;
      cout << ".... which is incorrect" << endl;
    }


    /* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */

    /*
    // Test the template version of the BST  with ints 
    BST<int> btemp;
    for (int item : v) {
        // The auto type here is the pair of BSTIterator<int>, bool
        cout << "Inserting " << item << " into the int template-based BST...";
        auto p = btemp.insert(item);
        if (*(p.first) != item) {
            cout << "Wrong iterator returned.  "
                 << "Expected " << item << " but got " << *(p.first) << endl;
            return -1;
        }
        if (!p.second) {
            cout << "Wrong boolean returned.  Expected true but got " 
                 << p.second << endl;
            return -1;
        }
        cout << "success!" << endl;
              
    }

    // Now test finding the elements we just put in
    for (int item: v) {
        cout << "Finding " << item << "...." << endl;
        BSTIterator<int> foundIt = btemp.find(item);
        if (*(foundIt) != item) {
            cout << "incorrect value returned.  Expected iterator pointing to "
                 << item << " but found iterator pointing to " << *(foundIt) 
                 << endl;
            return -1;
        }
        cout << "success!" << endl;
    }



    // Test the iterator: The iterator should give an in-order traversal
  
    // Sort the vector, to compare with inorder iteration on the BST
    sort(v.begin(),v.end());

    cout << "traversal using iterator..." << endl;
    auto vit = v.begin();
    auto ven = v.end();

    // This is equivalent to BSTIterator<int> en = btemp.end();
    auto en = btemp.end();

    //This is equivalent to BST<int>::iterator it = btemp.begin();
    auto it = btemp.begin();
    for(; vit != ven; ++vit) {
        if(! (it != en) ) {
            cout << *it << "," << *vit 
                 << ": Early termination of BST iteration." << endl;
            return -1;

        }
        cout << *it << endl;
        if(*it != *vit) {
            cout << *it << "," << *vit 
                 << ": Incorrect inorder iteration of BST." << endl;
            return -1;
        }
        ++it;
    }

    cout << "success!" << endl;

    */

    // ADD MORE TESTS HERE.  You might also want to change what is input
    // into the vector v.

    cout << "All tests passed!" << endl;
    return 0;
}
