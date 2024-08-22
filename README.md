Game Architecture Overview
1. Class Structure
The game's class hierarchy is built to separate different entities like the game mode, player characters, enemies, and controllers. Each class has a distinct role in defining behavior and interactions.

```sql
WarriorBaseGameMode  
│
├── WarriorBaseCharacter
│   ├── WarriorHeroCharacter
│   │   └── WarriorHeroController
│   └── WarriorEnemyCharacter
```

1.1 WarriorBaseGameMode
Role: The core game mode class that defines the game rules and manages the overall gameplay flow.
Responsibilities:
Manage player/enemy spawning
Oversee game logic, objectives, and rules
1.2 WarriorBaseCharacter
Role: The foundational character class that provides shared functionality and attributes for all game characters (both player and enemy).
Common Attributes:
Health, stamina, movement speed, strength
Common Methods:
Attack(), Defend(), TakeDamage(), Die()
1.3 WarriorHeroCharacter
Role: A specialized character class representing the player-controlled hero.
Hero-Specific Attributes:
Unique weapons and abilities
Hero-Specific Methods:
ActivateSpecialAbility(), EquipWeapon()
1.4 WarriorHeroController
Role: Manages the player's input and controls the WarriorHeroCharacter.
Responsibilities:
Handle player inputs
Control camera and character movement
Interface with the ability system
1.5 WarriorEnemyCharacter
Role: Represents enemy AI characters.
Enemy-Specific Attributes:
AI behavior and patterns
Enemy-Specific Methods:
ChasePlayer(), PerformAttack(), PatrolArea()

2. Gameplay Ability System (GAS)
The Gameplay Ability System (GAS) is a key system for managing abilities, their activation, and interactions. This system allows the game to handle abilities such as attacks, buffs, and other special actions in a modular and scalable way.

```sql
Gameplay Ability System
│
├── Ability System Component
│   ├── Set up Spawn Ability
│   ├── Create Weapon Class
│   ├── Grant Ability
│   └── Finish Spawning
│
└── Gameplay Ability
    ├── Ability Activation Policy
    ├── Give Ability to Character
    ├── Activate Ability
    │   ├── On Given (One-Time)
    │   └── On Triggered
    ├── End Ability
    └── Clear Ability
```

2.1 Ability System Component
Role: Manages the character's abilities, attributes, and the application of effects.
Setup Workflow:
Set up Spawn Ability: Initializes abilities on character spawn.
Create Weapon Class: Defines the weapons the character uses (including weapon stats and interactions with abilities).
Grant Ability: Attaches specific abilities to the character.
Finish Spawning: Completes the initialization, ensuring abilities and weapons are ready for activation.
2.2 Gameplay Ability
Role: Represents individual abilities that a character can use. Each ability can have unique effects, durations, and activation methods.
Ability Lifecycle:
Ability Activation Policy: Defines when and how an ability is activated (e.g., on trigger or automatically).
Give Ability to Character: Grants the character an ability during gameplay.
Activate Ability: Triggers the ability for use. There are two activation types:
On Given (One-Time): Ability automatically activates upon being given (e.g., a buff with a set duration).
On Triggered: Ability is activated manually or upon meeting certain conditions (e.g., an attack ability that requires input).
End Ability: Ends the ability, either due to completion or manual deactivation.
Clear Ability: Cleans up and removes the ability from the character to reset or free up resources.


Architecture Diagram

WarriorBaseGameMode  
```sql
├── WarriorBaseCharacter
│   ├── WarriorHeroCharacter
│   │   └── WarriorHeroController
│   └── WarriorEnemyCharacter
│
└── Gameplay Ability System
    ├── Ability System Component
    │   ├── Set up Spawn Ability
    │   ├── Create Weapon Class
    │   ├── Grant Ability
    │   └── Finish Spawning
    │
    └── Gameplay Ability
        ├── Ability Activation Policy
        ├── Give Ability to Character
        ├── Activate Ability
        │   ├── On Given (One-Time)
        │   └── On Triggered
        ├── End Ability
        └── Clear Ability
```
