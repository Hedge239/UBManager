#include <iostream>
#include <cstring>


int main(int argc, char* argv[])
{
    for(int i = 1; i < argc; i++)
    {
        if(std::strcmp(argv[i], "--installer") == 0)        // Allows the user to enable/disable using the application strait from cmd
        {

        } 
        else if(std::strcmp(argv[i], "--create") == 0)      // Ask the user various questions to create a new backup location
        {

        } 
        else if(std::strcmp(argv[i], "--dobackup") == 0)    // Performs a backup useing one of the users saved settings
        {

        }
        else if(std::strcmp(argv[i], "--gui") == 0)         // Opens the GUI version of the application through cmd
        {

        }
        else if(std::strcmp(argv[i], "--info") == 0)        // Prints info about the application (version, build, etc)
        {

        }
        else                                                // prints all the options above with small descriptions
        {

        }
    }

    return 0;
}