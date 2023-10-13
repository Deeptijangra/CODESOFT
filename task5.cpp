#include <iostream>
#include <vector>
#include <iomanip>

class Movie {
public:
    Movie(const std::string& title, double price) : title(title), price(price) {}
    const std::string& getTitle() const { return title; }
    double getPrice() const { return price; }

private:
    std::string title;
    double price;
};

class Booking {
public:
    Booking(const Movie& movie, int numTickets) : movie(movie), numTickets(numTickets) {}
    double calculateTotalCost() const { return movie.getPrice() * numTickets; }
    const Movie& getMovie() const { return movie; }
    int getNumTickets() const { return numTickets; }

private:
    Movie movie;
    int numTickets;
};

class Theater {
public:
    Theater(const std::string& name) : name(name) {}
    void addMovie(const Movie& movie) { movies.push_back(movie); }
    void displayMovies() const;
    bool makeBooking(int movieIndex, int numTickets);
    bool isValidMovieIndex(int index) const { return index >= 0 && index < movies.size(); }

private:
    std::string name;
    std::vector<Movie> movies;
    std::vector<Booking> bookings;
};

void Theater::displayMovies() const {
    std::cout << "Movie Listings at " << name << " Theater:\n";
    for (size_t i = 0; i < movies.size(); i++) {
        const Movie& movie = movies[i];
        std::cout << i + 1 << ". " << movie.getTitle() << " ($" << std::fixed << std::setprecision(2) << movie.getPrice() << ")\n";
    }
}

bool Theater::makeBooking(int movieIndex, int numTickets) {
    if (isValidMovieIndex(movieIndex) && numTickets > 0) {
        const Movie& selectedMovie = movies[movieIndex];
        Booking booking(selectedMovie, numTickets);
        bookings.push_back(booking);
        std::cout << "Booking successful for " << selectedMovie.getTitle() << " (" << numTickets << " tickets).\n";
        std::cout << "Total cost: $" << std::fixed << std::setprecision(2) << booking.calculateTotalCost() << std::endl;
        return true;
    } else {
        std::cout << "Invalid movie selection or ticket count. Booking failed.\n";
        return false;
    }
}

int main() {
    Theater theater("Cineplex");

    theater.addMovie(Movie("Avengers: Endgame", 12.50));
    theater.addMovie(Movie("Joker", 10.00));
    theater.addMovie(Movie("The Lion King", 11.00));

    theater.displayMovies();

    int movieChoice, ticketCount;

    std::cout << "Select a movie (1-" << theater.displayMovies().size() << "): ";
    std::cin >> movieChoice;

    if (theater.isValidMovieIndex(movieChoice - 1)) {
        std::cout << "Enter the number of tickets: ";
        std::cin >> ticketCount;
        theater.makeBooking(movieChoice - 1, ticketCount);
    } else {
        std::cout << "Invalid movie selection.\n";
    }

    return 0;
}
