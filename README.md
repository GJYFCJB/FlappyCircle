# Flappy Circle

**This is my team project with my classmates called Flappy Circle similar as Flappy Bird. I was responsible for writing the grass and WallQueue class in the game which is about 30% lines code of the whole project.**

**First Class - Wall class :** As shown in the page: 

Each wall has a hole in it, the hole divides the wall into 2 parts: the upper wall and the lower wall
We hardcoded the size of the hole = 25% screen height;
Therefore the height of the upper and lower wall should add up to 75% screen height;
The height of either of them should be generated randomly, as long as the sum of two heights = 75% screen height;

To randomly generate the heights, we do as follows:

Generate a random number from 5 to 70 and divide it by 100.

This number (upper height percentage) represents the height of the upper wall as a percentage of the total screen height, which means the upper wall can be from 5% to 70% of the screen height. We have the hole = 25% screen height, so the lower wall should be 5% to 70% of the screen height as well.

**Second Class - WallQueue class:**

We use the vector to store wall of the WallQueue.

Write calculateScore function to record the score by counting walls that the cat has passed.

Introduction: 
1. How to play
The gameplay is simple – it's similar to the once popular mobile game Flappy Bird. But there is no bird in this game – you would have to guide a cat through the obstacles instead.

* If no key is pressed, the cat just drops to the ground
* To make the cat jump, press Space ![Normal Gameplay](FlappyCat/GamePics/game.png)
* The rule of three in our game:
  * Don't hit the ceiling! ![Don't Hit The Ceiling](FlappyCat/GamePics/hit_ceiling.png)
  * Don't hit the grass! ![Don't Hit The Grass](FlappyCat/GamePics/hit_ground.png)
  * Last and probably the hardest, don't hit the wall! ![Don't Hit The Wall](FlappyCat/GamePics/hit_wall.png)

2. Game feature
* Press Enter to start the game ![Game Start](FlappyCat/GamePics/start.png)
* Press P (as in Pause) to pause the game and press C (as in Continue) to continue the game ![Pause](FlappyCat/GamePics/pause.png)
* When the game is over, a message box shows up displaying the user's score and prompting the user to press Enter to restart the game ![Game Over](FlappyCat/GamePics/game_over.png)
* Some side features:
  * At the end of the screen, there are two messages: one instructing the user about the aforementioned Pause feature and the other showing the current score as the game progresses.
  * The walls should be gradually moving faster and faster as time goes by.
  * The background should be changing from light blue to dark blue and then light blue again – this signifies the transition from day to night to day in game time.
