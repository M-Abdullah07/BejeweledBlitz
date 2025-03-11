

BEJEWELED BLITZZ

Authors
Sheraz Malik & Muhammad Abdullah

---> Overview
Bejeweled Blitzz is a simple game coded in C++ using the SFML (Simple and Fast Multimedia Library) for graphics. The game features a menu page with options to play and exit. If "play" is chosen, a new window opens with an 8x8 table of randomized gems.

---> Gameplay
- **Controls:**
  - Use cursor keys to navigate on the game board.
  - Press the enter key to select a gem for swapping.
  - Use the cursor key again to choose an adjacent gem for swapping.

---> **Scoring:**
  - The left side of the window displays the score and time.
  - Successful gem combinations increment the score:
    - Match of three: 50 points
    - Match of four: 100 points
    - Match of three with a special gem: 300 points

---> Special Features
- **Textures and Sprites:**
  - Textures and sprites are utilized to enhance the visual elements of the game.

- **Elimination of Gems:**
  - The `eliminateGems` function ensures the removal of matching gems and creation of special ones.

---> Rapid Movement
- Sometimes, due to the rapid movement of gems, the increment may be more than expected. This is designed to destroy matching gems not easily visible to the naked eye.

---> Timer Functionality
- The entire program is controlled by the built-in timer function named "timer" and "elapsedTime."
- The game continues to run until the timer reaches 60 seconds exactly.

---> End of Game
- The game concludes when the timer runs out, displaying the final score.

---> Running the Program
To run the Bejeweled Blitzz game, ensure you have SFML installed and configured in your C++ development environment. Compile and execute the source code file to enjoy the game.

Feel free to explore and modify the code for your own customization. Have fun playing Bejeweled Blitzz!

**Note:** Make sure to check the SFML documentation for any updates or specific requirements.