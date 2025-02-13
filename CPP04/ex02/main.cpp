#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main()
{
    {
		Dog d;
		std::cout << "\n\n\n";
		d.change_ith_idea(-9, "hellooooooo!");
		d.enouce_ith_idea(-9);
		std::cout << "\n\n\n";
    }
    {
        std::cout << "test : array of animal test the constructor and distructor " << std::endl;
        AAnimal* zoo[6] = {new Cat, new Dog, new Dog, new Cat,new Dog,new Dog,};

        std::cout << "*********************************" << std::endl;
        
        for (int i = 0; i < 6; i++)
            delete zoo[i];
    }
    {
        std::cout << "test : the deep copy" << std::endl;
        Dog* dog = new Dog;
        Cat* cat = new Cat;
    
        std::cout << "Dog :" << std::endl;  

        std::cout << "the first idea of the dog object : " << std::endl;
        dog->enouce_ith_idea(0);

        dog->change_ith_idea(0, "dog : i chage my mind");
        std::cout << "the first idea of the dog object after chaging idea: " << std::endl;
        dog->enouce_ith_idea(0);

        Dog *cpy_dog(dog);

        std::cout << "the first idea of the copied dog :" << std::endl;
        cpy_dog->enouce_ith_idea(0);



        std::cout << "Cat :" << std::endl;

        std::cout << "the first idea of the cat object : " << std::endl; 
        cat->enouce_ith_idea(0);

        cat->change_ith_idea(0, "cat : i chage my mind");

        std::cout << "the first idea of the cat object after chaging idea: " << std::endl;
        cat->enouce_ith_idea(0);

        Cat *cpy_cat;
        cpy_cat = cat;
        std::cout << "the first idea of the copied cat :" << std::endl;
        cpy_cat->enouce_ith_idea(0);

        delete dog;
        delete cat;
    }
    return 0;
}
