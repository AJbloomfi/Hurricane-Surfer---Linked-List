//
//  main.cpp
//  Hurricane Surfer Project
//
//  Created by Aaron Bloomfield on 11/8/18.
//  CPSC 340 Section 1
//
// This code is the creation of a project that takes data about hurricanes and storms contained in a csv
//file and then sorts all of that data, based off of the user's request.

#include "HurricaneDataBase.h"

#include "HurricaneEntry.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ostream & operator<<(ostream &out, HurricaneEntry temp);

int main(){
    
	int option; //variable for the option the user enters
	HurricaneDataBase DB("HurricaneData.csv"); //imports the data from a csv and parses each part of the data
    
    cout << endl;
	cout << "1:Print Yearly Hurricane Data."<<endl;
	cout << "2:Print out Tropical Storms in order from least to most"<<endl;
	cout<< "3:Print out Hurricanes in order from least to most" << endl;
	cout<<"4:Print out Major Hurricanes in order from least to most" << endl;
	cout << "5:Print out Number of Deaths in order from least to most" << endl;
	cout<<"6:Exit" << endl;
	cout << "Enter a choice:";
	cin >> (option);
    if(option == 6){
        cout << "Invalid Input";
    }
    while(option!=6){
	    if(option == 1){
	        
	        cout << "1 Hurricane = * " << endl;
	        cout <<"1 Tropical Storms = #" << endl;
	        
		    DB.PrintStormsByYear(); //Prints the basic storm information, sorting by year
		    
		    cout << "1:Print Yearly Hurricane Data."<<endl;
	        cout << "2:Print out Tropical Storms in order from least to most"<<endl;
	        cout<< "3:Print out Hurricanes in order from least to most" << endl;
	        cout<<"4:Print out Major Hurricanes in order from least to most" << endl;
	        cout << "5:Print out Number of Deaths in order from least to most" << endl;
	        cout<<"6:Exit" << endl;
	        cout << "Enter a choice:";
	        cin >> (option);
	    }
	
	    if(option == 2){
	         DB.SortsPrintsByNumberofTropicalStorms(); //prints the storm information based off of the # of tropical storms
	         cout << "1:Print Yearly Hurricane Data."<<endl;
	        cout << "2:Print out Tropical Storms in order from least to most"<<endl;
	        cout<< "3:Print out Hurricanes in order from least to most" << endl;
	        cout<<"4:Print out Major Hurricanes in order from least to most" << endl;
	        cout << "5:Print out Number of Deaths in order from least to most" << endl;
	        cout<<"6:Exit" << endl;
	        cout << "Enter a choice:";
	        cin >> (option);
	    }
	    if(option ==3){
	        DB.SortsPrintsByNumberofHurricanes(); //prints storm info by number of hurricanes
	        cout << "1:Print Yearly Hurricane Data."<<endl;
	        cout << "2:Print out Tropical Storms in order from least to most"<<endl;
	        cout<< "3:Print out Hurricanes in order from least to most" << endl;
	        cout<<"4:Print out Major Hurricanes in order from least to most" << endl;
	        cout << "5:Print out Number of Deaths in order from least to most" << endl;
	        cout<<"6:Exit" << endl;
	        cout << "Enter a choice:";
	        cin >> (option);
	    }if(option == 4){
	        DB.SortsPrintsByNumberofMajorStorms(); //prints storm info by number of major storms
	        cout << "1:Print Yearly Hurricane Data."<<endl;
	        cout << "2:Print out Tropical Storms in order from least to most"<<endl;
	        cout<< "3:Print out Hurricanes in order from least to most" << endl;
	        cout<<"4:Print out Major Hurricanes in order from least to most" << endl;
	        cout << "5:Print out Number of Deaths in order from least to most" << endl;
	        cout<<"6:Exit" << endl;
	        cout << "Enter a choice:";
	        cin >> (option);
	    }
	    if(option == 5){
	        DB.SortsPrintsByNumberofDeaths();// prints storm information by number of deaths
	        cout << "1:Print Yearly Hurricane Data."<<endl;
	        cout << "2:Print out Tropical Storms in order from least to most"<<endl;
	        cout<< "3:Print out Hurricanes in order from least to most" << endl;
	        cout<<"4:Print out Major Hurricanes in order from least to most" << endl;
	        cout << "5:Print out Number of Deaths in order from least to most" << endl;
	        cout<<"6:Exit" << endl;
	        cout << "Enter a choice:";
	        cin >> (option);
	    }
	 

    }
	return 0;
}


