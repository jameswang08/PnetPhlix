#ifndef MOVIE_INCLUDED
#define MOVIE_INCLUDED

#include <string>
#include <vector>

class Movie
{
  public:
    Movie(const std::string& id, const std::string& title,
          const std::string& release_year,
          const std::vector<std::string>& directors,
          const std::vector<std::string>& actors,
          const std::vector<std::string>& genres, float rating);
    std::string get_id() const;
    std::string get_title() const;
    std::string get_release_year() const;
    float get_rating() const;
    std::vector<std::string> get_directors() const;
    std::vector<std::string> get_actors() const;
    std::vector<std::string> get_genres() const;

  private:
    std::string id; //Move ID
    std::string name; //Move name
    std::string yr; //Movie Release Year
    std::vector<std::string> dirs; //Movie directors
    std::vector<std::string> actors; //Movie actors
    std::vector<std::string> genres; //Movie genres
    float rating; //Movie rating
};

#endif // MOVIE_INCLUDED
