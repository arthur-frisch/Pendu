#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void add_text(std::string filename, std::string text){
    std::fstream logs;
    logs.open(filename.c_str(), std::ios_base::app);
    logs<<text<<std::endl;
    logs.close();
}

std::vector<std::string> read_text(std::string text){
    std::vector<std::string> tab;
    int compteur = 0;
    std::string space = " ";
    std::string return_text;
    text += " ";
    while (compteur <= text.length()) {
        std::string letter = std::string(1, text[compteur]);
        if (letter == space) {
            tab.push_back(return_text);
            return_text = "";
        }
        else {
            return_text += letter;
        }
        compteur++;
    }
    return tab;
}


int main(int argc, char* argv[]) {
    std::string file = "logs";
    std::string texte = "Bonjour je m'appelle farouk";
    std::vector<std::string> tab;
    tab = read_text(texte);
    std::cout<<tab[2]<<std::endl;
    return 0;
}
