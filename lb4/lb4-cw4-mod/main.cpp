#include "Movie.h"
#include "Cinema.h"


int main() {
    Cinema * hollywood = new Cinema("Hollywood Archives");
    hollywood->moviePushBack(new Movie("Life of Charlie Chaplin","12:00"));
    hollywood->getMovieSchedule();
    delete hollywood;
    return 0;
}
