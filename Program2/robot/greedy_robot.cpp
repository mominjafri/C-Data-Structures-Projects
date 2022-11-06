#include <iostream>
#include "greedy_robot.h"
#include <string>
using namespace std;

Robot :: Robot(){ //initial constructor that initializes all variables
    robot_x = 0; 
    robot_y = 0;
    treasure_x = 0;
    treasure_y = 0;
    max_distance = 0;
    ptr = &path;
    maxDistance = &max_distance;
    checkInput(maxDistance, robot_x, robot_y, treasure_x, treasure_y, final_answer, ptr);

}

Robot ::  Robot(int distance, int x1, int y1, int x2, int y2){ //constructor with given parameters that can be assigned to private variables.
    robot_x = x1;
    robot_y = y1;
    treasure_x = x2;
    treasure_y = y2;
    max_distance = 0;
    ptr = &path;
    maxDistance = &max_distance;
    checkInput(maxDistance, robot_x, robot_y, treasure_x, treasure_y, final_answer, ptr);

}


void Robot :: checkInput(int *maxDistance, int x1, int y1, int x2, int y2, string &ans, string *ptr){ 
    if((x1 == x2) || (y1 == y2)){ //if x and y coordinates are equal
        *maxDistance = 0;
        *ptr = "Robot is already at treasure";
    } else {
        return find_shortest_distance(maxDistance, x1, y1, x2, y2, ans, ptr); //call recursive function
    }

}

void Robot :: find_shortest_distance(int *maxDistance,int x1, int y1, int x2, int y2, string &answer, string *ptr){
    if(x1 == x2 && y1 == y2){
        *maxDistance += 1; //++ function doesn't work if its a pointer
        answer = answer + "\n"; //new line
        *ptr += answer; //adding paths
    } 

        if(y1 < y2){ 
            if(x1 < x2){
                RobotEast(maxDistance, x1, y1, x2, y2, answer, ptr); //move East if startpoint is less than endpoint
            } else if (x1 > x2){
                RobotWest(maxDistance, x1, y1, x2, y2, answer, ptr); //move West if startpoint is greater than endpoint
            } return RobotNorth(maxDistance, x1, y1, x2, y2, answer, ptr); //move North if y-startpoint is less than its endpoint

        } else if (y1 > y2){ 
            if(x1 < x2){
                RobotEast(maxDistance, x1, y1, x2, y2, answer, ptr); 
            } else if (x1 > x2){
                RobotWest(maxDistance, x1, y1, x2, y2, answer, ptr); 
            } return RobotSouth(maxDistance, x1, y1, x2, y2, answer, ptr); //move South if y-startpoint is greater than its endpoint

        } else if (x1 < x2){
            if(y1 < y2){
                RobotNorth(maxDistance, x1, y1, x2, y2, answer, ptr);
            } else if (y1 > y2){
                RobotSouth(maxDistance, x1, y1, x2, y2, answer, ptr);
            } return RobotEast(maxDistance, x1, y1, x2, y2,answer, ptr);

        } else if (x1 > x2){
            if(y1 < y2){
                RobotNorth(maxDistance, x1, y1, x2, y2, answer, ptr);
            } else if (y1 > y2){
                RobotSouth(maxDistance, x1, y1, x2, y2, answer, ptr);
            } return RobotWest(maxDistance, x1, y1, x2, y2, answer, ptr);

        }     
}

bool Robot :: maximumDistance(char letter, string path, int distance){ //bool method that corrects max distance
    int letterCounter; //initialize variable 
    for(int i; i < path.length(); i++){ //checks to see how long the string for the path is
        char singlePath = path[i]; //breaks down singular letters of path
        if(letter == singlePath){  
            letterCounter ++; //adds up letter counter if it is equal to the letter in the path
        }
        if(letterCounter == distance){ //if letter count is equal to distance then return false
            return false;
        } 
    }

    return true;
}


void Robot :: RobotNorth(int *count,int x1, int y1, int x2, int y2, string &ans, string *ptr){
    string new_ans = ans + "N"; //initialize new variable so you can pass it through without getting a reference error
    find_shortest_distance(count, x1, y1 + 1, x2, y2, new_ans, ptr); //add 1 to y because going North (positive y direction)
   
}

void Robot :: RobotSouth(int *count, int x1, int y1, int x2, int y2, string &ans, string *ptr){
    string new_ans = ans + "S";
    find_shortest_distance(count, x1, y1 - 1, x2, y2, new_ans, ptr); //subtract 1 from y because going South (negative y direction)

}

void Robot :: RobotEast(int *count, int x1, int y1, int x2, int y2, string &ans, string *ptr){
    string new_ans = ans + "E";
    find_shortest_distance(count, x1 + 1, y1, x2, y2, new_ans, ptr); //add 1 to x because going East (positive x direction)
}

void Robot :: RobotWest(int *count, int x1, int y1, int x2, int y2, string &ans, string *ptr){
    string new_ans = ans + "W";
    find_shortest_distance(count, x1 - 1, y1, x2, y2, new_ans, ptr); //subtract 1 from x because going west (negative y direction)
}

istream& operator >>(istream& input, Robot& robot){ //istream operator that takes in parameters for output
    int distance;
    int startX;
    int startY;
    int endX;
    int endY;
    input >> distance >> startX >> startY >> endX >> endY;
    return input;


}


ostream &operator<<(ostream& output, Robot& robot){ //outstream operator
    output << robot.path << endl; //create robot object, call upon path variable to output string
    output << "Number of Paths: " << robot.max_distance << endl; //call upon distance variable to output max distance
    return output;
}
