------
----create table EMP_SSG as (select * from employees);
----COMMENT ON TABLE emp_ssg IS 'Informa?ii despre angajati';
----
----select comments
----from user_tab_comments
----where lower(table_name)='emp_ssg';
----
----ALTER SESSION SET NLS_DATE_FORMAT = 'MM.DD.YYYY HH24:MI:SS';
----
----SELECT EXTRACT(YEAR FROM SYSDATE)
----FROM dual;
----
----SELECT EXTRACT(DAY FROM SYSDATE), EXTRACT(MONTH FROM SYSDATE)
----FROM dual;
------
--
----set feedback off
----
----set pagesize 0
----spool 'C:\Users\Silviu\test-sgdb\stergere_tabel.sql'
----    
----select 'drop table ' || table_name
----from user_tables
----where lower(table_name) like '%_ssg';
----
----spool off
----
----spool 'C:\Users\Silviu\test-sgdb\inserare_tabel.sql'
----create table DEP_SSG as (select * from departments);
----spool off
----
----select * from dep_ssg;
--
--select max(count(tc.title_id)) 
--from rental r
--join title_copy tc on r.copy_id = tc.copy_id and r.title_id = tc.title_id
--join title t on t.title_id = tc.title_id;
--
--select max(count(title_copy.title_id))
--from title, rental, title_copy
--where title.title_id = rental.title_id
--      and title_copy.title_id = title.title_id
--      and title_copy.copy_id = rental.copy_id
--group by category;
--
--select title.title, count(copy_id)
--from title_copy join title on (title.title_id = title_copy.title_id)
--where copy_id not in (select rental.copy_id
--                      from rental join title_copy on (title_copy.title_id = rental.title_id and title_copy.copy_id = rental.copy_id)
--                      where act_ret_date is null and title_copy.title_id = title.title_id)
--group by title.title;
--
--select t.title "Titlu", tc.copy_id "Numar Exemplar", tc.status "Status Gresit",
--case
--  when  (r.book_date is not null and r.act_ret_date is null)
--        or tc.copy_id not in (select rental.copy_id
--                      from rental join title_copy on (title_copy.title_id = rental.title_id and title_copy.copy_id = rental.copy_id)
--                      where act_ret_date is null and tc.title_id = t.title_id)
--        then 'RENTED'
--  else 'AVAILABLE'
--end "Status Corect"
--from title_copy tc, rental r, title t
--where tc.title_id = t.title_id
--and r.title_id = t.title_id
--and r.copy_id = tc.copy_id;
--


--BEGIN
--    DBMS_OUTPUT.PUT_LINE('invat pl/sql');
--END;

VARIABLE rezultat VARCHAR2(35)
VARIABLE numar_angajati NUMBER(4)
BEGIN
    SELECT MAX(COUNT(*)) INTO :numar_angajati FROM employees GROUP BY department_id;

    SELECT department_name
    INTO :rezultat
    FROM employees e, departments d
    WHERE e.department_id=d.department_id
    GROUP BY department_name
    HAVING COUNT(*) = :numar_angajati;
    DBMS_OUTPUT.PUT_LINE('Departamentul '|| :rezultat || ' are ' || :numar_angajati || ' angajati');
END;
/
PRINT numar_angajati




