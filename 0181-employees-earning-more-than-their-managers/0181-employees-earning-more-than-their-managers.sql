# Write your MySQL query statement below

select e.name AS Employee
from employee e 
join employee m 
ON e.managerId=m.id 
where e.salary > m.salary 