#include "UserDatabase.h"
#include "User.h"

#include <string>
#include <vector>
#include <fstream>
using namespace std;

UserDatabase::UserDatabase()
{
   //Create empty tree to store user data
    userDB = TreeMultimap<std::string,User>();
    //Initial database has no file loaded
    fileLoaded = false;
}

bool UserDatabase::load(const string& filename)
{
    //Return false and do nothing if file has already been loaded
    if(fileLoaded) return false;
    
    //Load File
    ifstream infile(filename);
    
    //Return false if file could not be loaded
    if (!infile) return false;
    
    //Process file
    //Get user's name
    string uName;
    while(getline(infile,uName)){
        //Get user's email
        string email;
        getline(infile,email);
        
        //Get the number of movies user recently watched
        int nMovies = 0;
        infile >> nMovies;
        infile.ignore(10000, '\n');
        
        //Store recently watched movies into array
        vector<string> movieIDs;
        for(int i=0;i<nMovies;i++){
            string movie;
            getline(infile, movie);
            movieIDs.push_back(movie);
        }
        
        //Consume empty line seperating users
        string str;
        getline(infile,str);
        
        //Add this user to tree of users
        User* newUser = new User(uName, email, movieIDs);
        userDB.insert(email,newUser);
    }

    return true;
}

User* UserDatabase::get_user_from_email(const string& email) const
{
    return nullptr;  // Replace this line with correct code.
}
