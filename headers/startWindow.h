#ifndef STARTWINDOW_H_INCLUDED
#define STARTWINDOW_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "gates.h"
#include "text.h"
using namespace sf;
using namespace std;

class SuperWin
{
protected:
    float gate_windowWidth = 1200;
    float gate_windowHeight = 600;
    Sprite welcomeSprite;
    Texture welcomeTexture;
    int t;
};

class Wwindow: public SuperWin{
   public:
    int  QueBck=1;
    Wwindow(){}

    void start(){
        RenderWindow gate_window(VideoMode (gate_windowWidth,gate_windowHeight),"Project");

        // making object
        gate g1;
        subjects t1;
        bool atTop = true;
        bool atBotLeft = false;
        bool atBotRight = false;
        bool atTopRight = false;
        // making lower belt
            while (gate_window.isOpen())
        {
            Event event;
            while (gate_window.pollEvent(event))
            {
                if (event.type ==  Event::Closed || Keyboard::isKeyPressed(Keyboard::Return))
                    gate_window.close();
            }

            gate_window.clear(Color(150,220,65,255));

            //making dash and welcome
            g1.set_pos(445,50);
            gate_window.draw(g1.GetwelcomeSprite());
            g1.set_pos(gate_windowWidth-240,150);
            gate_window.draw(g1.GetdashSprite());

            //making gates
            g1.set_pos(0,0);
            gate_window.draw(g1.GetgateSprite());
            //gate 2
            g1.set_pos(gate_windowWidth-660,0);
            gate_window.draw(g1.GetgateSprite());
            //gate 3
            g1.set_pos(0,gate_windowHeight-316);
            gate_window.draw(g1.GetgateSprite());
            //gate 4
            g1.set_pos(gate_windowWidth-660,gate_windowHeight-316);
            gate_window.draw(g1.GetgateSprite());

          //placing character
            if(Keyboard::isKeyPressed(Keyboard::Up) && (g1.GetcharacterSprite().getPosition().x == 165))
            {
                QueBck = 1;
                atTop = true; atBotRight = false;
                atTopRight = false; atBotLeft = false;
            }
            if(atTop)
            {
                g1.set_pos(165,120);
                gate_window.draw(g1.GetcharacterSprite());
            }
            if(Keyboard::isKeyPressed(Keyboard::Right) && (g1.GetcharacterSprite().getPosition().x == 165))
            {
                QueBck = 2;
                atTop = false; atBotRight = false;
                atTopRight = true; atBotLeft = false;
            }
            if(atTopRight)
            {
                g1.set_pos(700,120);
                gate_window.draw(g1.GetcharacterSprite());
            }
            if(Keyboard::isKeyPressed(Keyboard::Down) && (g1.GetcharacterSprite().getPosition().x == 700))
            {
                QueBck=4;
                atTop = false; atBotRight = true;
                atTopRight = false; atBotLeft = false;
            }
            if(atBotRight)
            {
                g1.set_pos(700,410);
                gate_window.draw(g1.GetcharacterSprite());
            }
            if(Keyboard::isKeyPressed(Keyboard::Left) && (g1.GetcharacterSprite().getPosition().x == 700))
            {
                QueBck = 3;
                atTop = false; atBotRight = false;
                atTopRight = false; atBotLeft = true;
            }
            if(atBotLeft)
            {
                g1.set_pos(165,410);
                gate_window.draw(g1.GetcharacterSprite());
            }
            if(Keyboard::isKeyPressed(Keyboard::Up) && (g1.GetcharacterSprite().getPosition().x == 165))
            {
                QueBck =1;
                atTop = true; atBotRight = false;
                atTopRight = false; atBotLeft = false;
            }
            if(atTop)
            {
                g1.set_pos(165,120);
                gate_window.draw(g1.GetcharacterSprite());
            }

        //writing name
        t1.setString("1. Engineering");
        t1.setPos(120,230);
        gate_window.draw(t1.getSubject());
        t1.setString("3. Medical");
        t1.setPos(120,515);
        gate_window.draw(t1.getSubject());
        t1.setString("2. Sports");
        t1.setPos(690,230);
        gate_window.draw(t1.getSubject());
        t1.setString("4. G . K");
        t1.setPos(690,515);
        gate_window.draw(t1.getSubject());
        gate_window.display();
        }
    }
};

class start_win : public SuperWin
{
    public:
        void startWin()
        {
            welcomeTexture.loadFromFile("images/cover.png");
            welcomeSprite.setTexture(welcomeTexture);

            RenderWindow welcome_window(VideoMode (gate_windowWidth,gate_windowHeight),"WELCOME !");
            Text start;
            Font font;
            font.loadFromFile("font/arial.ttf");
            start.setFont(font);
            start.setCharacterSize(20);
            start.setPosition(500,350);
            start.setString("Press Enter to Start ");
            while (welcome_window.isOpen())
            {
            Event event;
            while (welcome_window.pollEvent(event))
                {
                if (event.type ==  Event::Closed || Keyboard::isKeyPressed(Keyboard::Return))
                    welcome_window.close();
                }
                 if( t > 0)
                    { start.setColor(Color::White); t=-1; }
                else
                    { start.setColor(Color::Red); t=1; }
            welcome_window.clear();
            welcome_window.draw(welcomeSprite);
            welcome_window.draw(start);
            welcome_window.display();
            }
        }
};
#endif // STARTWINDOW_H_INCLUDED
