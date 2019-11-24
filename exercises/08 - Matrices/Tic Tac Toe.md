# Tic Tac Toe

Implement a function that lets two players play a game of tic tac toe.

## Rules

- The function should take one parameter (the size of the board)
- Save the game board as a 2D array

## Turn breakdown

- Prompt the current player to input board coordinates until he inputs valid one
- Place his marker on the board
- Output the current board (use X for player 1, O for player 2, - for EMPTY)
- If the last move won the game, output "Player ? wins!" and end the game
- If the board is full and there isn't a winner, output "Draw!" and end the game

## Example

```
game(3)
- - -
- - -
- - -

>> 0 0
X - -
- - -
- - -

>> 0 1
X O -
- - -
- - -

>> 1 0
X O -
X - -
- - -

>> 1 1
X O -
X O -
- - -

>> 2 0
X O -
X O -
X - -

Player 1 wins!
```
