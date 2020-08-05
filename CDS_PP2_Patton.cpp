#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;



int main()
{



    std::cout << R"(

           __  __  _                                    _____         _         _    _                    
          |  \/  |(_)                                  / ____|       | |       | |  (_)                   
          | \  / | _  _ __    ___  _ __ __   __ __ _  | (___    ___  | | _   _ | |_  _   ___   _ __   ___ 
          | |\/| || || '_ \  / _ \| '__|\ \ / // _` |  \___ \  / _ \ | || | | || __|| | / _ \ | '_ \ / __|          
          | |  | || || | | ||  __/| |    \ V /| (_| |  ____) || (_) || || |_| || |_ | || (_) || | | |\__ \
          |_|  |_||_||_| |_| \___||_|     \_/  \__,_| |_____/  \___/ |_| \__,_| \__||_| \___/ |_| |_||___/
                                                                                                  

                                                                                               
)" << '\n';

    // Variables 
    bool exitProgram = false;

    do //Loop for the menu options
    {
        int choice;
        std::cout << "Welcome to Minerva Solutions, how may we help you?" << endl;
        std::cout << "1. Client login" << endl;
        std::cout << "2. Create an account" << endl;
        std::cout << "3. Quit" << endl;
        std::cin >> choice;

        string userLogin = "";
        string userPass = "";
        bool loginSuccess = false;
        
        switch (choice)
        {
        case 1: //Client log in
            std::cout << "Welcome back! ";

            //Check for valid user credentials.
            do
            {
                // Get username and password.
                std::cout << "Enter client username: ";
                std::cin >> userLogin;
                std::cout << "Enter client password: ";
                std::cin >> userPass;

                // Open username and password files.
                std::ifstream userFile("client.userName.txt");
                std::ifstream passFile("client.userPass.txt");

                // Check if there are any matches in the username and password files.
                std::string userLine;
                std::string passLine;

                while (std::getline(userFile, userLine) and std::getline(passFile, passLine))
                {
                    if ((userLogin == userLine) and (userPass == passLine))
                    {
                        loginSuccess = true;
                        break;
                    }
                }

                // if usename passsword invalid print error and try again
                if (not loginSuccess)
                {
                    std::cout << "ERROR, please try again." << endl;
                }
            } while (!loginSuccess);

            // view user data and input/update data
            int adminSelection;

            do //Loop for client service selection
            {
                std::cout << "1. List Employees" << endl;
                std::cout << "2. Add Employee" << endl;
                std::cout << "3. List Assets" << endl;
                std::cout << "4. Update Assets" << endl;
                std::cout << "5. Logout" << endl;
                std::cin >> adminSelection;

                // checks logged in client input  
                switch (adminSelection)
                {
                case 1: // get employee list file
                {
                    // Open client's user file
                    std::ifstream clientEmployeeList(userLogin + ".employees.txt");

                    // Get all lines from client's user file for reading
                    std::string employeeLine;
                    while (std::getline(clientEmployeeList, employeeLine))
                    {
                        std::cout << employeeLine << endl;
                    }
                }
                    break;
                case 2: // add an employee write to file
                {
                    // Open client's user file for appending/writing to
                    std::ofstream clientEmployeeList(userLogin + ".employees.txt", std::ios::out | std::ios::app);

                    // Write new employee to file
                    std::cout << "Please enter employee name: " << endl;
                    string employeeName;
                    std::cin.ignore();
                    std::getline(std::cin, employeeName, '\n');
                    clientEmployeeList << employeeName << endl;
                    std::cout << employeeName << " has been added." << endl;
                    clientEmployeeList.close();
                }
                    break;
                case 3: // get asset list file
                {
                    // Open client's asset list file
                    std::ifstream clientAssetList(userLogin + ".asset.txt");

                    // Get all lines from client's asset list file.
                    std::string assetLine;
                    while (std::getline(clientAssetList, assetLine))
                    {
                        std::cout << assetLine << endl;
                    }
                                       
                    
                }
                    break;
                case 4: // update asset list
                {
                    // Open client's user file for appending/writing to
                    std::ofstream clientAssetList(userLogin + ".asset.txt", std::ios::out | std::ios::app);

                    // Write new asset to file
                    std::cout << "Please enter Asset: " << endl;
                    string assetName;
                    std::cin.ignore();
                    std::getline(std::cin, assetName, '\n');
                    clientAssetList << assetName << endl;
                    std::cout << assetName << " has been added." << endl;
                    clientAssetList.close();                   
                }
                    break;
                case 5: // user logout
                    userLogin = "";
                    userPass = "";
                    loginSuccess = false;
                    break;
                default:
                    std::cout << "Invalid option, please try again." << endl;
                    break;
                }
            } while (loginSuccess);
            break;

        case 2:
        {
            // Get new username.
            std::cout << "Please enter a user name: " << endl;         
            std::cin.ignore();
            std::cin >> userLogin;

            // Check to see if username is already taken.
            std::ifstream userFile("client.userName.txt");
            std::string userLine;
            bool userNameTaken = false;
            while (std::getline(userFile, userLine))
            {
                if (userLogin == userLine) 
                {
                    userNameTaken = true;
                    break;
                }
            }
            userFile.close();


            

            // If not taken, get new password.
            std:cout << "Please enter a password: " << endl;
            std::cin.ignore();
            std::cin >> userPass;

            // Store username and password.
            std::ofstream passFileOut("client.userPass.txt", std::ios::out | std::ios::app);
            std::ofstream userFileOut("client.userName.txt", std::ios::out | std::ios::app);
            
            passFileOut << userPass << std::endl; 
            userFileOut << userLogin << std::endl;

            passFileOut.close();
            userFileOut.close();
                        
        }
            break;
        case 3:
            std::cout << "Have a nice day!";
            exitProgram = true;
            break;
        default:
            std::cout << "Invalid option, try again." << endl;
            break;
        }
    } while (not exitProgram);
    
    // Exit program
    return 0;
}




