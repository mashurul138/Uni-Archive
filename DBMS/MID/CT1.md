1. Create the following tables with the following constraints.

books (book_id, title, author, genre, price):  
a. Make book_id (int) the primary key.   
b. title and author (varchar [30]) cannot be NULL.   
c. Set price (float) with a default value of 500.00.  

    CREATE TABLE books (
    book_id int PRIMARY KEY,
    title varchar(30) NOT null,
    author varchar(30) NOT null,
    genre varchar(30),
    price float DEFAULT 500.00
    )

members (member_id, name, email):  
a. Make member_id (int) the primary key.   
b. name and email (varchar [30]) must be unique and cannot be NULL.   

    CREATE TABLE members (
    memebr_id int PRIMARY KEY,
    name varchar(30) NOT null UNIQUE,
    email varchar(30) NOT null UNIQUE
    )

book_issues (issue_id, member_id, book_id, issue_date):  
a. Make issue_id (int) the primary key.   
b. Set member_id as a foreign key referencing   

    CREATE TABLE book_issues (
    issue_id int PRIMARY KEY,
    member_id int,
    book_id int,
    issue_date date
    )
    