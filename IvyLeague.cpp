//
// Created by 전예찬 on 2022/12/04.
//

#include "IvyLeague.h"

IvyLeague::IvyLeague() {
    std::vector<std::vector<std::string>> lines = loadUnivFromCSV();
    for(const auto& line : lines)
    {
        std::string name = line[0];
        if(
                name == "Princeton University"
            or name == "Harvard University"
            or name == "Yale University"
            or name == "Pennsylvania State University"
            or name == "Dartmouth College"
            or name == "Brown University"
            or name == "Cornell University"
            or name == "Columbia University"
            )
        {
            if(line[1].length() == 0) {
                University u = University(line[0], -1, stoi(line[8]), line[4], line[5]);
                ivyLeagueCollection.push_back(u);
            }
            else {
                University u = University(line[0], stoi(line[1]), stoi(line[8]), line[4], line[5]);
                ivyLeagueCollection.push_back(u);
            }
        }
    }
}

std::vector<University> IvyLeague::GetCollection() {
    return ivyLeagueCollection;
}
//polymorphism
void IvyLeague::PrintCollection() {
    std::cout << "[Welcome to Ivy League]" << std::endl;
    for(auto univ : this->GetCollection())
    {
        std::string name = univ.GetUnivName();
        std::string state;
        std::cout << "Name : " << univ.GetUnivName() << " | ";
        std::cout << "World Rank : " << univ.GetUnivRank() << " | ";
        std::cout << "Number of Publications : " << univ.GetNumOfPublications() << " | ";
        std::cout << "Location : " << univ.GetUnivRegion() << ", " << univ.GetUnivCountry() << "\n";
        if(name == "Princeton University") state = "New Jersey";
        else if (name == "Harvard University") state = "Massachusetts";
        else if(name == "Yale University") state = "Connecticut";
        else if( name == "Pennsylvania State University") state = "Pennsylvania";
        else if(name == "Dartmouth College") state = "New Hampshire";
        else if( name == "Brown University") state = "Rhode Island";
        else if(name == "Cornell University") state = "New York";
        else state = "New York";
    }
}

void IvyLeague::SortUniversitiesByRank() {
    std::sort(ivyLeagueCollection.begin(), ivyLeagueCollection.end());
}


