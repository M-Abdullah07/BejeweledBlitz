#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;
using namespace sf;


void OutputToscoreBoard(int currentScore, Font& subheadingFont, Text& ScoreBoardText)
{

    ScoreBoardText.setString(to_string(currentScore));
    ScoreBoardText.setFont(subheadingFont);
    ScoreBoardText.setCharacterSize(50);
    ScoreBoardText.setPosition(450, 300);
    ScoreBoardText.setFillColor(Color::Black);

}

void eliminateGems(int grid[8][8], int& currentScore)
{

    for (int i = 0; i < 8; i++)
    { //For matching of 3 or 4 gems horizontally.
        for (int j = 0; j < 6; j++)
        {
            if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2] && grid[i][j] == grid[i][j + 3])
            {

               
                {

                    if (grid[i][j] == 0)
                    {
                        grid[i][j] = grid[i][j + 2] = grid[i][j + 3] = -1;

                        grid[i][j + 1] = 5; //Special gem introduction
                        currentScore += 100;
                    }
                    else if (grid[i][j] == 1)
                    {
                        grid[i][j] = grid[i][j + 2] = grid[i][j + 3] = -1;

                        grid[i][j + 1] = 6; //Special gem introduction
                        currentScore += 100;
                    }
                    else if (grid[i][j] == 2) {
                        grid[i][j] = grid[i][j + 2] = grid[i][j + 3] = -1;

                        grid[i][j + 1] = 7; //Special gem introduction
                        currentScore += 100;
                    }
                    else if (grid[i][j] == 3) {
                        grid[i][j] = grid[i][j + 2] = grid[i][j + 3] = -1;

                        grid[i][j + 1] = 8; //Special gem introduction
                        currentScore += 100;
                    }
                    else if (grid[i][j] == 4)
                    {
                        grid[i][j] = grid[i][j + 2] = grid[i][j + 3] = -1;

                        grid[i][j + 1] = 9; //Special gem introduction
                        currentScore += 100;
                    }
                }
            }
            //For 3 gems in a row.
            //For Destroyer Gem
            else if (grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2])
            {
                if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] )
                {
                    grid[i][j + 1] = grid[i][j + 2] = grid[i + 1][j] = grid[i + 2][j]  = -1;
                    grid[i][j] = 10;
                    currentScore += 300;
                }

                else if (grid[i][j + 2] == grid[i + 1][j + 2] && grid[i][j + 2] == grid[i + 2][j + 2] )
                {
                    grid[i][j] = grid[i][j + 1] = grid[i + 1][j + 2] = grid[i + 2][j + 2]  = -1;
                    grid[i][j + 2] = 10;
                    currentScore += 300;
                }

                else
                {
                    grid[i][j] = grid[i][j + 1] = grid[i][j + 2] = -1;
                    currentScore += 50;
                }
            }

            //Condition for special gem.
            else if ((grid[i][j] == grid[i][j + 1] || grid[i][j] == grid[i][j + 2] || grid[i][j + 1] == grid[i][j + 2]) && (grid[i][j] >= 5 || grid[i][j + 1] >= 5 || grid[i][j + 2] >= 5)) 
            {

                if ((grid[i][j] == 0 || grid[i][j + 1] == 0 || grid[i][j + 2] == 0) && (grid[i][j] == 5 || grid[i][j + 1] == 5 || grid[i][j + 2] == 5)) {

                    grid[i][j] = grid[i][j + 1] = grid[i][j + 2] = grid[i + 1][j] = grid[i + 1][j + 1] = grid[i + 1][j + 2] = grid[i - 1][j] = grid[i - 1][j + 1] = grid[i - 1][j + 2] = -1;
                    currentScore += 300;
                }

                if ((grid[i][j] == 1 || grid[i][j + 1] == 1 || grid[i][j + 2] == 1) && (grid[i][j] == 6 || grid[i][j + 1] == 6 || grid[i][j + 2] == 6)) {
                    grid[i][j] = grid[i][j + 1] = grid[i][j + 2] = grid[i + 1][j] = grid[i + 1][j + 1] = grid[i + 1][j + 2] = grid[i - 1][j] = grid[i - 1][j + 1] = grid[i - 1][j + 2] = -1;
                    currentScore += 300;
                }
                if ((grid[i][j] == 2 || grid[i][j + 1] == 2 || grid[i][j + 2] == 2) && (grid[i][j] == 7 || grid[i][j + 1] == 7 || grid[i][j + 2] == 7)) {
                    grid[i][j] = grid[i][j + 1] = grid[i][j + 2] = grid[i + 1][j] = grid[i + 1][j + 1] = grid[i + 1][j + 2] = grid[i - 1][j] = grid[i - 1][j + 1] = grid[i - 1][j + 2] = -1;
                    currentScore += 300;
                }
                if ((grid[i][j] == 3 || grid[i][j + 1] == 3 || grid[i][j + 2] == 3) && (grid[i][j] == 8 || grid[i][j + 1] == 8 || grid[i][j + 2] == 8)) {
                    grid[i][j] = grid[i][j + 1] = grid[i][j + 2] = grid[i + 1][j] = grid[i + 1][j + 1] = grid[i + 1][j + 2] = grid[i - 1][j] = grid[i - 1][j + 1] = grid[i - 1][j + 2] = -1;
                    currentScore += 300;
                }
                if ((grid[i][j] == 4 || grid[i][j + 1] == 4 || grid[i][j + 2] == 4) && (grid[i][j] == 9 || grid[i][j + 1] == 9 || grid[i][j + 2] == 9)) {
                    grid[i][j] = grid[i][j + 1] = grid[i][j + 2] = grid[i + 1][j] = grid[i + 1][j + 1] = grid[i + 1][j + 2] = grid[i - 1][j] = grid[i - 1][j + 1] = grid[i - 1][j + 2] = -1;
                    currentScore += 300;
                }
            }

            else
            {

                int s;
                int t;

                if ((grid[i][j] == grid[i][j+1] && grid[i][j+2] == 10))
                {
                    s = i ;
                    t = j +2;
                    currentScore += 500;

                    for (int k = 0; k < 8; k++)
                    {
                        grid[k][t] = -1;
                    }

                    for (int k = 0; k < 8; k++)
                    {
                        grid[s][k] = -1;

                    }

                }

                else if ((grid[i][j] == grid[i][j+2] && grid[i][j+1] == 10))
                {
                    s = i;
                    t = j + 1;
                    currentScore += 500;

                    for (int k = 0; k < 8; k++)
                    {
                        grid[k][t] = -1;
                    }

                    for (int k = 0; k < 8; k++)
                    {
                        grid[s][k] = -1;

                    }


                }

                else if ((grid[i][j+1] == grid[i][j+2] && grid[i][j] == 10))
                {
                    s = i;
                    t = j;
                    currentScore += 500;

                    for (int k = 0; k < 8; k++)
                    {
                        grid[k][t] = -1;
                    }

                    for (int k = 0; k < 8; k++)
                    {
                        grid[s][k] = -1;

                    }

                }

              /*  for (int k = 0; k < 8; k++)
                {
                    grid[k][t] = -1;
                }

                for (int k = 0; k < 8; k++)
                {
                    grid[s][k] = -1;

                }*/


            }
        }
    }

    for (int j = 0; j < 8; j++) { //For matching of 3 or 4 gems vertically.
        for (int i = 0; i < 6; i++) {
            if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j] && grid[i][j] == grid[i + 3][j])
            {
                { //Using gem positions to identify which special gem matches the regular gems.

                    if (grid[i][j] == 0)
                    {
                        grid[i][j] = grid[i + 2][j] = grid[i + 3][j] = -1;

                        grid[i + 1][j] = 5; //Special gem introduction
                        currentScore += 100;
                    }
                    else if (grid[i][j] == 1) {
                        grid[i][j] = grid[i + 2][j] = grid[i + 3][j] = -1;

                        grid[i + 1][j] = 6; //Special gem introduction
                        currentScore += 100;
                    }
                    else if (grid[i][j] == 2) {
                        grid[i][j] = grid[i + 2][j] = grid[i + 3][j] = -1;

                        grid[i + 1][j] = 7; //Special gem introduction
                        currentScore += 100;
                    }
                    else if (grid[i][j] == 3) {
                        grid[i][j] = grid[i + 2][j] = grid[i + 3][j] = -1;

                        grid[i + 1][j] = 8; //Special gem introduction
                        currentScore += 100;
                    }
                    else if (grid[i][j] == 4) {
                        grid[i][j] = grid[i + 2][j] = grid[i + 3][j] = -1;

                        grid[i + 1][j] = 9; //Special gem introduction
                        currentScore += 100;
                    }
                }
            }

            //3 in a column
            //For Destroyer Gem
            else if (grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i + 2][j])
            {
                if (grid[i + 2][j] == grid[i + 2][j + 1] && grid[i + 2][j] == grid[i + 2][j + 2] )
                {
                    grid[i][j] = grid[i + 1][j] = grid[i + 2][j + 1] = grid[i + 2][j + 2] = -1;
                    grid[i + 2][j] = 10;
                    currentScore += 300;
                }

                else if (grid[i + 2][j] == grid[i + 2][j - 1] && grid[i + 2][j] == grid[i + 2][j - 2] )
                {
                    grid[i][j] = grid[i + 1][j] = grid[i + 2][j - 1] = grid[i + 2][j - 2] = -1;
                    grid[i + 2][j] = 10;
                    currentScore += 300;
                }

                else
                {
                    grid[i][j] = grid[i + 1][j] = grid[i + 2][j] = -1;
                    currentScore += 50;
                }
            }
            //Condition for special gem.
            else if ((grid[i][j] == grid[i + 1][j] || grid[i][j] == grid[i + 2][j] || grid[i + 1][j] == grid[i + 2][j]) && (grid[i][j] >= 5 || grid[i + 1][j] >= 5 || grid[i + 2][j] >= 5)) 
            {

                if ((grid[i][j] == 0 || grid[i + 1][j] == 0 || grid[i + 2][j] == 0) && (grid[i][j] == 5 || grid[i + 1][j] == 5 || grid[i + 2][j] == 5)) {

                    grid[i][j] = grid[i + 1][j] = grid[i + 2][j] = grid[i][j + 1] = grid[i + 1][j + 1] = grid[i + 2][j + 1] = grid[i][j - 1] = grid[i + 1][j - 1] = grid[i + 1][j - 1] = -1;
                    currentScore += 300;
                }

                if ((grid[i][j] == 1 || grid[i + 1][j] == 1 || grid[i + 2][j] == 1) && (grid[i][j] == 6 || grid[i + 1][j] == 6 || grid[i + 2][j] == 6)) {
                    grid[i][j] = grid[i + 1][j] = grid[i + 2][j] = grid[i][j + 1] = grid[i + 1][j + 1] = grid[i + 2][j + 1] = grid[i][j - 1] = grid[i + 1][j - 1] = grid[i + 1][j - 1] = -1;
                    currentScore += 300;
                }
                if ((grid[i][j] == 2 || grid[i + 1][j] == 2 || grid[i + 2][j] == 2) && (grid[i][j] == 7 || grid[i + 1][j] == 7 || grid[i + 2][j] == 7)) {
                    grid[i][j] = grid[i + 1][j] = grid[i + 2][j] = grid[i][j + 1] = grid[i + 1][j + 1] = grid[i + 2][j + 1] = grid[i][j - 1] = grid[i + 1][j - 1] = grid[i + 1][j - 1] = -1;
                    currentScore += 300;
                }
                if ((grid[i][j] == 3 || grid[i + 1][j] == 3 || grid[i + 2][j] == 3) && (grid[i][j] == 8 || grid[i + 1][j] == 8 || grid[i + 2][j] == 8)) {
                    grid[i][j] = grid[i + 1][j] = grid[i + 2][j] = grid[i][j + 1] = grid[i + 1][j + 1] = grid[i + 2][j + 1] = grid[i][j - 1] = grid[i + 1][j - 1] = grid[i + 1][j - 1] = -1;
                    currentScore += 300;
                }
                if ((grid[i][j] == 4 || grid[i + 1][j] == 4 || grid[i + 2][j] == 4) && (grid[i][j] == 9 || grid[i + 1][j] == 9 || grid[i + 2][j] == 9)) {
                    grid[i][j] = grid[i + 1][j] = grid[i + 2][j] = grid[i][j + 1] = grid[i + 1][j + 1] = grid[i + 2][j + 1] = grid[i][j - 1] = grid[i + 1][j - 1] = grid[i + 1][j - 1] = -1;
                    currentScore += 300;
                }
            }
            //Destroyer gem explosion.
            else
            {

                int s;
                int t;

                if ((grid[i][j] == grid[i + 1][j] && grid[i + 2][j] == 10) )
                {
                    s = i+2;
                    t = j;
                    currentScore += 500;
                   
                    for (int k = 0; k < 8; k++)
                    {
                        grid[k][t] = -1;
                    }

                    for (int k = 0; k < 8; k++)
                    {
                        grid[s][k] = -1;

                    }
                }

                else  if ((grid[i][j] == grid[i + 2][j] && grid[i + 1][j] == 10))
                {
                      s = i+1;
                      t = j;
                      currentScore += 500;
                     
                      for (int k = 0; k < 8; k++)
                      {
                          grid[k][t] = -1;
                      }

                      for (int k = 0; k < 8; k++)
                      {
                          grid[s][k] = -1;

                      }
                   
                }

                else if ((grid[i + 1][j] == grid[i + 2][j] && grid[i][j] == 10))
                {
                     s = i;
                     t = j;
                     currentScore += 500;
                   
                     for (int k = 0; k < 8; k++)
                     {
                         grid[k][t] = -1;
                     }

                     for (int k = 0; k < 8; k++)
                     {
                         grid[s][k] = -1;

                     }
                }

               /* for (int k = 0; k < 8; k++)
                {
                    grid[k][t] = -1;
                }

                for (int k = 0; k < 8; k++)
                {
                    grid[s][k] = -1;

                }*/


            }
               
        }
    }


    //New values at eliminated gems position.
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) { //Randomizing for new gems.
            if (grid[i][j] == -1)
            {
                grid[i][j] = rand() % 5;
            }
        }
    }

}


void openGameWindow(int& currentScore, bool& wasGameCompleted)
{

    const int tableSize = 90;
    const int gridSize = 8;

    int grid[gridSize][gridSize];
    Texture jewelTextures[11]; // Declare jewelTextures 


    RenderWindow gameWindow(VideoMode(1800, 850), "Game Window");

    Texture backgroundTexture, tableTexture, cursorTexture, scoreBoardTexture;
    backgroundTexture.loadFromFile("bejeweled_3.JPG");
    tableTexture.loadFromFile("table2.png");
    jewelTextures[0].loadFromFile("jewel_0.png");
    jewelTextures[1].loadFromFile("jewel_1.png");
    jewelTextures[2].loadFromFile("jewel_2.png");
    jewelTextures[3].loadFromFile("jewel_3.png");
    jewelTextures[4].loadFromFile("jewel_4.png");

    //Special gem texture.
    jewelTextures[5].loadFromFile("jewel_5.png");
    jewelTextures[6].loadFromFile("jewel_6.png");
    jewelTextures[7].loadFromFile("jewel_7.png");
    jewelTextures[8].loadFromFile("jewel_8.png");
    jewelTextures[9].loadFromFile("jewel_9.png");

    //Destroyer gem texture.
    jewelTextures[10].loadFromFile("jewel_10.png");

    //For cursor
    cursorTexture.loadFromFile("cursor.png");

    Sprite backgroundSprite(backgroundTexture), tableSprite(tableTexture), cursorSprite(cursorTexture);

    //Initializing positions for each gem using rand function.
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            grid[i][j] = rand() % 5;
        }
    }

    //TIMER
    Font subheadingFont;
    Clock timer;
    Time elapsedTime;
    Time timeLimit = seconds(60);
    Text timetext;

    timetext.setFont(subheadingFont);
    timetext.setString("Time");
    timetext.setCharacterSize(70);
    timetext.setPosition(430, 500);
    timetext.setFillColor(Color::Red);

    Text time;

    time.setFont(subheadingFont);
    time.setCharacterSize(70);
    time.setPosition(450, 550);
    time.setFillColor(Color::Black);

    //For gem Selection
    bool gemSelected = false;

    //Sizing the table & Background picture & cursor.
    float scale = 2.2;
    float sideX = tableSize + 790;
    float sideY = tableSize - 25;
    backgroundSprite.setScale(scale, scale);
    tableSprite.setPosition(580, -50);
    tableSprite.setScale(0.632 * scale, 0.632 * scale);
    cursorSprite.setPosition(sideX, sideY);
    cursorSprite.setScale((0.042 * scale), (0.042 * scale));


    //For Scoring and saving
  // Font subheadingFont;
    subheadingFont.loadFromFile("subheadingFont.ttf");

    currentScore = 0;

    Text ScoreBoardHeading("Score", subheadingFont, 60);
    ScoreBoardHeading.setPosition(420, 250);
    ScoreBoardHeading.setFillColor(Color::Red);

    Text ScoreBoardText;
    OutputToscoreBoard(currentScore, subheadingFont, ScoreBoardText);

    //Drawing frame for score
    Texture scoreTexture;
    scoreTexture.loadFromFile("Score.png");
    Sprite scoreSprite(scoreTexture);
    scoreSprite.setPosition(300, 240);

    //Cursor Co-ordinates
    int cursorX = 0, cursorY = 0;



    // To exit gameWindow.

    while (gameWindow.isOpen()) {
        Event gameEvent;
        eliminateGems(grid, currentScore);
        while (gameWindow.pollEvent(gameEvent)) {
            if (gameEvent.type == Event::Closed) {
                gameWindow.close();
            }
            else if (gameEvent.type == Event::KeyPressed) {
                if (gameEvent.key.code == Keyboard::Escape)
                    gameWindow.close();
                else if (gameEvent.key.code == Keyboard::Right && sideX <= 1440 && gemSelected == false) {
                    sideX += 90;
                    cursorSprite.setPosition(sideX, sideY);
                    cursorY++;
                }
                else if (gameEvent.key.code == Keyboard::Left && sideX >= 970 && gemSelected == false) {
                    sideX -= 90;
                    cursorSprite.setPosition(sideX, sideY);
                    cursorY--;
                }
                else if (gameEvent.key.code == Keyboard::Down && sideY <= 650 && gemSelected == false) {
                    sideY += 90;
                    cursorSprite.setPosition(sideX, sideY);
                    cursorX++;
                }
                else if (gameEvent.key.code == Keyboard::Up && sideY >= 75 && gemSelected == false) {
                    sideY -= 90;
                    cursorSprite.setPosition(sideX, sideY);
                    cursorX--;
                }

                else if (gameEvent.key.code == Keyboard::Enter) { //Selection of gem using bool flag

                    gemSelected = true;


                }
                else if (gemSelected) {
                    //Swapping the gems using arrow keys.

                    if (gameEvent.key.code == Keyboard::Right && sideX <= 1440) { //To move the gem to the right.

                        int temp = grid[cursorX][cursorY];
                        grid[cursorX][cursorY] = grid[cursorX][cursorY + 1];
                        grid[cursorX][cursorY + 1] = temp;
                        eliminateGems(grid, currentScore);


                        OutputToscoreBoard(currentScore, subheadingFont, ScoreBoardText);

                        gemSelected = false; //False so that it can check again for the next gem.
                    }
                    else if (gameEvent.key.code == Keyboard::Left && sideX >= 970) { //To move the gem to the left.

                        int temp = grid[cursorX][cursorY];
                        grid[cursorX][cursorY] = grid[cursorX][cursorY - 1];
                        grid[cursorX][cursorY - 1] = temp;
                        eliminateGems(grid, currentScore);


                        OutputToscoreBoard(currentScore, subheadingFont, ScoreBoardText);

                        gemSelected = false;

                    }
                    else if (gameEvent.key.code == Keyboard::Down && sideY <= 650) { //To move the gem downwards.

                        int temp = grid[cursorX][cursorY];
                        grid[cursorX][cursorY] = grid[cursorX + 1][cursorY];
                        grid[cursorX + 1][cursorY] = temp;
                        eliminateGems(grid, currentScore);


                        OutputToscoreBoard(currentScore, subheadingFont, ScoreBoardText);

                        gemSelected = false;

                    }
                    else if (gameEvent.key.code == Keyboard::Up && sideY >= 75) { //To move the gem upwards

                        int temp = grid[cursorX][cursorY];
                        grid[cursorX][cursorY] = grid[cursorX - 1][cursorY];
                        grid[cursorX - 1][cursorY] = temp;
                        eliminateGems(grid, currentScore);


                        OutputToscoreBoard(currentScore, subheadingFont, ScoreBoardText);

                        gemSelected = false;

                    }
                }
            }
        }


        // Clear and draw contents of the game window here

        elapsedTime = timer.getElapsedTime();

        if (elapsedTime >= timeLimit)
        {
            wasGameCompleted = true;
            gameWindow.close();
        }
        int timeleft = 60 - elapsedTime.asSeconds();

        time.setString(to_string(timeleft));

        gameWindow.clear();
        gameWindow.draw(backgroundSprite);
        gameWindow.draw(tableSprite);
        gameWindow.draw(cursorSprite);
        gameWindow.draw(ScoreBoardHeading);
        gameWindow.draw(ScoreBoardText);
        gameWindow.draw(scoreSprite);
        gameWindow.draw(timetext);
        gameWindow.draw(time);


        // Drawing jewels and grids as sprite.
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {

                Sprite jewelSprite(jewelTextures[grid[i][j]]);
                jewelSprite.setPosition((j * tableSize) + 900, (i * tableSize) + 80); //To shift the table right.
                jewelSprite.setScale(0.3, 0.3);
                gameWindow.draw(jewelSprite);

            }
        }

        gameWindow.display();
    }
}

void OpenExitWindow(int finalScore)
{
    RenderWindow exitWindow(VideoMode(1800, 850), "Exit Screen");
    Font textFont;
    textFont.loadFromFile("subheadingFont.ttf");

    Text playerFinalScore;

    if (finalScore > 0)
    {
        playerFinalScore.setString("Your final score was " + to_string(finalScore));

    }

    else
    {
        playerFinalScore.setString("Your final score was " + to_string(finalScore - 100));
    }

    playerFinalScore.setPosition(900, 480);
    playerFinalScore.setFont(textFont);
    playerFinalScore.setCharacterSize(80);

    int highScore;
    ifstream infile("HighScoreFile.txt");
    infile >> highScore;
    infile.close();

    Text displayHighScore;
    if (finalScore > highScore)
    {
        ofstream outfile("HighScoreFile.txt");
        outfile << finalScore;
        outfile.close();

        displayHighScore.setString("You made a new high score!");
    }

    else
    {
        displayHighScore.setString("The current high score is " + to_string(highScore));
    }

    displayHighScore.setPosition(900, 400);
    displayHighScore.setFont(textFont);
    displayHighScore.setCharacterSize(80);

    while (exitWindow.isOpen())
    {
        Event event;

        exitWindow.clear();
        exitWindow.draw(playerFinalScore);
        exitWindow.draw(displayHighScore);
        exitWindow.display();

        while (exitWindow.pollEvent(event))
        {
            if (event.type == Event::Closed)
                exitWindow.close();
        }
    }


}


int main() {
    RenderWindow window(VideoMode(800, 560), " <Game> ");
    // First Page For Menu or Intro.
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("Bejeweled.Jfif");

    Sprite backgroundSprite(backgroundTexture);
    float scale = 1.2; // approximated from Bejeweled.jfif size
    backgroundSprite.setScale(scale, scale);

    Font headingFont;
    headingFont.loadFromFile("headingFont.ttf");
    Text headingText(" BEJEWELED ", headingFont, 100);
    headingText.setPosition(250, 0);
    Color headingColor(Color::Black);
    headingText.setFillColor(headingColor);

    Font subheadingFont;
    subheadingFont.loadFromFile("subheadingFont.ttf");

    Text playText("--> Play", subheadingFont, 50);
    playText.setPosition(350, 200);
    playText.setFillColor(Color::Black); // Adjust color if needed


    Text playsignText(" 'Press 'P''", subheadingFont, 45);
    playsignText.setPosition(350, 250);
    playsignText.setFillColor(Color::White); // Adjust color if needed


    Text exitText("--> Exit", subheadingFont, 50);
    exitText.setPosition(350, 300);
    exitText.setFillColor(Color::Black); // Adjust color if needed

    Text exitsignText(" 'Press 'E''", subheadingFont, 45);
    exitsignText.setPosition(350, 350);
    exitsignText.setFillColor(Color::White); // Adjust color if needed


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            else if (event.type == Event::KeyPressed) {
                // Check for key presses
                if (event.key.code == Keyboard::P)
                {
                    cout << "Hi. Welcome to the Game: ";
                    int currentScore = 0;
                    bool wasGameCompleted = false;
                    openGameWindow(currentScore, wasGameCompleted);

                    if (wasGameCompleted == true)
                    {
                        OpenExitWindow(currentScore);
                    }
                }
                else if (event.key.code == Keyboard::E) {
                    // Handle the "Exit" action
                    window.close();
                }
            }
        }

        // Display
        window.clear();
        window.draw(backgroundSprite);
        window.draw(headingText);
        window.draw(playText);
        window.draw(playsignText);
        window.draw(exitText);
        window.draw(exitsignText);
        window.display();
    }

    return 0;

}















