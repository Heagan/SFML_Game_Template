#ifndef SERVICELOCATOR_HPP
#define SERVICELOCATOR_HPP


class Window;
class EventManager;
class TextureManager;
class FontManager;

struct SharedContext{
    SharedContext(): 
        m_wind(nullptr),
        m_eventManager(nullptr),
        m_textureManager(nullptr),
        m_fontManager(nullptr)
        {}

    Window *m_wind;
    EventManager *m_eventManager;
    TextureManager *m_textureManager;
    FontManager *m_fontManager;
};

#endif