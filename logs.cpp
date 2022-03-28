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

void add_text_winner(std::string player){
    std::fstream logs;
    std::string filename = "logs";
    logs.open(filename.c_str(), std::ios_base::app);
    logs<<"Le joueur "<<player<<" a gagné la partie !"<<std::endl;
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

int process_logs(std::string player){
    std::fstream logs;
    std::string filename = "logs";
    std::string excla = "!";
    int compteur = 0;
    std::vector<std::string> tab;
    logs.open(filename.c_str(), std::ios_base::in);
    std::string line;
    while(getline(logs, line)){
        tab = read_text(line);
        if ((tab[tab.size()-1] == excla) && (tab[2] == player)){
            compteur++;
        }
    }
    logs.close();
    return compteur;   
}

int main(int argc, char* argv[]) {
    char letter = 'e';
    int compteur;
    add_text_winner("Jade");
    compteur = process_logs("Arthur");
    std::cout<<compteur<<std::endl;
    return 0;
}
