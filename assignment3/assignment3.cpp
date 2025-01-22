#include <iostream>
#include <string>
#include <vector>


using namespace std;

class LibraryException : public runtime_error {
public:
    explicit LibraryException(const string& message) : runtime_error(message) {}
};

class Book {
private:
    string title;
    string author;
    bool available;
    int id;

public:
    
    string getTitle() const {
        return title;
    }

    void setTitle(const string& title) {
        this->title = title;
    }

    string getAuthor() const {
        return author;
    }

    void setAuthor(const string& author) {
        this->author = author;
    }

    bool isAvailable() const {
        return available;
    }

    void setAvailable(bool available) {
        this->available = available;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    string toString() const {
        return "Book ===> { title='" + title + "', author='" + author + "', available=" + (available ? "true" : "false") + ", id=" + to_string(id) + "}";
    }
};

ostream& operator<<(ostream& os, const Book& book) {
    os << book.toString();
    return os;
}

class LibraryTasks {
public:
    

    virtual void addBook(int id, const string& title, const string& author) = 0;
    virtual void removeBook(int id) = 0;
    virtual void returnBook(int id) = 0;
    virtual void borrowBook(int id) = 0;
    virtual void showBook() = 0;
};

class Library : public LibraryTasks {
private:
    vector<Book> books;

public:
    Library() = default;

    void addBook(int id, const string& title, const string& author) override {
        for (const Book& book : books) {
            if (book.getId() == id) {
                throw LibraryException("Book already exists");
            }
        }
        Book b;
        b.setId(id);
        b.setTitle(title);
        b.setAuthor(author);
        b.setAvailable(true);
        books.push_back(b);
        cout << "Book added" << endl;
    }

    void removeBook(int id) override {
        bool found = false;
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getId() == id) {
                books.erase(books.begin() + i);
                found = true;
                cout << "Book removed" << endl;
                break;
            }
        }
        if (!found) {
            throw LibraryException("Book not there to remove");
        }
    }

    void borrowBook(int id) override {
        if (books.empty()) {
            throw LibraryException("No books available");
        }
        bool bookFound = false;
        for (Book& book : books) {
            if (book.getId() == id) {
                bookFound = true;
                if (!book.isAvailable()) {
                    throw LibraryException("Book is not available to borrow");
                } else {
                    book.setAvailable(false);
                    cout << "Book Borrowed with id " + to_string(id) + " successfully" << endl;
                    break;
                }
            }
        }

        if (!bookFound) {
            throw LibraryException("Book with id " + to_string(id) + " not found.");
        }
    }

    void returnBook(int id) override {
        bool found = false;
        for (Book& book : books) {
            if (book.getId() == id) {
                book.setAvailable(true);
                found = true;
                cout <<"Book Returned with id " + to_string(id) + " successfully" << endl;
                break;
            }
        }
        if (!found) {
            throw LibraryException("Book with id " + to_string(id) + " not found.");
        }
    }

    void showBook() override {
        if (books.empty()) {
            throw LibraryException("No books available");
        }
        for (const Book& book : books) {
            cout << book << endl;
        }
    }
};

int main() {
    try {
        Library lib;
        lib.addBook(1, "Mathametics", "Rd sharma");
        lib.addBook(2, "Physics", "hc verma");
        lib.addBook(3,"Rich Dad Poor Dad","Robert Kiyosaki");
        cout<<"----------------"<<endl;

        lib.borrowBook(1);
        lib.returnBook(1);
        cout<<"----------------"<<endl;

        lib.showBook();
        cout<<"----------------"<<endl;

        lib.removeBook(2);
        cout<<"----------------"<<endl;
        lib.showBook();
    }
    catch (const LibraryException& e) {
        cout << e.what() << endl;
    }

    return 0;
}