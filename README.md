# Conways-Game-Of-Life
A C++ Application that visualizes Conway's Game of Life a popular Cellular Automaton, using SFML:
> A Simple and Fast Multimedia Library ([SFML](https://www.sfml-dev.org/)) is a cross-platform software development library designed to provide a simple 
> application programming interface to various multimedia components in computers.

To Install visit: https://www.sfml-dev.org/download/sfml/2.5.1/

## Description
Conway's game of life is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.
The world of the Game of life is an infinite, two-dimensional orthogonal grid square cells, each of which is in one of two possible states, live or dead.
Every cell interacts with its eight neighbours, which are the cells horizontally, vertically, or diagonally adjacent to them.

## Rules
1. Any live cell with fewer than two live neighbours dies (as if by underpopulation)
2. Any live cell with two or three live neighbours lives on to the next generation
3. Any live cell with more than three live neighbours dies (as if by overpopulation)
4. Any dead cell with exactly three live neighbours becomes a live cell (as if by reproduction)

## Controls
- <kbd>Space</kbd>: Pauses any further generation iteration
- <kbd>Up</kbd>: Increases Sleep between each render (Slows down)
- <kbd>Down</kbd>: Decreases Sleep between each render (Speeds up)