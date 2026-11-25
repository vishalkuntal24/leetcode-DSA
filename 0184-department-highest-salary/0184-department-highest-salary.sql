# Write your MySQL query statement below

select d.name AS Department , e.name AS Employee , e.salary AS Salary 
from Employee e 
join Department d 
ON e.departmentId=d.id 

where e.salary = ( 
        select max(e2.salary) 
        from employee e2 
        where e.departmentId = e2.departmentId   
)