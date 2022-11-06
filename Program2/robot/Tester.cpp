#include <iostream>
#include "greedy_robot.h"
using namespace std;

int main() {
   int max_distance;
   int x1;
   int x2;
   int y1;
   int y2;
   cin >> max_distance >> x1 >> x2 >> y1 >> y2;
    Robot path1(max_distance, x1,x2, y1, y2);
   cout << path1 << endl; 

   return 0;

}
    