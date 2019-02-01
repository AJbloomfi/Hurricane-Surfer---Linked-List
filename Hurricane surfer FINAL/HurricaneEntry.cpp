#ifndef HURR_CPP
#define HURR_CPP
#include "HurricaneEntry.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Default constructor for Hurricane Entry
HurricaneEntry :: HurricaneEntry(){
    //could do null for all of these
    this -> year = 0000;
    this -> numTropicalStorms = 0;
    this -> numHurricanes = 0;
    this -> numMajorHurricanes = 0;
    this -> numDeaths = 0;
    vector<string> StrongestStorms;
    this -> key = 0;
}

//Non-Default constructor that parses through a line and gathers information needed for
//a hurricaneEntry

HurricaneEntry :: HurricaneEntry(string line){
    
    int position;
    string temp;
    
    //these 4 lines will be the same throughout
    position = line.find(","); //finds the position of a comma
    temp = line.substr(0, position); //puts everything up until a comma into temp
    year = stoi(temp); //converts that to an integer
    line.erase(line.begin(), line.begin()+position+1); //erases that information from the line
    
    
    position = line.find(",");
    temp = line.substr(0, position); 
    numTropicalStorms = stoi(temp);
    line.erase(line.begin(), line.begin()+position+1);
    
    position = line.find(",");
    temp = line.substr(0, position); 
    numHurricanes = stoi(temp);
    line.erase(line.begin(), line.begin()+position+1);
    
    position = line.find(",");
    temp = line.substr(0, position); 
    numMajorHurricanes = stoi(temp);
    line.erase(line.begin(), line.begin()+position+1);
    
    position = line.find(",");
    temp = line.substr(0, position); 
    if(temp == "Unknown"){ //checks if temp is unknown, converts it to a # so that can be converted to an int
        temp = "-999";
    }
    numDeaths = stoi(temp);
    line.erase(line.begin(), line.begin()+position+1);
        
    
    string numStrongStorm = line;
    
    
    //finds all dashes in strongest storms and replaces them with spaces
    /*int newposition = numStrongStorm.find("-");
    for(int i=0; i<numStrongStorm.length(); i++){
        if(newposition!=string::npos){
            numStrongStorm.replace(newposition,1," ");
            newposition = numStrongStorm.find("-", newposition +1);
        
        }
    }*/
    StrongestStorms.push_back(numStrongStorm);
    
    this -> key = 0;
    
}

//setter for year
void HurricaneEntry :: setYear(int year){
    this -> year = year;
}

//getter for year
int HurricaneEntry :: getYear(){
    return this -> year;
}

//setter for tropical storms
void HurricaneEntry :: setnumTropicalStorms(int numTropicalStorms){
    this -> numTropicalStorms = numTropicalStorms;
}

//getter for tropical storms
int HurricaneEntry :: getnumTropicalStorms(){
    return this -> numTropicalStorms;
}

//setter for hurricanes
void HurricaneEntry :: setnumHurricanes(int numHurricanes){
    this -> numHurricanes = numHurricanes;
}

//getter for hurricanes
int HurricaneEntry :: getnumHurricanes(){
    return this -> numHurricanes;
}

//setter for major hurricanes
void HurricaneEntry :: setnumMajorHurricanes(int numMajorHurricanes){
    this -> numMajorHurricanes = numMajorHurricanes;
}

//getter for major hurricanes
int HurricaneEntry :: getnumMajorHurricanes(){
    return this -> numMajorHurricanes;
}

//setter for deaths
void HurricaneEntry :: setnumDeaths(int numDeaths){
    this -> numDeaths = numDeaths;
}

//getter for deaths
int HurricaneEntry :: getnumDeaths(){
    return this -> numDeaths;
}

//getter for strongest storms
vector<string> HurricaneEntry :: getStrongestStorms(){
    
    return this -> StrongestStorms;
}

//getter for the amount of strongest storms
int HurricaneEntry :: getNumberStrongestStorms(){
    int count = 0;
    
    for(int i=0; i<StrongestStorms.size(); i++){
        int newposition = StrongestStorms.at(i).find("-");
        if(newposition!=string::npos){
            count++;
        }
        
    }
    return this -> StrongestStorms.size()+count;
}

//setter for keys
void HurricaneEntry :: setKey(int key){
    this -> key = key;
}

//getter for keys
int HurricaneEntry :: getKey(){
    return this -> key;
}

//overload operators for <,>,<=,>=,==,!=
bool HurricaneEntry :: operator < (HurricaneEntry left){
    if(key == 0){
        if(this -> year < left.year){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 1){
        if(this -> numHurricanes < left.numHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 2){
        if(this -> numTropicalStorms < left.numTropicalStorms){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 3){
        if(this -> numMajorHurricanes < left.numMajorHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 4){
        if(this -> numDeaths < left.numDeaths){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 5){
        if(this -> StrongestStorms < left.StrongestStorms){
            return true;
        }
        else{
            return false;
        }
    }
}


bool HurricaneEntry :: operator > (HurricaneEntry left){
    if(key == 0){
        if(this -> year > left.year){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 1){
        if(this -> numHurricanes > left.numHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 2){
        if(this -> numTropicalStorms > left.numTropicalStorms){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 3){
        if(this -> numMajorHurricanes > left.numMajorHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 4){
        if(this -> numDeaths > left.numDeaths){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 5){
        if(this -> StrongestStorms > left.StrongestStorms){
            return true;
        }
        else{
            return false;
        }
    }
}
bool HurricaneEntry :: operator <= (HurricaneEntry left){
    if(key == 0){
        if(this -> year <= left.year){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 1){
        if(this -> numHurricanes <= left.numHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 2){
        if(this -> numTropicalStorms <= left.numTropicalStorms){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 3){
        if(this -> numMajorHurricanes <= left.numMajorHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 4){
        if(this -> numDeaths <= left.numDeaths){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 5){
        if(this -> StrongestStorms <= left.StrongestStorms){
            return true;
        }
        else{
            return false;
        }
    }
}
bool HurricaneEntry :: operator >= (HurricaneEntry left){
    if(key == 0){
        if(this -> year >= left.year){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 1){
        if(this -> numHurricanes >= left.numHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 2){
        if(this -> numTropicalStorms >= left.numTropicalStorms){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 3){
        if(this -> numMajorHurricanes >= left.numMajorHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 4){
        if(this -> numDeaths >= left.numDeaths){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 5){
        if(this -> StrongestStorms >= left.StrongestStorms){
            return true;
        }
        else{
            return false;
        }
    }
}
bool HurricaneEntry :: operator != (HurricaneEntry left){
    if(key == 0){
        if(this -> year != left.year){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 1){
        if(this -> numHurricanes != left.numHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 2){
        if(this -> numTropicalStorms != left.numTropicalStorms){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 3){
        if(this -> numMajorHurricanes != left.numMajorHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 4){
        if(this -> numDeaths != left.numDeaths){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 5){
        if(this -> StrongestStorms != left.StrongestStorms){
            return true;
        }
        else{
            return false;
        }
    }
}
bool HurricaneEntry :: operator == (HurricaneEntry left){
    if(key == 0){
        if(this -> year == left.year){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 1){
        if(this -> numHurricanes == left.numHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 2){
        if(this -> numTropicalStorms == left.numTropicalStorms){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 3){
        if(this -> numMajorHurricanes == left.numMajorHurricanes){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 4){
        if(this -> numDeaths == left.numDeaths){
            return true;
        }
        else{
            return false;
        }
    }
    if(key == 5){
        if(this -> StrongestStorms == left.StrongestStorms){
            return true;
        }
        else{
            return false;
        }
    }
}

#endif