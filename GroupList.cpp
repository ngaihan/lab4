//
//  GroupList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the GroupList class below

#include "GroupList.h"

using namespace std;

GroupList::GroupList() {
	head = nullptr;
}

GroupList::~GroupList() {
	if (head != nullptr) {
		while (head != nullptr) {
			GroupNode* temp = head;
			head = head->getNext();
			delete temp;
		}
	}
}

GroupNode* GroupList::getHead() const {
	return head;
}

void GroupList::setHead(GroupNode* ptr) {
	head = ptr;
}

void GroupList::insert(GroupNode* s) {
	GroupNode* cur = head;
	if (cur == nullptr) {
		head = s;
		return;
	}
	while (cur->getNext() != nullptr) {
		cur = cur->getNext();
	}
	cur->setNext(s);
}

GroupNode* GroupList::remove(string name) {
	GroupNode* cur = head;
	while (cur != nullptr) {
		if (cur->getName() == name) {
			return cur;
		}
		cur = cur->getNext();
	}
	if (cur == NULL) { // Checks for null head and end list
		return nullptr;
	}
}

void GroupList::print() const {
	GroupNode* cur = head;
	cout << "drawing:" << endl;
	while (cur != nullptr) {
		cur->print();
		cur = cur->getNext();
	}
}
