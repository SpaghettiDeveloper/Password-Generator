//
//  PasswordGenerator.cpp


#include <iostream>
#include <string>

int main(int argc, const char * argv[]) {
    
    int number_generated = 1;
    int length = 15;
    bool sn = false;
    bool ol = false;
    
    std::string password = "";
    
    
    const std::string array_primary [] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w",
        "x","y","z","0","1","2","3","4","5","6","7","8","9","!","@","#","$","^","&","*",".",
        "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W",
        "X","Y","Z"};
    
    const std::string array_no_special_chars [] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w",
        "x","y","z","0","1","2","3","4","5","6","7","8","9",
        "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W",
        "X","Y","Z"};
    
    const std::string array_letters_only [] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w",
        "x","y","z",
        "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W",
        "X","Y","Z"};
    
    if(argc < 2) {
        std::cout << "\nGenerated one default password including english letters, numbers, and special characters of length 15. Defaults can be changed by adding: \n\n" <<
        "-n <number>      Number of passwords generated \n" <<
        "-l <length>      Length of password(s) generated \n" <<
        "-sn              Passwords consisting of english letters and numbers only \n" <<
        "-ol              Passwords consisting of letters only \n" << std::endl;
        
    }
    else {
        // Handle command line arguments
        try {
            for(int i = 0; i < argc; i++) {
                if(strcmp(argv[i], "-n") == 0 ) {
                    number_generated = std::stoi(argv[i + 1]);
                }
                else if(strcmp(argv[i], "-l") == 0) {
                    length = std::stoi(argv[i + 1]);
                }
                else if(strcmp(argv[i],"-sn") == 0) {
                    sn = true;
                }
                else if(strcmp(argv[i],"-ol") == 0) {
                    ol = true;
                }
            }
        } catch (std::exception e) {
            std::cout << "Invalid input. Exiting now..." << std::endl;
            return 0;
        }
    }
    
    std::cout << std::endl;  
  
    // One loop per password
    // Intended pun with the incrementor
    for(int c = 0; c < number_generated; c++) {
        
        // Loop for each char of password
        for(int j = 0; j < length; j++) {
            // Letters only
            if(ol) {
                password += array_letters_only[(rand() % (int)(sizeof(array_letters_only)/sizeof(array_letters_only[0])))];
            }
            // No special characters
            else if(sn) {
                password += array_no_special_chars[(rand() % (int)(sizeof(array_no_special_chars)/sizeof(array_no_special_chars[0])))];
            }
            // All
            else {
                password += array_primary[(rand() % (int)(sizeof(array_primary)/sizeof(array_primary[0])))];
            }
        }
        
        std::cout << "Password:   " << password << std::endl;
        password = "";
    }

    std::cout << std::endl;
    return 0;
}
