#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>

PhoneBook::PhoneBook()
{
	this->contactCount = 0;
	this->oldestContactIndex = 0;
	std::cout << "Constructeur de PhoneBook appelé." << std::endl;
};

void	PhoneBook::addContact()
{
	std::string firstNameInput;
	std::string lastNameInput;
    std::string nicknameInput;
    std::string phoneNumberInput;
    std::string darkestSecretInput;

	while (true)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, firstNameInput);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Input aborted. Returning to main menu." << std::endl;
			std::cin.clear();
			clearerr(stdin);
			return ;
		}
		if (!firstNameInput.empty())
			break ;
		std::cout << "Field can't be empty. Please try again." << std::endl;
	}

	while (true)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, lastNameInput);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Input aborted. Returning to main menu." << std::endl;
			std::cin.clear();
			clearerr(stdin);
			return ;
		}
		if (!lastNameInput.empty())
			break ;
		std::cout << "Field can't be empty. Please try again." << std::endl;
	}

	    while (true) {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nicknameInput);
        if (std::cin.eof()) {
            std::cout << std::endl << "Input aborted. Returning to main menu." << std::endl;
            std::cin.clear();
            clearerr(stdin);
            return;
        }
        if (!nicknameInput.empty()) {
            break;
        }
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }

	while (true) {
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumberInput);
        if (std::cin.eof()) {
            std::cout << std::endl << "Input aborted. Returning to main menu." << std::endl;
            std::cin.clear();
            clearerr(stdin);
            return;
        }
        if (!phoneNumberInput.empty()) {
            break;
        }
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
	 while (true) {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, darkestSecretInput);
        if (std::cin.eof()) {
            std::cout << std::endl << "Input aborted. Returning to main menu." << std::endl;
            std::cin.clear();
            clearerr(stdin);
            return;
        }
        if (!darkestSecretInput.empty()) {
            break;
        }
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }

    // On va détailler cette fonction plus tard.
    // Pour l'instant, on peut mettre un message pour savoir qu'elle est appelée.
    std::cout << "La fonction ADD contact sera implémentée ici." << std::endl;

    // La logique sera :
    // 1. Créer un objet Contact temporaire.
    // 2. Demander à l'utilisateur chaque champ (prénom, nom, etc.).
    //    - S'assurer qu'aucun champ n'est vide.
    // 3. Appeler la méthode `initialize` du contact temporaire avec les infos recueillies.
    // 4. Ajouter ce contact au tableau `contacts` à l'index `oldestContactIndex`.
    // 5. Mettre à jour `oldestContactIndex` pour le prochain ajout (en boucle de 0 à 7).
    // 6. Si `contactCount` < 8, l'incrémenter.
};

void	PhoneBook::searchContacts()
{
    // On va détailler cette fonction plus tard.
    std::cout << "La fonction SEARCH contact sera implémentée ici." << std::endl;
    // La logique sera :
    // 1. Afficher l'en-tête du tableau (index | first name | last name | nickname).
    // 2. Parcourir les `contactCount` contacts stockés.
    //    - Pour chaque contact, afficher ses infos formatées sur 10 caractères, alignées à droite,
    //      tronquées avec un '.' si plus longues.
    // 3. Demander à l'utilisateur l'index du contact à afficher en détail.
    // 4. Valider l'index.
    // 5. Si l'index est valide, afficher toutes les informations du contact sélectionné.
};