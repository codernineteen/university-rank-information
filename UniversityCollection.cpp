//
// Created by 전예찬 on 2022/12/04.
//

#include "UniversityCollection.h"

UniversityCollection::UniversityCollection() {
    std::vector<std::vector<std::string>> lines = loadUnivFromCSV();
    for(const auto& line : lines)
    {
        if(line[1].length() == 0) {
            University u = University(line[0], 0, stoi(line[8]), line[4], line[5]);
            topUniversities.push_back(u);
        }
        else {
            University u = University(line[0], stoi(line[1]), stoi(line[8]), line[4], line[5]);
            topUniversities.push_back(u);
        }
    }
};

std::vector<std::string> split(std::string line, char dlm) {
    std::istringstream iss(line);
    std::string buffer;

    std::vector<std::string> res;
    while(std::getline(iss, buffer, dlm))
    {
        res.push_back(buffer);
    }
    return res;
}

std::vector<std::vector<std::string>> UniversityCollection::loadUnivFromCSV() {
    std::vector<std::vector<std::string>> lines;
    std::string filePath = "universities.csv";
    std::ifstream ifs(filePath.data());
    if(ifs.is_open())
    {
        std::string line;
        while(std::getline(ifs,line))
        {
            std::vector<std::string> lineVector = split(line, ',');

            lines.push_back(lineVector);
        }
        ifs.close();
    }

    for(auto& line : lines)
    {
        if(line[1].length() != 0)
        {
            std::string rank = line[1];
            std::vector<std::string> rankVector = split(rank, ' ');
            std::string ownRank = rankVector[0];
            std::vector<std::string> exceptHashTag = split(ownRank, '#');
            line[1] = exceptHashTag[1];
        }
    }

    return lines;
}

void UniversityCollection::EraseNullRankData() {
    topUniversities.erase(std::remove_if(topUniversities.begin(), topUniversities.end(), [this](const University& u) {
        return u.GetUnivRank() == 0;
    }), topUniversities.end());
}

void UniversityCollection::SortUniversitiesByRank() {
    std::sort(topUniversities.begin(), topUniversities.end());
    std::cout << "Sorting completed" << std::endl;
}

std::vector<University> UniversityCollection::GetCollection() {
    return topUniversities;
}

void UniversityCollection::PrintCollection() {
    std::cout << "[Top 300 Universities in the world]" << std::endl;
    for(auto univ : this->GetCollection())
    {
        std::cout << "Name : " << univ.GetUnivName() << "\t| ";
        std::cout << "World Rank : " << univ.GetUnivRank() << "\t| ";
        std::cout << "Number of Publications : " << univ.GetNumOfPublications() << "\t| ";
        std::cout << "Location : " << univ.GetUnivRegion() << ", " << univ.GetUnivCountry() << "\n";
    }
}

void UniversityCollection::PrintFilteredCollection() {
    EraseNullRankData();
    SortUniversitiesByRank();
    for(auto univ : this->GetCollection())
    {
        std::cout << "Name : " << univ.GetUnivName() << " | ";
        std::cout << "World Rank : " << univ.GetUnivRank() << " | ";
        std::cout << "Number of Publications : " << univ.GetNumOfPublications() << " | ";
        std::cout << "Location : " << univ.GetUnivRegion() << ", " << univ.GetUnivCountry() << "\n";
    }
}

void UniversityCollection::PrintHighestRankUniv() {
    for(auto univ : this->GetCollection())
    {
        if(univ.GetUnivRank() != -1 and univ.GetUnivRank() == 1)
        {
            std::cout << "Top 1 University in the world : " << univ.GetUnivName() << std::endl;
        }
    }

}