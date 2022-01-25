#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
#include <map>

class MyMusic {
public:
    void playmusic() {

        if (!music.openFromFile("./image/music.ogg")){
            std::cout << "Error : could not open music file" << std::endl;
        }
        else{
            music.setLoop(true);
            music.setVolume(50);
            music.play();
        }
    } 
private:
    sf::Music music;
};