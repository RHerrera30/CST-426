#include "Application.h"
#include "imgui/imgui.h"
#include "classes/Log.h"

//CHANGES
//Included fstream, iostream and string for file reading.
//Added Log.cpp and Log.h to take log messages, write them to a file, and print them to the console.
//Added Log.cpp to my Cmake list

//RESOURCES
/*
https://learnxinyminutes.com/c++/
https://www.w3schools.com/cpp/cpp_files.asp 
https://www.w3schools.com/cpp/cpp_enum.asp 
https://www.w3schools.com/cpp/cpp_classes.asp
https://www.w3schools.com/cpp/cpp_class_methods.asp
https://www.geeksforgeeks.org/cpp/how-can-i-solve-the-error-lnk2019-unresolved-external-symbol/
https://medium.com/@kunal-mod/c-best-practices-understanding-the-need-for-splitting-class-declaration-and-definitions-into-389d523695b9
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace ClassGame {
        //
        // our global variables
        //

        //
        // game starting point
        // this is called by the main render loop in main.cpp
        //
        void GameStartUp() 
        {
                Log::initialize(Log::INFO);
                Log::write("Game started!", Log::INFO);
                Log::setLevel(Log::WARNING);
                Log::write("Gnome in the building", Log::WARNING);
                Log::write("GNOME APPROACHING", Log::WARNING);
                Log::setLevel(Log::ERROR);
                Log::write("THE GNOME IS BITING", Log::ERROR);
        }

        //
        // game render loop
        // this is called by the main render loop in main.cpp
        //
        void RenderGame() 
        {
            ImGui::DockSpaceOverViewport();
//            ImGui::ShowDemoWindow();

                static float f = 0.0f;
                static int counter = 0;
                bool show_demo_window = true;
                bool show_another_window = false;
                ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

                ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

                ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
                ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
                ImGui::Checkbox("Another Window", &show_another_window);

                ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
                ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

                if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                        counter++;
                ImGui::SameLine();
                ImGui::Text("counter = %d", counter);

                ImGui::End();
        }

        //
        // end turn is called by the game code at the end of each turn
        // this is where we check for a winner
        //
        void EndOfTurn() 
        {
        }
}
