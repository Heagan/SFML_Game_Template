#ifndef COMMUNICATOR_HPP
#define COMMUNICATOR_HPP

#include <include/Observer.hpp>
#include <vector>

using ObserverContainer = std::vector<Observer *>;

class Communicator
{
    public:
        virtual ~Communicator()
        {
            m_observers.clear();
        }

        bool AddObserver(Observer * l_observer)
        {}

        bool RemoveObserver(Observer * l_observer)
        {}

        bool HasObserver(const Observer * l_observer) const
        {}

        void Broadcast(const Message & l_msg)
        {}

    private:
        ObserverContainer m_observer;
};

#endif