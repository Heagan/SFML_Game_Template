#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <SFML/System.hpp>
#include <BaseState.hpp>

class StateManager
{
    public:
        StateManager(SharedContext & shared);
        ~StateManager();

        void Update(const sf::Time & time);
        void Draw();

        void ProcessRequests();
        SharedContext * GetContext();
        bool HasState(const StateType & type) const;
        StateType GetNextToLast() const;
        void SwitchTo(const StateType & type);
        void Remove(const StateType & type);
        template<class T>
        T * GetState(const StateType & type)
        {}
        template<class T>
        void RegisterStateType(const StateType & type)
        {

        }

        void AddDependent(StateDependent * dependent);
        void RemoveDependent(StateDependent * dependent);
    private:
        State_Loading * loading;
        StateDependents dependents;
};

#endif