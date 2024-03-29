/*
	Dodoi Lab
	Dodoi Engine
	Hudson Schumaker
*/

#pragma once
#include "../include/Common.h"

class AudioManager final {
private:
    inline static AudioManager* instance;
    std::map<std::string, Mix_Chunk*> sounds;

    AudioManager();
    ~AudioManager();

public:
    static AudioManager* getInstance();
    void load();
    void addSound(const std::string&name,  const std::string& filePath);
    void playSound(const std::string& name);
    int audioCount() const;
    void clearAssets();
};
