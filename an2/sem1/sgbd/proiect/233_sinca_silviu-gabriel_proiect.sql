
CREATE TABLE furnizor(
    id_furnizor NUMBER(4) PRIMARY KEY,
    nume_furnizor VARCHAR2(100) NOT NULL,
    adresa VARCHAR2(255) NOT NULL,
    oras VARCHAR2(255) NOT NULL
);

CREATE TABLE departament(
    id_departament NUMBER(4) PRIMARY KEY,
    nume_departament VARCHAR2(100) NOT NULL
);

CREATE TABLE produs(
    id_produs NUMBER(4) PRIMARY KEY,
    nume_produs VARCHAR2(100) NOT NULL,
    descriere VARCHAR2(255),
    pret NUMBER(6, 2) NOT NULL,
    id_furnizor NUMBER(4),
    FOREIGN KEY (id_furnizor) REFERENCES furnizor(id_furnizor)
);

CREATE TABLE client(
    id_client NUMBER(4) PRIMARY KEY,
    nume VARCHAR2(100) NOT NULL,
    prenume VARCHAR2(100) NOT NULL,
    adresa VARCHAR2(255) NOT NULL,
    oras VARCHAR2(255) NOT NULL,
    email VARCHAR2(100),
    telefon VARCHAR2(15) NOT NULL
);

CREATE TABLE angajat(
    id_angajat NUMBER(4) PRIMARY KEY,
    nume VARCHAR2(100) NOT NULL,
    prenume VARCHAR2(100) NOT NULL,
    data_angajarii DATE NOT NULL,
    salariu NUMBER(6) NOT NULL,
    id_departament NUMBER(4),
    FOREIGN KEY (id_departament) REFERENCES departament(id_departament)
);

CREATE TABLE comanda(
    id_comanda NUMBER(4) PRIMARY KEY,
    data_comanda DATE NOT NULL,
    id_client NUMBER(4),
    id_angajat NUMBER(4),
    FOREIGN KEY (id_client) REFERENCES client(id_client),
    FOREIGN KEY (id_angajat) REFERENCES angajat(id_angajat)
);

CREATE TABLE comanda_produs(
    id_comanda_produs NUMBER(4) PRIMARY KEY,
    id_comanda NUMBER(4),
    id_produs NUMBER(4),
    cantitate NUMBER(6),
    FOREIGN KEY (id_comanda) REFERENCES comanda(id_comanda),
    FOREIGN KEY (id_produs) REFERENCES produs(id_produs)
);

ALTER TABLE comanda_produs
ADD CONSTRAINT ck_cantitate_positive CHECK (cantitate > 0);


-- inserare in tabele:
-- furnizor
INSERT INTO furnizor(id_furnizor, nume_furnizor, adresa, oras)
VALUES (100, 'Flanco', 'Bulevardul 1 Decembrie 1918, 032451', 'Bucuresti');

INSERT INTO furnizor(id_furnizor, nume_furnizor, adresa, oras)
VALUES (101, 'Media Galaxy', 'Strada Avram Iancu 492-500, 407280', 'Cluj-Napoca');

INSERT INTO furnizor(id_furnizor, nume_furnizor, adresa, oras)
VALUES (102, 'Emag', 'Bulevardul George Coșbuc 251, 800552', 'Galati');

INSERT INTO furnizor(id_furnizor, nume_furnizor, adresa, oras)
VALUES (103, 'Altex', 'Calea Giulești 1-3, 060251', 'Bucuresti');

INSERT INTO furnizor(id_furnizor, nume_furnizor, adresa, oras)
VALUES (104, 'Go4IT', 'Strada Martir Al. Chorosi Nr.17 Bl. B11/a', 'Timisoara');

-- produs
INSERT INTO produs(id_produs, nume_produs, descriere, pret, id_furnizor)
VALUES (200, 'Macbook Pro 13', 'Macbook Pro 13 inch, procesor M1, 16GB memorie, 256GBm Space Grey', 1200.99, 100);

INSERT INTO produs(id_produs, nume_produs, descriere, pret, id_furnizor)
VALUES (201, 'iPhone 14', 'telefon Apple iPhone 14, 64GB, Space Grey', 1000.00, 100);

INSERT INTO produs(id_produs, nume_produs, descriere, pret, id_furnizor)
VALUES (202, 'Galaxy Watch 6', 'Samsung Galaxy Watch6 Classic, 43mm, LTE, Black', 500.23, 104);

INSERT INTO produs(id_produs, nume_produs, descriere, pret, id_furnizor)
VALUES (203, 'iPad 9', 'Apple iPad 9 (2021), 10.2 inch, 64GB, Wi-Fi, Space Grey', 745.99, 102);

INSERT INTO produs(id_produs, nume_produs, descriere, pret, id_furnizor)
VALUES (204, 'Monitor Dell', 'Monitor Gaming LED IPS Dell 23.8 inch, Full HD, 165Hz, DisplayPort, Negru, G2422HS', 250.50, 101);

INSERT INTO produs(id_produs, nume_produs, descriere, pret, id_furnizor)
VALUES (205, 'Placa Video RTX 3060TI', 'Placa video ASUS GeForce RTX® 3060TI TUF GAMING, 8GB GDDR6X, 256-bit', 487.95, 102);

INSERT INTO produs(id_produs, nume_produs, descriere, pret,id_furnizor)
VALUES (206, 'Tastatura Logitech', 'Tastatura mecanica Logitech G413 SE, Switch Tactile, Iluminata, Negru', 73.97, 101);

INSERT INTO produs(id_produs, nume_produs, descriere, pret,id_furnizor)
VALUES (207, 'Procesor Ryzen 5', 'Procesor AMD Ryzen 5 3600, 4.2GHz, 36MB, socket AM4', 132.99, 101);

INSERT INTO produs(id_produs, nume_produs, descriere, pret,id_furnizor)
VALUES (208, 'Nintendo Switch', 'Consola Nintendo Switch OLED (Neon Blue/ Red Joy - Con)', 447.99, 101);

-- client
CREATE SEQUENCE client_seq START WITH 300 INCREMENT BY 1 NOCACHE NOCYCLE;
INSERT INTO client(id_client, nume, prenume, adresa, oras, email, telefon)
VALUES (client_seq.nextval, 'Popescu', 'Mirela', 'Aleea Buchetului 5', 'Bucuresti', 'mirelapopescu@gmail.com', '0312623134');

INSERT INTO client(id_client, nume, prenume, adresa, oras, email, telefon)
VALUES (client_seq.nextval, 'Bejan', 'Andrei', 'Bulevardul Unirii 27', 'Bucuresti', 'bejanadnrei@gmail.com', '0532652344');

INSERT INTO client(id_client, nume, prenume, adresa, oras, email, telefon)
VALUES (client_seq.nextval, 'Gurea', 'Dragos', 'Bulevardul 13 Septembrie', 'Bucuresti', 'gureadragos213@gmail.com', '0843513442');

INSERT INTO client(id_client, nume, prenume, adresa, oras, email, telefon)
VALUES (client_seq.nextval, 'Andreescu', 'Rares', 'Strada Decebal 14', 'Slobozia', 'abdreescrares090@gmail.com', '0982347113');

INSERT INTO client(id_client, nume, prenume, adresa, oras, email, telefon)
VALUES (client_seq.nextval, 'Postolache', 'Vera', 'Strada Grivitei 89', 'Braila', 'veraposto762@gmail.com', '0532477912');

INSERT INTO client(id_client, nume, prenume, adresa, oras, email, telefon)
VALUES (client_seq.nextval, 'Techin', 'Ramona', 'Calea Cosbuc 98', 'Iasi', 'ramotechin22@gmail.com', '0754628997');

INSERT INTO client(id_client, nume, prenume, adresa, oras, email, telefon)
VALUES (client_seq.nextval, 'Techiu', 'Daniel', 'Strada Florilor 24', 'Braila', 'teqdan@gmail.com', '0653494723');

INSERT INTO client(id_client, nume, prenume, adresa, oras, email, telefon)
VALUES (client_seq.nextval, 'Marin', 'Stefania', 'Aleea Parcului 32', 'Ploiesti', 'stefimarin193@gmail.com', '0753199824');

INSERT INTO client(id_client, nume, prenume, adresa, oras, email, telefon)
VALUES (client_seq.nextval, 'Popa', 'Andreea', 'Bulevardul Berceni 1', 'Bucuresti', 'popandreea222222@gmail.com', '0981264234');

INSERT INTO client(id_client, nume, prenume, adresa, oras, email, telefon)
VALUES (client_seq.nextval, 'Pop', 'Ionela', 'Calea Dreptatii 95', 'Timisoara', 'ioni235pop@gmail.com', '0981471467');

INSERT INTO client(id_client, nume, prenume, adresa, oras, email, telefon)
VALUES (client_seq.nextval, 'Ion', 'Cristian', 'Strada Codrului 7', 'Galati', 'cristianion92315@gmail.com', '0359273642');

-- departament
INSERT INTO departament(id_departament, nume_departament)
VALUES (800, 'IT');

INSERT INTO departament(id_departament, nume_departament)
VALUES (801, 'Finante');

INSERT INTO departament(id_departament, nume_departament)
VALUES (802, 'HR');

INSERT INTO departament(id_departament, nume_departament)
VALUES (803, 'Legal');

INSERT INTO departament(id_departament, nume_departament)
VALUES (804, 'Vanzari');

-- angajat
INSERT INTO angajat(id_angajat, nume, prenume, data_angajarii, salariu, id_departament)
VALUES (400, 'Sinca', 'Silviu', DATE '2018-11-25', 12300, 800);

INSERT INTO angajat(id_angajat, nume, prenume, data_angajarii, salariu, id_departament)
VALUES (401, 'Mitrescu', 'Mirela', DATE '2018-11-25', 16000, 801);

INSERT INTO angajat(id_angajat, nume, prenume, data_angajarii, salariu, id_departament)
VALUES (402, 'Pop', 'Alexandru', DATE '2019-04-15', 8900, 802);

INSERT INTO angajat(id_angajat, nume, prenume, data_angajarii, salariu, id_departament)
VALUES (403, 'Teohari', 'William', DATE '2019-08-01', 9540, 803);

INSERT INTO angajat(id_angajat, nume, prenume, data_angajarii, salariu, id_departament)
VALUES (404, 'Cordu', 'Roxana', DATE '2023-03-30', 4500, 804);

INSERT INTO angajat(id_angajat, nume, prenume, data_angajarii, salariu, id_departament)
VALUES (405, 'Ionescu', 'Adrian', DATE '2018-12-08', 4700, 804);

INSERT INTO angajat(id_angajat, nume, prenume, data_angajarii, salariu, id_departament)
VALUES (406, 'Mihail', 'Razvan', DATE '2018-12-08', 4390, 804);

INSERT INTO angajat(id_angajat, nume, prenume, data_angajarii, salariu, id_departament)
VALUES (407, 'Dascalu', 'Mihaela', DATE '2018-12-08', 5600, 804);

-- comanda
INSERT INTO comanda(id_comanda, data_comanda, id_client, id_angajat)
VALUES (500, DATE '2019-08-12', 303, 407);

INSERT INTO comanda(id_comanda, data_comanda, id_client, id_angajat)
VALUES (501, DATE '2019-03-24', 301, 406);

INSERT INTO comanda(id_comanda, data_comanda, id_client, id_angajat)
VALUES (502, DATE '2020-03-16', 302, 405);

INSERT INTO comanda(id_comanda, data_comanda, id_client, id_angajat)
VALUES (503, DATE '2020-06-09', 302, 405);

INSERT INTO comanda(id_comanda, data_comanda, id_client, id_angajat)
VALUES (504, DATE '2020-07-30', 306, 405);

INSERT INTO comanda(id_comanda, data_comanda, id_client, id_angajat)
VALUES (505, DATE '2020-11-28', 309, 406);


-- comanda_produs

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (600, 500, 201, 1);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (601, 500, 202, 1);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (602, 500, 206, 4);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (603, 501, 208, 2);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (604, 502, 201, 1);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (605, 502, 204, 2);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (606, 503, 205, 3);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (607, 504, 200, 2);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (608, 504, 201, 1);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (609, 504, 203, 2);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (610, 505, 200, 10);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (611, 505, 201, 12);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (612, 505, 205, 8);

INSERT INTO comanda_produs(id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (613, 505, 206, 15);


-- 6. 
-- Procedura pentru calcularea pretului total al unei comenzi
CREATE OR REPLACE PROCEDURE calculeaza_pret_comanda(p_id_comanda NUMBER) AS
	TYPE v_pret_index is TABLE OF comanda_produs.id_comanda_produs%type INDEX BY binary_INTEGER;
	TYPE cantitate_varray is VARRAY(100) OF NUMBER;
    
   v_cantitati cantitate_varray := cantitate_varray();
   v_preturi v_pret_index;
   v_total NUMBER(10, 2) := 0;
BEGIN
   FOR c IN (SELECT id_produs, cantitate FROM comanda_produs WHERE id_comanda = p_id_comanda) LOOP
      v_cantitati.EXTEND;
      v_preturi(c.id_produs) := 0; 

      SELECT pret INTO v_preturi(c.id_produs)
      FROM produs
      WHERE id_produs = c.id_produs;

      v_total := v_total + (v_preturi(c.id_produs) * c.cantitate);
   END LOOP;

   DBMS_OUTPUT.PUT_LINE('Pretul total al comenzii ' || p_id_comanda || ' este: ' || v_total);
END;
/
    
DECLARE
   v_id_comanda NUMBER := 503; 
BEGIN
   calculeaza_pret_comanda(v_id_comanda);
END;
/



-- 7. 
-- cu ajutorul a 2 cursoare sa se listeze toate produsele detinute de un anumit furnizor 

CREATE OR REPLACE PROCEDURE afisare_informatii_furnizor_produse (
    p_id_furnizor IN NUMBER
) AS
    CURSOR c_furnizor IS
        SELECT f.id_furnizor, f.nume_furnizor, f.adresa, f.oras
        FROM furnizor f
        WHERE f.id_furnizor = p_id_furnizor;
        
    CURSOR c_produse (p_id_furnizor NUMBER) IS
        SELECT p.id_produs, p.nume_produs, p.descriere, p.pret
        FROM produs p
        WHERE p.id_furnizor = p_id_furnizor;
        
    v_id_furnizor furnizor.id_furnizor%TYPE;
    v_nume_furnizor furnizor.nume_furnizor%TYPE;
    v_adresa furnizor.adresa%TYPE;
    v_oras furnizor.oras%TYPE;
    
    v_id_produs produs.id_produs%TYPE;
    v_nume_produs produs.nume_produs%TYPE;
    v_descriere produs.descriere%TYPE;
    v_pret produs.pret%TYPE;
BEGIN
    OPEN c_furnizor;
    
    FETCH c_furnizor INTO v_id_furnizor, v_nume_furnizor, v_adresa, v_oras;
    
    IF c_furnizor%FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Furnizor: ' || v_nume_furnizor);
        DBMS_OUTPUT.PUT_LINE('Adresa: ' || v_adresa);
        DBMS_OUTPUT.PUT_LINE('Oras: ' || v_oras);
        
        OPEN c_produse(p_id_furnizor);
        
        LOOP
            FETCH c_produse INTO v_id_produs, v_nume_produs, v_descriere, v_pret;
            EXIT WHEN c_produse%NOTFOUND;
            DBMS_OUTPUT.PUT_LINE('  Produs: ' || v_nume_produs);
            DBMS_OUTPUT.PUT_LINE('  Descriere: ' || v_descriere);
            DBMS_OUTPUT.PUT_LINE('  Pret: ' || v_pret);
            DBMS_OUTPUT.PUT_LINE('------------------------');
        END LOOP;
        CLOSE c_produse;
    ELSE
        DBMS_OUTPUT.PUT_LINE('Furnizorul cu ID-ul ' || p_id_furnizor || ' nu a fost găsit.');
    END IF;
    
    CLOSE c_furnizor;
END;
/


BEGIN
    afisare_informatii_furnizor_produse(100);
END;
/

-- ================================================================================================================
-- 8
-- functie care ofera data despre comenzile facute de angajati

CREATE OR REPLACE FUNCTION informatii_angajati_comenzi RETURN VARCHAR2 IS
    v_result VARCHAR2(4000);  
    salariu_prea_mic EXCEPTION;
    angajat_prea_tarziu EXCEPTION;
BEGIN
    v_result := NULL;
    
    FOR rec IN (
        SELECT a.nume, a.prenume, a.salariu, d.nume_departament, a.data_angajarii,
               COUNT(c.id_comanda) AS numar_comenzi
        FROM angajat a
        JOIN departament d ON a.id_departament = d.id_departament
        LEFT JOIN comanda c ON a.id_angajat = c.id_angajat
        WHERE a.data_angajarii >= TO_DATE('01-JAN-2020', 'DD-MON-YYYY')
        GROUP BY a.nume, a.prenume, a.salariu, d.nume_departament, a.data_angajarii
        HAVING COUNT(c.id_comanda) > 0
        ORDER BY a.nume, a.prenume
    ) LOOP
        IF rec.data_angajarii > TO_DATE('31-DEC-2020', 'DD-MON-YYYY') THEN
            RAISE angajat_prea_tarziu;
        END IF;
        
        IF rec.salariu < 4500 THEN
            RAISE salariu_prea_mic;
        END IF;

        v_result := v_result || 'Nume: ' || rec.nume || ', Prenume: ' || rec.prenume ||
                    ', Salariu: ' || TO_CHAR(rec.salariu) || ', Departament: ' || rec.nume_departament ||
                    ', Număr Comenzi: ' || TO_CHAR(rec.numar_comenzi) || CHR(10);
        return v_result;
    END LOOP;
    
EXCEPTION
    WHEN salariu_prea_mic THEN
        RETURN 'Salariul angajatului este prea mic (mai mic de 4500 de lei).';
    WHEN angajat_prea_tarziu THEN
        RETURN 'Angajatul a fost angajat după anul 2020.';

END;
/

-- Apelarea subprogramului
DECLARE
    v_info VARCHAR2(4000);
BEGIN
    v_info := informatii_angajati_comenzi;
    DBMS_OUTPUT.PUT_LINE(v_info);
EXCEPTION
    WHEN OTHERS THEN
        -- Tratăm alte erori și afișăm un mesaj
        DBMS_OUTPUT.PUT_LINE('A apărut o eroare: ' || SQLERRM);
END;
/

-- ================================================================================================================
-- 9
-- Afisarea detaliilor despre o comanda data ca parametru cu id-ul, cu precizarea ca pentru comenzile clientilor
-- din Braila nu se pot afisa detalii

CREATE OR REPLACE PROCEDURE afisare_comanda_cu_conditie(p_id_comanda IN NUMBER) AS
	client_din_braila number := 0;
begin

	SELECT COUNT(*) INTO client_din_braila
    FROM client c
WHERE c.id_client = (SELECT co.id_client FROM comanda co WHERE co.id_comanda = p_id_comanda)
    AND c.oras = 'Braila';
    FOR record IN (
    SELECT c.id_comanda, c.data_comanda, cl.nume, cl.prenume, a.nume AS nume_angajat, cp.id_produs, p.nume_produs, cp.cantitate
    FROM comanda c
    JOIN client cl ON c.id_client = cl.id_client
    JOIN angajat a ON c.id_angajat = a.id_angajat
    JOIN comanda_produs cp ON c.id_comanda = cp.id_comanda
    JOIN produs p ON cp.id_produs = p.id_produs
    WHERE c.id_comanda = p_id_comanda
    ) LOOP
    dbms_output.put_line('Data comenzii: ' || TO_CHAR(record.data_comanda, 'DD-MON-YYYY'));
    dbms_output.put_line('Nume Client: ' || record.nume || ', Prenume Client: ' || record.prenume);
    dbms_output.put_line('Nume Angajat: ' || record.nume_angajat);
    dbms_output.put_line('Produsul ID: ' || record.id_produs || ', Nume: ' || record.nume_produs || ', Cantitate: ' || record.cantitate);
    END LOOP;


	IF client_din_braila > 0 THEN
        raise_application_error(-20101, 'Clientul este din Braila.');
    END IF;

EXCEPTION
    WHEN NO_DATA_FOUND THEN
        RAISE_APPLICATION_ERROR(-20000, 'Nu exista comanda cu id-uld at.');
    WHEN TOO_MANY_ROWS THEN
        RAISE_APPLICATION_ERROR(-20001, 'Exista mai mult de o comanda cu id-ul dat.');
    WHEN OTHERS THEN
        RAISE_APPLICATION_ERROR(-20002, 'Clientul apartine unei francize dintr-un alt oras: ' || SQLERRM);
END afisare_comanda_cu_conditie;
/

execute afisare_comanda_cu_conditie(503);
execute afisare_comanda_cu_conditie(504);

-- ================================================================================================================
-- 10
-- trigger lmd la nivel de comanda astfel incat sa nu se permita crearea de comenzi noi in zilele de duminica si sa 
-- se respecte programul de la 8 la 17

create or replace trigger trg_magazin_inchis
	before insert on comanda
	begin
    if (to_char(sysdate, 'HH24') < 8 or to_char(sysdate, 'HH24') > 17) or lower(to_char(sysdate,'Day')) = 'sunday' then
			RAISE_APPLICATION_ERROR(-20125, 'Magazinul este inchis!');
		end if;
	end;
/

INSERT INTO comanda(id_comanda, data_comanda, id_client, id_angajat)
VALUES (6, CURRENT_TIMESTAMP, 309, 406);

-- ================================================================================================================
-- 11.
-- trigger LMD la nivel de linie, astfel incat sa nu poti comanda mai mult de 50 de produse cu un pret de peste 1000 de euro

CREATE OR REPLACE TRIGGER trg_verificare_pret
BEFORE INSERT OR UPDATE ON comanda_produs
FOR EACH ROW
    DECLARE
  v_pret NUMBER(6, 2);
BEGIN
  SELECT pret INTO v_pret FROM produs WHERE id_produs = :NEW.id_produs;
  IF :NEW.cantitate > 50 AND v_pret > 1000 THEN
    raise_application_error(-20004,'Nu se pot comanda mai mult de 50 de produse cu un pret de peste 1000 de euro!');
  END IF;
END;
/

INSERT INTO comanda_produs (id_comanda_produs, id_comanda, id_produs, cantitate)
VALUES (700, 500, 200, 60);

-- ================================================================================================================
-- 12
-- trigger pentru a nu permite alterarea unui tabel
CREATE OR REPLACE TRIGGER trg_alter_tabel
BEFORE ALTER ON SCHEMA 
BEGIN
    RAISE_APPLICATION_ERROR(-20006,'Nu poti modifica tabela!');
END;
/

ALTER TABLE produs
ADD CONSTRAINT ck_pret CHECK (pret < 10000);
