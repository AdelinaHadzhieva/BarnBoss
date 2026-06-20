
#include "gameSystem.h"
#include "commandFactory.h"

#include "marketManagerCommands/changePriceCommand.h"
#include "marketManagerCommands/restockCommand.h"
#include "playerCommands/addToFarmCommands.h"
#include "playerCommands/buyAndSellCommands.h"
#include "playerCommands/checkCommands.h"
#include "playerCommands/completeTaskCommand.h"
#include "playerCommands/expandCommands.h"
#include "playerCommands/harvestCommand.h"
#include "taskManagerCommands/addTaskCommand.h"    
#include "taskManagerCommands/removeTaskCommand.h"

#include "openMarketCatalogCommand.h"
#include "profileInfoCommand.h"
#include "showTasksCommand.h"
#include "userType.h"

#include <iostream>

class GameSystem;

std::unique_ptr<ICommand> CommandFactory::create(const std::vector<std::string>& tokens, GameSystem& sys) 
{
        
        if (tokens.empty()) {
            throw std::invalid_argument("Empty command");
        }
        std::string command = tokens[0];
        UserType userType = sys.getCurrentUserType();

        if (command == "profileInfo") {
            const User* activeUser = sys.getCurrentUser();
            if (activeUser != nullptr) {
                return std::make_unique<ProfileInfoCommand>(activeUser);
            }
        }
        if (command == "openMarketCatalog") {
            if (userType == UserType::Player || userType == UserType::MarketManager) {
                return std::make_unique<OpenMarketCatalogCommand>(sys.getMarket());
            }
        }
        if (command == "showTaskBoard") {
            if (userType == UserType::Player || userType == UserType::TaskManager) {
                return std::make_unique<ShowTasksCommand>(sys.getTaskBoard());
            }
        }
        if (userType == UserType::Player) {
            
            if (command == "checkBalance") {
                return std::make_unique<CheckBalanceCommand>(sys.getActivePlayer());
            }
            if (command == "checkBarn") {
                return std::make_unique<CheckBarnCommand>(sys.getActivePlayer());
            }
            if (command == "checkFarm") {
                return std::make_unique<CheckFarmCommand>(sys.getActivePlayer());
            }
            if (command == "harvest") {
                return std::make_unique<HarvestCommand>(sys.getActivePlayer());
            }
            if (command == "expandCropland") {
                return std::make_unique<ExpandCroplandCommand>(sys.getActivePlayer());
            }
            if (command == "expandFarmland") {
                return std::make_unique<ExpandFarmlandCommand>(sys.getActivePlayer());
            }

            
            if (command == "sowPlant") {
                if (tokens.size() < 2) throw std::invalid_argument("Usage: sowPlant <seedId>");
                int seedId = std::stoi(tokens[1]);
                return std::make_unique<SowPlantCommand>(sys.getActivePlayer(), seedId);
            }
            if (command == "addAnimal") {
                if (tokens.size() < 2) throw std::invalid_argument("Usage: addAnimal <animalId>");
                int animalId = std::stoi(tokens[1]);
                return std::make_unique<AddAnimalCommand>(sys.getActivePlayer(), animalId);
            }
            if (command == "completeTask") {
                if (tokens.size() < 2) throw std::invalid_argument("Usage: completeTask <taskId>");
                int taskId = std::stoi(tokens[1]);
                return std::make_unique<CompleteTaskCommand>(sys.getActivePlayer(), sys.getTaskBoard(), taskId);
            }

            
            if (command == "buyItem") {
                if (tokens.size() < 3) throw std::invalid_argument("Usage: buyItem <productId> <quantity>");
                int id = std::stoi(tokens[1]);
                int qty = std::stoi(tokens[2]);
                return std::make_unique<BuyItemCommand>(sys.getActivePlayer(), sys.getMarket(), id, qty);
            }
            if (command == "sellItem") {
                if (tokens.size() < 3) throw std::invalid_argument("Usage: sellItem <productId> <quantity>");
                int id = std::stoi(tokens[1]);
                int qty = std::stoi(tokens[2]);
                return std::make_unique<SellItemCommand>(sys.getActivePlayer(), sys.getMarket(), id, qty);
            }
        }

        
        if (userType == UserType::MarketManager) {
            
            if (command == "restock") {
                if (tokens.size() < 3) throw std::invalid_argument("Usage: restock <productId> <quantity>");
                int id = std::stoi(tokens[1]);
                int qty = std::stoi(tokens[2]);
                return std::make_unique<RestockCommand>(sys.getMarketManager(), sys.getMarket(), id, qty);
            }
            if (command == "changePrice") {
                if (tokens.size() < 3) throw std::invalid_argument("Usage: changePrice <productId> <newPrice>");
                int id = std::stoi(tokens[1]);
                int newPrice = std::stoi(tokens[2]);
                return std::make_unique<ChangePriceCommand>(sys.getMarketManager(), sys.getMarket(), id, newPrice);
            }
        }

        if (userType == UserType::TaskManager) {
            
            if (command == "removeTask") {
                if (tokens.size() < 2) throw std::invalid_argument("Usage: removeTask <taskId>");
                int taskId = std::stoi(tokens[1]);
                return std::make_unique<RemoveTaskCommand>(sys.getTaskManager(), sys.getTaskBoard(), taskId);
            }
            if (command == "addTask") {
               
                if (tokens.size() < 5) throw std::invalid_argument("Usage: addTask <productName> <qty> <balance> <score>");
                Products prod = stringToProduct(tokens[1]).value();
                int qty = std::stoi(tokens[2]);
                int balance = std::stoi(tokens[3]);
                int score = std::stoi(tokens[4]);
                return std::make_unique<AddTaskCommand>(sys.getTaskManager(), sys.getTaskBoard(), prod, qty, balance, score);
            }
        }

        
        return nullptr;

}
