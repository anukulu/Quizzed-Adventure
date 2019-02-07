#include <SFML/Graphics.hpp>
#include "headers/game_objects.h"
using namespace std;
using namespace sf;

gobject::gobject(){
    SetboxSprite();
    SetspikeSprite();
    SetbaseSprite();
    Setbackground_gk();
    Setbackground_engg();
    Setbackground_medi();
    Setbackground_sport();
    SetcheckpointSprite();
}
void gobject::set_pos(float x,float y){
    position.x = x;
    position.y = y;
    boxSprite.setPosition(position);
    baseSprite.setPosition(position);
    engg_Sprite.setPosition(position);
    gk_Sprite.setPosition(position);
    medi_Sprite.setPosition(position);
    sport_Sprite.setPosition(position);
    spikeSprite.setPosition(position);
}
void gobject::set_Cpos(float x,float y){
    position.x = x;
    position.y = y;
    checkpointSprite.setPosition(position);
}

Sprite gobject::GetboxSprite(){
    return boxSprite ;
    }
Sprite gobject::GetcheckpointSprite(){
    return checkpointSprite;
    }
Sprite gobject::GetbaseSprite(){
    return baseSprite;
    }
Sprite gobject::GetspikeSprite(){
    return spikeSprite;
    }
// getting background
Sprite gobject::Getbackground_gk(){
    return gk_Sprite;
    }
Sprite gobject::Getbackground_medi(){
    return medi_Sprite;
    }
Sprite gobject::Getbackground_engg(){
    return engg_Sprite;
    }
Sprite gobject::Getbackground_sport(){
    return sport_Sprite;
    }

void gobject::SetboxSprite(){
    boxTexture.loadFromFile("images/box.png");
    boxSprite .setTexture(boxTexture);
    boxSprite .scale(0.4,0.5);
    }
void gobject ::SetspikeSprite(){
    spikeTexture.loadFromFile("images/spikes.png");
    spikeSprite.setTexture(spikeTexture);
    spikeSprite.scale(0.35,0.35);
    }
void gobject ::SetbaseSprite(){
    baseTexture.loadFromFile("images/stones.png");
    baseSprite.setTexture(baseTexture);
    baseSprite.scale(Vector2f(0.5f, 0.6f));
    }
// background started
void gobject ::Setbackground_gk(){
    gk_Texture.loadFromFile("images/backgroung.png");
    gk_Sprite.setTexture(gk_Texture);
    gk_Sprite.scale(Vector2f(1.25f, 1.25f));
    }
    void gobject ::Setbackground_medi(){
    medi_Texture.loadFromFile("images/medical.png");
    medi_Sprite.setTexture(medi_Texture);
    medi_Sprite.scale(Vector2f(1.25f, 1.25f));
    }
    void gobject ::Setbackground_sport(){
    sport_Texture.loadFromFile("images/sports.png");
    sport_Sprite.setTexture(sport_Texture);
    sport_Sprite.scale(Vector2f(1.25f, 1.25f));
    }
    void gobject ::Setbackground_engg(){
    engg_Texture.loadFromFile("images/engineer.png");
    engg_Sprite.setTexture(engg_Texture);
    engg_Sprite.scale(Vector2f(1.25f, 1.25f));
    }
// background finished
void gobject ::SetcheckpointSprite(){
    checkpointTexture.loadFromFile("images/flag.png");
    checkpointSprite.setTexture(checkpointTexture);
    checkpointSprite.scale(Vector2f(0.15f, 0.15f));
    }

FloatRect gobject::Getboxposition(){
    return boxSprite.getGlobalBounds();
}
FloatRect gobject::Getflagposition(){
    return checkpointSprite.getGlobalBounds();
}
/*void gobject::boundary(){
// sprite boundary for collision

    sleft = boxSprite .getPosition().x;
    sright = boxSprite .getPosition().x + boxSprite .getGlobalBounds().width;
    stop = boxSprite.getPosition().y;
}
*/
int gobject:: subLives(){
    LIVES = LIVES -1;
    return LIVES;
}
