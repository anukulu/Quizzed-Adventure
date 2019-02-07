#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

 class subjects{
 private:
    Text hud;
    Font font;
 public:
    subjects(){
        font.loadFromFile("Font_game.ttf");
        hud.setFont(font);
        hud.setCharacterSize(20);
        hud.setOutlineThickness(2);
        hud.setFillColor(Color::White);
        hud.setOutlineColor(Color::Black);
    }
    void setPos(float x,float y){
        hud.setPosition(x,y);
    }
    void setString(String name){
        hud.setString(name);
    }
    Text getSubject(){
        return hud;
    }
 };
#endif // TEXT_H_INCLUDED
