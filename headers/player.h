#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class player
{
    private:
        Texture pTexture;
        Clock clock;
        float frameCounter = 0, switchFrame = 0.16, frameSpeed = 500;
        // source is the position of rectangle on spritesheet
        Vector2i source{0, 0};
         bool isWalking = false;
         Vector2f velocity;
         float jumpForce = 12.0f;
        const float groundHeight = 495.0f;
        float movespeed = 1.15f;
        float verticalVelocity;
        float dir =1;
        Vector2f moveVector;
        enum Direction{Down, Up, Left, Right};
        bool isJumping = false;
        bool isOnGround = true;
        Music jumpM;

    public:
        Sprite playerImage;
        float pleft,pright,pbottom;

    public:
        player();
        FloatRect Getplayerposition();
        Vector2f GetPos();
        void collide();
        float pHeight();
        //float getDir();
        void update();
        void jump();

};
#endif // PLAYER_H
