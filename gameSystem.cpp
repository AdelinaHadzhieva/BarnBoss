#include "gameSystem.h"
#include <sstream>

GameSystem& GameSystem::getInstance(){
    static GameSystem instance;
    return instance;
}

const User* GameSystem::getCurrentUser() {
    if (currentUser == UserType::Player) return players[activePlayer].get();
    if (currentUser == UserType::MarketManager) return marketManager.get();
    if (currentUser == UserType::TaskManager) return taskManager.get();
    return nullptr;
}
Player& GameSystem::getActivePlayer() { return *players[activePlayer]; }

Market& GameSystem::getMarket() { return market; }
    
TaskBoard& GameSystem::getTaskBoard() { return taskBoard; }
    
const UserType& GameSystem::getCurrentUserType() const { return currentUser; }
    
MarketManager& GameSystem::getMarketManager() { return *marketManager; }
    
TaskManager& GameSystem::getTaskManager() { return *taskManager; }



std::vector<std::string> split(const std::string& input) {
    std::stringstream ss(input);
    std::string token;
    std::vector<std::string> result;

    
    while (ss >> token) {
        result.push_back(token);
    }
    return result;
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
        std::print("User registered successfully!\n");
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
    std::vector<std::string> tokens;
    
    std::print("========================================\n");
    std::print("               BARN BOSS                \n");
    std::print("========================================\n");
    while(true)
    {
        
            try{
                std::cout<<"> ";
                std::getline(std::cin,command);
                tokens=split(command);
                
                command=tokens[0];
                if(command == "exit"){
                    exit();
                    break;
                }
            
                if(currentUser == UserType::Guest){
                    if(command == "register"){
                        if (tokens.size() < 4) {
                        std::print("Usage: register <username> <password> <type>\n");
                            continue;
                        }
                        std::string username = tokens[1];
                        std::string password = tokens[2];
                        std::string type = tokens[3];
                        Register(username, password, type);
                        continue;
                    }
                    else if(command == "login"){
                        if (tokens.size() < 3) {
                            std::print("Usage: login <username> <password>\n");
                            continue;
                        }
        
                        std::string username = tokens[1];
                        std::string password = tokens[2];
        
                        login(username, password);
                        continue;
                    } 
                    else {
                        std::print("Please enter a valid command: register, login or exit\n");
                        continue;
                    }
                }
            
            
                if(currentUser == UserType::Player && command == "showScoreBoard"){
                    scoreBoard.scoreBoardInfo(players);
                    continue;
                }

            
                std::unique_ptr<ICommand> cmd = CommandFactory::create(tokens, *this);
                if (cmd) {
                    cmd->execute();
                } 
                else {
                    std::print("Unknown command!\n");
                }
            } 
            catch (const std::exception& e) {
                std::print("Error: {}\n", e.what());
            }

            if( command == "logout"){
                currentUser = UserType::Guest;
                std::print("========================================\n");
                std::print("               BARN BOSS                \n");
                std::print("========================================\n");
                continue;
            }
            
        }
            
    }

    


