//
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
//
//
//   If your program is having trouble finding these files. replace the
//   string literals with full path names to the files.  Also, for test
//   purposes, you may want to create some small, simple user and movie
//   data files to makde debuggiing easier, so you can replace the string
//   literals with the names of those smaller files.
#include "UserDatabase.h"
#include "MovieDatabase.h"
#include "User.h"
#include "Movie.h"
#include "treemm.h"
#include "Recommender.h"
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

void findMatches(const Recommender& r, const MovieDatabase& md, const string& user_email, int num_recommendations) {
    // get up to ten movie recommendations for the user
    vector<MovieAndRank> recommendations = r.recommend_movies(user_email, num_recommendations);
    if (recommendations.empty()) cout << "We found no movies to recommend :(.\n";
    else {
        for (int i = 0; i < recommendations.size(); i++) {
            const MovieAndRank& mr = recommendations[i];
             Movie* m = md.get_movie_from_id(mr.movie_id);
             cout << i << ". " << m->get_title() << " ("
             << m->get_release_year() << ")\n Rating: "
             << m->get_rating() << "\n Compatibility Score: "
             << mr.compatibility_score << "\n";
        }
    }
}

int main() {
    //Tests
}
