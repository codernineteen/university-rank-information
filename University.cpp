//
// Created by 전예찬 on 2022/12/04.
//

#include "University.h"

University::University(std::string n, int rank, int number, std::string r, std::string c)
: name(n) , worldRanking(rank), numberOfPublications(number), region(r), country(c) {}


int University::GetNumOfPublications() {
    return numberOfPublications;
}

std::string University::GetUnivName() {
    return name;
}

int University::GetUnivRank() const {
    return worldRanking;
}

std::string University::GetUnivRegion() {
    return region;
}

std::string University::GetUnivCountry() {
    return country;
}

//bool operator>(University& u1, University & u2) {
//    return u1.GetUnivRank() > u2.GetUnivRank();
//}
//
//bool operator<(University& u1, University & u2) {
//    return u1.GetUnivRank() < u2.GetUnivRank();
//}


