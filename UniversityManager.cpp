//
// Created by 전예찬 on 2022/12/05.
//

#include "UniversityManager.h"

UniversityManager::UniversityManager() {
    wholeUniversityList = UniversityCollection();
    koreaUniversityList = TopKoreaUniversityCollection();
    ivyLeagueList = IvyLeague();
}


void UniversityManager::Greeting() {
    std::cout << "[Welcome to University Rank Search Service]" << std::endl;
}

int UniversityManager::ShowMenu() {
    int mode;
    std::cout << "1. Show Top 300 Universities List" << std::endl;
    std::cout << "2. Show the Universities in Ivy League" << std::endl;
    std::cout << "3. Show the Universities in Korea included in the 300 lists" << std::endl;
    std::cout << "4. Exit the program" << std::endl;
    std::cout << "Your input : ";
    std::cin >> mode;
    while(mode != 1 and mode != 2 and mode != 3 and mode !=4)
    {
        std::cout << "[Invalid input] : you should choose your input 1 ~ 4" << std::endl;
        std::cout << "Your input";
        std::cin >> mode;
    }

    return mode;
}

int UniversityManager::ShowWholeUniversityMenu() {
    int mode;
    std::cout << "1. Show the list" << std::endl;
    std::cout << "2. Sort the list by rank" << std::endl;
    std::cout << "3. Show the filtered list (Sorted and erased null rank data)" << std::endl;
    std::cout << "4. Show the top 1 university in the world" << std::endl;
    std::cout << "5. Exit the current menu" << std::endl;
    std::cout << "Your input : ";
    std::cin >> mode;
    while(mode != 1 and mode != 2 and mode != 3 and mode !=4 and mode != 5)
    {
        std::cout << "[Invalid input] : you should choose your input 1 ~ 4" << std::endl;
        std::cout << "Your input";
        std::cin >> mode;
    }

    return mode;
}

int UniversityManager::ShowIvyLeagueMenu() {
    int mode;
    std::cout << "1. Show the list" << std::endl;
    std::cout << "2. Sort the list by rank" << std::endl;
    std::cout << "3. Exit the current menu" << std::endl;
    std::cout << "Your input : ";
    std::cin >> mode;
    while(mode != 1 and mode != 2 and mode != 3)
    {
        std::cout << "[Invalid input] : you should choose your input 1 ~ 3" << std::endl;
        std::cout << "Your input";
        std::cin >> mode;
    }

    return mode;
}

int UniversityManager::ShowKoreaMenu() {
    int mode;
    std::cout << "1. Show the list" << std::endl;
    std::cout << "2. Exit the current menu" << std::endl;
    std::cout << "Your input : ";
    std::cin >> mode;
    while(mode != 1 and mode != 2)
    {
        std::cout << "[Invalid input] : you should choose your input 1 ~ 3" << std::endl;
        std::cout << "Your input";
        std::cin >> mode;
    }

    return mode;
}

void UniversityManager::run() {
    Greeting();
    std::cout << "--------------" << std::endl;
    int mode = ShowMenu();

    while(mode != 4)
    {
        switch(mode) {
            case 1 : {
                std::cout << "--------------" << std::endl;
                std::cout << "[Top 300 Universities list]" << std::endl;
                int innerMode = ShowWholeUniversityMenu();
                while(innerMode != 5)
                {
                    switch(innerMode) {
                        case 1:
                            wholeUniversityList.PrintCollection();
                            std::cout << "--------------" << std::endl;
                            break;
                        case 2:
                            wholeUniversityList.SortUniversitiesByRank();
                            std::cout << "--------------" << std::endl;
                            break;
                        case 3:
                            wholeUniversityList.PrintFilteredCollection();
                            std::cout << "--------------" << std::endl;
                            break;
                        case 4:
                            wholeUniversityList.PrintHighestRankUniv();
                            std::cout << "--------------" << std::endl;
                            break;
                    }
                    innerMode = ShowWholeUniversityMenu();
                    std::cout << "--------------" << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << "--------------" << std::endl;
                std::cout << "[Ivy League]" << std::endl;
                int innerMode = ShowIvyLeagueMenu();
                while(innerMode != 3)
                {
                    switch(innerMode) {
                        case 1:
                            ivyLeagueList.PrintCollection();
                            std::cout << "--------------" << std::endl;
                            break;
                        case 2:
                            ivyLeagueList.SortUniversitiesByRank();
                            std::cout << "--------------" << std::endl;
                            break;
                    }
                    innerMode = ShowIvyLeagueMenu();
                    std::cout << "--------------" << std::endl;
                }
                break;
            }
            case 3: {
                std::cout << "--------------" << std::endl;
                std::cout << "[Top Korea university in world rank]" << std::endl;
                int innerMode = ShowKoreaMenu();
                while(innerMode != 2)
                {
                    switch(innerMode) {
                        case 1:
                            koreaUniversityList.PrintCollection();
                            std::cout << "--------------" << std::endl;
                            break;
                    }
                    innerMode = ShowKoreaMenu();
                    std::cout << "--------------" << std::endl;
                }
                break;
            }
        }
        mode = ShowMenu();
    }
}