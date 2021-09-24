##Domain Model

PlantUML script

http://www.plantuml.com/plantuml/uml/ZOzFJm8n4CNl-obwt4ta2s1YKA9UH4s88Hw7TaWR-uVCJZ5-Uxk3gT1mu0Jxtk_rlLcC3CGv-EvZH5ApE_KC0TLSYTx9Hn5NuE8AOow69WJ6hYhdhekE7NWtOZ_SgBmtmFAFC1gaVZZ9rIf3yDqFjKk6pFyJigof6T6ZPhNDp2cUlRcqGA0PQMcJqtZDf2PIDzIQ2jGfJQIYQ4xW5lgxUE_XvvfPbIsvnuXX2cq9mR1T8v2s_N2hPchdeb4JLne5QtgqHVtrb6YPV2bpAMuSstVXomFregCYk_QP9qUKSo-a0mQCV1fyoDuZ5tEqAObpLAwP8QHaBXrhK9FKlUQmHNhRlRW3ZWrzgUFU5t1wnLt62pgRVjSCZEepPRL9iLjWD3duNm00

@startuml
User -> Game : start
Game -> MainMenu : create
MainMenu -> MainMenu : initialise(), update(), render()
MainMenu -> Game : draw()
Game -> User : render()

User -> MainMenu : select button
MainMenu -> CharacterChoice : initialise(), update(), render()
CharacterChoice -> User : select Character
User -> CharacterChoice : selected Character
CharacterChoice -> Gameplay : initialise(), update(), render()
Gameplay -> Enemy : breadthSearch(); - find player
Enemy -> Gameplay : checkForCollisionWithPlayer();
User -> Player : input();
Player -> Player : movement();
User -> Bullet : shoot();
Bullet -> Gameplay : checkForCollisionWithBullet();
Gameplay -> Enemy : decrementNumberOfLives();
Gameplay -> Gameplay : checkForAliveEnemies();
Gameplay -> Game : -GameState You Won
@enduml


Render Screenshot: https://i.imgur.com/4sdKRBt.png