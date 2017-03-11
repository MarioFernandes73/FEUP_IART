PRAGMA foreign_keys = ON;


drop table if exists Student;
drop table if exists Exam;

CREATE TABLE Student (
id_student INTEGER PRIMARY KEY,
name VARCHAR NOT NULL
);


CREATE TABLE Exam (
id_exam INTEGER PRIMARY KEY,
name VARCHAR NOT NULL
);


INSERT INTO Student VALUES(1,'Cat');
INSERT INTO Student VALUES(2,'Ines');
INSERT INTO Student VALUES(3,'Mario');

INSERT INTO Exam VALUES(1,'IART');
INSERT INTO Exam VALUES(2,'SDIS');