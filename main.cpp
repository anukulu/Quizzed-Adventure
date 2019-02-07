#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "game_objects.h"
#include "player.h"
#include "text.h"
#include "time_text.h"
#include "startwindow.h"
#include "gates.h"
#include "queAns.h"
#include "Exit.h"

using namespace sf;
using namespace std;

//start window
    Wwindow x;
    start_win y;
// making window
    float windowWidth = 1200;
    float windowHeight = 600;
    RenderWindow window(VideoMode (windowWidth,windowHeight),"Project");

 //header files
    gobject obstacle;
    written texts;
    data QUIZ;

// function for obstacle
    void draw_o(float,float);
    void draw_s(float,float);

int main()
    {
        y.startWin();
        x.start();
        //Time
        Clock c;
        Time t;
        //create player, at the screen
        player Player;
        // player view on the screen
        View player_view;
        player_view.reset(FloatRect(0,0,1200,600));
        player_view.setViewport(FloatRect(0,0,1.0f,1.0f));
        Vector2f position(0,0);
        // playing music
        Music gMusic;
        gMusic.openFromFile("GMusic.ogg");
        gMusic.play();

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed || t.asSeconds()  >=180.0f)
                {
                window.close();
                Exit(1);
                }
            }
            //time process
            t = c.getElapsedTime();
            ostringstream ss;
            ss.setf(ios::fixed);
            ss.setf(ios::showpoint);
            ss.precision(1);
            ss << t.asSeconds()<< endl;
            texts.timer.setString(ss.str());

            // we keep our view on the player
            window.setView(player_view);
            // player control
            Player.update();
            Player.jump();

           // screen moment
            position.x = (Player.GetPos().x )-600;
            position.y = (Player.GetPos().y)-450 ;
           if (position.x < 0)
                position.x = 0;
            if (position.y < 0)
                position.y = 0;
            player_view.reset(FloatRect(position.x,position.y,1200,600));
            //text moment
            texts.text1.setPosition(position.x,position.y);
            texts.textL.setPosition(position.x,position.y);
            texts.text.setPosition(position.x,position.y);
            texts.timer.setPosition(position.x,position.y);

            window.clear(Color(200,222,200,0));
            // game end
            if(Player.pleft > 12050)
                {
                    window.close();
                    finish_win();
                }
            // Drawing Background
            if (x.QueBck==1)
            {
                for (int i=0;i<13000;i=i+1115)
                {
                    obstacle.set_pos(i,0); //drawing background
                    window.draw(obstacle.Getbackground_engg());
                }
            }
            else if(x.QueBck==2)
            {
                for (int i=0;i<13000;i=i+1200)
                {
                    obstacle.set_pos(i,0); //drawing background
                    window.draw(obstacle.Getbackground_sport());
                }
            }
            else if(x.QueBck==3)
            {
                for (int i=0;i<12000;i=i+1115)
                {
                    obstacle.set_pos(i,0); //drawing background
                    window.draw(obstacle.Getbackground_medi());
                }
            }
            else
            {
                for (int i=0;i<25000;i=i+1115)
                {
                    obstacle.set_pos(i,0); //drawing background
                    window.draw(obstacle.Getbackground_gk());
                }
            }
            for (int i=-700;i<15000;i=i+85)
            {
                obstacle.set_pos(i, windowHeight-20); // drawing base ground
                window.draw(obstacle.GetbaseSprite());
                obstacle.set_pos(i, windowHeight-120); // drawing base ground
                window.draw(obstacle.GetbaseSprite());
            }
            for (int i=1500;i<15000;i=i+1500)
            {
                obstacle.set_Cpos(i, windowHeight-180); // drawing check flag
                window.draw(obstacle.GetcheckpointSprite());
            }
        //make obstacles here //
        //box set 1
            draw_o(200,410);
            draw_o(1700,410);
            draw_o(3200,410);
            draw_o(4700,410);
            draw_o(6200,410);
            draw_o(7700,410);

        //box set 2
            draw_o(800,410);
            draw_o(2800,410);
            draw_o(4900,410);
            draw_o(6800,410);
            draw_o(8800,410);
            draw_o(10800,410);

            Player.collide();

        //spikes set 1
            draw_s(1300,430);
            draw_s(3100,430);
            draw_s(5100,430);
            draw_s(7100,430);
            draw_s(9100,430);
            draw_s(13800,430);

        // obstacles completed //
        //writing logic
        // for Question on check point
            if(Player.pleft > 1500 && Player.pleft < 1502 || Player.pleft > 3000 && Player.pleft < 3002
                || Player.pleft > 4500 && Player.pleft < 4502 || Player.pleft > 6000 && Player.pleft < 6002
                ||Player.pleft > 7500 && Player.pleft < 7502 || Player.pleft > 9000 && Player.pleft < 9002
                || Player.pleft > 10500 && Player.pleft < 10502 || Player.pleft > 12000 && Player.pleft < 12002 )
            {
                QUIZ.ques(x.QueBck);
                QUIZ.show();
            }
        //for decreasing lives in spikes
            if(Player.pleft > 1310 && Player.pleft < 1312 || Player.pleft > 3110 && Player.pleft < 3112
                ||Player.pleft > 5110 && Player.pleft < 5112|| Player.pleft > 7110 && Player.pleft < 7112
                || Player.pleft > 9110 && Player.pleft < 9112||Player.pleft > 13810 && Player.pleft < 13812 )
            {
                if(Player.playerImage.getPosition().y == 399)
                obstacle.subLives();
           }
        // lives
            if (obstacle.LIVES <0)
            {
                window.close();
                Exit(obstacle.LIVES);
            }

            stringstream life;
            life << obstacle.LIVES;
            string str = life.str();
            texts.textL.setString(str);
        // rendering player
            window.draw(Player.playerImage);
            window.draw(texts.getTime());
            window.draw(texts.timer);
            window.draw(texts.getLives());
            window.draw(texts.textL);
            window.display();

        window.setFramerateLimit(60);
        }
     return 0;
    }

void draw_o(float x,float y)
{
    obstacle.set_pos(x,y);
    window.draw(obstacle.GetboxSprite());
}
void draw_s(float x,float y)
{
    obstacle.set_pos(x,y);
    window.draw(obstacle.GetspikeSprite());
}
