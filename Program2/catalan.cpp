#include <iostream>
using namespace std;

int catalan(int n); //declare function at top

int main(){
    int n;
    cout << "Enter a number" << endl; 
    cin >> n;
    cout << "Catalan of " << n << " is " << catalan(n) << endl;

    return 0;
}

int catalan(int n){ //recursive method 

    if(n <= 1){
        return 1; //catalan returns 1 if n is less than or equal to 1
    }
    int cat = 0;
    for(int i = 0; i < n; i++){
        cat += catalan(i)*catalan(n-i-1); //recursive method where the variable cat takes the number from the forloop and multiplies it by the paramter given, forloop number and 1 subtracted.

    }
    return cat;
}