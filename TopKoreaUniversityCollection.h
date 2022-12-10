//
// Created by 전예찬 on 2022/12/05.
//

#ifndef PLAYERMANAGER_TOPKOREAUNIVERSITYCOLLECTION_H
#define PLAYERMANAGER_TOPKOREAUNIVERSITYCOLLECTION_H

#include "UniversityCollection.h"

class TopKoreaUniversityCollection : public UniversityCollection{
    std::vector<University> koreaCollection;

public:
    TopKoreaUniversityCollection();

    void PrintCollection() override;
    std::vector<University> GetCollection() override;
    void SortUniversitiesByRank() override;

public:
    void PrintNumberOfElements();
};


#endif //PLAYERMANAGER_TOPKOREAUNIVERSITYCOLLECTION_H
