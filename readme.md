# Arduino Memory Game

## Description

This project is an implementation of a memory game using Arduino. The game involves a sequence of LEDs and sounds that the player needs to remember and replicate by pressing the corresponding buttons. The difficulty of the game increases as the player progresses.
![](https://i.ibb.co/dKctySm/Memory-Game-bb.png)

## Table of Contents

- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Hardware Setup](#hardware-setup)
- [Usage](#usage)
- [Game Rules](#game-rules)
- [License](#license)

## Getting Started

### Prerequisites

To run this project, you will need the following:

- Arduino board
- LEDs
- Buzzer
- Capacitive Touch Sensor
- 220 Ohm Resistors matching the number of LED's
- Breadboard
- Jumpe Wires
- Arduino IDE (or compatible software) installed on your computer

### Hardware Setup

1. Connect the LEDs, buttons, and buzzer to the specified pins on your Arduino board as described in the code.

2. Ensure all the connections are secure and correctly wired.

3. Upload the provided Arduino code to your board using the Arduino IDE.

## Usage

- Press the reset button on your Arduino to start a new game.

- The game will begin by lighting up a random sequence of LEDs and playing corresponding sounds.

- Your goal is to replicate the sequence by pressing the buttons in the correct order.

- If you press the buttons in the correct order, the game progresses to the next level, increasing in difficulty.

- If you make a mistake, the game will signal with a wrong sequence alarm, and you can start a new game.

- Continue playing and see how far you can go!

## Game Rules

- The game starts with a sequence of three LEDs and sounds.

- You must replicate the sequence by pressing the corresponding buttons.

- The game will continue until you make a mistake, at which point you'll need to start over.

- As you successfully complete each level, the game will increase in difficulty by adding more LEDs to the sequence and decreasing the time between each LED and sound.


## License

This project is licensed under the [MIT License](LICENSE) - see the [LICENSE](LICENSE) file for details.