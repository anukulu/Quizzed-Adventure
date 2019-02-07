#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
using namespace std;
using namespace sf;

class gobject{
    private:
        Vector2f position;
        Sprite boxSprite;
        Texture boxTexture;
        Sprite spikeSprite;
        Texture spikeTexture;
        Sprite baseSprite;
        Texture baseTexture;
        Sprite checkpointSprite;
        Texture checkpointTexture;
        //background
        Sprite gk_Sprite;
        Texture gk_Texture;
        Sprite medi_Sprite;
        Texture medi_Texture;
        Sprite engg_Sprite;
        Texture engg_Texture;
        Sprite sport_Sprite;
        Texture sport_Texture;


    public:
        int LIVES=3;
        gobject();
        void set_pos(float X,float Y);
        void set_Cpos(float X,float Y);
        Sprite GetboxSprite();
        Sprite GetbaseSprite();
        Sprite GetspikeSprite();
        Sprite GetcheckpointSprite();
        void SetboxSprite();
        void SetspikeSprite();
        void SetbaseSprite();
        void SetcheckpointSprite();
        FloatRect Getboxposition();
        FloatRect Getspikeposition();
        FloatRect Getflagposition();
        // for background
        Sprite Getbackground_gk();
        void Setbackground_gk();
        Sprite Getbackground_engg();
        void Setbackground_engg();
        Sprite Getbackground_medi();
        void Setbackground_medi();
        Sprite Getbackground_sport();
        void Setbackground_sport();
        // for image boundary
        float sleft,sright,stop;
        void boundary();
        int subLives();
};
