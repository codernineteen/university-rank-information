//
// Created by 전예찬 on 2022/12/05.
//

#ifndef PLAYERMANAGER_UNIVERSITYMANAGER_H
#define PLAYERMANAGER_UNIVERSITYMANAGER_H

#include "UniversityCollection.h"
#include "TopKoreaUniversityCollection.h"
#include "IvyLeague.h"

class UniversityManager {
    UniversityCollection wholeUniversityList;
    TopKoreaUniversityCollection koreaUniversityList;
    IvyLeague ivyLeagueList;

public:
    UniversityManager();
    void run();

private:
    void Greeting();
    int ShowMenu();
    int ShowWholeUniversityMenu();
    int ShowIvyLeagueMenu();
    int ShowKoreaMenu();

};


#endif //PLAYERMANAGER_UNIVERSITYMANAGER_H
