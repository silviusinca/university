create table LOCATII(   id_locatie number(4)    constraint pk_locatie            primary key,
                        oras       varchar2(25) constraint null_oras_locatie    not null,
                        adresa     varchar2(25) constraint null_adresa_locatie  not null);


create table LIBRARIE(  id_librarie     number(4)       constraint pk_librarie          primary key, 
                        nume_librarie   varchar2(25)    constraint null_nume_librarie   not null, 
                        id_locatie      number(4)       constraint null_id_locatie      not null,
                        constraint fk_locatie_librarie foreign key(id_locatie) references locatii(id_locatie)
                    );                          


create table ANGAJATI(  id_angajat  number(4)       constraint pk_angajati primary key, 
                        nume        varchar2(20)    constraint null_nume_angajat not null, 
                        prenume     varchar2(20), 
                        email       char(20)        constraint unq_email_angajat unique,
                        nr_telefon  char(12)        constraint unq_nr_telefon_angajat unique,
                        data_ang    date default sysdate, 
                        id_manager  number(4)       constraint fk_angajati references angajati(id_angajat), 
                        salariu     number(8, 2),
                        id_librarie number(4)       constraint ck_id_librarie check(id_librarie>0),
                        nume_job    varchar2(20)        constraint null_nume_job not null,
                        constraint unq_nume_pren_ssg unique(nume, prenume),
                        constraint fk_librarie_angajat foreign key(id_librarie) references librarie(id_librarie)
                    );   


create table EDITURA(   id_editura      number(4)       constraint pk_editura primary key,
                        nume_editura    varchar2(20)    constraint null_nume_editura not null,
                        data_infiintare   date
                    );


create table CATEGORIE( id_categorie    number(4)       constraint pk_categorie primary key, 
                        nume_categorie  varchar2(20)    constraint null_nume_categorie not null
                    );


create table CARTI( id_carte        number(4)       constraint pk_carte primary key,
                    titlu      varchar2(30)    constraint null_titlu not null,
                    nume_autor      varchar2(20)    constraint null_nume_autor not null,
                    prenume_autor   varchar2(20),
                    pret            number(5,2)     constraint ck_pret_carte check(pret>0),
                    id_editura      number(4)       constraint null_id_edirtura not null,
                    id_categorie    number(4)       constraint null_id_categorie not null,
                    constraint fk_editura_carte     foreign key(id_editura) references editura(id_editura), 
                    constraint fk_categorie_carte   foreign key(id_categorie) references categorie(id_categorie)
                );


create table STOC(  id_stoc     number(4)   constraint pk_stoc primary key,
                    id_carte    number(4)   constraint null_id_carte_stoc not null,
                    id_librarie number(4)   constraint null_id_stoc_librarie not null,
                    cantitate   number(6)   constraint ck_cantitate check(cantitate > 0),
                    constraint fk_id_librarie_stoc foreign key(id_librarie) references LIBRARIE(id_librarie),
                    constraint fk_id_carte_stoc foreign key(id_carte) references CARTI(id_carte)
                );

insert into locatii
values (100, 'Bucuresti', 'Bulevardul Decebal 24');
insert into locatii
values (101, 'Cluj', 'Strada Macului 245');
insert into locatii
values (102, 'Timisoara', 'Aleea Unirii 13');
insert into locatii
values (103, 'Bucuresti', 'Calea Victoriei 97');
insert into locatii
values (104, 'Bucuresti', 'Strada Elizabeta 17');
insert into locatii
values (105, 'Bucuresti', 'Aleea Buchetului 8');
insert into locatii
values (106, 'Cluj', 'Bulevardul Eroilor 873');
insert into locatii
values (107, 'Braila', 'Strada Obor 3');
insert into locatii
values (108, 'Timisoara', 'Strada Timisului 1');
insert into locatii
values (109, 'Cluj', 'Bulevardul Basarabia 19');


insert into LIBRARIE
values (200, 'Carturesti Decebal', 100);
insert into LIBRARIE
values (201, 'Carturesti Macului', 101);
insert into LIBRARIE
values (202, 'Carturesti Unirii', 102);
insert into LIBRARIE
values (203, 'Carturesti Victoriei', 103);
insert into LIBRARIE
values (204, 'Carturesti Elizabeta', 104);
insert into LIBRARIE
values (205, 'Carturesti Buchetului', 105);
insert into LIBRARIE
values (206, 'Carturesti Eroilor', 106);
insert into LIBRARIE
values (207, 'Carturesti Obor', 107);
insert into LIBRARIE
values (208, 'Carturesti Timisului', 108);
insert into LIBRARIE
values (209, 'Carturesti Basarabia', 109);


-- manageri
insert into ANGAJATI
values (300,  'Raducan', 'Mihai', 'm.raducan@gmail.com', '0749135222', to_date('02-02-2014', 'dd-mm-yyyy'), null, 3000, 200, 'Manager');
insert into ANGAJATI
values (301,  'Alexe', 'Andrei', 'a.alexe@gmail.com', '0744137821', to_date('04-02-2014', 'dd-mm-yyyy'), null, 3150, 201, 'Manager');
insert into ANGAJATI
values (302,  'Popa', 'Andrei', 'a.popa@gmail.com', '0739195232', to_date('03-10-2016', 'dd-mm-yyyy'), null, 2870, 202, 'Manager');
insert into ANGAJATI
values (303,  'Mihai', 'Marius', 'm.mihai@gmail.com', '0745137101', sysdate, null, 3900, 203, 'Manager');
insert into ANGAJATI
values (304,  'Grozav', 'Robert', 'r.grozav@gmail.com', '0749330722', sysdate, null, 5030, 204, 'Manager');
insert into ANGAJATI
values (305,  'Popa', 'Roxana', 'r.popa@gmail.com', '0745137823', sysdate, null, 2950, 205, 'Manager');
insert into ANGAJATI
values (306,  'Axente', 'Cristina', 'c.alexe@gmail.com', '0759715222', sysdate, null, 3120, 206, 'Manager');
insert into ANGAJATI
values (307,  'Filote', 'Mirela', 'm.filote@gmail.com', '0749124821', sysdate, null, 4790, 207, 'Manager');
insert into ANGAJATI
values (308,  'Bejan', 'Oana', 'o.bejan@gmail.com', '0749139832', sysdate, null, 3000, 208, 'Manager');
insert into ANGAJATI
values (309,  'Gurea', 'Dragos', 'd.gurea@gmail.com', '0745130821', sysdate, null, 2900, 209, 'Manager');
-- librari
insert into ANGAJATI
values (310,  'Dumitriu', 'Adrian', 'a.dumitriu@gmail.com', '0745130321', sysdate, 300, 1750, 200, 'Librar');
insert into ANGAJATI
values (311,  'Teselea', 'Ciprian', 'c.teselea@gmail.com', '0745110821', sysdate, 300, 2000, 200, 'Librar');
insert into ANGAJATI
values (312,  'Cirip', 'Maria', 'm.cirip@gmail.com', '0749100821', sysdate, 301, 2150, 201, 'Librar');
insert into ANGAJATI
values (313,  'Andreas', 'Stefan', 's.andreas@gmail.com', '0735130823', sysdate, 302, 1600, 202, 'Librar');
insert into ANGAJATI
values (314,  'Stan', 'Irina', 'i.stan@gmail.com', '0725110821', sysdate, 302, 1800, 202, 'Librar');
insert into ANGAJATI
values (315,  'Radu', 'Ana', 'a.radu@gmail.com', '0754130821', sysdate, 303, 2000, 203, 'Librar');
insert into ANGAJATI
values (316,  'Stan', 'Georgiana', 'g.stan@gmail.com', '0749130821', to_date('04-05-2022', 'dd-mm-yyyy'), 303, 1950, 203, 'Librar');
insert into ANGAJATI
values (317,  'Dima', 'Alexandru', 'a.dima@gmail.com', '0745131821', to_date('23-11-2020', 'dd-mm-yyyy'), 304, 1900, 204, 'Librar');
insert into ANGAJATI
values (318,  'Marin', 'David', 'd.marin@gmail.com', '0745130121', sysdate, 305, 2300, 205, 'Librar');
insert into ANGAJATI
values (319,  'Toma', 'Silviu', 's.toma@gmail.com', '0736130821', sysdate, 305, 2150, 205, 'Librar');
insert into ANGAJATI
values (320,  'Toma', 'Daniel', 'd.toma@gmail.com', '0735130821', sysdate, 306, 2200, 206, 'Librar');
insert into ANGAJATI
values (321,  'Iancu', 'Elena', 'e.iancu@gmail.com', '0745130888', to_date('03-10-2021', 'dd-mm-yyyy'), 307, 1550, 207, 'Librar');
insert into ANGAJATI
values (322,  'Nistor', 'Alexandra', 'a.nistor@gmail.com', '0749130771', to_date('03-02-2021', 'dd-mm-yyyy'), 308, 2000, 208, 'Librar');
insert into ANGAJATI
values (323,  'Ionescu', 'Denisa', 'd.ionescu@gmail.com', '0749130833', to_date('01-01-2022', 'dd-mm-yyyy'), 308, 1800, 208, 'Librar');
insert into ANGAJATI
values (324,  'Dobre', 'Matei', 'm.dobre@gmail.com', '0745130812', to_date('03-10-2018', 'dd-mm-yyyy'), 309, 2100, 209, 'Librar');


insert into EDITURA
values (400, 'Humanitas', to_date('01-01-1995', 'dd-mm-yyyy'));
insert into EDITURA
values (401, 'Libris', null);
insert into EDITURA
values (402, 'Kiterion', to_date('05-12-2002', 'dd-mm-yyyy'));
insert into EDITURA
values (403, 'Hyperion', to_date('30-07-2010', 'dd-mm-yyyy'));
insert into EDITURA
values (404, 'Polirom', to_date('02-08-1990', 'dd-mm-yyyy'));


insert into CATEGORIE
values (500, 'Fantasy');
insert into CATEGORIE
values (501, 'Psihologie');
insert into CATEGORIE
values (502, 'Science Fiction');
insert into CATEGORIE
values (503, 'Nonfiction');
insert into CATEGORIE
values (504, 'Filosofie');


insert into CARTI
values (600, 'The Three-Body Problem', 'Liu', 'Cixin', 65, 402, 502);
insert into CARTI
values (601, 'The Dark Forest', 'Liu', 'Cixin', 80, 400, 502);
insert into CARTI
values (602, 'Ball Lightning', 'Liu', 'Cixin', 73.50, 402, 502);
insert into CARTI
values (603, 'Sapiens', 'Harari', 'Yuval Noah', 100, 401, 503);
insert into CARTI
values (604, 'Homo Deus', 'Harari', 'Yuval Noah', 59.99, 404, 503);
insert into CARTI
values (605, 'Why We Sleep', 'Walker', 'Matthew', 43.95, 400, 501);
insert into CARTI
values (606, 'Republic', 'Plato', null, 38, 403, 504);
insert into CARTI
values (607, 'The Last Wish', 'Sapkowski', 'Andrzej', 65.99, 400, 500);
insert into CARTI
values (608, 'Sword of Destiny', 'Sapkowski', 'Andrzej', 78, 403, 500);
insert into CARTI
values (609, 'Season of Storms', 'Sapkowski', 'Andrzej', 125.59, 402, 500);


insert into STOC
values (2000, 600, 200, 12);
insert into STOC
values (2001, 602, 200, 7);
insert into STOC
values (2002, 608, 200, 18);
insert into STOC
values (2003, 609, 200, 3);
insert into STOC
values (2004, 606, 200, 1);
insert into STOC
values (2100, 600, 201, 1);
insert into STOC
values (2200, 604, 202, 1);
insert into STOC
values (2201, 605, 202, 5);
insert into STOC
values (2202, 606, 202, 12);
insert into STOC
values (2203, 607, 202, 9);
insert into STOC
values (2204, 609, 202, 7);
insert into STOC
values (2205, 603, 202, 7);
insert into STOC
values (2206, 601, 202, 7);
insert into STOC
values (2300, 609, 203, 1);
insert into STOC
values (2400, 603, 204, 9);
insert into STOC
values (2401, 604, 204, 2);
insert into STOC
values (2500, 601, 205, 2);
insert into STOC
values (2501, 602, 205, 5);
insert into STOC
values (2502, 603, 205, 3);
insert into STOC
values (2503, 604, 205, 9);
insert into STOC
values (2504, 605, 205, 7);
insert into STOC
values (2600, 600, 206, 1);
insert into STOC
values (2601, 605, 206, 3);
insert into STOC
values (2700, 602, 207, 1);
insert into STOC
values (2800, 603, 208, 12);
insert into STOC
values (2801, 604, 208, 8);
insert into STOC
values (2802, 605, 208, 3);

-- 1. Afisati numele pentru editurile care au media preturilor cartilor mai mare decat media totala a preturilor tuturor cartilor
with total_edituri as (select e.nume_editura, sum(c.pret) as total 
                           from carti c, editura e
                           where c.id_editura = e.id_editura
                           group by e.nume_editura),
medie_edituri AS (select sum(total)/count(*) as medie from total_edituri )
SELECT  *
FROM    total_edituri
WHERE   total > (SELECT   medie
                  FROM      medie_edituri)
ORDER BY nume_editura;

select lb.nume_librarie, loc.oras, loc.adresa, c.titlu, s.cantitate
from librarie lb, locatii loc, carti c, stoc s
where lb.id_librarie = s.id_librarie
and c.id_carte = s.id_carte
and loc.id_locatie = lb.id_locatie
order by lb.nume_librarie;


-- 2. Afiasti numele managerilor, orasul si adresa librariilor unde se gasesc carti scrise de Liu Cixin.
select unique a.nume, loc.oras, loc.adresa
from librarie lb, locatii loc, angajati a, carti c, stoc s
where lb.id_librarie = s.id_librarie
and a.id_librarie = lb.id_librarie
and loc.id_locatie = lb.id_locatie
and s.id_carte = c.id_carte
and a.id_manager is null
and lb.id_librarie in (select lib.id_librarie
                      from librarie lib, stoc st, carti ct
                      where st.cantitate > 0
                      and lower(ct.nume_autor) like 'liu'
                      and lib.id_librarie = st.id_librarie
                      and ct.id_carte = st.id_carte);


-- 3. afisati numele librariilor doar pentru librariile care se afla pe o alee si care au numar maxim de angajati
select lib.id_librarie, lib.nume_librarie, loc.adresa, count(a.id_angajat) "Numar maxim de angajati"
from angajati a, librarie lib, locatii loc
where lib.id_locatie = loc.id_locatie
and a.id_librarie = lib.id_librarie
and lower(substr(loc.adresa, 1, 5)) like 'aleea'
group by lib.id_librarie, lib.nume_librarie, loc.adresa
having count(a.id_angajat) = (select max(count(ang.id_angajat))
                              from angajati ang, locatii lc, librarie lb
                              where lb.id_locatie = lc.id_locatie
                              and ang.id_librarie = lb.id_librarie
                              group by lb.id_librarie, lb.nume_librarie, lc.adresa);


-- 4. Mariti salariul cu 300 pentru librarii din bucuresti,
-- cu 200 pentru librarii din cluj si cu 150 pentru restul librarilor, doar pentru cei angajati de mai mult de 10 luni
-- Afisati salariul vechi, salariul marit, numele complet angajatilor si orasul in care lucreaza. Ordonati rezultatul dupa salariul marit
select concat(a.nume, concat(' ', a.prenume)) "Nume complet", loc.oras, a.nume_job, to_char(a.data_ang, 'Day/Month/YYYY') "Data Angajare", a.salariu,
case loc.oras 
when 'Bucuresti' then salariu+300
when 'Cluj' then salariu+200
else salariu+150
end salariu_marit
from angajati a, locatii loc, librarie lib
where a.id_librarie = lib.id_librarie
and loc.id_locatie = lib.id_locatie
and a.id_manager is not null
and months_between(sysdate, a.data_ang) >= 10
order by salariu_marit;


-- 5. Cresteti stocul cartilor astfel: pentru cartile publicate de Humanitas cresteti cu 20, pentru cele publicate de Libris cu 15 iar pentru restul cu 10, doar pentru librariile aflate in bucuresti. Afisati titlul cartii, numele complet al autorului, cantitatea veche si cea noua.
select c.titlu, c.nume_autor || ' ' || c.prenume_autor "Nume complet", s.cantitate, decode(e.nume_editura, 'Humanitas', s.cantitate+20, 'Libris', s.cantitate+15, s.cantitate+10) "Cantitate noua", e.nume_editura, loc.oras
from carti c, stoc s, editura e, locatii loc, librarie lib
where c.id_editura = e.id_editura
and c.id_carte = s.id_carte
and s.id_librarie = lib.id_librarie
and lib.id_locatie = loc.id_locatie
and lower(loc.oras) like 'bucuresti'; 


-- Actualizari:
-- 1. Actualizati tabela de angajati astfel incat fiecare librar sa aiba salariul minim 2000 de lei
update ANGAJATI
set salariu = 2000
where salariu < 2000 and upper(nume_job) like 'LIBRAR';

select * from angajati;

-- 2. Adaugati o carte noua: 'Life 3.0' de Max Tegmark, publicata de Humanitas care nu este momentan pe stoc. Ea va costa 71 de lei si este nonfiction

insert into CARTI
values (610, 'Life 3.0', 'Tegmark', 'Max', 71, 400, 503);

select * from CARTI;

-- 3. Stergeti de pe stoc toate cartile aflate in librariile din Braila
delete from stoc
where id_carte in ( select c.id_carte
                    from carti c, librarii lib, locatii loc, stoc s
                    where s.id_carte = c.id_carte
                    and s.id_librarie = lib.id_librarie
                    and lib.id_locatie = loc.id_locatie
                    and lower(loc.oras) like 'braila'
);