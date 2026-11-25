# Write your MySQL query statement below

select d.name As Department , e1.name AS Employee , e1.salary AS Salary

from employee e1 
join department d
ON e1.departmentId=d.id 
 
where (
        select count(distinct e2.salary)
        from employee e2 
        where e2.salary>e1.salary
        && e1.departmentId=e2.departmentId
) <3