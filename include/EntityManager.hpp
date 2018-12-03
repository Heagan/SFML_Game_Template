#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <include/Component.hpp>

class EntityManager
{
    public:
        EntityManager(SystemManager * l_sysMgr,
        TextureManager * l_textManager);
        ~EntityManager();

        int AddEntity(const Bitmask & l_mask);
        int AddEntity(const std::string & l_entityFile);
        bool RemoveEntity(const EntityId & l_id);

        bool AddComponent(const EntityId & l_entity,
            const Component &l_component);

        template<class T>
        void AddComponentType(const Component & l_id)
        {}

        template<class T>
        T* GetComponent(const EnityId & l_entity,
            const Component & l_component)
        {}

        bool RemoveComponent(const EntityId& l_entity,
            const Component & l_component);
        
        bool HasComponent(const EntityId & l_entity,
            const Component & l_component) const;
        
        void Purge();
};

#endif