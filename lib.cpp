#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class
class Book
{
private:
    string title;
    string author;
    string ISBN;
    bool isBorrowed;

public:
    // Constructor to initialize a book object
    Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn), isBorrowed(false) {}

    // Function to borrow a book
    bool borrowBook()
    {
        if (isBorrowed)
        {
            cout << "The book \"" << title << "\" is already borrowed.\n";
            return false;
        }
        else
        {
            isBorrowed = true;
            cout << "You have successfully borrowed the book \"" << title << "\".\n";
            return true;
        }
    }

    // Function to return a borrowed book
    bool returnBook()
    {
        if (!isBorrowed)
        {
            cout << "The book \"" << title << "\" was not borrowed.\n";
            return false;
        }
        else
        {
            isBorrowed = false;
            cout << "You have successfully returned the book \"" << title << "\".\n";
            return true;
        }
    }

    // Function to check if the book is available
    bool isAvailable() const
    {
        return !isBorrowed;
    }

    // Function to display book details
    void displayBook() const
    {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN
             << (isBorrowed ? " [Borrowed]" : " [Available]") << endl;
    }
};

// Library class to manage the list of books
class Library
{
private:
    vector<Book> books;

public:
    // Function to add a book to the library
    void addBook(const Book &book)
    {
        books.push_back(book);
    }

    // Function to borrow a book by its title
    void borrowBook(const string &title)
    {
        for (auto &book : books)
        {
            if (book.isAvailable() && book.borrowBook())
            {
                return;
            }
            else if (!book.isAvailable() && book.borrowBook())
            {
                return;
            }
        }
        cout << "The book \"" << title << "\" is not available for borrowing.\n";
    }

    // Function to return a book by its title
    void returnBook(const string &title)
    {
        for (auto &book : books)
        {
            if (!book.isAvailable() && book.returnBook())
            {
                return;
            }
        }
        cout << "The book \"" << title << "\" was not borrowed.\n";
    }

    // Function to display the list of available books
    void displayAvailableBooks() const
    {
        cout << "Available books:\n";
        bool found = false;
        for (const auto &book : books)
        {
            if (book.isAvailable())
            {
                book.displayBook();
                found = true;
            }
        }
        if (!found)
        {
            cout << "No available books at the moment.\n";
        }
    }
};

// Main program
int main()
{
    Library library;

    // Add books to the library
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "1234567890"));
    library.addBook(Book("1984", "George Orwell", "1234567891"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", "1234567892"));

    // Display available books
    library.displayAvailableBooks();

    // Borrow a book
    library.borrowBook("1984");

    // Try to borrow a book that is already borrowed
    library.borrowBook("1984");

    // Return the book
    library.returnBook("1984");

    // Display available books again
    library.displayAvailableBooks();

    return 0;
}
