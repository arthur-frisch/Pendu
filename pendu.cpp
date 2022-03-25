#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using std::cout;

bool is_letter(std::string word, char letter){
    int compteur = 0;
    for(int i = 0; i <= word.size()-1;i++){
        if(word[i] == letter){
            compteur ++;
        }
    }
    if (compteur > 0){
        return true;
    }
    else {
        return false;
    }
}

bool is_letter_in_tab(char letter, std::vector<char> tab){
    int compteur = 0;
    for (int i = 0;i<=tab.size()-1;i++){
        if (tab[i] == letter){
            compteur++;
        }
    }
    if (compteur > 0){
        return true;
    }
    else {
        return false;
    }
}

std::vector<int> find_letter(std::string word, char letter){
    std::vector<int> position;
    for(int i = 0; i <= word.length()-1;i++){
        if (word[i] == letter){
            position.push_back(i);
        }
    }
    return position;
}

void repr(std::vector<char> tab){
    for(int i = 0; i <= tab.size()-1;i++){
        printf("%c, ", tab[i]);
    }
}

std::string mystery_word(std::string word){
    std::string word2(word.length(), '_');
    return word2;
}

std::string replace(std::string word, char letter, std::vector<int> tab){
    for(int i = 0; i <= tab.size()-1; i++){
        word[tab[i]] = letter;
    }
    return word;
}

void affichage(int compteur){
    switch(compteur){
    case 1:
        printf("_______\n");
        break;
    case 2:
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
        break;
    case 3:
        printf(" ___________\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
        break;
    case 4:
        printf(" ___________\n");
        printf("|          |\n");
        printf("|\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
        break;
    case 5:
        printf(" ___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|\n");
        printf("|\n");
        printf("|_______\n");
        break;
    case 6:
        printf(" ___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|          |\n");
        printf("|\n");
        printf("|_______\n");
        break;
    case 7:
        printf(" ___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|          |\n");
        printf("|         /   \n");
        printf("|_______\n");
        break;
    case 8:
        printf(" ___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|          |\n");
        printf("|         / \\  \n");
        printf("|_______\n");
        break;
    case 9:
        printf(" ___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|        --|\n");
        printf("|         / \\  \n");
        printf("|_______\n");
        break;
    case 10:
        printf(" ___________\n");
        printf("|          |\n");
        printf("|          O\n");
        printf("|        --|--\n");
        printf("|         / \\  \n");
        printf("|_______\n");
        break;
    }
}   

std::vector<std::string> player() {
    std::vector<std::string> liste_joueur;
    std::string joueur1;
    std::string joueur2;
    printf("Joueur 1 : ");
    std::cin >> joueur1;
    printf("\nJoueur 2 : ");
    std::cin >> joueur2;
    liste_joueur.push_back(joueur1);
    liste_joueur.push_back(joueur2);
    return liste_joueur;
}

int main(int argc, char* argv[]) {
    char letter;
    int compteur = 0;
    std::string word;
    std::vector<std::string> joueurs;
    joueurs = player();
    std::string joueur1 = joueurs[0];
    std::string joueur2 = joueurs[1];
    cout<<joueur1<<", choisissez un mot a faire choisir a "<<joueur2<<" : ";
    std::cin >> word;
    system("cls");
    std::string mot_mystere = mystery_word(word);
    do {
        printf("Choisissez une lettre : ");
        std::cin >> letter;
        if (is_letter(word, letter)) {
            std::vector<int> position = find_letter(word, letter);
            mot_mystere = replace(mot_mystere, letter, position);
        }
        else {
            compteur++;
            affichage(compteur);
         }
        
        printf("\n");
        cout<<mot_mystere<<std::endl;
        printf("\n");
        if (compteur == 10){
            break;
        }
    } while(word != mot_mystere);
    cout<<"Le mot etait "<<word<<" !"<<std::endl;
    printf("Appuie sur s pour stopper le programme : ");
    char stop;
    std::cin>>stop;
}