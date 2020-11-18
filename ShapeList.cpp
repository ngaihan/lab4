//
//  ShapeList.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.

//  ECE244 Student:
//  Write the implementation (and only the implementation) of the ShapeList class below

#include "ShapeList.h"
using namespace std;

ShapeList::ShapeList() {
	head = nullptr;
}

ShapeList::~ShapeList() {
	ShapeNode* cur = head;
	ShapeNode* temp = nullptr;
	while (cur != nullptr) {
		temp = cur;
		cur = cur->getNext();
		delete temp;
	}
}

ShapeNode* ShapeList::getHead() const {
	return head;
}

void ShapeList::setHead(ShapeNode* ptr) {
	head = ptr;
}

ShapeNode* ShapeList::find(string name) const {
	ShapeNode* cur = head;
	while (cur != nullptr) {
		if (cur->getShape()->getName() == name) return cur;
		cur = cur->getNext();
	}
	return cur;
}

void ShapeList::insert(ShapeNode* s) {
	ShapeNode* cur = head;
	if (cur == nullptr) {
		head = s;
		return;
	}
	while (cur->getNext() != nullptr) {
		cur = cur->getNext();
	}
	cur->setNext(s);
}

ShapeNode* ShapeList::remove(string name) {
	ShapeNode* cur = head;
	ShapeNode* prev = nullptr;
	while (cur != nullptr) {
		if (cur->getShape()->getName() == name) break;
		prev = cur;
		cur = cur->getNext();
	}
	if (cur == nullptr) { // Name not found
		return cur;
	}
	else if (cur == head) { // Remove head ShapeNode
		head = head->getNext();
		return cur;
	}
	prev->setNext(cur->getNext());
	return cur;
}

void ShapeList::print() const {
	ShapeNode* cur = head;
	if (head == nullptr) return;
	while (cur != nullptr) {
		cur->print();
	}
}
