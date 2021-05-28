# Tic Tac Toe

This is a console based Tic Tac Toe game.

## Features

- Play against an AI: **random** or **minimax**
- Play against a friend using P2P

## How to play

The game starts directly when you launch the executable, as a human you can provide an input between [1; 9].
1 is the top-left corner, 9 is the bottom-right corner.  
  
You can play against another human on the same computer, against a random AI or a perfect AI (using minimax algorithm).

## Usage

```
./TicTacToe.exe -p1 [human|random|minimax] -p2 [human|random|minimax]
```
If you omit the `-p1` or `-p2` argument, the default is `human`.  
  
If you want to play against a friend, the first player has to use the `-host` parameter and the second the `-join`
with the IP of the first.

```
./TicTacToe.exe -host
./TicTacToe.exe -join [ip]
```

## Purposes & Source code

I tried to make the source code easily understandable if someone wants to learn from it, it's a pretty simple project. It uses polymorphism and is easily extendable.  
It uses no external library, and basic sockets for the P2P part.
