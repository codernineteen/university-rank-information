//
// Created by 전예찬 on 2022/12/04.
//

#ifndef PLAYERMANAGER_UNIVERSITY_H
#define PLAYERMANAGER_UNIVERSITY_H

#include <string>

class University {
    std::string name;
    int worldRanking;
    int numberOfPublications;
    std::string region;
    std::string country;

public:
    University(std::string n, int rank, int number, std::string r, std::string c);

    std::string GetUnivName();
    int GetUnivRank() const;
    int GetNumOfPublications();
    std::string GetUnivRegion();
    std::string GetUnivCountry();

    //다형성 feature
    friend bool operator>(const University& u1, const University & u2) {
        return u1.GetUnivRank() > u2.GetUnivRank();
    }

    friend bool operator<(const University& u1, const University & u2) {
        return u1.GetUnivRank() < u2.GetUnivRank();
    }
//    void UpdateUnivName();
//    void UpdateWorldRanking();
//    void UpdatePublications();
};


#endif //PLAYERMANAGER_UNIVERSITY_H
