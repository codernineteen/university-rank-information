//
// Created by 전예찬 on 2022/12/04.
//

#ifndef PLAYERMANAGER_UNIVERSITYCOLLECTION_H
#define PLAYERMANAGER_UNIVERSITYCOLLECTION_H

#include "University.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

class UniversityCollection {
    std::vector<University> topUniversities;

public:
    UniversityCollection();

    std::vector<std::vector<std::string>> loadUnivFromCSV();
    void EraseNullRankData();
    void PrintFilteredCollection();
    void PrintHighestRankUniv();

public:
    virtual void SortUniversitiesByRank();
    virtual std::vector<University> GetCollection();
    virtual void PrintCollection();
};


#endif //PLAYERMANAGER_UNIVERSITYCOLLECTION_H
