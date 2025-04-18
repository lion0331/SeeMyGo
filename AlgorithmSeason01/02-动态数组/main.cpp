#include "main.h"
#include "ArrayList.h"
#include "Person.h"

int main() {

        ArrayList<Person> persons{};
        persons.add(Person(25, "John"));
        persons.add(Person(10, "Jack"));
        persons.add(Person(12, "James"));
        persons.add(Person(15, "Rose"));
        persons.clear();
        persons.add(Person(22, "Saga"));


        ArrayList<Person> newPersons;

        ArrayList<int> ints = ArrayList<int>();
        ints.add(10);
        ints.add(10);

	ints.add(22);
	ints.add(33);

	std::cout << "Size of persons: " << persons.getSize() << std::endl;
	std::cout << "Size of ints: " << ints.getSize() << std::endl;

    for (int i = 0; i < persons.getSize(); i++)
    {
        std::cout << persons.get(i).getName() << " " << persons.get(i).getAge() << std::endl;
    }


	for (int i = 0; i < ints.getSize(); i++) {
		std::cout << ints.get(i) << std::endl;
	}
	return 0;

	return 0;
}