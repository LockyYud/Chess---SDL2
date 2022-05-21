# Chess - A SDL2 C++ Game

## Introduction

A game project made with SDL2 C++.

## Technologies

Project uses:

- Visual Studio Code (VSCode).
- SDL2 image devel 2.0.5 mingw.
- SDL2 ttf devel 2.0.18 mingw.
- SDL2 mixer devel 2.0.4 mingw.
- SDL2 devel 2.0.20 mingw.

## How to compile and play

- **Windows 64bit**: 
    - Requirements:
        - VSCode.
        - Makefile on Windows.
        - MinGW-w64.
    - Clone this repository to your computer.
    - Open command line inside the cloned folder.
    - Run `make`.
    - `main.exe` file will be generated. Open the file to run the game.



## Contents

#### How to play

You got reincarnated as a fearsome warrior living in the open world Mystersy - a dangerous place filled with skeletons and bats.

Try to survive, level up and prepare for your last battle against the Mega Boss. Demolish him to win the game.

**Controls**:

- 4 arrow keys    :       Move around.
- SPACE           :       Slash with sword (bats can't be slashed).
- Q               :       Deliver a blow (1 out of 8 directions) dealing damage to monsters on its way.
- E               :       Create a shield, block every attack of monsters.
- A               :       Show where to find the Mega Boss.
- S               :       Turn on/off background music.
- D               :       Turn on/off sound effects.

**Notes**:

- Killing skeletons will grant you 1 star, killing bats will grant you 2 stars. Reach a certain number of stars to **level up** (heal to full health and increase player's stats).

- To win the game, find and kill the **Mega Boss** (**Mega Boss** will enter rage mode when its health is low).
