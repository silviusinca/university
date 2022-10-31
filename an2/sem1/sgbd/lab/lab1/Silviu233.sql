----
--create table EMP_SSG as (select * from employees);
--COMMENT ON TABLE emp_ssg IS 'Informa?ii despre angajati';
--
--select comments
--from user_tab_comments
--where lower(table_name)='emp_ssg';
--
--ALTER SESSION SET NLS_DATE_FORMAT = 'MM.DD.YYYY HH24:MI:SS';
--
--SELECT EXTRACT(YEAR FROM SYSDATE)
--FROM dual;
--
--SELECT EXTRACT(DAY FROM SYSDATE), EXTRACT(MONTH FROM SYSDATE)
--FROM dual;
----

--set feedback off
--
--set pagesize 0
--spool 'C:\Users\Silviu\test-sgdb\stergere_tabel.sql'
--    
--select 'drop table ' || table_name
--from user_tables
--where lower(table_name) like '%_ssg';
--
--spool off
--
--spool 'C:\Users\Silviu\test-sgdb\inserare_tabel.sql'
--create table DEP_SSG as (select * from departments);
--spool off
--
--select * from dep_ssg;
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

--select title.title, count(copy_id)
--from title_copy join title on (title.title_id = title_copy.title_id)
--where copy_id not in (select rental.copy_id
--                      from rental join title_copy on (title_copy.title_id = rental.title_id and title_copy.copy_id = rental.copy_id)
--                      where act_ret_date is null and title_copy.title_id = title.title_id)
--group by title.title;

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


--BEGIN
--    DBMS_OUTPUT.PUT_LINE('invat pl/sql');
--END;

--VARIABLE rezultat VARCHAR2(35)
--VARIABLE numar_angajati NUMBER(4)
--BEGIN
--    SELECT MAX(COUNT(*)) INTO :numar_angajati FROM employees GROUP BY department_id;
--
--    SELECT department_name
--    INTO :rezultat
--    FROM employees e, departments d
--    WHERE e.department_id=d.department_id
--    GROUP BY department_name
--    HAVING COUNT(*) = :numar_angajati;
--    DBMS_OUTPUT.PUT_LINE('Departamentul '|| :rezultat || ' are ' || :numar_angajati || ' angajati');
--END;
--/
--PRINT numar_angajati
--
--
--
---- ex 6
--with status_corect as (select t.title, tc.title_id, tc.copy_id, max(ren.book_date) maxim
--             from title t, title_copy tc, rental ren
--             where ren.title_id(+) = tc.title_id 
--             and ren.copy_id(+) = tc.copy_id 
--             and tc.title_id = t.title_id
--             group by(t.title, tc.copy_id, tc.title_id))
--select status_corect.title titlu, status_corect.copy_id nr_Exemplar, tc.status status_Setat, 
--case 
--    when r.act_ret_date <= r.exp_ret_date 
--    or status_corect.maxim is null then 'AVAILABLE'
--    else 'RENTED'
--end as status_Corect
--from status_corect, rental r, title_copy tc, title t
--where status_corect.title_id = r.title_id(+) and status_corect.title_id = t.title_id
--and status_corect.copy_id = r.copy_id(+) and t.title_id = tc.title_id 
--and status_corect.copy_id = tc.copy_id and (r.book_date = status_corect.maxim or status_corect.maxim is null);
--
---- ex 8 
--select case 
--            when (select count(*) 
--                from rental ren, reservation res
--                where ren.title_id = res.title_id and ren.member_id = res.member_id and ren.book_date = res.res_date) = (select count(*) from reservation)
--                then 'Da'
--            else 'Nu'
--       end as "Raspuns"
--from dual;
--
---- ex 9
--select last_name, first_name, t.title, nr.num "Raspuns"
--from member m, title t, (select title_id, member_id, count(*) num
--                          from rental
--                          group by (title_id, member_id)) nr
--where m.member_id = nr.member_id and t.title_id = nr.title_id;
--
---- ex 10
--select last_name, first_name, nr.copy_id, t.title, nr.num "Raspuns"
--from member m, title t, (select copy_id, title_id, member_id, count(*) num
--                          from rental
--                          group by (copy_id, title_id, member_id)) nr
--where m.member_id = nr.member_id and t.title_id = nr.title_id;

--
set verify off
declare
    v_cod   employees.employee_id%TYPE := &p_cod;
    v_bonus number(8);
    v_salariu_anual number(8);
begin
    select salary*12 into v_salariu_anual
    from employees
    where employee_id = v_cod;
    case when v_salariu_anual >= 200001
            then v_bonus := 20000;
        when v_salariu_anual >= 100001 and v_salariu_anual <= 200000
            then v_bonus := 10000;
        when v_salariu_anual <= 100000
            then v_bonus := 5000;
    end case;
DBMS_OUTPUT.PUT_LINE('Bonusul este ' || v_bonus);
end;
/
set verify on

define p_cod_sal = 1
define p_cod_dep = 50
define p_procent = 30
declare
    v_cod_sal   emp_ssg.employee_id%TYPE := &p_cod_sal;
    v_cod_dep   emp_ssg.department_id%TYPE := &p_cod_dep;
    v_procent   number(8) := &p_procent;
begin
    update emp_ssg
    set department_id = v_cod_dep, 
        salary = salary + salary*v_procent/100
    where employee_id = v_cod_sal;
    if sql%rowcount = 0
        then DBMS_OUTPUT.PUT_LINE('Nu exista un angajat cu acest cod');
    else DBMS_OUTPUT.PUT_LINE('Actualizare realizata');
    end if;
end;
/
rollback;

create table zile_ssg (
        id  number(6),
        data date,
        nume_zi varchar2(100)
);

declare
    contor number(6) := 1;
    v_data date;
    maxim number(2) := last_day(sysdate)-sysdate;
begin
    while contor <= maxim loop
        v_data := sysdate + contor;
        insert into zile_ssg values(contor, v_data, to_char(v_data, 'Day'));
        contor := contor + 1;
    end loop;
end;
/

select * from zile_ssg;
drop table zile_ssg;


declare
    contor number(6) := 1;
    v_data date;
    nr_zile number(2) := to_char(sysdate, 'dd');
    data_aux date := trunc(sysdate, 'MM');
begin
    while nr_zile >= 1 loop
        v_data := data_aux;
        insert into octombrie_ssg values(contor, v_data);
        nr_zile := nr_zile - 1;
        data_aux := data_aux + 1;
        contor := contor + 1;
    end loop;
end;
/

create table octombrie_ssg (
        id  number(6),
        data date
);
drop table octombrie_ssg;
select * from octombrie_ssg;

select data, (select count(*)
              from rental
              where to_date(book_date) = data)
from octombrie_ssg;

