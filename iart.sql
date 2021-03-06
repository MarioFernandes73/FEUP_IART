PRAGMA foreign_keys = ON;

drop table if exists Student;
drop table if exists Exam;
drop table if exists Subscription;

CREATE TABLE Student (
id_student INTEGER PRIMARY KEY,
name VARCHAR NOT NULL
);

CREATE TABLE Exam (
id_exam INTEGER PRIMARY KEY,
name VARCHAR NOT NULL,
year INTEGER NOT NULL,
duration INTEGER NOT NULL
);

CREATE TABLE Subscription (
id_epoch INTEGER,
id_exam INTEGER,
id_student INTEGER
);

CREATE TABLE Epoch (
name VARCHAR NOT NULL,
date1 DATETIME,
date2 DATETIME
);

INSERT INTO Student VALUES(1,'Cat');
INSERT INTO Student VALUES(2,'Ines');
INSERT INTO Student VALUES(3,'Mario');
INSERT INTO Student VALUES(4,'Andreia');
INSERT INTO Student VALUES(5,'Edu');
INSERT INTO Student VALUES(6,'Queiros');
INSERT INTO Student VALUES(7,'Nuno');

INSERT INTO Exam VALUES(1,'MEST',1,1);
INSERT INTO Exam VALUES(2,'PROG',1,2);
INSERT INTO Exam VALUES(3,'FISI1',1,3);
INSERT INTO Exam VALUES(4,'MPCP',1,1);
INSERT INTO Exam VALUES(5,'BDAD',2,2);
INSERT INTO Exam VALUES(6,'CAL',2,3);
INSERT INTO Exam VALUES(7,'CGRA',2,1);
INSERT INTO Exam VALUES(8,'SOPE',2,2);
INSERT INTO Exam VALUES(9,'IART',3,3);
INSERT INTO Exam VALUES(10,'SDIS',3,1);
INSERT INTO Exam VALUES(11,'TBDA',4,2);
INSERT INTO Exam VALUES(12,'MARK',4,3);
INSERT INTO Exam VALUES(13,'TDIN',4,1);
INSERT INTO Exam VALUES(14,'CMO',4,2);
INSERT INTO Exam VALUES(15,'SSIN',4,3);
INSERT INTO Exam VALUES(16,'AGRS',4,1);
INSERT INTO Exam VALUES(17,'CPAR',4,2);
INSERT INTO Exam VALUES(18,'MNSE',4,3);

INSERT INTO Subscription VALUES(1,1,7);
INSERT INTO Subscription VALUES(1,1,1);
INSERT INTO Subscription VALUES(1,2,7);
INSERT INTO Subscription VALUES(1,2,2);
INSERT INTO Subscription VALUES(1,3,7);
INSERT INTO Subscription VALUES(1,3,5);
INSERT INTO Subscription VALUES(1,4,7);
INSERT INTO Subscription VALUES(1,4,3);
INSERT INTO Subscription VALUES(1,5,6);
INSERT INTO Subscription VALUES(1,5,2);
INSERT INTO Subscription VALUES(1,6,6);
INSERT INTO Subscription VALUES(1,6,5);
INSERT INTO Subscription VALUES(1,7,6);
INSERT INTO Subscription VALUES(1,7,3);
INSERT INTO Subscription VALUES(1,8,6);
INSERT INTO Subscription VALUES(1,8,5);
INSERT INTO Subscription VALUES(1,8,4);
INSERT INTO Subscription VALUES(1,9,1);
INSERT INTO Subscription VALUES(1,9,2);
INSERT INTO Subscription VALUES(1,9,3);
INSERT INTO Subscription VALUES(1,9,4);
INSERT INTO Subscription VALUES(1,9,5);
INSERT INTO Subscription VALUES(1,10,1);
INSERT INTO Subscription VALUES(1,10,2);
INSERT INTO Subscription VALUES(1,10,3);
INSERT INTO Subscription VALUES(1,10,5);
INSERT INTO Subscription VALUES(1,11,4);

INSERT INTO Epoch VALUES('Normal','2017-05-08','2017-05-26');
INSERT INTO Epoch VALUES('Recurso','2017-05-29','2017-05-16');