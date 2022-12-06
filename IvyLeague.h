//
// Created by 전예찬 on 2022/12/04.
//

#ifndef PLAYERMANAGER_IVYLEAGUE_H
#define PLAYERMANAGER_IVYLEAGUE_H

#include "UniversityCollection.h"

//inheritance from collection class
class IvyLeague : public UniversityCollection {
    std::vector<University> ivyLeagueCollection;
public:
    IvyLeague();

    std::vector<University> GetCollection() override;
    void PrintCollection() override;
    void SortUniversitiesByRank() override;
};


#endif //PLAYERMANAGER_IVYLEAGUE_H
