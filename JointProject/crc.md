##The player, wants to be able to collide with the enemy and lose health, to add difficulty to the game.

##Class 
	
	- Game

##Responsibility

	- check for the player position
	- check for the enemy position
	- check if the enemy and player sprites are overlapping
	
##Collaborators
	
	- Player
	- Enemy
	
	http://www.plantuml.com/plantuml/uml/SoWkIImgAStDuN9Fp4rLqBLJ2CX9h4mjKh1II4yj2SWlpYp9pC_JqBJcWeY3L81K0kKBm08m9Lnm0rppKdChCVL3X17QKq5yJDqWsaeXEICrETivFoSdinYY7TDvAQd9HQcvgNabFfbbgSLObHIb5gEu0Ts9c0eSKlDIW8410000

	ScreenShot: https://i.imgur.com/7Wlpo2y.png
====================================================================================================================	
	
##The Player, wants to see their character animated, to make the game less stale.

##Class
	
	- Player
	
##Responsibility

	- load in the sprite sheet for the player character	
	- keep the timer running to change from one part of the sprite sheet to another
	- switch back to the starting position when approaching the end of the sprite sheet
	- draw the player sprite
	
##Collaborators

	- Game

	http://www.plantuml.com/plantuml/uml/SoWkIImgAStDuN9Fp4rLqBLJ2CX9h4mjKh1II2vAJIn9LV1FoafDBk622ACeoCpBBCbCpCaiJjNGjCQceBGW9R449AcW2sKNAvHaf2eK5nHb0aqkGZKNx00he6XUIceHo4G780leCW00
	
	ScreenShot: https://i.imgur.com/KIU4Y96.png
====================================================================================================================

#The Player, wants to use the mouse to aim and shoot, so that he is able to shoot the enemies very accurately.

#Class
	
	- Bullet
	
#Responsibility
	
	- Implement a function which tracks where the mouse is positioned on screen before and on mouse click.
	- On mouse click create a line between the player and the end point, where the player clicked.
	- Animate the line to act like a projectile.
	- Delete the line once it hits the endpoint or when it collides with the enemy.

#Collaborators

	- Gameplay
	- Player

	http://www.plantuml.com/plantuml/uml/ROux3i8m44Jxd69AA7A1H48H59Hm1IjPX67zaNUtuFOO9Q08fHjvnc_V8EgAMk3cx09bTY-q1noDcHGTVFJg7NkXtRv72o4LM0RqJiWbFMXKpmH95gTjnEU1oZL99QNORuz2Cg7lvX9FxCTdtoprUcXvShh8p5bcb-KlqktVZUAq8ltEToYreL9PpL2J1Nu3
	
	Screenshot: https://i.imgur.com/gFnnTcC.png
	
====================================================================================================================

#The Player, wants the projectile to collide with the enemy, so that the enemy can be damaged

#Class
	
	- Gameplay
	
#Responsibility

	-Set up collisions between projectile and enemy
	-Decrement enemy health on collision
	-Add score on collision
	-Clear the shot on collision and allow a new projectile to be shot
	
#Collaborators

	- Enemy
	- Bullet

	http://www.plantuml.com/plantuml/uml/TP31JiCm44Jl-Oezmg7z091G1K9S421nH0YvpgHTkauixnhKlmSx8Mg1dhBQdNdnp4hD9Sj1cZiN4CNjQN55ytn1ERRES7P-sLnd4TYlStXRr_Lo0tjAmpkyiHGvBMZ37r2oBIZE5ug3il7GDxSzmluF3MMxdBxFCR51N_YruYVd18Vf35CQEd8YL6mCFHN6R-5tDuC8wmWw4fON5LKBdn3GsqCEQwJ7xhu46NzhRWSbz_djG9LB3SaT-HyiiPAbZ2FsLDv1OLxWqWYjus59_-9MwDiSv0i0

	Screenshot: https://i.imgur.com/Ca0PHcd.png