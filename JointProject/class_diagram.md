#Class Diagram

#PlantUML script: 

@startuml
Game : + Game();
Game : + run();
Game : + currentGameState;

ScreenSize : + s_width;
ScreenSize : + s_height;

MainMenu : + initialise();
MainMenu : + update();
MainMenu : + render();

Help : + displayHelp();
Help : + update();
Help : + processInput();
Help : + render();

Gameplay : + void initialise();
Gameplay : + void processInput(sf::Event t_event, sf::RenderWindow& t_window);
Gameplay : + void update(double dt, sf::RenderWindow& t_window, int t_character);
Gameplay : + void checkCell();
Gameplay : + void checkForPlayerLives();
Gameplay : + void checkForCollisionWithPlayer();
Gameplay : + void checkForCollisionWithBullet();
Gameplay : + void checkForCollisionWithWalls();
Gameplay : +void checkForAliveEnemies();
Gameplay : + void render(sf::RenderWindow& t_window);
Gameplay : + Player m_player;
Gameplay : + int m_chosenCharacter = 0;

Player : + void initialise();
Player : + void update(double dt, int t_character);
Player : + void movement();
Player : + void boundary();
Player : + void increaseRotation();
Player : + void decreaseRotation();
Player : + void playerDeath();
Player : + void render(sf::RenderWindow& t_window);
Player : + sf::Vector2f getPlayerPosition() { return m_playerSprite.getPosition(); };
Player : + double getRotation() { return m_playerSprite.getRotation(); };
Player : + void decrementNumberOfLives() { m_lives--; }
Player : + int returnNumberOfLives() { return m_lives; }
Player : + sf::Sprite returnSprite() { return m_playerSprite; };
Player : + sf::Sprite m_playerSprite;
Player : + int m_characterChosen = 1;
Player : + double m_speed = 0.0;

CharacterChoice : + 	void initialise(sf::Font& t_font);
CharacterChoice : + 	void render(sf::RenderWindow& t_window);
CharacterChoice : + 	void update(double t_deltaTime, sf::Window& t_window);
CharacterChoice : + 	void processInput(sf::Event t_event);
CharacterChoice : + 	int characterChosen = 0;

Bullet : + void initialise();
Bullet : + void update(double dt, Player t_player, sf::Window& t_window);
Bullet : + void shoot(double dt, Player t_player, sf::Window& t_window);
Bullet : + void render(sf::RenderWindow& t_window);
Bullet : + sf::Vector2f getProjectile() { return m_mobileBullet; };
Bullet : + sf::Vector2f playerPos;
Bullet : + sf::VertexArray m_laserPointer{ sf::Lines };
Bullet : + bool m_bulletFired = false;

Cell : + Cell(sf::Vector2f t_position, int t_cellID);
Cell : + void mark(bool t_marked);
Cell : + void addNeighbour(int t_cellID);
Cell : + void setParentCell(int t_cell);
Cell : + bool checkMark();
Cell : + int returnID();
Cell : + int returnParentCell();
Cell : + std::vector<int>& neighbours();
Cell : + void render(sf::RenderWindow& t_window);
Cell : + sf::RectangleShape getRect();

Grid : + Grid(int t_rows, int t_cols);
Grid : + 	std::vector<int> breadthFirst(int t_startCellId, int t_destCellId);
Grid : + void neighbours(int t_row, int t_col, std::vector<Cell>& t_cells, int t_current);
Grid : + void reset();
Grid : + void initialiseMap();
Grid : + void update(double dt);
Grid : + void render(sf::RenderWindow& t_window);
Grid : + Cell returnCell(int t_id);
Grid : + std::vector<Cell> returnAllCells();
Grid : + int breadthSearch( int startCellID, int DestCellID);


Enemy : + void initialise();
Enemy : + void update();
Enemy : + void render(sf::RenderWindow& t_window);
Enemy : + void enemyMovement();
Enemy : + void setEnemyPosition(sf::Vector2f m_enemyPosition);
Enemy : + void checkNumberOfLives();
Enemy : + void decrementNumberOfLives();
Enemy : + int returnNumberOfLives(); 
Enemy : + void resetEnemyPosition();
Enemy : + sf::Vector2f getEnemyPosition(int t_enemy)
Enemy : + sf::Sprite returnSprite();
Enemy : + sf::Sprite m_enemySprites[3];
Enemy : + bool isEnemyMoving = false;
Enemy : + bool isDestinationReached = false;
Enemy : + bool foundNextPosition = false;
Enemy : + std::vector<int> traversableCells;
Enemy : + int currentRow[2];
Enemy : + int currentCol[2];
Enemy : + int enemyID = 0;
Enemy : + sf::Vector2f pos{};
Enemy : + int m_enemyLives[3]{ 3,3,3 };
GameEnd : + void initialise(sf::Font& t_font);
GameEnd : + void update(double dt);
GameEnd : + void render(sf::RenderWindow& t_window);


Obstacles : + void initialise();
Obstacles : + void setObstaclePositions();
Obstacles : + void render(sf::RenderWindow& t_window);
Obstacles : + static const int m_numberOfObstacles = 32;
Obstacles : + sf::Sprite m_obstacles[m_numberOfObstacles];

Particles : + (sf::Vector2f pos, sf::Vector2f vel) 
Particles : + int timetoLive;
Particles : + sf::Vector2f velocity;
Particles : + sf::RectangleShape shape;
Particles : + void Update();
Particles : + void Draw(sf::RenderWindow& win) ;

ParticleSystem : + void Initialise(sf::Vector2f pos);
ParticleSystem : + Particles particles[maxParticles];
ParticleSystem : + sf::Vector2f position;
ParticleSystem : + void Update();
ParticleSystem : + void Draw(sf::RenderWindow& win);

ScreenSize -> Game
Game --> MainMenu
Game --> Help
Game --> Gameplay
Game --> CharacterChoice
Player --> Gameplay
Player --> Bullet
Bullet --> Gameplay
Enemy --> Gameplay
CharacterChoice --> Player
MainMenu --> CharacterChoice
Particles --> ParticleSystem
Particles --> Enemy
Particles --> Player
Obstacles --> Gameplay
Grid --> Gameplay
Cell --> Grid
Gameplay -> GameEnd
@enduml

#Screenshot:


#Link:http://www.plantuml.com/plantuml/uml/fLXHRzks4t-kFuMU2WV_jFYlVOlNefsTRWQQjeYtvI480bewnrmfKY0fErcGxpuUHPdMKSfK30KQyUvtnxlV7S-KFXZBjArBCVcLbP2TPV_By65wCei2NSlEEg-r1cbnlRBCmcmoMUKQGAxutmt2tEvvORUpLBu5VhUrpkA2SNa1ilPoBhdbJ7236tTLTLKmcuero08qYYU_WQYyhE2c4km1rwXevT5555LQvM3CKbQrZOgkNymF_NdvJl62X9dgErxDvkpiV0VIPlOMyEzfXg9Bly4LbuNQltIglN_gTHVYBbIz5f0LppeupRZVATyopN8BkjTZleNy-no4c0whFodzpKb1V-OxCCy3vqe8RhYILznk6wiVCFYb5WBi3nXSCI6IY3hmZy85VIwXv4EXXmAFBqMJLbRULlw1Q97rqh6k3CXvottsBlk_Qw1WET0-L9jMEwqejIdL3agGji_VMjMoOFgXJyTbhe4Pk5IMMKTk7wQ0VySqb2o0sIrLZ-EwOuEuFo6tIh_PP7TW6zKtPNYpV_ReFDfQoqCnLfNc5buxR4JDigUErq2emyHCXZq55FL4Q47ElzJb6lJNZJycwDBv4lZywfKpZ7Q-Hy9sYKsGjwPeI0Xf0WkuPZ4SVuoOEg106byP-spkczdry4yfZ-Z7L005jlXhRFBvaHdFmKDVq7R7E3ufQR7o6_VtP3PiDw9hXgt9CN8c1GZBVkSbDDDphAyHytp85EbCoKIkce4tD12eDXq8eHesb78m8-h9R9Mo_z7HwD94c_H0Q_MNMt91MhXKQoTh3B651trKxKJeWMWBzn-rPWzuc9X169SMzAFNV-OI376zLaeuyDfBFd7jkth3X07iQn32e_1Xsed2qHQcpM56EynouPBtLd4yC_rzYhiu23v3aK1OKNp1Av6Rrdhwh3FZ-6CQf4Nn4JG2GqR-j_02jmugCeIMYm55TDy165kSdUryyZyxyFkNcMmZDXtWs1Q95WqgjqpU2LXjMUNdD4gQ6vZcXSVXGqXPgxqvqAw4SRW3x0KDDLjhO8NTkk8Q6npu2oz6i2nQFmMO80dUOZenrRZ_qVQd7NRGXwEdgKkCihak9wur6B3JH1o7mWMhKZMT2X4mlW3H0YCErJzgAzxX8Sam67mK0fUc4oCw2AIlWEbyE_MYIFgYeMK19gonq1EyiWrUjACoCa0KepCd9e3BYtYBede3ralQwqLt49ItSAnCpVrH93_w54Hl51H83Ya5PIaBDEZeAXtA11eQ051s4es6RoApVb1WfbcPwxSt4HUc53VdWNikx-BSJL3OA5mo3EuIc2Eq60HlyCRx1UvjcqqVCXaHLhCTQCFM0dmxKzh3yRrK--itDmFAkH8zIa_1Se4__eC5g9HvVAA6WJqiCNBtcBqzTV-of-RTuroIQJ5yoQ9mEZqePlGncao-herbkG0pS6hx00PiAsrBP2XqV134p3rRdcUvysa3YpASbGXybxrzqp6aRQjQrNMF-Gs-r35j-S5sIejvsYtl3iH9Hcpy4UCbM8K5dX4jDLSvjmyfAFdTDFW_nNag_mZpibUvq6pVmxBZ-2GxodRrO2oKqMmPIqqP2FiGgxXrvPyym-p-8BxfjQA-VSkaI9efHOnAj_iLwzLx_nqCJuTRk5NxzIbAy9jHNBLV1QA4l1o4TwaE-5ZMN4p3_RIByjEXAoBElR9n5h-JzGKHwu3QBar4wNUb1dwBU818wfeN94mGmajG5R-SeA0PEvCF88kw5Fy0