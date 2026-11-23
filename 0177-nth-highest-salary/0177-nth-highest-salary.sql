CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.

         select distinct e.salary 
         from Employee e
         where N-1 = (
                        select count(distinct salary)
                        from Employee 
                        where salary > e.salary 

                   )
                   limit 1 

  );
END