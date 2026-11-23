# Write your MySQL query statement below
select (
        select distinct e.salary 
        from Employee e
        where 1 = ( 

            select count(DISTINCT salary) 
            from Employee
            where salary > e.salary
            ) 
) AS SecondHighestSalary 
