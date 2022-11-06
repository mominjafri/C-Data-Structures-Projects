#ifndef GREEDY_ROBOT_H
#define GREEDY_ROBOT_H 
#include <iostream>
#include <string>
using namespace std;

class Robot{
    public:
    //Constructors
    Robot();
    Robot(int distance, int x1, int y1, int x2, int y2);

    void find_shortest_distance(int *max_distance, int x1, int y1, int x2, int y2, string &answer, string *ptr);
    bool maximumDistance(char letter, string path, int distance);

    void RobotNorth(int *count,int x1, int y1, int x2, int y2, string &ans, string *ptr);
    void RobotSouth(int *count,int x1, int y1, int x2, int y2, string &ans, string *ptr);
    void RobotEast(int *count,int x1, int y1, int x2, int y2, string &ans, string *ptr);
    void RobotWest(int *count, int x1, int y1, int x2, int y2, string &ans, string *ptr);

    friend istream& operator >>(istream& input, Robot& robot);
    friend ostream&  operator <<(ostream& output, Robot& robot);
    
  
    private:
    int max_distance;
    int robot_x;
    int robot_y;
    int treasure_x;
    int treasure_y;
    int *maxDistance;
    string *ptr;
    string path;
    string final_answer;
    void checkInput(int *count, int x1, int y1, int x2, int y2, string &ans, string *ptr);

}; 
#endif

