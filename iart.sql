PRAGMA foreign_keys = ON;


drop table if exists Student;

CREATE TABLE Student (
id_student INTEGER PRIMARY KEY,
name VARCHAR NOT NULL
);


INSERT INTO Student VALUES(1,'Cat');