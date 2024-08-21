//
//  game.hpp
//  sfmlgame2
//
//  Created by Sunmyoung Yun on 2024/08
//
#ifndef game_hpp
#define game_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include "sprites.hpp"
#include "sound.hpp"
#include "fonts.hpp"
#include "global.hpp"

class GameManager {
public:
    GameManager();
    void runGame();
    
private:
    void createAssets();
    void countTime();
    void handleEventInput();
    void handleGameEvents();
    void updateSprites();
    void draw();
    void restartGame();

    sf::RenderWindow window;
    sf::Clock clock;
    float deltaTime {};
    float globalTime {}; 
    
    // Use std::unique_ptr for managing the lifetime of objects
    std::unique_ptr<Obstacle> obstacle1; 
    std::vector<std::unique_ptr<Obstacle>> obstacles; 
    std::unique_ptr<Static> background; 
    std::unique_ptr<Player> playerSprite;
    std::unique_ptr<TextClass> textSprite; 
    std::unique_ptr<MusicClass> backgroundMusic;
    std::unique_ptr<SoundClass> playerDeadSound;

    const std::string gameTitle{}; 
    const int screenHeight{};
    const int screenWidth{};
    const int frameLimit{};
};

#endif /* game_hpp */
