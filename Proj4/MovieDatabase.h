#ifndef MOVIEDATABASE_INCLUDED
#define MOVIEDATABASE_INCLUDED

#include <string>
#include <vector>
#include "treemm.h"

class Movie;

class MovieDatabase
{
  public:
    MovieDatabase();
    ~MovieDatabase();
    bool load(const std::string& filename);
    Movie* get_movie_from_id(const std::string& id) const;
    std::vector<Movie*> get_movies_with_director(const std::string& director) const;
    std::vector<Movie*> get_movies_with_actor(const std::string& actor) const;
    std::vector<Movie*> get_movies_with_genre(const std::string& genre) const;
    
  private:
    bool fileLoaded; //Flag for whether file has already been loaded or not
    TreeMultimap<std::string, Movie*> idTree; //Tree w/ movie ID as key
    TreeMultimap<std::string, Movie*> dirTree; //Tree w/ movie directors as key
    TreeMultimap<std::string, Movie*> actTree; //Tree w/ movie actors as key
    TreeMultimap<std::string, Movie*> genreTree; //Tree w/ movie genre as key
    std::vector<Movie*> createdMovies; //Tracks all of the movies created
};

#endif // MOVIEDATABASE_INCLUDED
