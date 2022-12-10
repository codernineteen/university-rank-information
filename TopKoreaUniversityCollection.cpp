//
// Created by 전예찬 on 2022/12/05.
//

#include "TopKoreaUniversityCollection.h"

TopKoreaUniversityCollection::TopKoreaUniversityCollection() {
    std::vector<std::vector<std::string>> lines = loadUnivFromCSV();

    for(const auto& line : lines)
    {
        std::string name = line[0];
        if(
                name == "Seoul National University"
                )
        {
            University u = University(line[0], stoi(line[1]), stoi(line[8]), line[4], line[5]);
            koreaCollection.push_back(u);
        }
    }
}

std::vector<University> TopKoreaUniversityCollection::GetCollection() {
    return koreaCollection;
}

void TopKoreaUniversityCollection::PrintCollection() {
    std::cout << "[세계를 주도하는 한국의 대학교]" << std::endl;
    for(auto univ : this->GetCollection())
    {
        std::string name = univ.GetUnivName();
        std::string state;
        std::cout << "이름 : " << univ.GetUnivName() << " | ";
        std::cout << "세계 랭킹 : " << univ.GetUnivRank() << "등 | ";
        std::cout << "논문 출판 수 : " << univ.GetNumOfPublications() << " | ";
        std::cout << "위치 : " << univ.GetUnivRegion() << ", " << univ.GetUnivCountry() << "\n";
    }
}

void TopKoreaUniversityCollection::PrintNumberOfElements() {
    std::cout << "세계 랭킹에 속하는 한국의 대학교 수는 : " << koreaCollection.size() << std::endl;
}

void TopKoreaUniversityCollection::SortUniversitiesByRank() {
    std::sort(koreaCollection.begin(), koreaCollection.end());
    std::cout << "정렬을 완료했습니다." << std::endl;
}