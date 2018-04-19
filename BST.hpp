#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
      This is inlined because it is trivial.
   */
  BST() : root(nullptr), isize(0) {}


  /** Default destructor.
      Delete every node in this BST.
  */
  ~BST();

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return a pair where the first element is an iterator 
   *  pointing to either the newly inserted element or the element 
   *  that was already in the BST, and the second element is true if the 
   *  element was newly inserted or false if it was already in the BST.
   * 
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=)  
   */
  std::pair<iterator, bool> insert(const Data& item);


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use ==, >, <=, >=).  For the reasoning
   *  behind this, see the assignment writeup.
   */
  iterator find(const Data& item) const;

  
  /** Return the number of items currently in the BST.
   */ 
  unsigned int size() const;
  
  /** Return the height of the BST.
      height of a tree starts with root at height 0
	  height of an empty tree is -1
   */ 
   int height() const;


  /** Return true if the BST is empty, else false.
   */
  bool empty() const;

  /** Return an iterator pointing to the first (smallest) item in the BST.
   */ 
  iterator begin() const;

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const;


private:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;
  
  /** Number of Data items stored in this BST. */
  unsigned int isize;

  /** Find the first element of the BST
   * Helper function for the begin method above.
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root);

  /** do a postorder traversal, deleting nodes
   */
  static void deleteAll(BSTNode<Data>* n);

  /**
   * Helper method for finding height of BST
   */
  static int findHeight(BSTNode<Data> * root);
 };


// ********** Function definitions ****************


/** Default destructor.
    Delete every node in this BST.
*/
template <typename Data>
BST<Data>::~BST() {
  deleteAll(root);
}


/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return a pair where the first element is an iterator pointing to either the newly inserted
 *  element or the element that was already in the BST, and the second element is true if the 
 *  element was newly inserted or false if it was already in the BST.
 * 
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  
 */
template <typename Data>
std::pair<BSTIterator<Data>, bool> BST<Data>::insert(const Data& item) {
  if (!root) {
    root = new BSTNode<Data>(item);
    ++isize;
    return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(root), true);
  }

  BSTNode<Data>* curr = root;
  
  while( curr ) {
    if( item < curr->data ) {
      if( !curr->left ) {
        BSTNode<Data> * newNode = new BSTNode<Data>(item);
        curr->left = newNode;
        newNode->parent = curr;
        curr = nullptr;
      } else {
          curr = curr->left;
      }
    } else if( curr->data < item ){
      if( !curr->right ) {
        BSTNode<Data> * newNode = new BSTNode<Data>(item);
        curr->right = newNode;
        newNode->parent = curr;
        curr = nullptr;
      } else {
          curr = curr->right;
      }
    } else {
        return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(curr), false);
    }
  }

  ++isize;
  return std::pair<BSTIterator<Data>, bool>(BSTIterator<Data>(newNode), true);

}


/** Find a Data item in the BST.
 *  Return an iterator pointing to the item, or pointing past
 *  the last node in the BST if not found.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
template <typename Data>
BSTIterator<Data> BST<Data>::find(const Data& item) const
{
  BSTNodeInt<Data> * curr = root;

  while( curr ) {
    if( curr->data < item ) {
      curr = curr->right;
    }
    else if(item < curr->data) {
      curr = curr-left;
    }
    else{
      return BSTIterator<Data>(curr);
    }
  }
  return BSTIterator<Data>(nullptr);

}

  
/** Return the number of items currently in the BST.
 */ 
template <typename Data>
unsigned int BST<Data>::size() const
{
  return isize;
}

/** Return the height of the BST.
 */
template <typename Data> 
int BST<Data>::height() const
{
  return findHeight(root);
}


/** Return true if the BST is empty, else false.
 */ 
template <typename Data>
bool BST<Data>::empty() const
{
  if( this->size() == 0 ) {
    return true;
  }

  return false;
}

/** Return an iterator pointing to the first (smallest) item in the BST.
 */ 
template <typename Data>
BSTIterator<Data> BST<Data>::begin() const
{
  return BSTIterator<Data>(first(root));
}

/** Return an iterator pointing past the last item in the BST.
 */
template <typename Data>
BSTIterator<Data> BST<Data>::end() const
{
  return BSTIterator<Data>(nullptr);
}

/** Find the first element of the BST
 * Helper function for the begin method above.
 */ 
template <typename Data>
BSTNode<Data>* BST<Data>::first(BSTNode<Data>* root)
{
  if( !root ) {
    return nullptr;
  }

  BST<data> * curr = root;

  while( curr->left ) {
    curr = curr->left;
  }

  return curr;
}

/** do a postorder traversal, deleting nodes
 */
template <typename Data>
void BST<Data>::deleteAll(BSTNode<Data>* n)
{
  if( !n ) {
    return;
  }

  deleteAll( n->left );
  delete n;
  deleteAll( n->right );
}

/**
 * Will recursively find the height of the tree using a postorder traversal
 */
int BST<Data>::findHeight(BSTNode<Data> * n) {
  int lheight;
  int rheight;
  
  if( !n ) {
    return -1;
  }

  else if( !n->left && !n->right ) {
    return 0;
  }

  else {
    lheight = 1 + findHeight( n->left );
    rheight = 1 + findHeight( n->right );

    if( lheight < rheight ) {
      return rheight;
    }

    else {
      return lheight;
    }
  }

}
#endif //BST_HPP
