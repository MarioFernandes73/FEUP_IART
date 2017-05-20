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

INSERT INTO Student (id_student,name) VALUES (1,"Fulton Marks"),(2,"Lance Vaughn"),(3,"Xena Sutton"),(4,"Laura Abbott"),(5,"Joshua Caldwell"),(6,"Alexis Livingston"),(7,"Adele Vinson"),(8,"Ruby Callahan"),(9,"Guy Patrick"),(10,"Noelani Kirk");
INSERT INTO Student (id_student,name) VALUES (11,"Ivor Mullen"),(12,"Hashim Norton"),(13,"Odysseus Allen"),(14,"Keane Hunter"),(15,"Quail Vinson"),(16,"Roary Dudley"),(17,"Alea Mcfadden"),(18,"Stacy Norton"),(19,"Jermaine Moon"),(20,"Yuri Macdonald");
INSERT INTO Student (id_student,name) VALUES (21,"Gemma Henson"),(22,"Morgan Mathis"),(23,"Clementine Freeman"),(24,"Rhona Rowland"),(25,"Yardley Medina"),(26,"Breanna Mosley"),(27,"Lev Lowe"),(28,"Riley Hudson"),(29,"Castor Franco"),(30,"Azalia Salazar");
INSERT INTO Student (id_student,name) VALUES (31,"Priscilla Fry"),(32,"Leonard Kirk"),(33,"Jessamine Haynes"),(34,"Ainsley Sykes"),(35,"Aubrey Kent"),(36,"Melinda Stone"),(37,"Kane Vincent"),(38,"Tiger Stewart"),(39,"Stephen Hampton"),(40,"Velma Mcneil");
INSERT INTO Student (id_student,name) VALUES (41,"Carter Carver"),(42,"Georgia Oliver"),(43,"Colby Stokes"),(44,"Daniel Kline"),(45,"Sylvia Allison"),(46,"Lana Valentine"),(47,"Jenna Avila"),(48,"Inga Guzman"),(49,"Lewis Calderon"),(50,"Rajah Singleton");
INSERT INTO Student (id_student,name) VALUES (51,"Deirdre Sargent"),(52,"Dane Wood"),(53,"Iris Swanson"),(54,"Chester Shepherd"),(55,"Leo Chandler"),(56,"Rhona Burks"),(57,"Gloria Briggs"),(58,"Whilemina Hart"),(59,"Moses Duffy"),(60,"Jada Hess");
INSERT INTO Student (id_student,name) VALUES (61,"Patricia Gonzalez"),(62,"Tarik Mcconnell"),(63,"Kuame Parks"),(64,"Benedict Chaney"),(65,"Colt Hendricks"),(66,"Amethyst Giles"),(67,"Shelby Walker"),(68,"Inez Mccall"),(69,"Dale Goff"),(70,"Gabriel Gray");
INSERT INTO Student (id_student,name) VALUES (71,"Athena Ratliff"),(72,"Morgan Oneal"),(73,"Jemima Bowers"),(74,"Susan Flynn"),(75,"Tallulah Lee"),(76,"Mallory Hewitt"),(77,"Owen Randall"),(78,"Cooper Livingston"),(79,"Autumn Langley"),(80,"Tashya Lott");
INSERT INTO Student (id_student,name) VALUES (81,"Brianna Serrano"),(82,"Lenore Daugherty"),(83,"Brittany Valenzuela"),(84,"Lane Taylor"),(85,"Martin Duncan"),(86,"Marcia Banks"),(87,"Bianca Dudley"),(88,"Basia Jones"),(89,"Ingrid Reeves"),(90,"Randall Morton");
INSERT INTO Student (id_student,name) VALUES (91,"Sandra Foreman"),(92,"Charlotte Malone"),(93,"Howard Gilliam"),(94,"Jackson Evans"),(95,"Cyrus Macdonald"),(96,"Hayden Nelson"),(97,"Ruth Johnston"),(98,"Paki Wise"),(99,"Helen Clay"),(100,"Catherine Harding");
INSERT INTO Student (id_student,name) VALUES (200,"Nehru Castillo"),(101,"Ronan Barry"),(102,"Althea Hopper"),(103,"Amos Hudson"),(104,"Hillary Stevens"),(105,"Demetria Mckenzie"),(106,"Eden Martin"),(107,"Ifeoma Stafford"),(108,"Cassandra Burt"),(109,"Charissa Ewing");
INSERT INTO Student (id_student,name) VALUES (110,"Aphrodite Fields"),(111,"Nolan Douglas"),(112,"Drake Robles"),(113,"Harding Mcgowan"),(114,"Lawrence Mayo"),(115,"Sonia Roberts"),(116,"Keefe Alford"),(117,"Norman Alvarado"),(118,"Chiquita Lester"),(119,"Zachery Turner");
INSERT INTO Student (id_student,name) VALUES (120,"Jakeem Gates"),(121,"Jenette Brock"),(122,"Joseph Burton"),(123,"Jessamine Colon"),(124,"Unity Mcfarland"),(125,"Bryar Witt"),(126,"Rae Daniels"),(127,"Lee Carson"),(128,"Ezra Kramer"),(129,"Kamal Hamilton");
INSERT INTO Student (id_student,name) VALUES (130,"Hope Calhoun"),(131,"Otto Weiss"),(132,"Gavin Vinson"),(133,"Urielle Lucas"),(134,"Luke Wong"),(135,"Wang Brown"),(136,"Gisela Baldwin"),(137,"Buckminster Evans"),(138,"Paki Rice"),(139,"Elton Kidd");
INSERT INTO Student (id_student,name) VALUES (140,"Silas Malone"),(141,"Kirestin Kline"),(142,"Lev Cash"),(143,"Jakeem Frye"),(144,"Doris Collier"),(145,"Anne Huff"),(146,"Zachery Gilbert"),(147,"Sonia Barron"),(148,"Hiram Butler"),(149,"Signe Kirby");
INSERT INTO Student (id_student,name) VALUES (150,"Wilma Bass"),(151,"Serina Sandoval"),(152,"Hu Knox"),(153,"Cynthia Hopper"),(154,"Cairo Molina"),(155,"Logan Deleon"),(156,"Xanthus Mays"),(157,"Jessica Nash"),(158,"Astra Padilla"),(159,"Tad Goodman");
INSERT INTO Student (id_student,name) VALUES (160,"Cairo Reynolds"),(161,"Kareem Lloyd"),(162,"Kimberly Kirby"),(163,"Chandler Caldwell"),(164,"Sacha Alvarez"),(165,"Chadwick Mcconnell"),(166,"Guy Reid"),(167,"Damon Ortega"),(168,"Thane Williams"),(169,"Hashim Drake");
INSERT INTO Student (id_student,name) VALUES (170,"Demetria Blankenship"),(171,"Serina Lancaster"),(172,"Catherine Hurley"),(173,"Iola Skinner"),(174,"Logan Mcclure"),(175,"Sophia Mullins"),(176,"Regina Bishop"),(177,"Grace Ryan"),(178,"Stella Aguirre"),(179,"Nelle Watts");
INSERT INTO Student (id_student,name) VALUES (180,"Teegan Hyde"),(181,"Karina Gentry"),(182,"Warren Bryan"),(183,"Trevor Wilkerson"),(184,"Dale Webb"),(185,"Jocelyn Randolph"),(186,"Evan Perez"),(187,"Bo Decker"),(188,"Tatyana Calderon"),(189,"Gil Mckay");
INSERT INTO Student (id_student,name) VALUES (190,"Gabriel Burke"),(191,"Portia Manning"),(192,"Selma Pittman"),(193,"Zenia Duncan"),(194,"Mari Dominguez"),(195,"Elizabeth Parsons"),(196,"Britanney Garrett"),(197,"Norman Yates"),(198,"Michelle Cooley"),(199,"Jack Randolph");


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

INSERT INTO Epoch VALUES('Normal','2017-05-08','2017-05-26');
INSERT INTO Epoch VALUES('Recurso','2017-05-29','2017-05-16');

INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,1,71),(1,1,196),(1,1,37),(1,1,137),(1,1,133),(1,1,123),(1,1,80),(1,1,100),(1,1,8),(1,1,169);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,1,154),(1,1,65),(1,1,182),(1,1,224),(1,1,174),(1,1,74),(1,1,89),(1,1,41),(1,1,4),(1,1,107);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,2,71),(1,2,196),(1,2,37),(1,2,137),(1,2,133),(1,2,123),(1,2,80),(1,2,100),(1,2,8),(1,2,169);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,2,154),(1,2,65),(1,2,182),(1,2,224),(1,2,136),(1,2,74),(1,2,89),(1,2,41),(1,2,4),(1,2,107);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,3,71),(1,3,196),(1,3,37),(1,3,137),(1,3,133),(1,3,123),(1,3,80),(1,3,100),(1,3,8),(1,3,169);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,3,154),(1,3,65),(1,3,182),(1,3,224),(1,3,136),(1,3,74),(1,3,89),(1,3,41),(1,3,4),(1,3,107);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,4,71),(1,4,196),(1,4,37),(1,4,137),(1,4,133),(1,4,123),(1,4,80),(1,4,100),(1,4,8),(1,4,169);
INSERT INTO Subscription (id_epoch,id_exam,id_student) VALUES (1,4,154),(1,4,65),(1,4,182),(1,4,224),(1,4,174),(1,4,74),(1,4,89),(1,4,41),(1,4,4),(1,4,107);
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
