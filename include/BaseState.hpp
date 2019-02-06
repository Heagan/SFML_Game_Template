#ifndef BASESTATE_HPP
#define BASESTATE_HPP

#include <SFML/System.hpp>
#include <SFML/Main.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <StateManager.hpp>

enum class StateType {
    Intro = 1,
    MainMenu,
    Game,
    Loading
};

class BaseState
{
    friend class StateManger;
    public:
        BaseState(StateManager * stateManager): stateMgr(stateManager), transparent(false), transcendent(false)
        {}
        virtual ~BaseState();

        virtual void OnCreate() = 0;
        virtual void OnDestroy() = 0;

        virtual void Activate() = 0;
        virtual void Deactivate() = 0;

        virtual void Update(const sf::Time & time) = 0;
        virtual void Draw() = 0;

        sf::View & GetView()
        {
            return view;
        }

        StateManager * GetStateManager()
        {
            return stateMgr;
        }
    
    protected:
        StateManager * stateMgr;
        bool transparent;
        bool transcendent;
        sf::View view;
};

#endif