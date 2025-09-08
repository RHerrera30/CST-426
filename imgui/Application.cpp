#include "Application.h"
#include "imgui/imgui.h"
#include "classes/Log.h"

//CHANGES
//Included fstream, iostream and string for file reading.
//Added Log class to hold log messages, print them to a file, and show in the IMGUI window.
//Added Log class to my cmake list

//RESOURCES
//https://www.w3schools.com/cpp/cpp_files.asp 
//https://www.w3schools.com/cpp/cpp_enum.asp 

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
                // Log logFile;
                // logFile.writeToFile("Hello");
                Log::writeToFile("Game started!", Log::INFO);
                Log::writeToFile("Gnome in the building", Log::WARNING);
                Log::writeToFile("THE GNOME IS BITING", Log::ERROR);
                // std::string logInfo = "Here is my log info.";
                // logFile.writeToFile(logInfo);
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
