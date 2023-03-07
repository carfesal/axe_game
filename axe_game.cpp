#include "raylib.h"
#include <cstdio>;

int main()
{
    int width = 350;
    int length = 720;
    bool variable = true;
    float float_variable = 5.99;
    double double_variable = 5.99;
    double brace_initialization{}; // initialized w type's default value
    bool brace_initialization_2{false}; //initializaed w a value
    bool equal{ 4 == 4};
    bool not_equal{5 != 6};

    // loops 
    int miles = 500;

    InitWindow(width,length,"Ventana Nueva");

    while(true)
    {
        BeginDrawing(); // SET UP THE CANVAS IN THE WINDOW
        ClearBackground(RED); 
        EndDrawing(); // TEAR DOWN THE CANVAS
    }
    
    
}