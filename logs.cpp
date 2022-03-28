#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void add_text_move(std::string player, char letter){
    std::fstream logs;
    std::string filename = "logs";
    logs.open(filename.c_str(), std::ios_base::app);
    logs<<"Le joueur "<<player<<" a joué la lettre "<<letter<<std::endl;
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
    char letter = 'e';
    add_text_move("Arthur", letter);
    return 0;
}
