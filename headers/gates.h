#ifndef GATES_H_INCLUDED
#define GATES_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class gate{
    private:
        Vector2f position;
        Sprite gateSprite;
        Texture gateTexture;
        Sprite dashSprite;
        Texture dashTexture;
        Sprite welcomeSprite;
        Texture welcomeTexture;
        Texture characterTexture;
        Sprite characterSprite;

    public:
        gate(){
            setgate();
            setdash();
            setwelcome();
            setcharacter();
        }
        void setgate(){
            gateTexture.loadFromFile("images/gate.png");
            gateSprite.setTexture(gateTexture);
            gateSprite.scale(0.389,0.389);
        }
        void setdash(){
            dashTexture.loadFromFile("images/dash.png");
            dashSprite.setTexture(dashTexture);
            dashSprite.scale(0.75,0.75);
        }
        void setwelcome(){
            welcomeTexture.loadFromFile("images/welcome.png");
            welcomeSprite.setTexture(welcomeTexture);
            welcomeSprite.scale(0.8,0.8);
        }
        void setcharacter(){
            characterTexture.loadFromFile("images/characterW.png");
            characterSprite.setTexture(characterTexture);
        }
        void set_pos(float x,float y){
            position.x = x;
            position.y = y;
            gateSprite.setPosition(position);
            dashSprite.setPosition(position);
            welcomeSprite.setPosition(position);
            characterSprite.setPosition(position);
        }
        Sprite GetgateSprite(){
            return gateSprite;
        }
        Sprite GetdashSprite(){
            return dashSprite;
        }
        Sprite GetwelcomeSprite(){
            return welcomeSprite;
        }
         Sprite GetcharacterSprite(){
            return characterSprite;
        }
};
#endif // GATES_H_INCLUDED
