Lab 8: BST and Hash Tables Part 2 (100 pts)

Due Tuesday, November 21 at 11:20am on Canvas


Pair Programming Extra Credit Opportunity (5 pts)
If you and/or your partner has not done so already, watch the video and answer the questions on this worksheet (only one time per quarter).
Both partners fill in, sign and date the pair programming contract (once per assignment).
Upload the document(s) along with your Lab to Canvas.
Only ONE partner submits the lab assignment on Canvas. Please make sure both your names are on it.

Part 1: HashTable.h
Copy and paste the following code into a header file named HashTable.h
Note that we are now declaring an array of BSTs rather than an array of Lists in the private section of the class.
Please do not alter this file in any way or you may not receive credit for this lab
For this lab, you will implement each of the hash table functions whose prototypes are in HashTable.h.
Write these functions in a file named HashTable.cpp.
Note that you will update your HashTable.cpp file from Lab 7 to call the BST functions, not the List functions.
Why will this change give you a slight advantage in efficiency?
What other advantage does using an array of BSTs rather than an array of Lists offer?
Please test each hash table function as you write it in a file named HashTest.cpp (which should include your main function).
Additionally, you will need to include your BST.h and the files Book.h and Book.cpp in the same project as your Hash Table.
To keep things simple, the size of the table is defined to be only 10 for this assignment. According to the rule of thumb defined in class, the size should be changed for your project to be roughly 2-3 times the number of projected entries to the table.

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <string>
#include "BST.h"
#include "Book.h"
using namespace std;

class HashTable {
public:
    /**Constructors*/

    HashTable(){}
    //constructor

    ~HashTable(){}
    //destructor


    /**Access Functions*/

    int hash(string key) const;
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: title + author

    int countBucket(int index) const;
    //counts the number of Books at this index
    //returns the count
    //pre: 0<= index < SIZE

    int search(Book b) const;
    //Searches for b in the table
    //returns the index at which b is located
    //returns -1 if b is not in the table

    /**Manipulation Procedures*/

    void insert(Book b);
    //inserts a new book into the table
    //calls the hash function on the key to determine
    //the correct bucket

    void remove(Book b);
    //removes b from the table
    //calls the hash function on the key to determine
    //the correct bucket
    //pre: b is in the table

    /**Additional Functions*/

    void printBucket(ostream& out, int index) const;
    //Prints all the books at index according to inOrderPrint
    //pre: 0<= index < SIZE
    //Should print according to the following formula:
    //Prints each book at that index in the format:
    //<title> by <author>
    //$<X.XX>
    //ISBN#: <isbn>
    //followed by a blank line

    void printTable(ostream& out) const;
    //Prints the first book at each index
    //along with a count of the total books
    //at each index by calling count_bucket
    //as a helper function
    //Prints in the format:
    //Books in the Catalogue:
    //<new line>
    //Group <bucket>
    //<title> by <author>
    //$<X.XX>
    //ISBN: <isbn>
    //+<number of elements at this index> -1 more similar book(s)
    //<new line><new line><new line>

private:
    static const int SIZE = 10;
    BST<Book> Table[SIZE];
};

#endif /* HASHTABLE_H_ */

Part 2: Catalogue.cpp
Working with the catalogue.txt file provided above, write a user interface that works like the example below.
This user interface must use a parallel BST and hash table into which you will insert the books from catalogue.txt to pre-populate the catalogue.
Catalogue.cpp must contain a main function that offers a list of options to the user.
Option 1: Browse catalogue calls the preOrderPrint function of the BST to display the records in order. Note that you may alter the preOrderPrint function from BST.h so that each element prints on a separate line.
Option 2: Insert a new book calls the insert function for both the hash table and BST to insert a new book in both structures.
Option 3: Remove a book calls the remove function for both the hash table and BST to remove the book from both structures.
Option 4: Search for a book calls the search function of the hash table (not the BST).
Option 5: Writes the current contents of the BST to catalogue.txt before exiting, with the message "Happy Reading!"
After the user makes a selection, the menu should loop around again to allow the user to continue working with the hash table of books.
Additionally, you should add some error checking if the user enters an option other than 1-5 or enters text instead of a numerical input for the option number.
Please see the example output below for more information.
Welcome to the Best Reads App!

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 8

Invalid input.

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 10

Invalid input.

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: one

Please enter numbers not letters

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: two

Please enter numbers not letters

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 1

Here is an alphabetical list of the books in our catalogue:

A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

Fangirl by Rainbow Rowell
$10.79
ISBN#: 2413725

Jane Eyre by Charlotte Bronte
$7.90
ISBN#: 2345674

Lady Audley's Secret by Mary Elizabeth Braddon
$5.50
ISBN#: 1212134

Middlemarch by George Elliot
$12.50
ISBN#: 1256743

Murder on the Orient Express by Agatha Christie
$2.99
ISBN#: 9837583

Our Souls at Night by Kent Haruf
$11.99
ISBN#: 7847489

Outlander by Diana Galbadon
$19.95
ISBN#: 5466565

Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

Rebecca by Daphe Dumaurier
$5.50
ISBN#: 3242382

The Hunger Games by Suzanne Collins
$6.90
ISBN#: 4232322

The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789


What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 2

Enter the title: Harry Potter
Enter the author: J.K. Rowling
Enter the price: 8.99
Enter the isbn: 4222222

Harry Potter has been added to the catalogue

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 1

Here is an alphabetical list of the books in our catalogue:

A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

Fangirl by Rainbow Rowell
$10.79
ISBN#: 2413725

Harry Potter by J.K. Rowling
$8.99
ISBN#: 4222222

Jane Eyre by Charlotte Bronte
$7.90
ISBN#: 2345674

Lady Audley's Secret by Mary Elizabeth Braddon
$5.50
ISBN#: 1212134

Middlemarch by George Elliot
$12.50
ISBN#: 1256743

Murder on the Orient Express by Agatha Christie
$2.99
ISBN#: 9837583

Our Souls at Night by Kent Haruf
$11.99
ISBN#: 7847489

Outlander by Diana Galbadon
$19.95
ISBN#: 5466565

Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

Rebecca by Daphe Dumaurier
$5.50
ISBN#: 3242382

The Hunger Games by Suzanne Collins
$6.90
ISBN#: 4232322

The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789


What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 3

Enter the title of the book to remove: Murder on the Orient Express
Enter the author: Agatha Christie
true

Murder on the Orient Express has been removed from the catalogue

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 1

Here is an alphabetical list of the books in our catalogue:

A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

Fangirl by Rainbow Rowell
$10.79
ISBN#: 2413725

Harry Potter by J.K. Rowling
$8.99
ISBN#: 4222222

Jane Eyre by Charlotte Bronte
$7.90
ISBN#: 2345674

Lady Audley's Secret by Mary Elizabeth Braddon
$5.50
ISBN#: 1212134

Middlemarch by George Elliot
$12.50
ISBN#: 1256743

Our Souls at Night by Kent Haruf
$11.99
ISBN#: 7847489

Outlander by Diana Galbadon
$19.95
ISBN#: 5466565

Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

Rebecca by Daphe Dumaurier
$5.50
ISBN#: 3242382

The Hunger Games by Suzanne Collins
$6.90
ISBN#: 4232322

The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789


What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 4

Enter the title of the book: Murder on the Orient Express
Enter the author: Agatha Christie

Murder on the Orient Express is not in the catalogue

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 4

Enter the title of the book: Harry Potter
Enter the author: J.K. Rowling

Harry Potter is in the catalogue

What would you like to do?
1. Browse catalogue by title
2. Insert a new book
3. Remove a book
4. Search for a book
5. Quit

Enter your choice: 5


Happy reading!



The above should output the current catalogue to catalogue.txt using inOrderPrint:



A Face like Glass by Frances Hardinge
$15.95
ISBN#: 4455443

A Room with a View by E.M. Forster
$7.50
ISBN#: 1177889

Bleak House by Charles Dickens
$8.99
ISBN#: 3567897

Fangirl by Rainbow Rowell
$10.79
ISBN#: 2413725

Harry Potter by J.K. Rowling
$8.99
ISBN#: 4222222

Jane Eyre by Charlotte Bronte
$7.90
ISBN#: 2345674

Lady Audley's Secret by Mary Elizabeth Braddon
$5.50
ISBN#: 1212134

Middlemarch by George Elliot
$12.50
ISBN#: 1256743

Our Souls at Night by Kent Haruf
$11.99
ISBN#: 7847489

Outlander by Diana Galbadon
$19.95
ISBN#: 5466565

Ramona Blue by Julie Murphy
$9.99
ISBN#: 9328311

Rebecca by Daphe Dumaurier
$5.50
ISBN#: 3242382

The Hunger Games by Suzanne Collins
$6.90
ISBN#: 4232322

The Time in Between by Maria Duenas
$9.86
ISBN#: 4345344

The Woman in White by Wilkie Collins
$10.75
ISBN#: 3256789



What to Submit

Once you are certain your program is working as shown above, upload your files to Canvas under Lab 8.
You must submit the following files: Book.cpp, HashTable.cpp, HashTest.cpp, BST.h, Catalogue.cpp
Please do not submit HashTable.h or Book.h or catalogue.txt as I will assume that these files are unaltered from the ones provided (no points if you alter these header files).
You will receive 50 points for the updated HashTable.cpp.
You will receive 50 points for a correct Catalogue.cpp that works identically to the example above.
