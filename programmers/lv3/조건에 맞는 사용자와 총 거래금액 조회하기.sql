with tb as (
    select u.user_id, u.nickname, sum(b.price) as total_sales
    from used_goods_board b
    join used_goods_user u on b.writer_id = u.user_id
    where b.status like 'DONE'
    group by b.writer_id
    having count(*) > 0
)
SELECT *
from tb
where tb.total_sales >= 700000
order by tb.total_sales asc;