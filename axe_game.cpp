#include "raylib.h"
#include <cstdio>;

int main()
{
    /*
    bool variable = true;
    float float_variable = 5.99;
    double double_variable = 5.99;
    double brace_initialization{}; // initialized w type's default value
    bool brace_initialization_2{false}; //initializaed w a value
    bool equal{ 4 == 4};
    bool not_equal{5 != 6};
    */

    // loops 
    int miles = 500;

    int width = 720;
    int height = 720;

    // circle
    int center_x = 0;
    int center_y = height/2;
    int circle_radius = 20;
    //circle edges
    int l_circle_x{center_x - circle_radius};
    int r_circle_x{center_x + circle_radius};
    int u_circle_y{center_y - circle_radius};
    int b_circle_y{center_y + circle_radius};

    //rectangle or axe
    int pos_x_r = 300;
    int pos_y_r = 0;
    int rectangle_length = 40;
    int direction = 10;

    //axe edges
    int l_edge{pos_x_r};
    int r_edge{pos_x_r + rectangle_length};
    int u_edge{pos_y_r};
    int b_edge{pos_y_r+rectangle_length};
    
    // collision 
    bool  collision = 
                        (r_edge >= l_circle_x) && 
                        (u_edge <= b_circle_y) && 
                        (b_edge >= u_circle_y) && 
                        (l_edge <= r_circle_x);

    InitWindow(width,height,"Ventana Nueva");
    SetTargetFPS(60); // TIME OF WINDOW UPDATE EACH SECOND

    while(!WindowShouldClose()) //false if x or ESC is not pressed or clicked
    {
        BeginDrawing(); // SET UP THE CANVAS IN THE WINDOW
        ClearBackground(WHITE);

        if(collision)
        {
            DrawText("Se chocaron. Se acaba el juego.", width/2, height/2, 20, BLACK);
        } else
        {
            //update edges
            l_circle_x = center_x - circle_radius;
            r_circle_x = center_x + circle_radius;
            u_circle_y = center_y - circle_radius;
            b_circle_y = center_y + circle_radius;
            
            l_edge = pos_x_r;
            r_edge = pos_x_r + rectangle_length;
            u_edge = pos_y_r;
            b_edge = pos_y_r + rectangle_length;

            collision = 
                        (r_edge >= l_circle_x) && 
                        (u_edge <= b_circle_y) && 
                        (b_edge >= u_circle_y) && 
                        (l_edge <= r_circle_x);


            DrawCircle(center_x, center_y, circle_radius, BLACK); // draw a circle (centerX, centerY, radius, Color)
            DrawRectangle(pos_x_r,pos_y_r,rectangle_length,rectangle_length, RED); // posx and posy is the upper left corner

            //moving the axe
            pos_y_r += direction;
            if (pos_y_r > height || pos_y_r < 0)
            {
                direction = -direction;
            }
            

            if (IsKeyDown(KEY_D) && center_x < width) {
                center_x += 10;
            } else if (IsKeyDown(KEY_A) && center_x > 0) {
                center_x -= 10;
            } else if (IsKeyDown(KEY_S) && center_y < height){
                center_y += 10;
            } else if (IsKeyDown(KEY_W) && center_y > 0){
                center_y -= 10;
            }            
        }       
        
        EndDrawing(); // TEAR DOWN THE CANVAS
    }
}