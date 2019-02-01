//
//  main.cpp
//  Hurricane Surfer Project
//
//  Created by Aaron Bloomfield on 11/8/18.
//  CPSC 340 Section 1
//

#ifndef HurricaneDataBase__h
#define HurricaneDataBase__h
#include <iostream>
#include <fstream>
#include <string>

#include "HurricaneEntry.h"
#include "linked_list.h"
using namespace std;

class HurricaneDataBase {
public:
    const int YEAR=0; //Used to compare or print out Year Informatiuon
    const int HURRICANE= 1; //Used to compare or print out hurricane information
    const int STORM = 2;  //Used to compare or print out tropical storms
    const int MAJOR = 3; //Used to compare or print out Major Storms
    const int DEATHS = 4;   //Used to compare or print out deaths based on year
    const int STRONGEST = 5; //Used to compare or print out Strongest Storms
    
    //This is the constructor for the hurricane database that reads in the file
    HurricaneDataBase(string filename);
    
    //This function sorts and prints the hurricaneEntry info by year
    void PrintStormsByYear();
    
    //This function sorts and prints the number of tropical storms in order
    void SortsPrintsByNumberofTropicalStorms();
    
    //This function sorts and prints by the number of hurricanes
    void SortsPrintsByNumberofHurricanes();
    
    //This function sorts and prints by the number of major hurricanes
    void SortsPrintsByNumberofMajorStorms();
    
    //This function sorts and prints by the number of deaths
    void SortsPrintsByNumberofDeaths();
private:
    linked_list<HurricaneEntry> database;
};


#endif /* HurricaneDataBase__h */
