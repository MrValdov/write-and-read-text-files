#include <iostream>
#include <fstream>
#include <string>


int main(int, char**){
    //Greeting the user
    std::string usrname;
    std::string line;
    std::string last_record;
    std::string response;
    std::cout << "Hello, please enter your name\n";
    std::cin >> usrname;
    std::cout << "Nice to meet you " + usrname + ".\n";

    //setting the file name
    std::string filename = "example.txt";

    //Searching for the file
    std::ifstream infile(filename.c_str());
    if (!infile.good()) {
        std::ofstream outfile(filename.c_str());

        //Creating file if it did not exist
        outfile << "This is a new file." << std::endl;
        outfile.close();
        std::cout << "File created successfully." << std::endl;
    } else {
        //Notifying that file already existed
        std::cout << "File already exists." << std::endl;

        //Reading file to scan for word "Index" as first record
        if (infile.is_open()) {
            std::getline(infile, line);
            if (line == "Index") {
                //Reading the last username recorded
                while (std::getline(infile, line)) {
                    last_record = line;
                }

                //Writting new username in text file                                
                std::ofstream outfile;
                outfile.open(filename, std::ios_base::app);
                outfile << usrname << std::endl;
                outfile.close();
                std::cout << "Data written to the file successfully!" << std::endl;                
                //
                
                std::cout << "The last record is: " << last_record << std::endl;
            } else {
                std::cout << "The first record is not equal to \"Index\"." << std::endl;  

                //Validating if the user wants to initialize the file          
                std::cout << "Do you want to create a record in the text file? (yes/no): ";
                std::cin >> response;
                if (response == "yes") {
                    std::ofstream outfile(filename);
                    if (outfile.is_open()) {
                        std::cout << "Enter the data you want to write to the file: ";
                        std::string data;
                        std::cin.ignore();
                        std::getline(std::cin, data);
                        outfile << data << std::endl;
                        outfile.close();
                        std::cout << "Data written to the file successfully!" << std::endl;
                    } else {
                        std::cout << "Unable to open the file." << std::endl;
                    }   
                } else if (response == "no") {                   
                    if (infile.is_open()) {
                        std::string line;
                        while (std::getline(infile, line)) {
                            std::cout << line << std::endl;
                        }                        
                    } else {
                        std::cout << "Unable to open the file." << std::endl;
                    }
                } else {
                    std::cout << "Invalid response. Please enter either 'yes' or 'no'." << std::endl;
                }
            }   
        }
    }
    infile.close();
    return 0;
}
