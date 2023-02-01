#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <fstream>
std::set<std::string> make_exit_commands()
{
    return {"q", "quit", "e", "exit"};
}
void print(const std::map<std::string, std::string> &dic)
{
    for (auto s : dic)
    {
        std::cout << s.first << "  " << s.second << std::endl;
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

int main()
{
    std::string line;
    std::map<std::string, std::string> dic;
    std::vector<std::string> history;
    while (true)
    {
        std::vector<std::string> tab;
        std::cout << "This is a translator, but it does nothing for now..." << std::endl;
        getline(std::cin, line);
        std::stringstream stream(line);
        std::string s;
        if (make_exit_commands().count(line) != 0)
        {
            return 1;
        }
        while (stream >> s)
        {
            tab.emplace_back(s);
        }
        if (tab[0] == "add")
        {
            history.emplace_back(line);
            if (tab.size() == 3)
            {
                dic[tab[1]] = tab[2];
            }
            else
            {
                if (dic.count(tab[1]) != 0)
                {
                    std::cout << tab[1] << " => " << dic[tab[1]] << std::endl;
                }
                else
                {
                    std::cout << "????" << std::endl;
                }
            }
        }
        if (tab[0] == "print")
        {
            print(dic);
        }
        if (tab[0] == "save")
        {
            std::ofstream file(tab[1]);
            for (auto s : history)
            {
                file << s << std::endl;
            }
        }
        if (tab[0] == "load")
        {
            std::ifstream file(tab[1]);

            while (file >> s)
            {
                std::stringstream str(s);
                std::vector<std::string> tab2;
                std::string valeur;
                while (str >> valeur)
                {
                    tab2.emplace_back(valeur);
                }
                if (tab2.size() == 3)
                {
                    dic[tab2[1]] = tab2[2];
                }
                if(tab2.size()==2)
                {
                    if (dic.count(tab2[1]) != 0)
                    {
                        std::cout << tab2[1] << " => " << dic[tab2[1]] << std::endl;
                    }
                    else
                    {
                        std::cout << "????" << std::endl;
                    }
                }
            }
        }
    }

    return 0;
}