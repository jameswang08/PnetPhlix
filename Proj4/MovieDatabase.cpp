#include "MovieDatabase.h"
#include "Movie.h"

#include <string>
#include <vector>
using namespace std;

MovieDatabase::MovieDatabase()
{
    //Initially no file loaded
    fileLoaded = false;
    
    //Create empty trees
    idTree = TreeMultimap<std::string, Movie*>();
    dirTree = TreeMultimap<std::string, Movie*>();
    actTree = TreeMultimap<std::string, Movie*>();
    genreTree = TreeMultimap<std::string, Movie*>();
    
    //Movie Database starts out with zero movie objects
    createdMovies = std::vector<Movie*>();
}

bool MovieDatabase::load(const string& filename)
{
    return false;  // Replace this line with correct code.
}

Movie* MovieDatabase::get_movie_from_id(const string& id) const
{
    return nullptr;  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_director(const string& director) const
{
    return vector<Movie*>();  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_actor(const string& actor) const
{
    return vector<Movie*>();  // Replace this line with correct code.
}

vector<Movie*> MovieDatabase::get_movies_with_genre(const string& genre) const
{
    return vector<Movie*>();  // Replace this line with correct code.
}
