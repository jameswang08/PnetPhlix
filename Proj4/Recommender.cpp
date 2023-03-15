#include "Recommender.h"
#include "UserDatabase.h"
#include "MovieDatabase.h"
#include "User.h"
#include "Movie.h"

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

Recommender::Recommender(const UserDatabase& user_database,
                         const MovieDatabase& movie_database)
{
    udb = &user_database;
    mdb = &movie_database;
}

vector<MovieAndRank> Recommender::recommend_movies(const string& user_email, int movie_count) const
{
    //Get user's watch history
    vector<string> hist = udb->get_user_from_email(user_email)->get_watch_history();
    
    unordered_map<string,int> directorMap;
    unordered_map<string,int> actorMap;
    unordered_map<string,int> genreMap;
    
    //Loop through user's watch history
    for(int i=0;i<hist.size();i++){
        //Get movie assosciated with ID
        Movie* thisMovie = mdb->get_movie_from_id(hist[i]);
        
        //Get Directors for Movie and tally up total points each director should add to a movie
        vector<string> dirs = thisMovie->get_directors();
        for(int j=0;j<dirs.size();j++){
            directorMap[dirs[i]] = 20;
        }
        //Get Actors for Movie and tally up total points each actor should add to a movie
        vector<string> acts = thisMovie->get_actors();
        for(int j=0;j<acts.size();j++){
            actorMap[acts[i]] = 30;
        }
        //Get Genres for Movie and tally up total points each genre should add to a movie
        vector<string> gnr = thisMovie->get_genres();
        for(int j=0;j<gnr.size();j++){
            genreMap[dirs[i]] = 1;
        }
    }
    //hash table containing all movies with score >= 1
    unordered_map<string, int> movieScores;
    
    //Find movies assosciated w/ director and add compatability score to movie
    unordered_map<string, int>::iterator it;
    for(it=directorMap.begin(); it!=directorMap.end();it++){
        //Loop through directors stored in hash table of director/score pairs
        vector<Movie*> movies =  mdb->get_movies_with_director(it->first);
        for(int i=0;i<movies.size();i++){
            //Add compatability score to movie
            movieScores[movies[i]->get_id()] = it->second;
        }
    }
    
    //Find movies assosciated w/ actor and add compatability score to movie
    for(it=actorMap.begin(); it!=actorMap.end();it++){
        //Loop through directors stored in hash table of director/score pairs
        vector<Movie*> movies =  mdb->get_movies_with_actor(it->first);
        for(int i=0;i<movies.size();i++){
            //Add compatability score to movie
            movieScores[movies[i]->get_id()] = it->second;
        }
    }
    
    //Find movies assosciated w/ genre and add compatability score to movie
    for(it=genreMap.begin(); it!=genreMap.end();it++){
        //Loop through directors stored in hash table of director/score pairs
        vector<Movie*> movies =  mdb->get_movies_with_genre(it->first);
        for(int i=0;i<movies.size();i++){
            //Add compatability score to movie
            movieScores[movies[i]->get_id()] = it->second;
        }
    }
    
    
    return vector<MovieAndRank>();  // Replace this line with correct code.
}
