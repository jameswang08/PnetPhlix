#include "UserDatabase.h"
#include "User.h"

#include <string>
#include <vector>
#include <fstream>
using namespace std;

UserDatabase::UserDatabase()
{
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
    //Return false if file is empty
    if(!getline(infile,uName)) return false;
    do{
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
        
        //Consume empty line seperating users, if there is one
        string str;
        if(!getline(infile,str)) break;
        
        //Add this user to tree of users
        User newUser = User(uName, email, movieIDs);
        userDB.insert(email,newUser);
    }while(getline(infile,uName));
    return true;
}

User* UserDatabase::get_user_from_email(const string& email) const
{
    TreeMultimap<string, User>::Iterator it = userDB.find(email);
    if(it.is_valid()){
        return &(it.get_value());
    }
    else return nullptr;
}
