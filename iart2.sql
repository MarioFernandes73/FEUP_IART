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

INSERT INTO Student (id_student,name) VALUES (1,"Hedley"),(2,"Quon"),(3,"Vielka"),(4,"Ariana"),(5,"Wendy"),(6,"Rhiannon"),(7,"Noelani"),(8,"Patrick"),(9,"Karleigh"),(10,"Byron");
INSERT INTO Student (id_student,name) VALUES (11,"Jeremy"),(12,"Kellie"),(13,"Marcia"),(14,"Murphy"),(15,"Xanthus"),(16,"Indigo"),(17,"Eleanor"),(18,"Audrey"),(19,"Conan"),(20,"Reed");
INSERT INTO Student (id_student,name) VALUES (21,"David"),(22,"Britanney"),(23,"Quinlan"),(24,"Daryl"),(25,"Kiayada"),(26,"Shellie"),(27,"Karen"),(28,"Margaret"),(29,"Timon"),(30,"Paul");
INSERT INTO Student (id_student,name) VALUES (31,"Ezra"),(32,"Marcia"),(33,"Martena"),(34,"Kevin"),(35,"Hilel"),(36,"Harriet"),(37,"Nasim"),(38,"Natalie"),(39,"Kathleen"),(40,"Allistair");
INSERT INTO Student (id_student,name) VALUES (41,"Grant"),(42,"Nasim"),(43,"Clare"),(44,"Fletcher"),(45,"Brenna"),(46,"Kirk"),(47,"Hadassah"),(48,"Macon"),(49,"Wallace"),(50,"Ciaran");
INSERT INTO Student (id_student,name) VALUES (51,"Gloria"),(52,"Cooper"),(53,"Porter"),(54,"Imelda"),(55,"Hillary"),(56,"Gloria"),(57,"Jana"),(58,"Kirk"),(59,"Christian"),(60,"Kato");
INSERT INTO Student (id_student,name) VALUES (61,"Stuart"),(62,"Heather"),(63,"Upton"),(64,"Chantale"),(65,"Jillian"),(66,"Dieter"),(67,"Dane"),(68,"Shad"),(69,"Brett"),(70,"Adrienne");
INSERT INTO Student (id_student,name) VALUES (71,"Kieran"),(72,"Yardley"),(73,"Shad"),(74,"Stephen"),(75,"Gisela"),(76,"Charde"),(77,"Pandora"),(78,"Zephania"),(79,"Zeph"),(80,"Mohammad");
INSERT INTO Student (id_student,name) VALUES (81,"Aiko"),(82,"Sophia"),(83,"Urielle"),(84,"Sandra"),(85,"Camden"),(86,"Gretchen"),(87,"Wayne"),(88,"Erica"),(89,"Keely"),(90,"Liberty");
INSERT INTO Student (id_student,name) VALUES (91,"Sage"),(92,"Vladimir"),(93,"Kevin"),(94,"Xenos"),(95,"Uriah"),(96,"Xantha"),(97,"Sean"),(98,"Craig"),(99,"Gil"),(100,"Jonas");
INSERT INTO Student (id_student,name) VALUES (101,"Arthur"),(102,"Camille"),(103,"Bertha"),(104,"Amal"),(105,"Gretchen"),(106,"Arsenio"),(107,"Shafira"),(108,"Giacomo"),(109,"Keaton"),(110,"Michelle");
INSERT INTO Student (id_student,name) VALUES (111,"Xerxes"),(112,"Tatiana"),(113,"Xaviera"),(114,"Phelan"),(115,"Ali"),(116,"Casey"),(117,"Timothy"),(118,"Shaine"),(119,"Deanna"),(120,"Paki");
INSERT INTO Student (id_student,name) VALUES (121,"Shaine"),(122,"Lavinia"),(123,"Selma"),(124,"Anika"),(125,"Sharon"),(126,"Bianca"),(127,"Eric"),(128,"Anika"),(129,"Isaiah"),(130,"Brock");
INSERT INTO Student (id_student,name) VALUES (131,"Colby"),(132,"Madaline"),(133,"Arden"),(134,"Jennifer"),(135,"Lareina"),(136,"Jermaine"),(137,"Lucius"),(138,"James"),(139,"Nevada"),(140,"Katelyn");
INSERT INTO Student (id_student,name) VALUES (141,"Preston"),(142,"Curran"),(143,"Remedios"),(144,"Keane"),(145,"Joshua"),(146,"Nayda"),(147,"Octavius"),(148,"Julian"),(149,"Alan"),(150,"Boris");
INSERT INTO Student (id_student,name) VALUES (151,"Lucius"),(152,"Isaac"),(153,"August"),(154,"Honorato"),(155,"Azalia"),(156,"Karly"),(157,"Slade"),(158,"Violet"),(159,"Jermaine"),(160,"Keane");
INSERT INTO Student (id_student,name) VALUES (161,"Brielle"),(162,"Gray"),(163,"September"),(164,"Julie"),(165,"Tucker"),(166,"Reese"),(167,"Lee"),(168,"Brendan"),(169,"Sarah"),(170,"Justina");
INSERT INTO Student (id_student,name) VALUES (171,"Evan"),(172,"Galena"),(173,"Signe"),(174,"Halla"),(175,"Adam"),(176,"Aurelia"),(177,"Damian"),(178,"Tate"),(179,"Shafira"),(180,"Hiroko");
INSERT INTO Student (id_student,name) VALUES (181,"Belle"),(182,"Austin"),(183,"Raphael"),(184,"Baxter"),(185,"Halee"),(186,"Forrest"),(187,"Rigel"),(188,"Shea"),(189,"Quinn"),(190,"Chancellor");
INSERT INTO Student (id_student,name) VALUES (191,"Herman"),(192,"Inez"),(193,"Thomas"),(194,"Lynn"),(195,"Audra"),(196,"Jelani"),(197,"Aline"),(198,"Fleur"),(199,"Jesse"),(200,"Katelyn");



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

INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,14,93),(2,11,146),(1,9,42),(1,15,112),(1,11,144),(1,13,95),(2,4,111),(2,5,192),(2,7,142),(1,6,173);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,11,142),(2,3,25),(1,10,40),(2,9,158),(1,3,200),(2,10,137),(1,6,137),(1,12,6),(2,7,192),(2,5,113);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,3,13),(2,12,104),(1,13,112),(1,2,7),(1,17,162),(1,15,10),(1,10,109),(1,11,102),(1,3,141),(2,10,4);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,2,116),(2,3,115),(1,10,39),(1,1,141),(1,16,147),(1,13,175),(2,7,112),(1,11,198),(1,10,160),(1,12,67);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,6,144),(1,14,96),(1,6,75),(1,3,138),(2,16,140),(1,13,47),(2,12,35),(1,8,13),(2,14,41),(1,13,84);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,16,6),(1,6,163),(1,9,39),(2,5,87),(1,6,12),(2,3,5),(1,15,74),(2,1,3),(2,3,32),(1,16,1);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,14,24),(2,8,112),(1,5,129),(2,10,148),(1,18,117),(1,5,91),(1,15,164),(1,8,27),(2,9,57),(2,14,125);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,16,117),(2,6,37),(2,18,96),(2,3,167),(1,14,85),(1,15,104),(2,1,30),(2,14,88),(1,7,14),(2,2,60);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,8,112),(2,7,39),(1,15,48),(1,13,181),(1,15,104),(2,5,148),(2,18,172),(1,15,157),(1,17,176),(1,18,153);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,11,172),(1,11,16),(2,5,95),(1,15,145),(2,1,58),(2,7,89),(1,14,98),(2,4,103),(1,9,64),(1,16,132);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,10,77),(2,11,60),(2,10,68),(1,16,166),(1,3,145),(1,1,162),(1,5,31),(1,15,25),(2,16,126),(1,15,47);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,2,106),(1,18,69),(2,1,1),(2,1,116),(1,7,76),(2,10,126),(1,8,54),(2,10,117),(2,9,154),(1,6,135);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,17,54),(1,2,54),(1,9,46),(1,16,72),(2,2,10),(1,17,159),(1,6,79),(2,8,129),(1,17,155),(1,17,84);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,18,73),(2,8,109),(1,6,174),(1,10,79),(2,11,121),(2,8,164),(1,9,31),(1,9,71),(2,17,190),(1,5,28);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,15,144),(2,3,77),(1,7,51),(1,9,101),(1,1,144),(2,4,68),(1,11,93),(1,16,108),(1,15,166),(1,6,119);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,13,92),(1,18,140),(1,15,129),(2,3,190),(1,10,43),(2,5,32),(1,9,79),(2,16,136),(1,10,168),(1,17,23);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,2,101),(2,2,133),(1,14,111),(1,4,26),(2,9,54),(1,1,188),(2,15,101),(2,3,107),(1,14,28),(2,11,124);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,8,127),(1,3,2),(1,13,110),(2,3,106),(2,8,12),(2,18,94),(2,13,92),(2,2,51),(1,13,68),(2,18,159);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,18,27),(2,2,123),(2,3,134),(1,15,127),(1,8,172),(1,7,44),(2,1,60),(1,10,84),(1,16,38),(1,12,46);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,13,26),(2,8,92),(1,16,63),(1,10,34),(2,18,137),(1,16,91),(2,5,154),(1,12,143),(1,5,125),(1,4,51);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,2,47),(2,16,185),(1,6,8),(1,3,172),(2,1,92),(1,15,150),(2,17,95),(2,7,46),(1,7,53),(2,5,9);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,4,183),(2,10,73),(2,14,113),(2,7,18),(2,5,45),(2,10,120),(1,15,31),(1,13,33),(2,17,37),(2,12,6);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,12,150),(2,10,68),(2,14,136),(1,12,87),(1,4,37),(2,13,127),(1,11,19),(1,7,48),(2,11,85),(1,5,50);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,10,167),(1,14,58),(2,7,122),(1,1,161),(1,6,184),(2,10,27),(2,15,45),(2,12,73),(2,10,39),(1,2,15);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,10,141),(2,15,91),(2,6,45),(1,15,93),(2,5,162),(1,18,48),(2,13,100),(2,6,141),(1,3,104),(1,2,154);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,17,164),(1,16,102),(2,2,55),(1,15,89),(2,8,4),(1,8,61),(2,4,20),(1,8,41),(1,16,152),(1,12,155);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,11,9),(2,4,112),(2,3,24),(1,8,169),(2,11,131),(2,14,21),(1,15,71),(1,2,102),(2,12,65),(2,4,130);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,1,102),(1,17,70),(2,11,39),(2,17,118),(1,1,105),(2,12,88),(2,9,30),(2,2,45),(2,15,70),(2,6,117);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,16,199),(2,4,153),(1,18,65),(1,11,98),(2,18,66),(1,7,93),(2,15,162),(2,13,100),(2,5,125),(1,18,129);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,4,56),(2,10,71),(1,1,64),(2,4,147),(2,15,32),(1,9,101),(2,4,132),(1,12,166),(2,8,136),(2,18,194);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,10,13),(2,7,72),(1,3,14),(2,16,117),(2,5,135),(2,12,121),(2,16,29),(2,12,33),(2,10,54),(1,15,42);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,17,12),(1,6,41),(2,18,185),(2,6,92),(1,3,68),(2,8,132),(2,5,33),(1,13,55),(2,7,198),(2,10,139);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,14,127),(1,5,62),(2,3,86),(1,1,103),(1,18,136),(2,3,32),(2,6,109),(1,10,68),(2,18,76),(1,1,90);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,14,190),(2,10,109),(2,3,40),(2,18,139),(2,14,126),(2,3,29),(1,13,113),(2,6,147),(1,8,141),(2,14,37);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,10,5),(2,17,37),(2,17,24),(2,15,60),(2,1,195),(2,4,137),(2,15,96),(2,14,134),(1,10,126),(1,12,8);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,4,72),(1,13,103),(1,18,19),(1,16,164),(2,13,46),(1,3,83),(1,13,82),(1,17,173),(2,10,78),(1,16,53);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,17,51),(1,10,116),(2,8,24),(2,3,58),(2,14,199),(1,14,171),(1,7,200),(1,9,179),(1,10,23),(2,7,157);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,13,101),(2,16,7),(2,3,52),(1,18,41),(1,7,129),(1,12,14),(1,10,152),(2,14,6),(2,15,34),(1,17,39);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,12,179),(2,7,52),(1,15,8),(1,15,31),(1,12,61),(2,1,71),(1,15,56),(2,11,108),(2,13,153),(1,13,115);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,4,129),(2,7,91),(2,6,29),(2,1,15),(1,16,150),(2,8,171),(1,17,191),(2,16,194),(2,10,30),(1,16,134);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,1,99),(2,7,156),(2,14,171),(2,13,163),(2,9,187),(2,8,77),(2,17,63),(2,18,2),(1,10,30),(1,12,140);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,18,44),(2,1,67),(2,18,118),(2,15,78),(1,10,47),(1,17,3),(2,9,24),(2,1,78),(2,5,73),(2,6,178);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,3,30),(2,14,164),(1,14,109),(1,12,155),(2,15,174),(1,4,37),(2,15,88),(1,15,119),(2,6,113),(2,14,67);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,11,66),(1,16,166),(1,17,101),(2,12,30),(2,3,89),(2,12,59),(1,11,75),(1,9,35),(2,5,84),(2,4,185);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,18,56),(1,7,156),(2,5,138),(2,2,88),(2,17,140),(1,2,123),(2,12,178),(2,8,180),(1,16,116),(1,17,21);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,2,38),(1,10,117),(2,11,60),(2,4,37),(1,3,41),(2,15,158),(2,15,200),(1,16,27),(1,13,79),(2,13,28);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,15,191),(1,11,170),(1,1,9),(2,9,28),(1,13,174),(1,1,55),(1,16,58),(2,13,197),(1,5,176),(1,8,16);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,3,122),(1,6,14),(2,5,30),(1,16,90),(2,7,60),(1,14,129),(2,9,136),(1,15,88),(2,1,102),(2,16,81);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,15,195),(2,14,165),(1,14,149),(2,18,51),(2,14,193),(1,18,44),(2,17,59),(1,14,29),(1,12,12),(2,4,75);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,1,52),(2,8,149),(2,12,81),(1,2,159),(1,17,93),(1,18,104),(2,8,108),(2,7,109),(1,10,190),(1,13,189);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,9,193),(1,5,129),(2,7,16),(2,4,64),(2,12,103),(1,12,157),(1,17,113),(2,13,115),(2,1,10),(1,15,121);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,14,155),(1,13,69),(1,9,169),(1,3,39),(1,10,103),(1,14,110),(1,17,65),(1,17,198),(2,13,46),(1,9,70);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,16,132),(2,3,170),(2,17,23),(2,13,113),(2,4,199),(2,18,58),(1,11,10),(2,11,46),(2,6,139),(1,11,96);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,3,165),(1,9,193),(2,4,185),(1,10,166),(1,17,90),(2,5,107),(1,10,53),(1,6,72),(2,13,35),(1,16,188);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,4,115),(1,14,180),(1,12,93),(2,6,52),(1,17,49),(2,15,131),(1,6,175),(1,5,41),(2,7,26),(1,17,173);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,2,41),(1,1,28),(2,7,81),(1,7,41),(2,18,187),(2,6,22),(1,9,165),(2,12,115),(1,8,3),(2,3,4);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,9,173),(1,6,61),(1,11,19),(1,2,50),(2,1,194),(1,15,189),(1,6,58),(1,18,144),(1,8,37),(2,8,64);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,12,131),(2,3,122),(2,14,137),(1,11,58),(1,3,189),(1,6,124),(1,16,194),(1,8,165),(2,9,58),(2,13,41);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (2,5,109),(1,14,85),(1,16,31),(1,13,25),(2,13,19),(2,5,109),(2,12,42),(2,15,170),(2,1,49),(2,7,158);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,4,35),(1,7,72),(1,18,53),(1,7,43),(2,10,136),(1,15,129),(1,15,4),(2,9,64),(1,11,51),(1,7,144);


INSERT INTO Epoch VALUES('Normal','2017-05-08','2017-05-26');
INSERT INTO Epoch VALUES('Recurso','2017-05-29','2017-05-16');