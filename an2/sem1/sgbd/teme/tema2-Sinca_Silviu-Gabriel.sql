set verify off
declare
    v_nume          member.last_name%TYPE := '&p_nume';
    v_count         number(8);
    v_member_count  number(8);
begin
    select count(*) into v_member_count from member where lower(v_nume) = lower(last_name);
    if v_member_count = 0
        then DBMS_OUTPUT.PUT_LINE('Nu exista acest membru');
    elsif v_member_count > 1
        then DBMS_OUTPUT.PUT_LINE('Exista mai multi membri cu acelasi nume');
    else
        select count(*) into v_count
        from rental r, member m
        where lower(v_nume) = lower(m.last_name) and r.member_id = m.member_id;
        DBMS_OUTPUT.PUT_LINE('Numarul de carti imprumutate: ' || v_count);
    end if;
end;
/
set verify on


-- 4
set verify off
declare
    v_nume          member.last_name%TYPE := '&p_nume';
    v_count         number(8);
    v_member_count  number(8);
    v_num_titluri   number(8);
begin
    select count(*) into v_member_count from member where lower(v_nume) = lower(last_name);
    if v_member_count = 0
        then DBMS_OUTPUT.PUT_LINE('Nu exista acest membru');
    elsif v_member_count > 1
        then DBMS_OUTPUT.PUT_LINE('Exista mai multi membri cu acelasi nume');
    else
        select count(*) into v_num_titluri from title;
    
        select count(*) into v_count
        from rental r, member m
        where lower(v_nume) = lower(m.last_name) and r.member_id = m.member_id;
        case 
            when v_count > 0.75*v_num_titluri
                then DBMS_OUTPUT.PUT_LINE('Categoria 1');
            when v_count > 0.5*v_num_titluri and v_count <= 0.75*v_num_titluri
                then DBMS_OUTPUT.PUT_LINE('Categoria 2');
            when v_count > 0.25*v_num_titluri and v_count <= 0.5*v_num_titluri
                then DBMS_OUTPUT.PUT_LINE('Categoria 3');
            else DBMS_OUTPUT.PUT_LINE('Categoria 4');
        end case;    
    end if;
end;
/
set verify on

-- 5
create table member_ssg as (select * from member);
alter table member_ssg
add discount number(8);

set verify off
declare
    v_nume          member.last_name%TYPE := '&p_nume';
    v_count         number(8);
    v_member_count  number(8);
    v_num_titluri   number(8);
    v_discount      number(8);
begin
    select count(*) into v_member_count from member where lower(v_nume) = lower(last_name);
    if v_member_count = 0
        then DBMS_OUTPUT.PUT_LINE('Nu exista acest membru. Actualizarea nu a fost realizata');
    elsif v_member_count > 1
        then DBMS_OUTPUT.PUT_LINE('Exista mai multi membri cu acelasi nume. Actualizarea nu a fost realizata');
    else
        select count(*) into v_num_titluri from title;
    
        select count(*) into v_count
        from rental r, member m
        where lower(v_nume) = lower(m.last_name) and r.member_id = m.member_id;
        case 
            when v_count > 0.75*v_num_titluri
                then v_discount := 10;
            when v_count > 0.5*v_num_titluri and v_count <= 0.75*v_num_titluri
                then v_discount := 5;
            when v_count > 0.25*v_num_titluri and v_count <= 0.5*v_num_titluri
                then v_discount := 3;
            else v_discount := 0;
        end case;
        
        update member_ssg m set m.discount = v_discount where lower(m.last_name) = lower(v_nume); 
        DBMS_OUTPUT.PUT_LINE('Actualizarea a fost realizata');
    end if;
end;
/
set verify on

commit;