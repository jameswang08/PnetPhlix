#include "MovieDatabase.h"
#include "Movie.h"

#include <string>
#include <vector>
#include <fstream>
using namespace std;

MovieDatabase::MovieDatabase()
{
    //Initially no file loaded
    fileLoaded = false;
}

MovieDatabase::~MovieDatabase(){
    for(int i=0;i<createdMovies.size();i++){
        delete createdMovies[i];
    }
}

bool MovieDatabase::load(const string& filename)
{
    //Return false and do nothing if file has already been loaded
    if(fileLoaded) return false;
    
    //Load File
    ifstream infile(filename);
    
    //Return false if file could not be loaded
    if (!infile) return false;
    
    //Process file
    //Get movie id
    string id;
    //Return false if file is empty
    if(!getline(infile,id)) return false;
    do{
        //Get movie name
        string nm;
        getline(infile,nm);
        
        //Get movie release year
        string yr;
        getline(infile,yr);
        
        //Get list of directors
        string dirs;
        getline(infile, dirs);
        //Split apart list by commas
        vector<string> directors;
        string str;
        for(int i=0;i<dirs.size();i++){
            if(dirs[i]!=','){
                str += dirs[i];
                if(i==dirs.size()-1){
                    directors.push_back(str);
                }
            }
            else{
                directors.push_back(str);
                str = "";
            }
        }
        
        //Get list of actors
        string acts;
        getline(infile, acts);
        //Split apart list by commas
        vector<string> actors;
        str = "";
        for(int i=0;i<acts.size();i++){
            if(acts[i]!=','){
                str += acts[i];
                if(i==acts.size()-1) actors.push_back(str);
            }
            else{
                actors.push_back(str);
                str = "";
            }
        }
        
        //Get list of genres
        string grs;
        getline(infile, grs);
        //Split apart list by commas
        vector<string> genres;
        str = "";
        for(int i=0;i<grs.size();i++){
            if(grs[i]!=','){
                str += grs[i];
                if(i==grs.size()-1) genres.push_back(str);
            }
            else{
                genres.push_back(str);
                str = "";
            }
        }
        
        //Get rating
        float rating;
        infile >> rating;
        infile.ignore(10000,'\n');
        
        //Consume empty line seperating users, if there is one
        if(!getline(infile,str)) break;
        
        //Add movie object to trees
        Movie* newMovie = new Movie(id,nm,yr,directors,actors,genres,rating);
        
        //Make ID lowercase
        for(int i=0;i<id.size();i++){
            id[i] = tolower(id[i]);
        }
        //ID Tree
        idTree.insert(id,newMovie);
        
        //Director Tree
        for(int i=0;i<directors.size();i++){
            //Make director key lowercase
            for(int j=0;j<directors[i].size();j++){
                directors[i][j] = tolower(directors[i][j]);
            }
            dirTree.insert(directors[i],newMovie);    
        }
        //Actor Tree
        for(int i=0;i<actors.size();i++){
            //Make actors key lowercase
            for(int j=0;j<actors[i].size();j++){
                actors[i][j] = tolower(actors[i][j]);
            }
            actTree.insert(actors[i],newMovie);
        }
        //Genre Tree
        for(int i=0;i<genres.size();i++){
            //Make actors key lowercase
            for(int j=0;j<genres[i].size();j++){
                genres[i][j] = tolower(genres[i][j]);
            }
            genreTree.insert(genres[i],newMovie);
        }
        
        //Add movie object to list of movies that were dynamically allocated
        createdMovies.push_back(newMovie);
    }while(getline(infile,id));
    
    return true;
}

Movie* MovieDatabase::get_movie_from_id(const string& id) const
{
    string tId = id;
    //Make ID lowercase
    for(int i=0;i<tId.size();i++){
        tId[i] = tolower(tId[i]);
    }
    TreeMultimap<string, Movie*>::Iterator it = idTree.find(tId);
    if(it.is_valid()){
        return it.get_value();
    }
    else return nullptr;
}

vector<Movie*> MovieDatabase::get_movies_with_director(const string& director) const
{
    string tDir = director;
    //Make Director lowercase
    for(int i=0;i<tDir.size();i++){
        tDir[i] = tolower(tDir[i]);
    }
    TreeMultimap<string, Movie*>::Iterator it = dirTree.find(tDir);
    vector<Movie*> movies;
    while(it.is_valid()){
        movies.push_back(it.get_value());
        it.advance();
    }
    return movies;
}

vector<Movie*> MovieDatabase::get_movies_with_actor(const string& actor) const
{
    string tAct = actor;
    //Make Actor lowercase
    for(int i=0;i<tAct.size();i++){
        tAct[i] = tolower(tAct[i]);
    }
    TreeMultimap<string, Movie*>::Iterator it = actTree.find(tAct);
    vector<Movie*> movies;
    while(it.is_valid()){
        movies.push_back(it.get_value());
        it.advance();
    }
    return movies;
}

vector<Movie*> MovieDatabase::get_movies_with_genre(const string& genre) const
{
    string tGnr = genre;
    //Make genre lowercase
    for(int i=0;i<tGnr.size();i++){
        tGnr[i] = tolower(tGnr[i]);
    }
    TreeMultimap<string, Movie*>::Iterator it = genreTree.find(tGnr);
    vector<Movie*> movies;
    while(it.is_valid()){
        movies.push_back(it.get_value());
        it.advance();
    }
    return movies;
}
