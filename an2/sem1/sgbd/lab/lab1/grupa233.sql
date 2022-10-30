----
create table EMP_SSG as (select * from employees);
COMMENT ON TABLE emp_ssg IS 'Informaţii despre angajati';

select comments
from user_tab_comments
where lower(table_name)='emp_ssg';

ALTER SESSION SET NLS_DATE_FORMAT = 'MM.DD.YYYY HH24:MI:SS';

SELECT EXTRACT(YEAR FROM SYSDATE)
FROM dual;

SELECT EXTRACT(DAY FROM SYSDATE), EXTRACT(MONTH FROM SYSDATE)
FROM dual;
----

spool 'Users/silviu/stergere_tabel.sql'

select 'drop table ' || table_name
from user_tables
where lower(table_name) like '%_ssg';

spool off

