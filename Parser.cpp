//
//  parser.cpp
//  Lab4
//
//  Created by Tarek Abdelrahman on 2020-10-25.
//  Copyright © 2020 Tarek Abdelrahman.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

// This is a pointer to the groups list
// The list itseld must be allocated
GroupList* gList;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

bool invalidName(string name); // Checks for reserved word used for name
bool nameExists(GroupList* list, string name); // Checks for an existing name
bool shapeNameNotFound(GroupList* list, string name); // Checks for shape name
bool groupNameNotFound(GroupList* list, string name); // Checks for group name

int main() {
    // Create the groups list
    gList = new GroupList();
    
    // Create the poo group and add it to the group list
    GroupNode* poolGroup = new GroupNode(keyWordsList[NUM_KEYWORDS-1]);
    gList->insert(poolGroup);
    
    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);    // Get a line from standard input

    while ( !cin.eof () ) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so flags etc. are cleared
        stringstream lineStream (line);
        
        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        
        if (command == keyWordsList[0]) { // Shape
            string name, type;
            int locx, locy, szx, szy;

            lineStream >> name >> type >> locx >> locy >> szx >> szy;

            if (invalidName(name)) { // invalid name
                cerr << "Error: invalid name" << endl;
            }
            else if (nameExists(gList, name) { // name exists
                cerr << "Error: name " << name << " exists" << endl;
            }
            else {
                
            }
        }
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);
        
    }  // End input loop until EOF.
    
    return 0;
}

// Function definitions
bool invalidName(string name) { // Checks for reserved word used for name
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (keyWordsList[i] == name) {
            return false;
        }
    }
    for (int i = 0; i < NUM_TYPES; i++) {
        if (shapeTypesList[i] == name) {
            return false;
        }
    }
    return true;
}

bool nameExists(GroupList* list, string name) { // Checks for an existing name
    GroupNode* curGroup = list->getHead();
    ShapeNode* curShape = nullptr;

    while (curGroup != nullptr) {
        if (curGroup->getName() == name) return true;
        curShape = curGroup->getShapeList()->getHead();
        while (curShape != nullptr) {
            if (curShape->getShape()->getName() == name) return true;
            curShape = curShape->getNext();
        }
        curGroup = curGroup->getNext();
    }

    return false;
}

bool shapeNameNotFound(GroupList* list, string name) { // Checks for shape name
    GroupNode* curGroup = list->getHead();
    ShapeNode* curShape = nullptr;

    while (curGroup != nullptr) {        
        curShape = curGroup->getShapeList()->getHead();
        while (curShape != nullptr) {
            if (curShape->getShape()->getName() == name) return false;
            curShape = curShape->getNext();
        }
        curGroup = curGroup->getNext();
    }

    return true;
}

bool groupNameNotFound(GroupList* list, string name) { // Checks for group name
    GroupNode* curGroup = list->getHead();
    ShapeNode* curShape = nullptr;

    while (curGroup != nullptr) {
        if (curGroup->getName() == name) return false;
        curGroup = curGroup->getNext();
    }

    return true;
}