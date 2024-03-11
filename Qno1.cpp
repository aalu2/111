#include <iostream>
#include <string>
#include <array>
#include <random>
#include <ctime>
#include <chrono>

class Card {
public:
    int face;
    int suit;
    static std::array<std::string, 13> faces;
    static std::array<std::string, 4> suits;

    // Default constructor
    Card() : face(0), suit(0) {}

    Card(int face, int suit) : face(face), suit(suit) {}

    std::string toString() {
        return faces[face] + " of " + suits[suit];
    }
};

std::array<std::string, 13> Card::faces = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
std::array<std::string, 4> Card::suits = {"Hearts", "Diamonds", "Clubs", "Spades"};

class DeckOfCards {
public:
    std::array<Card, 52> deck;
    int currentCard;

    DeckOfCards() {
        currentCard = 0;
        for (int i = 0; i < 52; ++i) {
            deck[i] = Card(i % 13, i / 13);
        }
    }

    void shuffle() {
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 rng(static_cast<unsigned>(seed));
        std::uniform_int_distribution<int> uni(0, 51);

        for (int i = 0; i < 52; ++i) {
            int randomIndex = uni(rng);

            Card temp = deck[i];
            deck[i] = deck[randomIndex];
            deck[randomIndex] = temp;
        }
    }

    Card dealCard() {
        if (moreCards()) {
            return deck[currentCard++];
        } else {
            return Card(); // return a default-constructed card (invalid)
        }
    }

    bool moreCards() {
        return currentCard < 52;
    }
};

int main() {
    DeckOfCards deck;
    deck.shuffle();

    for (int i = 0; i < 52; ++i) {
        std::cout << deck.dealCard().toString() << std::endl;
    }

    return 0;
}
