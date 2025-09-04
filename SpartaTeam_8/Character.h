#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>
using namespace std;

struct Item
{
    std::string name;
    int healthBoost;    
    int attackBoost;    
    int price;          

    Item(const std::string& itemName, int health, int attack, int itemPrice)
        : name(itemName), healthBoost(health), attackBoost(attack), price(itemPrice) {
    }
};

class Character
{
private:
    std::string name;           
    int level;                  
    int currentHealth;          
    int maxHealth;             
    int attack;                
    int experience;            
    int gold;                  
    std::vector<Item> inventory;

    static const int EXP_FOR_LEVELUP = 100; 
    static const int MAX_LEVEL = 10;        

public:
    
    Character(const std::string& characterName);

    
    const std::string& getName() const { return name; }
    int getLevel() const { return level; }
    int getCurrentHealth() const { return currentHealth; }
    int getMaxHealth() const { return maxHealth; }
    int getAttack() const { return attack; }
    int getExperience() const { return experience; }
    int getGold() const { return gold; }

    void displayStatus() const;
    bool isAlive() const { return currentHealth > 0; }

    void gainExperience(int exp);
    bool canLevelUp() const { return experience >= EXP_FOR_LEVELUP && level < MAX_LEVEL; }
    void levelUp();

    
    void takeDamage(int damage);
    void heal(int amount);
    int dealDamage() const { return attack; }

    
    void addGold(int amount) { gold += amount; }
    bool spendGold(int amount);

    
    void addItem(const Item& item);
    bool hasItems() const
    {
        return !inventory.empty();
    }
    void displayInventory() const;
    bool useRandomItem();   
    bool sellItem(int index, int sellPrice);

    const vector<Item>& getInventory() const { return inventory; }

private:
    void updateMaxHealth();
    void updateAttack();

};

#endif 
