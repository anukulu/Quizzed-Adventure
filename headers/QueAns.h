#ifndef QUEANS_H_INCLUDED
#define QUEANS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "startwindow.h"
#include "player.h"

using namespace std;
using namespace sf;
class data{
    private:
        int line_n=1;
        char p;
        int x,j=0;
        int ans=0;
        bool done;
        ifstream infile;
        ifstream file1;
        ifstream file11;
        string line1[25], line11[25];

    public:
        Text textq1,textq2,textq3;
        Text texta;
        RectangleShape rect1,rect2;
        Font font;
        int curr_line=1;
        string str,getSize,str1;
        data(){
            font.loadFromFile("font/Gabriola.TTF");

            textq1.setFont(font);
            textq1.setCharacterSize(20);
            textq1.setColor(Color::Red);
            textq1.setPosition(60,60);

            texta.setFont(font);
            texta.setCharacterSize(20);
            texta.setColor(Color::Red);
            texta.setPosition(60,360);

            textq2.setFont(font);
            textq2.setCharacterSize(20);
            textq2.setColor(Color::Red);
            textq2.setPosition(60,100);

            textq3.setFont(font);
            textq3.setCharacterSize(20);
            textq3.setColor(Color::Red);
            textq3.setPosition(60,140);

            rect1.setSize(Vector2f(420,120));
            rect1.setFillColor(Color::Green);
            rect1.setOutlineColor(Color::White);
            rect1.setOutlineThickness(5);
            rect1.setPosition(50,50);

            rect2.setSize(Vector2f(40,40));
            rect2.setFillColor(Color::Green);
            rect2.setOutlineColor(Color::White);
            rect2.setOutlineThickness(5);
            rect2.setPosition(50,350);
            }

            void ques(int num)
            {
                if(num==1)
                {
                    ifstream file1("database/engineering.txt");
                    ifstream file11("database/enggans.txt");
                    for (int i=0;getline(file1,line1[i]);i++)
                    {
                        if (i==line_n)
                        {
                            getline(file1,line1[curr_line]);

                        }
                    }
                line_n+=2;
                // doutfull code ????
                getline(file11,line11[ans]);
                cout<<line11[ans]<<endl;
                //getline(file11,line11[1]);
                //getline(file11,line11[2]);
                ans=ans+1;
                }
                else if(num==2)
                {
                    ifstream file1("database/sports.txt");
                    ifstream file11("database/sportsans.txt");
                    for (int i=0;getline(file1,line1[i]);i++)
                    {
                        if (i==line_n)
                        {
                            getline(file1,line1[curr_line]);
                        }
                    }
                line_n+=2;
                getline(file11,line11[0]);
                //getline(file11,line11[1]);
                //getline(file11,line11[2]);
                }
                else if(num==3)
                {
                    ifstream file1("database/medical.txt");
                    ifstream file11("database/medicalans.txt");
                    for (int i=0;getline(file1,line1[i]);i++)
                    {
                        if (i==line_n)
                        {
                            getline(file1,line1[curr_line]);
                        }
                    }
                line_n+=2;
                getline(file11,line11[0]);
                //getline(file11,line11[1]);
                //getline(file11,line11[2]);
                }
                else if(num==4)
                {
                    ifstream file1("database/gk.txt");
                    ifstream file11("database/gkans.txt");
                    for (int i=0;getline(file1,line1[i]);i++)
                    {
                        if (i==line_n)
                        {
                            getline(file1,line1[curr_line]);
                            //getline(file11,line11[curr_line]);
                        }

                    }
                line_n+=2;
                getline(file11,line11[ans]);
                //getline(file11,line11[1]);
                //getline(file11,line11[2]);
                }
//            ans++;
            }

            void show(){
                // object for player class
                player p_r;
                // window for quiz
                RenderWindow window(VideoMode (500,500),"!! Quize !!");
                while(window.isOpen())
                {
                    Event event1,event;
                    while (window.pollEvent(event1))
                    {
                        if (event1.type == Event::Closed)
                            window.close();
                    }
                    if (event1.type == Event::TextEntered && done == false)
                    {
                        if (event1.text.unicode < 128 && event1.text.unicode !=0)
                        {
                            str1 = static_cast<char>(event1.text.unicode);
                            texta.setString(str1);
                        }
                    }
                if (Keyboard::isKeyPressed(Keyboard::Return))
                {
                    if (str1== line11[ans-1])
                    {
                        // Error in comparision
                        window.clear();
                        texta.setString("");
                        window.close();
                    }
                    else
                    {
                        window.close();
                    if(p_r.pleft > 1500 && p_r.pleft < 1505)
                        p_r.playerImage.setPosition(10,350);
                    if(p_r.pleft > 3000 && p_r.pleft < 3005)
                        p_r.playerImage.setPosition(1510,350);
                    if (p_r.pleft > 4500 && p_r.pleft < 4505)
                        p_r.playerImage.setPosition(3010,350);
                    if (p_r.pleft > 6000 && p_r.pleft < 6005)
                        p_r.playerImage.setPosition(4510,350);
                    if (p_r.pleft > 7500 && p_r.pleft < 7505)
                        p_r.playerImage.setPosition(6010,350);
                    if (p_r.pleft > 9000 && p_r.pleft < 9005)
                        p_r.playerImage.setPosition(7510,350);
                    if (p_r.pleft > 10500 && p_r.pleft < 10505)
                        p_r.playerImage.setPosition(9010,350);
                    if (p_r.pleft > 12000 && p_r.pleft < 12005)
                        p_r.playerImage.setPosition(10510,350);
                    }
                }
//                if (event1.type == Event::TextEntered && done == false)
//                {
//                    if (event1.text.unicode < 128 && event1.text.unicode !=0)
//                    {
//                        str1 = static_cast<char>(event1.text.unicode);
//                        texta.setString(str1);
//                    }
//                }
                // done cout << str1 << endl;
            textq1.setString(line1[curr_line]);
            textq2.setString(line1[curr_line+1]);
            textq3.setString(line1[curr_line+2]);

           // textq2.setString(line1[i+1]);
           // textq3.setString(line1[i+2]);
            window.draw(rect1);
            window.draw(rect2);
            window.draw(textq1);
            window.draw(texta);
            window.draw(textq2);
            window.draw(textq3);
            window.display();
        }
        curr_line+=3;
    }
};

#endif // QUEANS_H_INCLUDED
