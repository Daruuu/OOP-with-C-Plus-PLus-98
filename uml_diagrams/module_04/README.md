# Module 04 - Polymorphism

This directory contains UML diagrams for Module 04 exercises.

## 📊 Available Diagrams

- **ex00_animal_hierarchy.png** - Virtual functions and polymorphism
- **ex01_animal_brain.png** - Composition with Brain class
- **ex02_abstract_animal.png** - Abstract classes and pure virtual functions
- **ex03_materia_system.png** - Complex polymorphic system with interfaces

## 🎯 Diagram Descriptions

### ex00_animal_hierarchy.png
- Animal base class with virtual makeSound() method
- Cat and Dog classes inheriting from Animal
- Virtual destructor implementation
- WrongAnimal and WrongCat classes (non-virtual comparison)
- Polymorphic behavior demonstration

### ex01_animal_brain.png
- Animal class with Brain* composition
- Brain class with ideas_ array
- Deep copying implementation
- Virtual destructor with composition
- Memory management in polymorphic hierarchies

### ex02_abstract_animal.png
- AAnimal abstract class with pure virtual makeSound() = 0
- Cannot instantiate abstract classes
- Derived classes must implement pure virtual functions
- Interface design patterns
- Abstract class vs concrete class

### ex03_materia_system.png
- AMateria abstract base class with pure virtual clone()
- Ice and Cure concrete materia classes
- ICharacter interface with pure virtual methods
- Character class implementing ICharacter
- IMateriaSource interface for factory pattern
- MateriaSource class implementing IMateriaSource
- Complex polymorphic relationships

## 📝 Notes

- Virtual function diagrams show runtime polymorphism
- Abstract class diagrams show pure virtual functions
- Interface diagrams show contract-based design
- Factory pattern diagrams show object creation
- Clone pattern diagrams show object duplication
- Polymorphic container diagrams show object management
