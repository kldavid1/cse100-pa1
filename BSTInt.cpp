/*
 * Filename: BSTInt.cpp
 * Author: Kenneth David, Marianne Thio
 * Userid: kldavid, cs100sgz
 * Description: Class that implements a Binary Search Tree in which the elements
 *              in this tree are integers
 * Date: Apr 11 2018
 * Sources of Help: Zybooks assignments: Intro to C++, Binary Search Trees
 */
#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    return true;
  }

  BSTNodeInt* curr = root;
  
  while (curr->left && curr->right) {
    if (item < curr->data) {
      curr = curr->left;
    }
    else if (curr->data < item) {
      curr = curr->right;
    }
    else {
      return false;
    }
  }

  // Ready to insert
  BSTNodeInt* newNode = new BSTNodeInt(item);
  if (item < curr->data) {
    curr->left = newNode;
    newNode->parent = curr;
  }
  else if(curr->data < item) {
    curr->right = newNode;
    newNode->parent = curr;
  }
  else {
    delete newNode;
    return false;
  }

  ++isize;
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  BSTNodeInt* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return true;
    }
  }
  return false;
}

  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

  
/** Return the height of the BST.
    Height of tree with just root node is 0
    height of an empty tree is -1
 */
int BSTInt::height() const
{
  return findHeight(root);
}




/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{
  if(this->size() == 0) {
    return true;
  }
  return false;
}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  // Check to see if Node is null
  if(!n) {
    return;
  }
  
  deleteAll(n->left);
  delete n;
  deleteAll(n->right);
}

/**
 * Will recursivelt find the height of the tree using a postorder
 * traversal
 */
int BSTInt::findHeight(BSTNodeInt* n)
{
  int lheight;
  int rheight;

  if( !n ) {
    return -1;  
  } else if ( !n->left && !n->right ) {
      return 0;
  } else {
      lheight = 1 + findHeight( n->left );
      rheight = 1 + findHeight( n->right );
      if( lheight < rheight ) {
        return rheight;
      } else {
          return lheight;
      }
  }
}
