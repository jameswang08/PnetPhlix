#ifndef USERDATABASE_INCLUDED
#define USERDATABASE_INCLUDED

#include <string>
#include "treemm.h"

class User;

class UserDatabase
{
  public:
    UserDatabase();
    bool load(const std::string& filename);
    User* get_user_from_email(const std::string& email) const;
  private:
    TreeMultimap<std::string, User> userDB;
    bool fileLoaded; //Flag to check for if a file has been loaded already
};

#endif // USERDATABASE_INCLUDED
