#include <iostream>
#include <array>

enum Suit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
    GENERAL_SUITS,
};

enum Value {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    GENERAL_VALUE,
};

struct Card {
    Suit suit;
    Value value;
};

void printCard(const Card &card) {
    switch (card.value) {
    case TWO: std::cout << '2'; break;
    case THREE: std::cout << '3'; break;
    case FOUR: std::cout << '4'; break;
    case FIVE: std::cout << '5'; break;
    case SIX: std::cout << '6'; break;
    case SEVEN: std::cout << '7'; break;
    case EIGHT: std::cout << '8'; break;
    case NINE: std::cout << '9'; break;
    case TEN: std::cout << "10"; break;
    case JACK: std::cout << 'J'; break;
    case QUEEN: std::cout << 'Q'; break;
    case KING: std::cout << 'K'; break;
    case ACE: std::cout << 'A'; break;
    }
    switch (card.suit) {
    case CLUBS: std::cout << 'C'; break;
    case DIAMONDS: std::cout << 'D'; break;
    case HEARTS: std::cout << 'H'; break;
    case SPADES: std::cout << 'S'; break;
    }
}

void swapCard(Card &card, Card &cardSecond) {
    std::swap(card,cardSecond);
}

void printDeck(const std::array<Card, 52> &deck) {
    for (const auto &card : deck) {
        printCard(card); std::cout << ' ';
    }
    std::cout << '\n';
}
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
void shuffleDeck(std::array<Card, 52> &deck) {
    for (auto& card : deck) {
        swapCard(card,deck[getRandomNumber(0,51)]);
    }
}
int getCardValue(const Card &card) {
    switch (card.value) {
    case TWO: return 2;
    case THREE: return 3;
    case FOUR: return 4;
    case FIVE: return 5;
    case SIX: return 6;
    case SEVEN: return 7;
    case EIGHT: return 8;
    case NINE: return 9;
    case TEN: return 10;
    case JACK: return 10;
    case QUEEN: return 10;
    case KING: return 10;
    case ACE: return 11;
    }
}
bool playBlackjack(const std::array<Card,52> &deck) {
    const Card* ptr = &deck[0];
    printCard(*ptr);
    return true;
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();
    // Deck initialization
    std::array<Card, 52> deck;
    int card = 0;
    for (int suit = 0; suit < GENERAL_SUITS; ++suit)
        for (int rank = 0; rank < GENERAL_VALUE; ++rank)
        {
            deck[card].suit = static_cast<Suit>(suit);
            deck[card].value = static_cast<Value>(rank);
            ++card;
        }
    /*
    Card c{ CLUBS,TEN };
    Card d{ HEARTS,ACE };
    printCard(c);
    swapCard(c, d);
    printCard(c);
    */
    shuffleDeck(deck);
    printDeck(deck);
    playBlackjack(deck);

    return 0;
}
