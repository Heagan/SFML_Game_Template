#ifndef S_BASE_HPP
#define S_BASE_HPP

#include <include/Observer.hpp>

class S_Base : public Observer
{
    public:
        S_Base(const System & l_id, 
        SystemManager * l_systemMgr);
        virtual ~S_Base();

        bool AddEnity(const EntityId & l_entity);
        bool AddEnity(const EntityId & l_entity) const;
        bool RemoveEnity(const EntityId & l_entity);

        System GetId() const;

        bool FitsRequirements(const BitMask & l_bits) const;
        void Purge();

        virtual void Update(float l_dT) = 0;
        virtual void HandleEvent(const EntityId & l_entity,
            const EntityEvent & l_event) = 0;
};

#endif