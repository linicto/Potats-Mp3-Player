#pragma once

#include <filesystem>
#include <map>
#include <optional>

#include "Album.h"
#include "IRepositoryController.h"

class MusicCollectionRepository : public IRepositoryController
{
private:
    std::map<std::string, Album> albumCollection_;

public:
    MusicCollectionRepository();

    void AddEntry(std::filesystem::path mp3FilePath) override;

    std::optional<std::reference_wrapper<Album>> GetAlbumByTitle(std::string title);

    MusicFile ConvertToMusicFile(std::filesystem::path musicPath);

    //There are no properties in C++. One way to have a property that is private set 
    //and public get, is to declare a getter method.
    const std::map<std::string, Album>& GetReadonlyAlbumCollection() const;

    //Important! not translated since they were only called by tests in the original C# implementation.
    //void CreateNewRepository();//This was essentially only recreating the albumCollection_
    //void RemoveAllEntries();//same for this one.
    //void RemoveEntry(std::string entry);

private:
    void InitializeNewAlbum(std::filesystem::path mp3FilePath);
};

