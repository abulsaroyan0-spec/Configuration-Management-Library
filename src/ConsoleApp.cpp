#include "ConsoleApp.hpp"

#include "Library.hpp"
#include "PublicationFactory.hpp"
#include "SearchStrategy.hpp"

#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

namespace {
    void printPublications(const std::vector<const Publication*>& publications) {
        if (publications.empty()) {
            std::cout << "No publications found.\n";
            return;
        }

        for (const Publication* publication : publications) {
            std::cout << *publication << '\n';
        }
    }

    int readYear() {
        int year;
        if (!(std::cin >> year)) {
            throw std::invalid_argument("Year must be an integer.");
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return year;
    }
}

void ConsoleApp::printMenu() const {
    std::cout
        << "\n===== Library Management System =====\n"
        << "1. Add publication\n"
        << "2. Remove publication\n"
        << "3. Display all publications\n"
        << "4. Find publication by ID\n"
        << "5. Borrow publication\n"
        << "6. Return publication\n"
        << "7. Search by title\n"
        << "8. Search by year\n"
        << "9. Show library statistics\n"
        << "0. Exit\n"
        << "Choose: ";
}

void ConsoleApp::run() {
    Library library;
    PublicationFactory factory;

    while (true) {
        printMenu();

        int choice;
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) {
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid menu choice.\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        try {
            if (choice == 0) {
                break;
            }

            if (choice == 1) {
                std::string type, id, title;
                int year;

                std::cout << "Type (Book/Magazine/DigitalBook): ";
                std::getline(std::cin, type);
                std::cout << "ID: ";
                std::getline(std::cin, id);
                std::cout << "Title: ";
                std::getline(std::cin, title);
                std::cout << "Year: ";
                year = readYear();

                std::vector<std::string> extra;
                if (type == "Book") {
                    std::string author;
                    std::cout << "Author: ";
                    std::getline(std::cin, author);
                    extra.push_back(author);
                } else if (type == "Magazine") {
                    std::string issue;
                    std::cout << "Issue number: ";
                    std::getline(std::cin, issue);
                    extra.push_back(issue);
                }

                library.add(factory.create(type, id, title, year, extra));
                std::cout << "Publication registered successfully.\n";
            } else if (choice == 2) {
                std::string id;
                std::cout << "ID: ";
                std::getline(std::cin, id);
                library.remove(id);
                std::cout << "Publication removed successfully.\n";
            } else if (choice == 3) {
                printPublications(library.getAll());
            } else if (choice == 4) {
                std::string id;
                std::cout << "ID: ";
                std::getline(std::cin, id);
                std::cout << library.find(id) << '\n';
            } else if (choice == 5 || choice == 6) {
                std::string id;
                std::cout << "ID: ";
                std::getline(std::cin, id);
                Publication& publication = library.find(id);

                if (choice == 5) {
                    publication.borrow();
                    std::cout << "Publication borrowed successfully.\n";
                } else {
                    publication.giveBack();
                    std::cout << "Publication returned successfully.\n";
                }
            } else if (choice == 7 || choice == 8) {
                std::string query;
                std::cout << (choice == 7 ? "Title text: " : "Year: ");
                std::getline(std::cin, query);

                if (choice == 7) {
                    SearchByTitle strategy;
                    printPublications(library.search(strategy, query));
                } else {
                    SearchByYear strategy;
                    printPublications(library.search(strategy, query));
                }
            } else if (choice == 9) {
                const LibraryStatistics stats = library.getStatistics();
                std::cout << "Total publications: " << stats.total << '\n'
                          << "Books: " << stats.books << '\n'
                          << "Magazines: " << stats.magazines << '\n'
                          << "Digital books: " << stats.digitalBooks << '\n'
                          << "Available physical: " << stats.availablePhysical << '\n'
                          << "Borrowed physical: " << stats.borrowedPhysical << '\n';
            } else {
                std::cout << "Unknown menu option.\n";
            }
        } catch (const std::exception& error) {
            std::cout << "Error: " << error.what() << '\n';
        }
    }
}
