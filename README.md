# 🃏 Blackjack (21) Console Game

A simple console-based Blackjack (21) game written in C++. The game simulates a real deck of cards, shuffling, player decisions, and dealer logic based on classic Blackjack rules.

---

## 📋 Description

This project is a terminal implementation of the classic Blackjack (21) card game.

The game uses a standard 52-card deck, supports shuffling, and simulates both player and dealer turns with simple AI logic.

You play against the dealer with the goal of getting as close to 21 as possible without going over.

---

## 🎯 Game Rules

- A standard 52-card deck is used  
- Cards are shuffled before each game  
- Player starts with 2 cards  
- Dealer starts with 1 visible card  
- Card values:
  - Number cards = face value
  - J, Q, K = 10
  - Ace = 11
- Player can:
  - Take a card (Hit)
  - Stop (Stand)
- If player exceeds 21 → lose
- Dealer draws cards until reaching at least 17
- Closest to 21 without busting wins

---

## 🛠️ Technologies

- C++11
- std::array – deck storage
- std::vector – player/dealer hands
- rand() – simple shuffle logic
- Procedural programming style

---

## 🚀 How to Run

### GCC / Clang
g++ -std=c++11 blackjack.cpp -o blackjack  
./blackjack  

### Visual Studio
1. Open project in Visual Studio  
2. Build solution (Ctrl + Shift + B)  
3. Run (F5)  

---

## 📂 Project Structure

finaltest66/  
└── blackjack.cpp – full game implementation  

---

## 🎮 Gameplay Example

Welcome to BlackJack(21) game!

Dealer cards now is: 7H  
Total: 7  

Your cards: 10S QD  
Total: 20  

Do you want to take a card?: y  

You got a card: 2C  
Your cards now: 10S QD 2C  
Total: 22  

You lost... Do you want to play again?(Y/N):

---

## ⚙️ Features

- Full 52-card deck simulation  
- Shuffle mechanic  
- Dealer AI (hits until 17)  
- Win / Lose / Draw system  
- Replay option  
- Console interface  

---

## 🚀 Possible Improvements

- Replace rand() with <random> (mt19937)
- Add Ace logic (1 or 11 choice)
- Add betting system
- Add ASCII cards
- Refactor into OOP (Deck, Player, Game)
- Add statistics tracking

---

## 👤 Author

Oleksandr Kopii  
GitHub: https://github.com/SamuraiSanch

---

⭐ If you like this project, give it a star!
