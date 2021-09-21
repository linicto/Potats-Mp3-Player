#pragma once

#include <filesystem>
#include <optional>
#include <set>

#include "Album.h"
#include "IRepositoryController.h"

class MusicCollectionRepository : public IRepositoryController
{
private:
    std::set<Album> albumCollection_;

public:
    MusicCollectionRepository();

    void AddEntry(std::filesystem::path entry);

    std::optional<Album> GetAlbumByTitle(std::string title);

    MusicFile ConvertToMusicFile(std::filesystem::path musicPath);

    //There are no properties in C++. One way to have a property that is private set 
    //and public get, is to declare a getter method.
    const std::set<Album>& GetReadonlyAlbumCollection() const;

    //Important! not translated since they were only called by tests in the original C# implementation.
    //void CreateNewRepository();//This was essentially only recreating the albumCollection_
    //void RemoveAllEntries();//same for this one.
    //void RemoveEntry(std::string entry);

private:
    Album InitializeNewAlbum(TagFilePlaceholder tagFile);
};

