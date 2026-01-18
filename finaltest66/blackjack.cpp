#include <iostream>
#include <array>
#include <vector>
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
    case CLUBS: std::cout << "C "; break;
    case DIAMONDS: std::cout << "D "; break;
    case HEARTS: std::cout << "H "; break;
    case SPADES: std::cout << "S "; break;
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
void printPlayerCards(const std::vector<Card> &playerCards) {
    for (const auto& card : playerCards) {
        printCard(card);
    }
}
int getTotalValueOfCards(const std::vector<Card>& playerCards) {
    int sum = 0;
    for (const auto& card : playerCards) {
        sum += getCardValue(card);
    }
    return sum;
}
bool playBlackjack(const std::array<Card,52> &deck) {
    std::cout << "Welcome to BlackJack(21) game!";
    std::vector<Card> dealer;
    const Card* ptr = &deck[0];
    dealer.push_back(*ptr);
    std::cout << "\nDealer cards now is: ";
    printPlayerCards(dealer);
    std::cout << "\nTotal: " << getTotalValueOfCards(dealer);
    std::cout << "\nYour cards: ";
    std::vector<Card> player;
    player.push_back(*(++ptr));
    player.push_back(*(++ptr));
    printPlayerCards(player);
    std::cout << "\nTotal: " << getTotalValueOfCards(player);
    char answer;
    do {
        std::cout << "\nDo you want to take a card?: ";
        std::cin >> answer;
        if (answer == 'Y' || answer == 'y') {
            player.push_back(*(++ptr));
            std::cout << "\nYou got a card: "; printCard(*ptr);
            std::cout << "\nYour cards now: "; printPlayerCards(player);
            int total = getTotalValueOfCards(player);
            std::cout << "\nTotal: " << total;
            if (total > 21)
                return false;
        }
    } while (answer != 'N' && answer != 'n');
    do {
        std::cout << "\nDealer gets a card...";
        dealer.push_back(*(++ptr));
        std::cout << "\nDealer got a card: "; printCard(*ptr);
        std::cout << "\nDealer cards now: "; printPlayerCards(dealer);
        int total = getTotalValueOfCards(dealer);
        std::cout << "\nTotal: " << total;
        if (total > 21) 
            return true;
    } while (getTotalValueOfCards(dealer) < 17);
    if (getTotalValueOfCards(dealer) > getTotalValueOfCards(player))
        return false;
    else if (getTotalValueOfCards(dealer) < getTotalValueOfCards(player))
        return true;
    else
        std::cout << "\nDraw! Wow! We'll assume you won!";
    return true;
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    rand();
    std::array<Card, 52> deck;
    int card = 0;
    for (int suit = 0; suit < GENERAL_SUITS; ++suit)
        for (int rank = 0; rank < GENERAL_VALUE; ++rank)
        {
            deck[card].suit = static_cast<Suit>(suit);
            deck[card].value = static_cast<Value>(rank);
            ++card;
        }
    char userAnswer;
    do {
        shuffleDeck(deck);
        printDeck(deck);
        if (playBlackjack(deck)) {
            std::cout << "\nYou won! Do you want to play again?(Y/N): ";
            std::cin >> userAnswer;
        }
        else {
            std::cout << "\nYou lost... Do you want to play again?(Y/N): ";
            std::cin >> userAnswer;
        }
    } while (userAnswer != 'N' && userAnswer != 'n');
    std::cout << "\nThank you for gaming!";
    return 0;
}
