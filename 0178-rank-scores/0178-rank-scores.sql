# Write your MySQL query statement below

select score , DENSE_rank() OVER ( order by score DESC) as 'rank'
from scores 