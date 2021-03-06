#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <include/ResourceManager.hpp>
#include <SFML/Graphics/Texture.hpp>

class TextureManager : public ResourceManager<TextureManager, sf::Texture>
{
    public:
        TextureManager(): ResourceManager("textures.cfg")
        {}

        bool Load(sf::Texture * l_resource, const std::string & l_path)
        {
            return l_resource->loadFromFile(GetWorkingDirectory() + l_path);
        }
};
#endif