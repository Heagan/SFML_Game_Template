#ifndef SYSTEMMANAGER_HPP
#define SYSTEMMANAGER_HPP

enum System
{

};

class SystemManager
{
    public:
        template<class T>
        void AddSystem(const System& l_system)
        {};

        template<class T>
        T* GetSystem(const System & l_system)
        {}

        void AddEvent(const EntityId & l_entity, const EventID & l_event);

        void Update(float l_dT);
        void HandleEvents();
        void Draw(Window * l_wind, unsigned int l_elevation);

        void EntityModified(const EntityId & l_entity,
            const Bitmask & l_bits);
        void RemoveEntity(const EntityId & l_entity);
        void PurgeEntities();
        void PurgeSystems();
    
    private:
        MessageHandler m_messages;
};

#endif