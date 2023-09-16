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
