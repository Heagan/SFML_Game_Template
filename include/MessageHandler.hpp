#ifndef MESSAGEHANDLER_HPP
#define MESSAGEHANDLER_HPP

#include <include/Observer.hpp>
#include <map>

using Subscriptions = std::unordered_map<EntityMessage, Communicator>;

class MessageHandler
{
    public:
        bool Subscribe(const EntityMessage & l_type,
            Observer * l_observer)
        {}

        bool Unsubsribe(const EntityMessage & l_type,
            Observer* l_observer)
        {}

        void Dispatch(const Message& l_msg)
        {}
    
    private:
        Subscriptions m_communicators;
};

#endif