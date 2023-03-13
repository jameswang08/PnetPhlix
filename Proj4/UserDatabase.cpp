#include "UserDatabase.h"
#include "User.h"

#include <string>
#include <vector>
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
    return false;
}

User* UserDatabase::get_user_from_email(const string& email) const
{
    return nullptr;  // Replace this line with correct code.
}
