#include "gameSystem.h"
#include <sstream>
GameSystem::GameSystem() {
    loadFromFile();
}
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
    
void GameSystem::exit() {
    std::ofstream outFile("savegame.txt");
    if (!outFile) {
        std::print("Error: Could not create save file!\n");
        return;
    }

    
    if (marketManager) {
        outFile << "---MARKET_MANAGER---\n1\n";
        marketManager->save(outFile);
    } else {
        outFile << "---MARKET_MANAGER---\n0\n";
    }

    if (taskManager) {
        outFile << "---TASK_MANAGER---\n1\n";
        taskManager->save(outFile);
    } else {
        outFile << "---TASK_MANAGER---\n0\n";
    }

    
    outFile << "---MARKET---\n";
    market.save(outFile);

    outFile << "---TASKBOARD---\n";
    taskBoard.save(outFile);

    
    outFile << "---PLAYERS---\n";
    outFile << players.size() << "\n";
    for (const auto& player : players) {
        player->save(outFile);
    }

    outFile.close();
    std::print("Game saved successfully!\nGoodbye!\n");
}



void GameSystem::loadFromFile() {
    std::ifstream inFile("savegame.txt");
    
    
    if (!inFile) {
        std::print("No save file found. Starting a new world...\n");
        return; 
    }

    std::string dummyHeader;
    int exists;

    
    inFile >> dummyHeader >> exists; 
    if (exists == 1) {
        
        marketManager = std::make_unique<MarketManager>("", "123");
        marketManager->load(inFile);
    }

   
    inFile >> dummyHeader >> exists; 
    if (exists == 1) {
        taskManager = std::make_unique<TaskManager>("", "123");
        taskManager->load(inFile);
    }

    
    inFile >> dummyHeader; 
    market.load(inFile);

    inFile >> dummyHeader; 
    taskBoard.load(inFile);

    
    inFile >> dummyHeader; 
    int numPlayers;
    
    if (inFile >> numPlayers) {
        for (int i = 0; i < numPlayers; ++i) {
            
            auto p = std::make_unique<Player>("", "123"); 
            
            p->load(inFile); 
            
            players.push_back(std::move(p));
        }
    }

    inFile.close();
    std::print("Game loaded successfully!\n");
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
                if (tokens.empty()) {
                    continue; 
                }
                
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
                if( command == "logout"){
                    currentUser = UserType::Guest;
                    std::print("========================================\n");
                    std::print("               BARN BOSS                \n");
                    std::print("========================================\n");
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
    }
            
}

    


