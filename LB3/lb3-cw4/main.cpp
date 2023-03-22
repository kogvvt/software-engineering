#include "Movie.h"
#include "Cinema.h"


int main() {
     Cinema *cinema = new Cinema("Movie Watch");
     cinema->setMovieSchedule("Sancho and Pancho","12:00");
     cinema->getMovieSchedule();
     delete cinema;
     return 0;
}
