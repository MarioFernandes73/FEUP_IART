PRAGMA foreign_keys = ON;

drop table if exists Student;
drop table if exists Exam;
drop table if exists Subscription;
drop table if exists Epoch;

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

INSERT INTO Student (id_student,name) VALUES (1,"Nash Bender"),(2,"Nyssa Schmidt"),(3,"Lance Rios"),(4,"Talon Kaufman"),(5,"Gavin Berry"),(6,"Judah Trujillo"),(7,"Rosalyn Frazier"),(8,"Medge Schultz"),(9,"Yuli Bennett"),(10,"Eric Shelton");
INSERT INTO Student (id_student,name) VALUES (11,"Sopoline Barlow"),(12,"Priscilla York"),(13,"Nolan Campos"),(14,"Casey Lynch"),(15,"Leonard Spencer"),(16,"Edward Juarez"),(17,"Melissa Booker"),(18,"Peter Hughes"),(19,"Xena Gallegos"),(20,"Dustin Maddox");
INSERT INTO Student (id_student,name) VALUES (21,"Lois Morin"),(22,"Lilah Vance"),(23,"Brenda Mcneil"),(24,"Briar Warren"),(25,"Alyssa Franklin"),(26,"Adam Hendricks"),(27,"Hadley Wright"),(28,"Salvador Clayton"),(29,"Lucius Hayes"),(30,"Herman Wiley");
INSERT INTO Student (id_student,name) VALUES (31,"Cruz Pope"),(32,"Melinda Peterson"),(33,"Nicole Marshall"),(34,"Xavier Francis"),(35,"Phelan Lester"),(36,"Vaughan Schneider"),(37,"Jared Morrow"),(38,"Callie Miles"),(39,"Coby Kemp"),(40,"Gemma Lindsey");
INSERT INTO Student (id_student,name) VALUES (41,"Ruby King"),(42,"Cassady Mccall"),(43,"Oscar Witt"),(44,"Inga Benson"),(45,"Risa Butler"),(46,"Quon Andrews"),(47,"Lacy Talley"),(48,"Diana Rush"),(49,"Malcolm Joseph"),(50,"Hayfa Ray");
INSERT INTO Student (id_student,name) VALUES (51,"Dorothy Macias"),(52,"Macaulay Benjamin"),(53,"Buffy Phillips"),(54,"Charles Kinney"),(55,"Armando Swanson"),(56,"Hector Rodriquez"),(57,"Judah Alvarez"),(58,"Myles Goodwin"),(59,"Jenna Alexander"),(60,"Rylee Everett");
INSERT INTO Student (id_student,name) VALUES (61,"Amery Hopkins"),(62,"Ciara Ayers"),(63,"Harding Newton"),(64,"Oprah Franks"),(65,"Cassady Anderson"),(66,"Hanae Rosario"),(67,"Plato Walls"),(68,"Laura Bright"),(69,"Chandler Herrera"),(70,"Gemma Valentine");
INSERT INTO Student (id_student,name) VALUES (71,"Alexander Bruce"),(72,"Meghan Fry"),(73,"Yoko Bass"),(74,"Debra Paul"),(75,"Andrew Valencia"),(76,"Jacob Goff"),(77,"Amelia Mosley"),(78,"Camden Conner"),(79,"Mikayla Mosley"),(80,"Tyler Myers");
INSERT INTO Student (id_student,name) VALUES (81,"Hasad Stafford"),(82,"Alika Koch"),(83,"Meghan Kennedy"),(84,"Shafira Mcdonald"),(85,"Janna Moses"),(86,"Nyssa Vasquez"),(87,"Janna Steele"),(88,"Malik Gibbs"),(89,"Joel Eaton"),(90,"Hop Johnson");
INSERT INTO Student (id_student,name) VALUES (91,"Zane Peters"),(92,"Sylvia Watkins"),(93,"Thane Pittman"),(94,"Jane Curtis"),(95,"Caldwell Hardin"),(96,"Rinah Bridges"),(97,"Mercedes Collins"),(98,"Serina Banks"),(99,"Ava Conway"),(100,"Uriel Cain");
INSERT INTO Student (id_student,name) VALUES (101,"David Oneill"),(102,"Micah Barron"),(103,"Wyoming Anderson"),(104,"Jelani Barron"),(105,"Reagan Cardenas"),(106,"Todd Wyatt"),(107,"Signe Stewart"),(108,"Alexa Le"),(109,"Jermaine Hunt"),(110,"Price Colon");
INSERT INTO Student (id_student,name) VALUES (111,"Gail Moran"),(112,"Ivan Cortez"),(113,"Sydnee Blevins"),(114,"Tamara Dejesus"),(115,"Hyatt Mcleod"),(116,"Mercedes Payne"),(117,"Colorado Nielsen"),(118,"Devin Green"),(119,"Summer Tyler"),(120,"Ila Fry");
INSERT INTO Student (id_student,name) VALUES (121,"Grace Hodges"),(122,"Brynne Romero"),(123,"Mechelle Gibson"),(124,"Tallulah Delaney"),(125,"Basil Mclean"),(126,"Ray Dominguez"),(127,"Jelani Beasley"),(128,"Blaine Walls"),(129,"Martha Henry"),(130,"Neve Lamb");
INSERT INTO Student (id_student,name) VALUES (131,"Briar Daniel"),(132,"Deborah Ferguson"),(133,"Reagan Craft"),(134,"Callum Blackburn"),(135,"Mechelle Barnes"),(136,"Harding Booker"),(137,"Justin Brock"),(138,"Maryam Estes"),(139,"Alana Roach"),(140,"Linda Hines");
INSERT INTO Student (id_student,name) VALUES (141,"Althea Russell"),(142,"Abel Beasley"),(143,"Britanney Snow"),(144,"Chancellor Wolf"),(145,"Martha Guy"),(146,"Serena Bates"),(147,"Martina Harris"),(148,"Ori Black"),(149,"Signe Garrison"),(150,"John Price");
INSERT INTO Student (id_student,name) VALUES (151,"Reese Lara"),(152,"Blaine Clarke"),(153,"Kevin Anthony"),(154,"Mikayla Miranda"),(155,"Victor Madden"),(156,"Hamilton Olsen"),(157,"Renee Day"),(158,"Maia Lawrence"),(159,"Maxwell Hall"),(160,"Tatyana Daugherty");
INSERT INTO Student (id_student,name) VALUES (161,"Ivory Munoz"),(162,"Phillip Franklin"),(163,"Mari Lara"),(164,"Maggie Alexander"),(165,"Simon Gutierrez"),(166,"Inez Morris"),(167,"Hayley William"),(168,"Logan Lawson"),(169,"Bo Baird"),(170,"Zahir Figueroa");
INSERT INTO Student (id_student,name) VALUES (171,"Armand Brooks"),(172,"Lunea Bentley"),(173,"Nolan Guerra"),(174,"Kirestin Wiley"),(175,"Guinevere Ford"),(176,"Paki Mckee"),(177,"Sybil Sullivan"),(178,"Evelyn Blankenship"),(179,"Ronan Poole"),(180,"Ivy Poole");
INSERT INTO Student (id_student,name) VALUES (181,"Maryam Salinas"),(182,"Cassidy Vaughan"),(183,"Herman Austin"),(184,"Fuller Brennan"),(185,"Rhea Jefferson"),(186,"Lewis Newman"),(187,"Charlotte Hardin"),(188,"Dominique Pierce"),(189,"Abdul Knapp"),(190,"Hiroko Freeman");
INSERT INTO Student (id_student,name) VALUES (191,"Noelle Duffy"),(192,"Elliott Roman"),(193,"Medge Small"),(194,"Chanda Knapp"),(195,"Colt Valenzuela"),(196,"Sylvester Robertson"),(197,"Macy Blackburn"),(198,"Geoffrey Horne"),(199,"Craig Conley"),(200,"Zenaida Kaufman");

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

INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,1,71),(1,1,196),(1,1,37),(1,1,137),(1,1,133),(1,1,123),(1,1,80),(1,1,100),(1,1,8),(1,1,169);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,1,154),(1,1,65),(1,1,182),(1,1,127),(1,1,174),(1,1,74),(1,1,89),(1,1,41),(1,1,4),(1,1,107);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,2,71),(1,2,196),(1,2,37),(1,2,137),(1,2,133),(1,2,123),(1,2,80),(1,2,100),(1,2,8),(1,2,169);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,2,154),(1,2,65),(1,2,182),(1,2,127),(1,2,136),(1,2,74),(1,2,89),(1,2,41),(1,2,4),(1,2,107);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,3,71),(1,3,196),(1,3,37),(1,3,137),(1,3,133),(1,3,123),(1,3,80),(1,3,100),(1,3,8),(1,3,169);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,3,154),(1,3,65),(1,3,182),(1,3,127),(1,3,136),(1,3,74),(1,3,89),(1,3,41),(1,3,4),(1,3,107);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,4,71),(1,4,196),(1,4,37),(1,4,137),(1,4,133),(1,4,123),(1,4,80),(1,4,100),(1,4,8),(1,4,169);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,4,154),(1,4,65),(1,4,182),(1,4,127),(1,4,174),(1,4,74),(1,4,89),(1,4,41),(1,4,4),(1,4,107);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,5,198),(1,5,191),(1,5,146),(1,5,59),(1,5,179),(1,5,52),(1,5,159),(1,5,119),(1,5,172),(1,5,124);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,5,106),(1,5,22),(1,5,73),(1,5,167),(1,5,46),(1,5,142),(1,5,114),(1,5,61),(1,5,79),(1,5,35);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,6,198),(1,6,191),(1,6,146),(1,6,59),(1,6,179),(1,6,52),(1,6,159),(1,6,119),(1,6,172),(1,6,124);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,6,106),(1,6,22),(1,6,73),(1,6,167),(1,6,46),(1,6,142),(1,6,21),(1,6,61),(1,6,79),(1,6,35);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,7,198),(1,7,191),(1,7,146),(1,7,59),(1,7,179),(1,7,52),(1,7,159),(1,7,119),(1,7,172),(1,7,124);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,7,106),(1,7,22),(1,7,73),(1,7,167),(1,7,46),(1,7,142),(1,7,132),(1,7,61),(1,7,79),(1,7,35);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,8,198),(1,8,191),(1,8,146),(1,8,59),(1,8,179),(1,8,52),(1,8,159),(1,8,119),(1,8,172),(1,8,124);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,8,106),(1,8,22),(1,8,73),(1,8,167),(1,8,46),(1,8,142),(1,8,114),(1,8,61),(1,8,79),(1,8,35);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,9,151),(1,9,2),(1,9,165),(1,9,175),(1,9,153),(1,9,200),(1,9,111),(1,9,16),(1,9,20),(1,9,35);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,9,45),(1,9,42),(1,9,162),(1,9,192),(1,9,152),(1,9,164),(1,9,25),(1,9,44),(1,9,163),(1,9,70);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,10,151),(1,10,2),(1,10,165),(1,10,175),(1,10,153),(1,10,200),(1,10,111),(1,10,16),(1,10,20),(1,10,35);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,10,45),(1,10,42),(1,10,162),(1,10,192),(1,10,152),(1,10,164),(1,10,25),(1,10,44),(1,10,60),(1,10,70);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,18,152),(1,14,60),(1,16,148),(1,16,17),(1,13,143),(1,15,14),(1,17,40),(1,13,138),(1,12,139),(1,17,136);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,11,159),(1,11,147),(1,17,96),(1,11,136),(1,15,162),(1,18,15),(1,18,107),(1,16,111),(1,17,82),(1,14,156);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,13,184),(1,17,10),(1,17,124),(1,11,77),(1,16,4),(1,16,162),(1,15,196),(1,12,138),(1,11,137),(1,17,118);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,18,103),(1,16,143),(1,16,183),(1,14,125),(1,16,169),(1,18,26),(1,12,34),(1,14,180),(1,17,197),(1,12,55);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,15,177),(1,11,140),(1,11,143),(1,14,108),(1,15,42),(1,14,146),(1,11,132),(1,16,19),(1,17,73),(1,16,9);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,13,200),(1,17,107),(1,16,161),(1,13,10),(1,13,78),(1,13,9),(1,11,171),(1,16,126),(1,16,151),(1,18,24);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,18,197),(1,14,35),(1,16,189),(1,14,56),(1,18,40),(1,18,142),(1,14,66),(1,12,165),(1,14,68),(1,13,136);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,18,120),(1,18,132),(1,12,163),(1,13,114),(1,16,156),(1,17,106),(1,17,36),(1,14,199),(1,16,178),(1,12,49);

INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,1,71),(2,1,196),(2,1,37),(2,1,137),(2,1,133),(2,1,123),(2,1,80),(2,1,100),(2,1,8),(2,1,169);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,2,154),(2,2,82),(2,2,52),(2,2,224),(2,2,174),(2,2,74),(2,2,89),(2,2,41),(2,2,4),(2,2,107);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,3,101),(2,3,70),(2,3,31),(2,3,64),(2,3,131),(2,3,189),(2,3,58),(2,3,9),(2,3,149),(2,3,72);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,4,71),(2,4,196),(2,4,52),(2,4,224),(2,4,131),(2,4,189),(2,4,80),(2,4,100),(2,4,4),(2,4,107);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,5,198),(2,5,191),(2,5,146),(2,5,59),(2,5,179),(2,5,52),(2,5,159),(2,5,119),(2,5,172),(2,5,124);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,6,106),(2,6,22),(2,6,73),(2,6,167),(2,6,46),(2,6,142),(2,6,114),(2,6,61),(2,6,154),(2,6,35);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,7,130),(2,7,131),(2,7,59),(2,7,177),(2,7,29),(2,7,141),(2,7,114),(2,7,114),(2,7,173),(2,7,75);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,8,198),(2,8,191),(2,8,73),(2,8,167),(2,8,29),(2,8,141),(2,8,159),(2,8,119),(2,8,154),(2,8,35);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,9,151),(2,9,2),(2,9,165),(2,9,175),(2,9,59),(2,9,198),(2,9,189),(2,9,61),(2,9,25),(2,9,35);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,10,52),(2,10,42),(2,10,119),(2,10,192),(2,10,152),(2,10,164),(2,10,25),(2,10,44),(2,10,163),(2,10,70);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,18,89),(2,14,60),(2,16,148),(2,16,17),(2,13,143),(2,15,14),(2,17,40),(2,13,138),(2,12,139),(2,17,136);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,11,159),(2,12,147),(2,17,96),(2,11,136),(2,15,162),(2,18,15),(2,17,107),(2,16,191),(2,17,82),(2,14,156);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,13,184),(2,17,10),(2,17,124),(2,11,77),(2,16,4),(2,16,162),(2,15,196),(2,12,138),(2,11,137),(2,17,118);

INSERT INTO Epoch VALUES('Normal','2017-05-08','2017-05-26');
INSERT INTO Epoch VALUES('Recurso','2017-05-29','2017-06-16');