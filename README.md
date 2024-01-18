### **Milestone 1: Project Initialization and Class Implementation**

**Description:
This project involves creating a simple 2D game, a blend of Pac-Man and Metal Slug, playable through console input. The primary goal is to navigate a 15 x 15 grid, eliminate monsters, and survive.**

### **Milestone 1 Objectives:**

1. **Object Class:**
    - **Base class with a 'type' attribute representing the object type.**
2. **Character Class:**
    - **Base class for Hero and Monster with attributes like position and health points.**
3. **Hero Class:**
    - **Inherits from Character class and includes a 'Gun' attribute representing the hero's weapon.**
4. **Gun Class:**
    - **Three subclasses: Pistol, Bazooka, Rifle, with specific attributes.**
5. **Monster Class:**
    - **Subclass of Character class with attributes like name and health points.**
6. **Hero and Monster Subclasses:**
    - **MedicHero, DemolitionHero, GhostMonster, TankMonster, each with unique attributes.**
7. **Item Class:**
    - **Represents items on the map, with subclasses Ammo and Potion.**
8. **Game Class:**
    - **Manages a 2D array grid of objects, Hero, and game functions (GenerateMap, showMap, startGame).**

### **Milestone 2: Game Logic Implementation**

**Description:
In this milestone, the focus is on implementing the behavior of different classes and the overall game logic. The objective is for the hero to eliminate all monsters without dying.**

### **Milestone 2 Objectives:**

1. **Object Class:**
    - **Overload the `<<` operator to display the object type.**
2. **Hero Class:**
    - **Overload `<<` operator for hero info, and `+` and `` operators for specific interactions.**
    - **Implement `useSpecial()` method for unique hero behavior.**
3. **Gun Class:**
    - **Overload `<<` operator to display gun info.**
    - **Implement `useSpecial()` method for special abilities.**
4. **Game Class:**
    - **Introduce a static variable for rounds.**
    - **Implement game functions: `move()`, `FireGun()`, `useGunSpecial()`, `checkGameOver()`, `updateMap()`.**

**Game Flow:**

- **User selects hero and gun.**
- **Game starts, displaying hero info, round, and map.**
- **Actions include movement, shooting, using special abilities.**
- **Console updates after each action.**
