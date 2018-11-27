#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>
#include <strstream>

#ifdef RUNNING_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Shlwapi.h>

inline std::string GetWorkingDirectory()
{
    HMODULE hModule = GetModuleHandle(nullptr);
    if (!hModule)
    {
        return "";
    }

    char path[256];
    GetModuleFileName(hModule, path, sizeof(path));
    PathRemoveFileSpec(path);
    strcat_s(path,"");
    return std::string(path);
}

inline std::vector<std::string> GetFileList
    (const std::string & l_directory, const std::string & l_search = "*.*")
{
    std::vector<std::string> files;
    if (l_search.empty())
    {
        return files;
    }
    std::string path = l_directory + l_search;
    WIN32_FIND_DATA data;
    HANDLE found = FindFirstFile(path.c_str(), &data);
    if (found == INVALID_HANDLE_VALUE)
    {
        return files;
    }
    do
    {
        if (!(data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            files.emplace_back(data.cFileName);
        }
    } while (FindNextFile(found, &data));
    FindClose(found);
    return files;
}

#elif defined RUNNING_LINUX
#include <unistd.h>
#include <dirent.h>

inline std::string GetWorkingDirectory()
{
    char cwd[256];
    if (!getcwd(cwd, sizeof(cwd)))
    {
        return "";
    }
    return std::string(cwd) + std::string("/");
}

inline std::vector<std::string> GetFileList
    (const std::string & l_directory, const std::string & l_search = "*.*")
{
    std::vector<std::string> files;
    DIR *dpdf;
    dpdf = opendir(l_directory.c_str());
    if (!dpdf || l_search.empty())
    {
        return files;
    }
    std::string search = l_search;
    if (search[0] == "*")
    {
        search.erase(search.begin());
    }
    if (search[search.length() - 1] == "*")
    {
        search.pop_back();
    }
    struct dirent *epdf;
    while (epdf = readdir(dpdf))
    {
        std::string name = epdf->d_name;
        if (edpf->d_type == DT_DIR)
        {
            continue;
        }
        if (l_search != "*.*")
        {
            if (name.length() < search.length())
            {
                continue;
            }
            if (search[0] == '.')
            {
                if (name.compare(name.length() - search.length(),
                    search.length(), search) != 0)
                {
                    continue;
                }
            }
            else if (name.find(search) == std::string::npos)
            {
                continue;
            }
        }
        files.emplace_back(name);
    }
    closedir(dpdf);
    return files;
}

#endif

inline void ReadQuotedString(std::stringstream & l_stream, std::string & l_string)
{
    l_stream >> l_string;
    if (l_string.at(0) == '"')
    {
        while (l_string.at(l_string.length() - 1) != '"' || !l_string.eof())
        {
            std::string str;
            l_stream >> str;
            l_string.append(" " + str);
        }
    }
    l_string.erase(std::remove(l_string.begin(),
        l_string.end(), '"'), l_string.end());
}

template<class T>
inline T Interpolate(float tBegin, float tEnd,
    const T& begin_val, const T& end_val, float tX)
{
    return static_cast<T>((
        ((end_val - begin_val) / (tEnd - tBegin)) *
        (tX - tBegin)) + begin_val);   
}

#include <SFML_Text.hpp>

inline float getSFMLTextMaxHeight(const sf::Text & l_text)
{
    auto charSize = l_text.getCharacterSize();
    auto font = l_text.getFont();
    auto string = l_text.getString().toAnsiString();
    bool bold = (l_text.getStyle() & sf::Text::Bold);
    float max = 0.f;
    for (size_t i = 0; i < string.length(); ++i)
    {
        sf::Uint32 character = string[i];
        auto glyph = font->getGlyph(character, charSize, bold);
        auto height = glyph.bounds.height;
        if (height <= max)
            continue;
        max = height;
    }
    return max;
}

#endif