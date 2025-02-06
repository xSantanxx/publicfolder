#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <fstream>

void setGame();
void mainGame(int pPlayer, int nightNo, std::string fileName);
int nightTime();
int nightSys(int stage);
void nightSysV(int nightNo); 
bool doorCheck();
int freddyMo(int playerP, int enemyMov, int enemyLo, int moveNum);
int bonnieMo(int playerP, int enemyMov, int enemyLo, int moveNum);
int chicaMo(int playerP, int enemyMov, int enemyLo, int moveNum);
int foxyMo(int playerP, int enemyMov, int enemyLo, int moveNum);
int gFreddyMo(int playerP, int enemyMov, int enemyLo, int moveNum);
void ifFreddyCaught();
void ifBonnieCaught();
void ifChicaCaught();
void ifFoxyCaught();
void ifgFreddyCaught();
void endGame();

//check for how many yes's i use
//battery system
//minus every time you use it by 10
//when its zero, cant be called
//timer 3 seconds to answer


int main(){
    std::string answer;
    std::cout << "Play?" << std::endl;
    std::getline(std::cin, answer);

    if(answer == "yes"){
        setGame();
    }
    else if(answer == "no"){
        endGame();
    }
}

void setGame(){
    std::cout << "Alri, welcome to the game" << std::endl;
    std::cout << "Hope you have fun" << std::endl;

    //file creation
    std::cout << "Enter your name " << std::endl;
    std::string name;
    std::getline(std::cin, name);

    std::string fileName = name + ".txt";
    std::ifstream file(fileName);
    int nightNo;
    std::string text;

    if(!file){
        file.close();
        std::ofstream file(fileName);
        file << "1";
        text = "1";
        nightNo = std::stoi(text);
        file.close();
        //bug night one bug
    }
    else{
        while(std::getline(file, text)){
        nightNo = std::stoi(text);
        file.close();
        }
    }

    //read the file then obtain the number then call the specific night
    
    std::cout << "Night number " << nightNo << std::endl;


    srand(time(0));
    int random = ((rand() % 10) + 1);
    int pPlayer = random;

    //nightTime();

    std::cout << "You start at " << pPlayer << std::endl;

    mainGame(pPlayer, nightNo, fileName);


    std::cout << "" << std::endl;
}

int nightTime(int i){
    //find a win condition and update it
    //int i = 1;
    int multiNum;
    switch (i)
    {
    case 1:
        std::cout << "Night One" << std::endl;
        multiNum = 2; // remember to change
        return multiNum;
        break;

    case 2:
        std::cout << "Night Two" << std::endl;
        multiNum = 4;
        return multiNum;
        break;

    case 3:
        std::cout << "Night Three" << std::endl;
        multiNum = 5;
        return multiNum;
        break;

    case 4:
        std::cout << "Night Four" << std::endl;
        multiNum = 5;
        return multiNum;
        break;

    case 5:
        std::cout << "Night Five" << std::endl;
        multiNum = 7;
        return multiNum;
        break;
    
    default:
    return -1;
        break;
    }

    nightSys(i);
    
}

//pointless
int nightSys(int stage){
    int multiNum;
    switch (stage)
    {
    case 1:
        multiNum = 2;
        return multiNum;
        break;

    case 2:
        multiNum = 4;
        return multiNum;
        break;
    
    default:
        break;
    }

}

void nightSysV(int nightNo){
    switch (nightNo)
    {
    case 1:
        std::cout << "Night One " << std::endl;
        break;

    case 2:
        std::cout << "Night Two " << std::endl;
        break;

    case 3:
        std::cout << "Night Three " << std::endl;
        break;

    case 4:
        std::cout << "Night Four " << std::endl;
        break;

    case 5:
        std::cout << "Night Five " << std::endl;
        break;
    
    default:
        break;
    }
}

void mainGame(int pPlayer, int nightNo, std::string fileName){
    std::cout << "Here how it goes" << std::endl;
    std::cout << "If the enemies, reach up to you" << std::endl;
    std::cout << "Then you lose" << std::endl;

    int addAi = nightTime(nightNo);
    srand(time(0));
    std::string enemy1 = "Freddy";
    int enemy1Mo = 10 + addAi;//modify movement
    //std::cout << "Freddy movement " << enemy1Mo << std::endl;
    int enemy1Lo = 0;
    int enemy1In = 5;
    std::string enemy2 = "Bonnie";
    int enemy2Mo = 4 + addAi;
    int enemy2Lo = 0;
    int enemy2In = 7;
    std::string enemy3 = "Chica";
    int enemy3Mo = 7 + addAi;
    int enemy3Lo = 0;
    int enemy3In = 8;
    std::string enemy4 = "Foxy";
    int enemy4Mo = 8 + addAi;
    int enemy4Lo = 0;
    int enemy4In = 11;

    //code golden freddy broken 
    int enemy5Mo;
    int enemy5Lo;
    int enemy5In;
    if(nightNo >= 5){
        std::string enemy5 = "Golden Freddy";
        int enemy5Mo = 10 + addAi;
        int enemy5Lo = 0;
        int enemy5In = 6;
    }

    //std::string call = nightSysV(nightNo);

    //present night 5

    int i = 0;

    //battery status
    //int batterySys = 100;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    while(i <= 120){
        system("clear");

        nightSysV(nightNo);

        std::cout << "Timer: " << i << "s" << std::endl;
        int randomE = ((rand() % 20));

        std::cout << "You are at " << pPlayer << std::endl;

        if(i % enemy1In == 0){ //enemy1In = 5
            enemy1Lo = freddyMo(pPlayer, enemy1Mo, enemy1Lo, randomE);
            if(enemy1Lo == -1)
                break;
        }

        if(i % enemy2In == 0){ //enemy1In = 5
            enemy2Lo = bonnieMo(pPlayer, enemy2Mo, enemy2Lo, randomE);
            if(enemy2Lo == -1)
                break;
        }

        if(i % enemy3In == 0){ //enemy1In = 5
            enemy3Lo = chicaMo(pPlayer, enemy3Mo, enemy3Lo, randomE);
            if(enemy3Lo == -1)
                break;
        }

        if(i % enemy4In == 0){ //enemy1In = 5
            enemy4Lo = foxyMo(pPlayer, enemy4Mo, enemy4Lo, randomE);
            if(enemy4Lo == -1)
                break;
        }

        if(nightNo >= 5){
            if(i % enemy5In == 0){ //enemy1In = 5
            enemy5Lo = gFreddyMo(pPlayer, enemy5Mo, enemy5Lo, randomE);
            if(enemy5Lo == -1)
                break;
        }
        }
        

        std::this_thread::sleep_for(std::chrono::seconds(1));

        ++i;

        if(i == 61){
            std::cout << "Congrats you survived " << std::endl;
            std::ifstream file2(fileName);
            std::string text;
            int no;
            while(std::getline(file2, text)){
                no = std::stoi(text);
            }
            if(no == 5){
                std::cout << "You've completed the game " << std::endl;
                file2.close();
                break;
            }
            std::cout << "Onto the next night" << std::endl;
            std::ofstream file(fileName);
            nightNo++;
            file << nightNo;
            file.close();
            break;
        }
    }   
}

int freddyMo(int playerP, int enemyMov, int enemyLo, int moveNum){
    
    bool door;
    
    if(enemyMov >= moveNum){
        enemyLo += moveNum;
        if(enemyLo > 10){
            enemyLo = enemyLo - 10;
        }
    }
    int disFromP = playerP - enemyLo;
    std::cout << "Freddy is " << disFromP << " from the player" << std::endl;
    /*
    if(disFromP <= 3){
        std::cout << "Freddy is nearby you, would you like to close the door? " << std::endl;
        std::string ans;
        std::cin >> ans;
        if(ans == "yes"){
            std::cout << "System: Door is closed " << std::endl;
        }
    }
    */
    if(disFromP == 0){
        door = doorCheck(); 
        if(enemyLo == playerP && !door){
            std::cout << "System Note: Freddy caught you" << std::endl;
            ifFreddyCaught();
            enemyLo -= 10;
            return -1;
            
        }
    else if(enemyLo == playerP && door){
        std::cout << "System: Door stopped Freddy " << std::endl;
        enemyLo -= 10;
    }
    }
    //bool doorValue = false;
    return enemyLo;
}

int bonnieMo(int playerP, int enemyMov, int enemyLo, int moveNum){

    bool door;
    if(enemyMov >= moveNum){
        enemyLo += moveNum;
        if(enemyLo > 10){
            enemyLo = enemyLo - 10;
        }
    }
    int disFromP = playerP - enemyLo;
    std::cout << "Bonnie is " << disFromP << " from the player" << std::endl;
    if(disFromP == 0){
        door = doorCheck();
        if(enemyLo == playerP && !door){
            std::cout << "System Note: Bonnie caught you" << std::endl;
            ifBonnieCaught();
            enemyLo = enemyLo - 10;
            return -1;
            
        }
    else if(enemyLo == playerP && door){
        std::cout << "System: Door stopped Bonnie " << std::endl;
        enemyLo -= 10;
    }
    }
    
    return enemyLo;
}

int chicaMo(int playerP, int enemyMov, int enemyLo, int moveNum){
    
    bool door;
    if(enemyMov >= moveNum){
        enemyLo += moveNum;
        if(enemyLo > 10){
            enemyLo = enemyLo - 10;
        }
    }
    int disFromP = playerP - enemyLo;
    std::cout << "Chica is " << disFromP << " from the player" << std::endl;
    if(disFromP == 0){
        door = doorCheck();
        if(enemyLo == playerP && !door){
            std::cout << "System Note: Chica caught you" << std::endl;
            ifChicaCaught();
            enemyLo = enemyLo - 10;
            return -1;
            
        }
    else if(enemyLo == playerP && door){
        std::cout << "System: Door stopped Chica " << std::endl;
        enemyLo -= 10;
    }
    }
    
    return enemyLo;
}

int foxyMo(int playerP, int enemyMov, int enemyLo, int moveNum){
    
    bool door;
    if(enemyMov >= moveNum){
        enemyLo += moveNum;
        if(enemyLo > 10){
            enemyLo = enemyLo - 10;
        }
    }
    int disFromP = playerP - enemyLo;
    std::cout << "Foxy is " << disFromP << " from the player" << std::endl;
    if(disFromP == 0){
        door = doorCheck();
        if(enemyLo == playerP && !door){
            std::cout << "System Note: Foxy caught you" << std::endl;
            ifFoxyCaught();
            enemyLo = enemyLo - 10;
            return -1;
            
        }
        else if(enemyLo == playerP && door){
        std::cout << "System: Door stopped Foxy " << std::endl;
        enemyLo -= 10;
    }
    }
    
    return enemyLo;
}

int gFreddyMo(int playerP, int enemyMov, int enemyLo, int moveNum){
    
    bool door;
    if(enemyMov >= moveNum){
        enemyLo += moveNum;
        if(enemyLo > 10){
            enemyLo = enemyLo - 10;
        }
    }
    int disFromP = playerP - enemyLo;
    std::cout << "Golden Freddy is " << disFromP << " from the player" << std::endl;
    if(disFromP == 0){
        door = doorCheck();
        if(enemyLo == playerP && !door){
            std::cout << "System Note: Golden Freddy caught you" << std::endl;
            ifgFreddyCaught();
            enemyLo = enemyLo - 10;
            return -1;
            
        }
        else if(enemyLo == playerP && door){
        std::cout << "System: Door stopped Golden Freddy " << std::endl;
        enemyLo -= 10;
    }
    }
    
    return enemyLo;
}

bool doorCheck(){
    std::cout << "Would you like to close the door? " << std::endl;
    std::string ans;
    std::cin >> ans;
    if(ans == "yes"){
        return true;
    }
    else if(ans == "no"){
        return false;
    }
}

void ifFreddyCaught(){
    std::cout << "I caught youuuuuu hehe xd" << std::endl;
}

void ifBonnieCaught(){
    std::cout << "lol wow" << std::endl;
}

void ifChicaCaught(){
    std::cout << "pizza time" << std::endl;
}

void ifFoxyCaught(){
    std::cout << "AGHHHHH" << std::endl;
}

void ifgFreddyCaught(){
    std::cout << "HOOOOOOOO" << std::endl;
}

void endGame(){
    std::cout << "Oh, okay... that's fine" << std::endl;
}