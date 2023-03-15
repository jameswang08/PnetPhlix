
//////////////////////////i/////////////////////////////////////////////////////
//
// You are free to do whatever you want with this file, since you won't
// be turning it in.  Presumably, you will make changes to help you test
// your classes.  For example, you might try to implement only some User
// member functions to start out with, and so replace our main routine with
// one that simply creates a User and verifies that the member functions you
// implemented work correctly.
//
//////////////////////////i/////////////////////////////////////////////////////


  // If your program is having trouble finding these files. replace the
  // string literals with full path names to the files.  Also, for test
  // purposes, you may want to create some small, simple user and movie
  // data files to makde debuggiing easier, so you can replace the string
  // literals with the names of those smaller files.
#include "UserDatabase.h"
#include "User.h"
#include "Movie.h"
#include "treemm.h"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

const string USER_DATAFILE  = "/Users/jams/Desktop/School/CS32/Proj4/Proj4/users.txt";
const string MOVIE_DATAFILE = "/Users/jams/Desktop/School/CS32/Proj4/Proj4/movies.txt";
const string TEST_DATAFILE = "/Users/jams/Desktop/School/CS32/Proj4/Proj4/test.txt";

class Dog{
public:
    Dog(){
        cout << "Dog has been created" << endl;
    }
    ~Dog(){
        cout << "Dog has been deleted" << endl;
    }
};

int main() {
//    //User Tests
//    //Test constructor
//    vector<string> a;
//    a.push_back("Movie1");
//    a.push_back("Movie2");
//    User u1 = User("John Doe", "jd@gmail.com", a);
//
//    //Test get full name
//    assert(u1.get_full_name()=="John Doe");
//    //Test get email
//    assert(u1.get_email()=="jd@gmail.com");
//    //Test get watch history
//    for(int i=0;i<u1.get_watch_history().size();i++){
//        cout << "Watch History: " << u1.get_watch_history()[i] << endl;
//    }
//
//    //Movie Tests
//    //Test constructor
//    vector<string> directors;
//    directors.push_back("Jane Doe");
//    vector<string> actors;
//    actors.push_back("Bob");
//    vector<string> genres;
//    genres.push_back("Action");
//    Movie m1 = Movie("123", "Movie", "1999", directors, actors, genres, 4.2);
//
//    //Test get_id()
//    assert(m1.get_id()=="123");
//    //Test get_title()
//    assert(m1.get_title()=="Movie");
//    //Test get_release_year()
//    assert(m1.get_release_year()=="1999");
//    //Test get_rating()
//    cout << "Rating: " << m1.get_rating() << endl;
//    //Test get_directors()
//    for(int i=0;i<m1.get_directors().size();i++){
//        cout << "Director: " << m1.get_directors()[i] << endl;
//    }
//    //Test get_actors()
//    for(int i=0;i<m1.get_actors().size();i++){
//        cout << "Actor: " << m1.get_actors()[i] << endl;
//    }
//    //Test get_genres()
//    for(int i=0;i<m1.get_genres().size();i++){
//        cout << "Genre: " << m1.get_genres()[i] << endl;
//    }
//
//
//    //Iterator and Tree Tests
//    TreeMultimap<string, int> tmm;
//    //Test insert
//    tmm.insert("carey", 5);
//    tmm.insert("carey", 6);
//    tmm.insert("carey", 7);
//    tmm.insert("david", 25);
//    tmm.insert("david", 425);
//    //Test find when key in tree
//    //Test overloaded iterator constructor
//    TreeMultimap<string,int>::Iterator it = tmm.find("carey");
//    // prints 5, 6, and 7 in some order
//    //Test is_valid(), get_value(), advance() when iterator is valid and there are values
//    while (it.is_valid()) {
//        cout << it.get_value() << endl;
//        it.advance();
//    }
//    //Test find when key not in tree
//    it = tmm.find("laura");
//    if (!it.is_valid())
//    cout << "laura is not in the multimap!\n";
//
//    //Test iterator default constructor and is_valid() when iterator is invalid
//    TreeMultimap<string,int>::Iterator defaultIt;
//    assert(!defaultIt.is_valid());
//
//    //Test tree destructor
//    Dog* d1 = new Dog();
//    Dog* d2 = new Dog();
//    TreeMultimap<std::string, Dog*>* tmmptr = new TreeMultimap<std::string, Dog *>();
//    tmmptr->insert("carey", d1);
//    tmmptr->insert("cindy", d2);
//    delete tmmptr;
//    cout << "tmmptr has been deleted" << endl;
//    delete d1;
//    delete d2;
    
    //Userdatabase Tests
    UserDatabase udb;
    if (!udb.load(USER_DATAFILE))  // In skeleton, load always return false
    {
        cout << "Failed to load user data file " << USER_DATAFILE << "!" << endl;
        return 1;
    }
    for (;;)
    {
        cout << "Enter user email address (or quit): ";
        string email;
        getline(cin, email);
        if (email == "quit")
            return 0;
        User* u = udb.get_user_from_email(email);
        if (u == nullptr)
            cout << "No user in the database has that email address." << endl;
        else
            cout << "Found " << u->get_full_name() << endl;
    }
}
