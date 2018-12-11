#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <string>

template<typename Derived, typename T>
class ResourceManager 
{
    public:
        ResourceManager(const std::string l_pathsFile)
        {
            LoadPaths(l_pathsFile);
        }

        virtual ~ResourceManager()
        {}

        T* GetResource(const std::string& l_id)
        {}

        std::string GetPath(const std::string l_id)
        {}

        bool RequireResource(const std::string & l_id)
        {}

        bool ReleaseResource(const std::string & l_id)
        {}

        void PurgeResources()
        {}

    protected:
        bool Load(T* l_resource, const std::string & l_path)
        {
            return static_cast<Derived *>(this)->Load(l_resource, l_path);
        }
};

#endif