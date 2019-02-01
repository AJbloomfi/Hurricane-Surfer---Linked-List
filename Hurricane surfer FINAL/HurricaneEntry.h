//
//  main.cpp
//  Hurricane Surfer Project
//
//  Created by Aaron Bloomfield on 11/8/18.
//  CPSC 340 Section 1
//

#ifndef HurricaneEntry__h
#define HurricaneEntry__h
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class HurricaneEntry {
    //friending and overloading the out operator
    friend ostream & operator<<(ostream &out, HurricaneEntry temp);
public:

    //default constructor
    HurricaneEntry();
    
    //Non-Default constructor that parses through a line and gathers information needed for
    //a hurricaneEntry
    HurricaneEntry(string line);
    
    //setter for year
    void setYear(int year);
    
    //getter for year
    int getYear();
    
    //setter for tropical storms
    void setnumTropicalStorms(int numTropicalStorms);
    
    //getter for tropical storms
    int getnumTropicalStorms();
    
    //setter for hurricanes
    void setnumHurricanes(int numHurricanes);
    
    //getter for hurricanes
    int getnumHurricanes();
    
    //setter for major hurricanes
    void setnumMajorHurricanes(int numMajorHurricanes);
    
    //getter for major hurricanes
    int getnumMajorHurricanes();
    
    //setter for DEATHS
    void setnumDeaths(int numDeaths);
    
    //getter fro deaths
    int getnumDeaths();
    
    //getter for strongest storms
    vector<string> getStrongestStorms();
    
    //getter for number of strongest storms
    int getNumberStrongestStorms();
    
    //setter for key
    void setKey(int key);
    //Will be one of the constant from above
    //If Hurricane is the key that means the linked list is will be created based year
    
    //getter for key
    int getKey();
    
    //pverload operators
    bool operator< (HurricaneEntry left);
    bool operator> (HurricaneEntry left);
    bool operator<= (HurricaneEntry left);
    bool operator>= (HurricaneEntry left);
    bool operator!= (HurricaneEntry left);
    bool operator== (HurricaneEntry left);
    
private:
    
    int year;
    int numTropicalStorms;
    int numHurricanes;
    int numMajorHurricanes;
    int numDeaths;
    vector<string>    StrongestStorms;
    int key;

    
};


#endif /* HurricaneEntry__h */
