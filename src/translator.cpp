#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
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
int main(int argc, char const *argv[])
{
    std::string src;
    std::string cible;
    if (argc == 3)
    {
        src = argv[1];
        cible = argv[2];
    }
    else
    {
        src = "fr";
        cible = "en";
    }
    std::string x;
    std::map<std::string, std::string> mapp;
    std::vector<std::string> history;

    while (true)
    {
        std::cout << src << " " << cible << std::endl;
        std::cout << "This is a translator, but it does nothing for now..." << std::endl;
        std::string s;
        getline(std::cin, x);
        const std::string xx = x;
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
        std::cout << xx << std::endl;
        if (tab[0] == "load")
        {
            std::string ss;
            std::ifstream fichier(tab[1]);
            std::vector<std::string> tab2;
            while (fichier >> s)
            {
                std::stringstream ss(s);

                while (ss >> s)
                {
                    std::cout << s << std::endl;
                    tab2.emplace_back(s);
                }
            }
            fichier.close();
        }
        if (tab[0] == "save")
        {
            std::ofstream fichier(tab[1]);

            for (auto ss : history)
            {

                fichier << ss << std::endl;
            }
            fichier.close();
        }
        if (tab[0] == "add")
        {
            history.emplace_back(xx);

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
            int siz = tab.size();
            for (int i = 1; i < siz; i++)
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
        if (tab[0] == "clear")
        {
            mapp.clear();
        }
        if (tab[0] == "remove")
        {
            mapp.erase(tab[1]);
        }
    }

    return 0;
}