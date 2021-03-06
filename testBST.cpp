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
 * Ruoxin Huang and Shengyuan Lin
 * TODO: Add more tests
 */
/*
 * 1/18/2017
 * Ruoxin Huang(A99084753) and Shengyuan Lin(A13533001)
 * Assignment 1
 */
int main() {

	/* Create STL vectors of some ints */
	/*test*/
	vector<int> v;
	v.push_back(1);
        v.push_back(2);
        v.push_back(7);
        v.push_back(5);
        v.push_back(3);
        v.push_back(4);
        v.push_back(6);
	v.push_back(100);
	v.push_back(-50);
	v.push_back(-60);
	v.push_back(-55);
	v.push_back(-40);
	
	vector<int> rootDuplicate;
	rootDuplicate.push_back(2);
	rootDuplicate.push_back(3);
	rootDuplicate.push_back(1);
	rootDuplicate.push_back(2);
	rootDuplicate.push_back(5);

	vector<int> middleDuplicate;
	middleDuplicate.push_back(1);
	middleDuplicate.push_back(3);
	middleDuplicate.push_back(2);
	middleDuplicate.push_back(4);
	middleDuplicate.push_back(3);

	vector<int> leafDuplicate;
	leafDuplicate.push_back(1);
	leafDuplicate.push_back(3);
	leafDuplicate.push_back(5);
	leafDuplicate.push_back(2);
	leafDuplicate.push_back(5);

	vector<int> oneChildDuplicate;
	oneChildDuplicate.push_back(2);
	oneChildDuplicate.push_back(3);
	oneChildDuplicate.push_back(1);
	oneChildDuplicate.push_back(4);
	oneChildDuplicate.push_back(3);

	vector<int> succ;
        succ.push_back(1);
        succ.push_back(2);
        succ.push_back(7);
        succ.push_back(6);
        succ.push_back(3);
        succ.push_back(4);
        succ.push_back(5);


	/* Create an instance of BST holding int */
	BSTInt b;

	/*Test Empty*/
	if(!b.empty()){
		cout << "Some error at empty()" <<endl;
		return -1;
	}

	/*Test Height */
	if(b.height() != -1){
		cout << "Some error at height()" << endl;
		return -1;
	}

	/*Test find*/
	for(int item : v) {
		if(b.find(item)) {
			cout << "Incorrect return value when finding " << item << endl;
			return -1;
		}
	}

	/*Test size*/
	if(b.size() != 0) {
		cout << "... which is incorrect." << endl;
		return -1;
	}
	// Could use: for(auto item : v) { instead of the line below
	for(int item : v) {
		bool pr = b.insert(item);
		if(! pr ) {
			cout << "Incorrect bool return value when inserting " << item << "to v" 
				<< endl;
			return -1;
		}
	}


	/* Create an instance of BST holding int */
	BSTInt c;
	int i=0;
	// Could use: for(auto item : v) { instead of the line below
	for(int item : rootDuplicate) {
		bool pr = c.insert(item);
		i++;
		if(pr&&i==4) {
			cout << "Incorrect bool return value when inserting " << item << " to rootDuplicate"
				<< endl;
			return -1;
		}
	}

	/* Create an instance of BST holding int */
	BSTInt d;
	i=0;
	// Could use: for(auto item : v) { instead of the line below
	for(int item : middleDuplicate) {
		bool pr = d.insert(item);
		i++;
		if(pr&&i==5 ) {
			cout << "Incorrect bool return value when inserting " << item << " to middleDuplicate"
				<< endl;
			return -1;
		}
	}

	/* Create an instance of BST holding int */
	BSTInt e;
	i=0;
	// Could use: for(auto item : v) { instead of the line below
	for(int item : leafDuplicate) {
		bool pr = e.insert(item);
		i++;
		if(pr&&i==5 ) {
			cout << "Incorrect bool return value when inserting " << item << " to leafDuplicate"
				<< endl;
			return -1;
		}
	}

	/* Create an instance of BST holding int */
	BSTInt f;
	i=0;
	// Could use: for(auto item : v) { instead of the line below
	for(int item : oneChildDuplicate) {
		bool pr = f.insert(item);
		i++;
		if(pr&&i==5 ) {
			cout << "Incorrect bool return value when inserting " << item << " to oneChildDuplicate"
				<< endl;
			return -1;
		}
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

	/* Test find return value. */
	// Test the items that are already in the tree
	for(int item : rootDuplicate) {
		if(!c.find(item)) {
			cout << "Incorrect return value when finding " << item << endl;
			return -1;
		}
	}

	/* Test find return value. */
	// Test the items that are already in the tree
	for(int item : middleDuplicate) {
		if(!d.find(item)) {
			cout << "Incorrect return value when finding " << item << endl;
			return -1;
		}
	}

	/* Test find return value. */
	// Test the items that are already in the tree
	for(int item : leafDuplicate) {
		if(!e.find(item)) {
			cout << "Incorrect return value when finding " << item << endl;
			return -1;
		}
	}

	/* Test find return value. */
	// Test the items that are already in the tree
	for(int item : oneChildDuplicate) {
		if(!f.find(item)) {
			cout << "Incorrect return value when finding " << item << endl;
			return -1;
		}
	}

	/*Test empty() */

	if(b.empty()){
		cout << "Some error at empty()" <<endl;
		return -1;
	}

	/*Test height*/

	if(c.height() != 2){
		cout << "Some error at height()" << endl;
		return -1;
	}

	/*Test height*/
	if(d.height() != 2){
		cout << "Some error at height()" << endl;
		return -1;
	}

	/*Test height*/
	if(e.height() != 2){
		cout << "Some error at height()" << endl;
		return -1;
	}

	/*Test height*/
	if(f.height() != 2){
		cout << "Some error at height()" << endl;
		return -1;
	}

	/* Test size. */
        if(c.size() != rootDuplicate.size()-1) {
          cout << "Size is: " << c.size() << endl;
          cout << "... which is incorrect." << endl;
          return -1;
        }


	/* Test size. */
        if(d.size() != middleDuplicate.size()-1) {
          cout << "Size is: " << d.size() << endl;
          cout << "... which is incorrect." << endl;
          return -1;
        }

	/* Test size. */
        if(e.size() != leafDuplicate.size()-1) {
          cout << "Size is: " << e.size() << endl;
          cout << "... which is incorrect." << endl;
          return -1;
        }

	/* Test size. */
        if(f.size() != oneChildDuplicate.size()-1) {
          cout << "Size is: " << f.size() << endl;
          cout << "... which is incorrect." << endl;
          return -1;
        }



	
	/*Test height*/
	BSTInt k;
	k.insert(0);
	k.insert(1);
	k.insert(2);
	k.insert(3);
	k.insert(4);
	if(k.height() != 4){
		cout << "Some error at height()" << endl;
		return -1;
	}
	/* Test size. */
	if(c.size() != 4) {
		cout << "It is incorrect." << endl;
		return -1;
	}
	/* Test size. */
	if(d.size() != 4) {
		cout << "It is incorrect." << endl;
		return -1;
	}
	/* Test size. */
	if(e.size() != 4) {
		cout << "It is incorrect." << endl;
		return -1;
	}
	/* Test size. */
	if(f.size() != 4) {
		cout << "It is incorrect." << endl;
		return -1;
	}
	/* Test size. */
	if(k.size() != 5) {
		cout << "It is incorrect." << endl;
		return -1;
	}
	/* UNCOMMENT THE LINES BELOW TO TEST THE TEMPLATE-BASED ITERATOR */
	
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

	// Now test the size method
	cout << "Size is: " << btemp.size() << endl;
	if(btemp.size() != v.size()) {
		cout << "... which is incorrect." << endl;
		return -1;
	}

	/*Test empty() */
	if(btemp.empty()){
		cout << "Some error at empty()" <<endl;
		return -1;
	}

	/*Test height*/
	
	if(btemp.height() != 5){
	  cout << "Some error at height()" << btemp.height() << endl;
		return -1;
	}
	
	BST<int> empty1;

	/*Test empty() */
	if(!empty1.empty()){
		cout << "Some error at empty()" <<endl;
		return -1;
	}

	/*Test height*/
	if(empty1.height() != -1){
		cout << "Some error at height()" << endl;
		return -1;
	}
	
 	/*Test size*/	
	cout << "The size of a empty bst is: " << empty1.size() << endl;
	if(empty1.size() != 0) {
		cout << "... which is incorrect." << endl;
		return -1;
	}
	
	/*Test find*/
	for(int item : v) {
	BSTIterator<int> foundIt = empty1.find(item);
	if ((foundIt) != BSTIterator<int>(nullptr)) {
		cout << "incorrect value returned. This is a empty BST and should not be able to find the object. "
		<< endl;
		return -1;
		}
	}

	empty1.insert(1);
	
	/*Test empty() */
	if(empty1.empty()){
		cout << "Some error at empty()" <<endl;
		return -1;
	}

	/*Test height*/
	if(empty1.height() != 0){
		cout << "Some error at height()" << endl;
		return -1;
	}
	
 	/*Test size*/	
	cout << "The size of a empty bst is: " << empty1.size() << endl;
	if(empty1.size() != 1) {
		cout << "... which is incorrect." << endl;
		return -1;
	}

	/*Test find*/
	BSTIterator<int> foundIt = empty1.find(1);
	if ((*foundIt) != 1) {
		cout << "incorrect value returned. "
		<< endl;
		return -1;
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

	//Test the overloaded operator != and ==
	auto be = btemp.begin();
	
	if(en != en){
		cout << "Incorrect != operator" << endl;
		return -1;
	}

	if(be == en){
		cout << "Incorrect == operator" << endl;
		return -1;
	}

	if(!(be == be)){
		cout << "Incorrect == operator" << endl;
		return -1;	
	}

	if(!(be != en)){
		cout << "Incorrect != operator" << endl;
		return -1;	
	}
	// ADD MORE TESTS HERE.  You might also want to change what is input
	// into the vector v.

	//Test for another vector
	BST<int> ctemp;
	for(int item : rootDuplicate) {
	        ctemp.insert(item);
	}	
	
	// Now test finding the elements we just put in
	for (int item: rootDuplicate) {
	cout << "Finding " << item << "...." << endl;
	BSTIterator<int> foundIt = ctemp.find(item);
	if (*(foundIt) != item) {
	cout << "incorrect value returned.  Expected iterator pointing to "
	<< item << " but found iterator pointing to " << *(foundIt) 
	<< endl;
	return -1;
	}
	cout << "success!" << endl;
	}

	// Now test the size method
	cout << "Size is: " << ctemp.size() << endl;
	if(ctemp.size() != 4) {
		cout << "... which is incorrect." << endl;
		return -1;
	}

	/*Test empty() */
	if(ctemp.empty()){
		cout << "Some error at empty()" <<endl;
		return -1;
	}

	/*Test height*/
	if(ctemp.height() != 2){
		cout << "Some error at height()" << endl;
		return -1;
	}
	
	
	
	/* Create an instance of BST holding int */
        BST<int> c1;
        i=0;
        // Could use: for(auto item : v) { instead of the line below
        for(int item : rootDuplicate) {
          bool pr =  (c1.insert(item).second);
          i++;
          if(pr&&i==4) {
            cout << "Incorrect bool return value when inserting " << item << " to rootDuplicate"
                 << endl;
            return -1;
          }
        }

        /* Create an instance of BST holding int */
        BST<int> d1;
        i=0;
        // Could use: for(auto item : v) { instead of the line below
        for(int item : middleDuplicate) {
          bool pr =  (d1.insert(item).second);
          i++;
          if(pr&&i==5 ) {
            cout << "Incorrect bool return value when inserting " << item << " to middleDuplicate"
                 << endl;
            return -1;
          }
        }

        /* Create an instance of BST holding int */
        BST<int> e1;
        i=0;
        // Could use: for(auto item : v) { instead of the line below
        for(int item : leafDuplicate) {
          bool pr =  (e1.insert(item).second);
          i++;
          if(pr&&i==5 ) {
            cout << "Incorrect bool return value when inserting " << item << " to leafDuplicate"
                 << endl;
            return -1;
          }
	}

        /* Create an instance of BST holding int */
        BST<int> f1;
        i=0;
        // Could use: for(auto item : v) { instead of the line below
        for(int item : oneChildDuplicate) {
          bool pr =  (f1.insert(item).second);
          i++;
          if(pr&&i==5 ) {
            cout << "Incorrect bool return value when inserting " << item << " to oneChildDuplicate"
                 << endl;
            return -1;
          }
        }

       
	// Test the items that are already in the tree
	for(int item : rootDuplicate) {
	  if(!*(c1.find(item))) {
	    cout << "Incorrect return value when finding " << item << endl;
	    return -1;
	  }
	}

	/* Test find return value. */
	// Test the items that are already in the tree
	for(int item : middleDuplicate) {
	  if(!*(d1.find(item))) {
	    cout << "Incorrect return value when finding " << item << endl;
	    return -1;
	  }
	}

	/* Test find return value. */
	// Test the items that are already in the tree
	for(int item : leafDuplicate) {
	  if(!*(e1.find(item))) {
	    cout << "Incorrect return value when finding " << item << endl;
	    return -1;
	  }
	}

	/* Test find return value. */
	// Test the items that are already in the tree
	for(int item : oneChildDuplicate) {
	  if(!*(f1.find(item))) {
	    cout << "Incorrect return value when finding " << item << endl;
	    return -1;
	  }
	}
	
	/* Test size. */
	if(c1.size() != rootDuplicate.size()-1) {
	  cout << "Size is: " << c1.size() << endl;
	  cout << "... which is incorrect." << endl;
	  return -1;
        }
	
	/* Test size. */
        if(d1.size() != middleDuplicate.size()-1) {
          cout << "Size is: " << d1.size() << endl;
          cout << "... which is incorrect." << endl;
          return -1;
        }

	/* Test size. */
        if(e1.size() != leafDuplicate.size()-1) {
          cout << "Size is: " << e1.size() << endl;
          cout << "... which is incorrect." << endl;
          return -1;
        }

	/* Test size. */
        if(f1.size() != oneChildDuplicate.size()-1) {
          cout << "Size is: " << f1.size() << endl;
          cout << "... which is incorrect." << endl;
          return -1;
        }
	
	cout << "All tests passed!" << endl;
	return 0;
}
