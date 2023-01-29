#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <sstream>
std::set<std::string> make_exit_commands()
{

    return {"q", "quit", "e", "exit"};
}
void print(const std::map<std::string, std::string> &dic)
{
    for (auto s : dic)
    {
        std::cout << s.first << " " << s.second << std::endl;
    }
}
int main()
{
    std::string x;
    std::map<std::string, std::string> mapp;

    while (true)
    {
        std::cout << "This is a translator, but it does nothing for now..." << std::endl;
        std::string s;
        getline(std::cin, x);
        std::stringstream stream(x);
        std::vector<std::string> tab;
        if (make_exit_commands().count(x) != 0)
        {
            return 0;
        }
        while (stream >> s)
        {
            tab.emplace_back(s);
        }
        if (tab[0] == "add")
        {
            if (tab.size() == 3)
            {
                mapp.emplace(tab[1], tab[2]);
                std::cout << tab[1] << " => " << tab[2] << std::endl;
            }
            else
            {
                if (mapp.count(tab[1]))
                {
                    std::cout << tab[1] << " => " << mapp[tab[1]] << std::endl;
                }
            }
        }
        if (tab[0] == "translate")
        {
            for (int i = 1; i < tab.size(); i++)
            {
                if (mapp.count(tab[i]) != 0)
                {
                    std::cout << mapp[tab[i]] << std::endl;
                }
                else
                {
                    std::cout << "???" << std::endl;
                }
            }
        }
    }

    return 0;
}