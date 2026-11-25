# Write your MySQL query statement below

select distinct p.email AS Email 
from person p 
where EXISTS ( select 1
                from person q 
                where p.email=q.email
                        AND p.id <> q.id
                    ) ;