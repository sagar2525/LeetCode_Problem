# Write your MySQL query statement below
select e.name as name , b.bonus as bonus
from employee e
left join bonus b
on 
e.empid = b.empid 
where bonus<1000 or bonus is null