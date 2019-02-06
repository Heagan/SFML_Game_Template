#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Window
{
    public:
        Window(const std::string& title = "Window", const sf::Vector2u & size = {640, 480}, bool useShaders = true);
        ~Window();

        void BeginDraw();
        void EndDraw();

        void Update();

        bool IsDone() const;
        bool IsFullscreen() const;
        bool IsFocused() const;

        void ToggleFullscreen(EventDetails * details);
        void Close(EventDetails * details = NULL);

        sf::RenderWindow * GetRenderWindow();
        Renderer * GetRenderer();
        EventManager * GetEventManager();
        sf::Vector2u GetWindowSize();
        sf::FloatRect GetViewSpace();
    private:
    
};

#endif