
//
//  HurricaneDataBase.cpp
//  Hurricane Surfer Project
//
//  Created by Aaron Bloomfield on 11/8/18.
//  CPSC 340 Section 1

#ifndef HURRDB_CPP
#define HURRDB_CPP
#include "HurricaneDataBase.h"
#include "HurricaneEntry.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;


//This is the constructor for the hurricane database that reads in the file
HurricaneDataBase :: HurricaneDataBase(string filename){
	string line;
	ifstream input(filename);
	while(input.good()){
		getline(input, line);
		HurricaneEntry temp(line);
		//cout<<line << endl;
		//cout << temp << endl;

		database.InsertInOrder(temp);
	}

	//database.PrintAll();


}

//This function sorts and prints the hurricaneEntry info by year
void HurricaneDataBase :: PrintStormsByYear(){
    cout << "Prints out the numbers of storms per year" << endl;
	HurricaneEntry tempVar;

	linked_list<HurricaneEntry> temp;
	database.RemoveFront(tempVar);
	
	if(tempVar.getKey()==0){ //Checks if it matches key for year
		
		database.InsertFront(tempVar); //inserts tempVar back into database
		database.PrintAll(); //prints the database
	}
	else{
	    tempVar.setKey(0);
	    database.InsertFront(tempVar);
		while(!database.IsEmpty()){ 

			database.RemoveFront(tempVar); //removes the front variable in the linked list and passes back by reference
			tempVar.setKey(0); //sets the key to 0
			temp.InsertInOrder(tempVar); //inserts tempvar in a temporary linked list in order
		}
		while(!temp.IsEmpty()){
			temp.RemoveFront(tempVar);
			database.InsertRear(tempVar); //puts tempvar back in order in the linked list
		}
		database.PrintAll();    
	}

}

//This function sorts and prints the number of tropical storms in order
void HurricaneDataBase :: SortsPrintsByNumberofTropicalStorms(){
    cout << "Tropical Storms Least to the Most over Time" << endl;
    HurricaneEntry tempVar;

	linked_list<HurricaneEntry> temp;
	database.RemoveFront(tempVar);

	if(tempVar.getKey()==2){ //checks to see if the key matches tropical storms
		
		database.InsertFront(tempVar);
		database.PrintAll();
	}
	else{
	    tempVar.setKey(2);
	    database.InsertFront(tempVar);
		while(!database.IsEmpty()){

			database.RemoveFront(tempVar);
			tempVar.setKey(2);
			temp.InsertInOrder(tempVar);
		}
		while(!temp.IsEmpty()){
			temp.RemoveFront(tempVar);
			database.InsertRear(tempVar);
		}
		database.PrintAll();    
	}
}


//This function sorts and prints by the number of hurricanes
   void HurricaneDataBase :: SortsPrintsByNumberofHurricanes(){
    cout << "Hurricanes Least to the Most over Time" << endl;
    HurricaneEntry tempVar;

	linked_list<HurricaneEntry> temp;
	database.RemoveFront(tempVar);
	
	if(tempVar.getKey()==1){//checks to see if the key matches the number of hurricanes
		
		database.InsertFront(tempVar);
		database.PrintAll();
	}
	else{
	    tempVar.setKey(1);
	    database.InsertFront(tempVar);
		while(!database.IsEmpty()){

			database.RemoveFront(tempVar);
			tempVar.setKey(1);
			temp.InsertInOrder(tempVar);
		}
		while(!temp.IsEmpty()){
			temp.RemoveFront(tempVar);
			database.InsertRear(tempVar);
		}
		database.PrintAll();    
	}
   }


//This function sorts and prints by the number of major hurricanes
   void HurricaneDataBase :: SortsPrintsByNumberofMajorStorms(){
    cout << "Major Storms Least to the Most over Time" << endl;
    HurricaneEntry tempVar;

	linked_list<HurricaneEntry> temp;
	database.RemoveFront(tempVar);
	
	if(tempVar.getKey()==3){ //checks to see if the key matches major storms
		
		database.InsertFront(tempVar);
		database.PrintAll();
	}
	
	else{
	    tempVar.setKey(3);
	    database.InsertFront(tempVar);
		while(!database.IsEmpty()){

			database.RemoveFront(tempVar);
			tempVar.setKey(3);
			temp.InsertInOrder(tempVar);
		}
		while(!temp.IsEmpty()){
			temp.RemoveFront(tempVar);
			database.InsertRear(tempVar);
		}
		database.PrintAll();    
	}
   }


//This function sorts and prints by the number of deaths
   void HurricaneDataBase :: SortsPrintsByNumberofDeaths(){
            HurricaneEntry tempVar;
    cout << "Lost of Life Due to Storms Least to the Most over Time" << endl;
	linked_list<HurricaneEntry> temp;
	database.RemoveFront(tempVar);
	
	if(tempVar.getKey()==4){ //checks to see if the key matches deaths
		
		database.InsertFront(tempVar);
		database.PrintAll();
	}
	else{
	    
	    tempVar.setKey(4);
	    database.InsertFront(tempVar);
		while(!database.IsEmpty()){

			database.RemoveFront(tempVar);
			tempVar.setKey(4);
			temp.InsertInOrder(tempVar);
		}
		while(!temp.IsEmpty()){
			temp.RemoveFront(tempVar);
			database.InsertRear(tempVar);
		}
		database.PrintAll();    
	}
   }
   ostream & operator<<(ostream &out, HurricaneEntry temp){
    //cout<<"Temp ="<<temp.getKey()<<endl;
	if(temp.getKey() == 0){ //Overload operators for basic infor including year, hurricane, Trop. Storm, and strongest storm
		string ex;
		for(int i=0; i<temp.getnumHurricanes(); i++){
			ex = ex +"*";
		}
		string pound;
		for(int i=0; i<temp.getnumTropicalStorms(); i++){
			pound = pound +"#";
		}
		int i=0;
		out<<temp.getYear()<<endl;
		out<<"Hurricanes -" << ex <<endl;
		out<<"Tropical St-" << pound <<endl;
		if(temp.getStrongestStorms().at(i).find(" ") != string::npos){
		    out<<"Largest Storms -" << temp.getStrongestStorms().at(i) << " ";
		}
		else{
		    out<<"Largest Storm -" << temp.getStrongestStorms().at(i) << " ";
		}
		
		

	}else if(temp.getKey() == 1){ //overload operator for number of hurricanes
		string ex;
		for(int i=0; i<temp.getnumHurricanes(); i++){
			ex = ex +"*";
		}
		out<<temp.getYear()<<"-" << ex;
		
	}
	else if(temp.getKey() == 2){ //overload operator for number of tropical storms
	 string pound;
	   for(int i=0; i<temp.getnumTropicalStorms(); i++){
	   pound = pound +"#";
	   }
	   out << temp.getYear() << "-" << pound;
	}
	else if(temp.getKey() == 3){ //overload operators for number of major hurricanes
	    string pound;
	   for(int i=0; i<temp.getnumMajorHurricanes(); i++){
	   pound = pound +"X";
	   }
	   out << temp.getYear() << "-" << pound;
	}
	else if(temp.getKey() == 4){ //overload operator for number of deaths
	    if(temp.getnumDeaths() == -999){
	        out << temp.getYear() << "-" << "Unknown";
	    }
	    else{
	        out << temp.getYear() << "-" << temp.getnumDeaths();
	    }
	   
	}
	
	return out;
}
#endif
