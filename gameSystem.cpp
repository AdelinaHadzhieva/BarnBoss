#include "gameSystem.h"

GameSystem& GameSystem::getInstance(){
    static GameSystem instance;
    return instance;
}

void GameSystem::Register(const std::string& username, const std::string& password, const std::string& type){
    if(type == "MarketManager"){
        if(marketManager != nullptr)
            throw std::logic_error("Market Manager already exists!");
        else{
            marketManager = std::make_unique<MarketManager>(username, password);
            std::print("User registered successfully!\n");
            return;
        }
    }
    else if(type == "TaskManager"){
        if(taskManager != nullptr)
            throw std::logic_error("Task Manager already exists!");
        else{
            taskManager = std::make_unique<TaskManager>(username, password);
            std::print("User registered successfully!\n");
            return;
        }
    }
    else if(type == "Player"){
        for(const auto& player : players){
            if(player->getName() == username){
                throw std::invalid_argument("A player with that username already exists!");
            }
        }
        players.emplace_back(std::make_unique<Player>(username,password));
    }
    else {
        std::print("Unknown user type\n");
    }
    
}
    
void GameSystem::login(const std::string& username, const std::string& password){
    if(marketManager && marketManager->getName() == username && marketManager->getPass() == password)
    {
        currentUser = UserType::MarketManager; 
        std::print("Welcome, {}!\n", username);
        return;
    }
    else if(taskManager && taskManager->getName() == username && taskManager->getPass() == password)
    {
        currentUser = UserType::TaskManager; 
        std::print("Welcome, {}!\n", username);
        return;
    }
    else {
        for (size_t i = 0; i < players.size(); i++) {
            if (players[i]->getName() == username && players[i]->getPass() == password) {
                currentUser = UserType::Player;
                activePlayer = i; 
                std::print("Welcome, {}!\n", username);
                return;
            }
        }
        throw std::invalid_argument("Please enter valid username and password!");
    }
}
    
void GameSystem::exit(){
    //files
    std::print("Game save successfully!\nGoodbye!");
}
    
void GameSystem::run(){
    std::string command;
    std::cout<<"> ";
    while(true)
    {
        std::print("========================================\n");
        std::print("               BARN BOSS                \n");
        std::print("========================================\n>");
        while(true){
            try{
                std::cin >> command;
                if(command == "exit"){
                break;
                }
            
                if(currentUser == UserType::Guest){
                    std::string username;
                    std::string password;
                    std::string type;
                    if(command == "register"){
                        std::cin >> username;
                        std::cin >> password;
                        std::cin >> type;
                        Register(username, password, type);
                        continue;
                    }
                    else if(command == "login"){
                        std::cin >> username;
                        std::cin >> password;
                        login(username, password);
                        continue;
                    } 
                    else {
                        std::print("Please enter a valid command: register, login or exit");
                        continue;
                    }
                }
            
            if(currentUser == UserType::MarketManager){
                if(command == "profileInfo"){
                    marketManager->profileInfo();
                }
                else if(command == "openMarketCatalog"){
                    marketManager->openMarketCatalog(market);
                }
                else if(command == "restock"){
                    int id, quantity; std::cin >> id >> quantity;
                    marketManager->restock(market, id, quantity);
                }
                else if(command == "changePrice"){
                    int newPrice, id; std::cin >> id >> newPrice;
                    marketManager->changePrice(market, id, newPrice);
                }
            }
            if(currentUser == UserType::TaskManager){
                if(command == "profileInfo"){
                    taskManager->profileInfo();
                }
                else if(command == "showTasks"){
                    taskManager->showTasks(taskBoard);
                }
                else if(command == "addTask"){
                    int quantity, balance, score;
                    std::string product;
                    std::cin>>product >> quantity >> balance >> score;
                    taskManager->addTask(taskBoard, stringToProduct(product), quantity, balance, score);
                }
                else if(command == "removeTask"){
                    int id; std::cin >> id;
                    taskManager->removeTask(taskBoard, id);
                }

            }
            if(currentUser == UserType::Player){
                if(command == "profileInfo"){
                    players[activePlayer]->profileInfo();
                }
                if(command == "checkBalance"){
                    players[activePlayer]->checkBalance();
                }
                if(command == "checkScore"){
                    players[activePlayer]->checkScore();
                }
                if(command == "checkBarn"){
                    players[activePlayer]->checkBarn();
                }
                if(command == "checkFarm"){
                    players[activePlayer]->checkFarm();
                }
                if(command == "expandCropland"){
                    players[activePlayer]->expandCropland();
                }
                if(command == "expandFarmland"){
                    players[activePlayer]->expandFarmland();
                }
                if(command == "sowPlant"){
                    int id; std::cin >> id;
                    players[activePlayer]->sowPlant(id);
                }
                if(command == "addAnimal"){
                    int id; std::cin >> id;
                    players[activePlayer]->addAnimal(id);
                }
                else if(command == "openMarketCatalog"){
                    players[activePlayer]->openMarketCatalog(market);
                }
                else if(command == "harvest"){
                    players[activePlayer]->harvest();
                }
                else if(command == "buyItem"){
                    int id, quantity; std::cin >> id >> quantity;
                    players[activePlayer]->buyItem(market, id, quantity);
                }
                else if(command == "sellItem"){
                    int id, quantity; std::cin >> id >> quantity;
                    players[activePlayer]->sellItem(market, id, quantity);
                }
                else if(command == "showTaskBoard"){
                    players[activePlayer]->showTaskBoard(taskBoard);
                }
                else if(command == "completeTask"){
                    int id; std::cin >> id;
                    players[activePlayer]->completeTask(taskBoard, id);
                }

            }

            if( command == "logout"){
                currentUser = UserType::Guest;
                continue;
            }
            std::cout<<"> ";
            }
            catch(const std::exception& e){std::print("{}.\n", e.what());}
        }
        if(command == "exit"){
            exit();
            break;
        }
        
    }
    
}

