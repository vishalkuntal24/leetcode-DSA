# Write your MySQL query statement below

select c.name AS Customers 
from Customers c
LEFT join Orders o 
ON c.id=o.customerId 
where o.customerId is NULL 