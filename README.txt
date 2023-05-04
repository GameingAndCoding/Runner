This Game utilizes the C++ programming language using unreal engine Libraries. 

Thus for it's creation both the default C++ data structures and variable types are used as well as unreal engine data structures and variables


This game also saves the highest score to a Json file titled TEST.json. It is done using the Unreal engine JsonConverter

This game utilizes a series of spawning tiles each holding specific components in it 

The pre-made tiles are saved as blueprints and are then put into a TArray that are then chosen and spawned at random. 

50 tiles are spawned at a time and every time the player reaches the 25th tile the previous 25 are destroyed and 25 more 
are added to the end of the road. This ensures that the game is truly infinite while also removing tiles that will never 
be seen or walked over again. This system also utilizes both an array with a predetermined size and an array of a 
changing size (array of possible segments is set and array of currently spawned segments is changing in size)

The game also includes Obstacles colored in red that upon collision with the player will lower player's lives by 1
When player reaches 0 lives current distance traveled is written down in the Json file. In the future the game will end
and the player will be sent to a different scene where they will be offered to retry. 


Final version is ready and I managed to achieve most of the goals. Unfortunately I didnt manage to dispay the highscore 
in game as well as create a menu scene before starting the game due to time constraints. However I achieved the other 
two very difficult goals of adding local coop and a objects that are destroyed at random when passing through some parts 
of the runner.
 
I achieved multiplayer by having the first player spawn and control another pawn rather than spawning in a second pawn 
and then possessing it with a spawned 2nd character controller because I had some issues with doing that and heard that 
Unreal 5 is bugged and doesnt actually support that.

I achieved the destruction goal by having each platform rolling a percentile and on a roll of 75 or higher telling the 
tile manager that the next tile should be destroyed. I didnt manage to only destroy the obstacle on the tile and had to
destroy the whole thing. But destroying the whole tile seems to not cause any issues, so I think I successfully achieved 
that goal.