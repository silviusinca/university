-- ex 6
with status_corect as (select t.title, tc.title_id, tc.copy_id, max(ren.book_date) maxim
             from title t, title_copy tc, rental ren
             where ren.title_id(+) = tc.title_id 
             and ren.copy_id(+) = tc.copy_id 
             and tc.title_id = t.title_id
             group by(t.title, tc.copy_id, tc.title_id))
select status_corect.title titlu, status_corect.copy_id nr_Exemplar, tc.status status_Setat, 
case 
    when r.act_ret_date <= r.exp_ret_date 
    or status_corect.maxim is null then 'AVAILABLE'
    else 'RENTED'
end as status_Corect
from status_corect, rental r, title_copy tc, title t
where status_corect.title_id = r.title_id(+) and status_corect.title_id = t.title_id
and status_corect.copy_id = r.copy_id(+) and t.title_id = tc.title_id 
and status_corect.copy_id = tc.copy_id and (r.book_date = status_corect.maxim or status_corect.maxim is null);

-- ex 8 
select case 
            when (select count(*) 
                from rental ren, reservation res
                where ren.title_id = res.title_id and ren.member_id = res.member_id and ren.book_date = res.res_date) = (select count(*) from reservation)
                then 'Da'
            else 'Nu'
       end as "Raspuns"
from dual;

-- ex 9
select last_name, first_name, t.title, nr.num "Raspuns"
from member m, title t, (select title_id, member_id, count(*) num
                          from rental
                          group by (title_id, member_id)) nr
where m.member_id = nr.member_id and t.title_id = nr.title_id;

-- ex 10
select last_name, first_name, nr.copy_id, t.title, nr.num "Raspuns"
from member m, title t, (select copy_id, title_id, member_id, count(*) num
                          from rental
                          group by (copy_id, title_id, member_id)) nr
where m.member_id = nr.member_id and t.title_id = nr.title_id;
