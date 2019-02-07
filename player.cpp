#include "headers/game_objects.h"
#include "headers/player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <iostream>

using namespace std;
using namespace sf;
gobject p;

player::player()
{

    if(!pTexture.loadFromFile("images/Character.png"))
    {
        cout<< "Error! The file is not found!";
    }
    else
    {
        playerImage.setTexture(pTexture);
        playerImage.setPosition(Vector2f(10,395));
    }
}
void player::update()
{
    // collide command
   //if(!p.Getboxposition().contains(Vector2f(Getplayerposition().left + 1 * 10,Getplayerposition().top+ pHeight()/2))){
        if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                source.y = Direction::Left;
                velocity.x = -movespeed;
                isWalking = true;
                dir =-1;
            }
         else if(Keyboard::isKeyPressed((Keyboard::Right)))
            {
                source.y = Direction::Right;
                velocity.x = movespeed;
                isWalking = true;
                dir =1;
            }
          else
            {
                source.y = Direction::Down;
                playerImage.setTextureRect(IntRect(2*64, 0 , 64, 96 ));
                velocity.x = 0;
            }
        if(isWalking)
        {
            frameCounter += clock.restart().asSeconds();
            if (frameCounter >= switchFrame)
            {
                frameCounter = 0;
                source.x++;
                if(source.x * 64 >= pTexture.getSize().x)
                {
                    source.x = 0 ;
                }
            }
            playerImage.setTextureRect(IntRect(source.x *64, source.y*96 , 64, 96 ));
        }
        playerImage.move(velocity);
        isWalking = false;
}

void player::jump()
{
    verticalVelocity = 0;
        if(playerImage.getPosition().y < (groundHeight - 250))
        {
            isOnGround = false;
            //cout<<"up"<<endl;
        }
    if (playerImage.getPosition().y + playerImage.getGlobalBounds().height == groundHeight)
    {
        //cout<<"down"<<endl;
        isOnGround = true;
    }
    if(Keyboard::isKeyPressed(Keyboard::Space)){
        if(isOnGround == true)
        {
            verticalVelocity = -2*jumpForce;
//            jumpM.openFromFile("Jump.ogg");
//            jumpM.play();
        }
    }
    if(isOnGround == false && playerImage.getPosition().y + playerImage.getGlobalBounds().height < groundHeight)
    {
        verticalVelocity = 2.0f;
    }
    moveVector = {0, verticalVelocity};
    playerImage.move(moveVector);
}
void player::collide(){
            pleft = playerImage.getPosition().x;
            pright = playerImage.getPosition().x + playerImage.getGlobalBounds().width;
            pbottom = playerImage.getPosition().y + playerImage.getGlobalBounds().height;

            if (pright < 205 || pleft > 260 || pbottom < 420)
            {
                //no collision
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

            if (pright < 805 || pleft > 860 || pbottom < 420)
            {
                //no collision
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

            if (pright < 1705 || pright > 1820 || pbottom <420)
            {
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

            if (pright < 2805 || pleft > 2860 || pbottom < 420)
            {
                //no collision
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

            if (pright < 3205 || pleft > 3260 || pbottom < 420)
            {
                //no collision
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

            if (pright < 4905 || pleft > 4960 || pbottom < 420)
            {
                //no collision
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

            if (pright < 4705 || pleft >4760 || pbottom < 420)
            {
                //no collision
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

            if (pright < 6805 || pleft > 6860 || pbottom < 420)
            {
                //no collision
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

            if (pright < 6205 || pleft > 6260 || pbottom < 420)
            {
                //no collision
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

            if (pright < 8805 || pleft > 8860 || pbottom < 420)
            {
                //no collision
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

            if (pright < 7705 || pleft > 7760 || pbottom < 420)
            {
                //no collision
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

            if (pright < 10805 || pleft > 10860 || pbottom < 420)
            {
                //no collision
            }
            else
            {
            if(Keyboard::isKeyPressed((Keyboard::Left)))
            {
                velocity.x = +1;
                isWalking = false;
            }
            if (Keyboard::isKeyPressed(Keyboard::Right))
            {
                velocity.x=-1;
                isWalking=false;
            }
            }

        playerImage.move(velocity.x,velocity.y);
}

FloatRect player::Getplayerposition(){
    return playerImage.getGlobalBounds();
}
Vector2f player::GetPos(){
        return playerImage.getPosition();
}
float player::pHeight(){
    return playerImage.getGlobalBounds().height;
}
